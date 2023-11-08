#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

class File
{
public:
    File(const std::string &name)
        : m_name(name)
    {

    }

    bool isDirectory() const {
        return m_isDirectory;
    }

    void setDirectory(bool isDirectory)
    {
        m_isDirectory = isDirectory;
    }

    std::string getFileName() const {
        return m_name;
    }
    
private:
    std::string m_name;
    bool m_isDirectory{false};
};


class IFileVisitor
{
public:
    virtual ~IFileVisitor() {}

    virtual void visit(const File &dir) = 0;
};



class Directory
{

public:
    Directory(const std::string &dir_path)
        : m_dir_path(dir_path)
    {

    }

    void scan(IFileVisitor &v)
    {
        int directoryCount = 0;
        int fileCount = 0;
        
        try
        {
             
            for (auto const& dir_entry : fs::directory_iterator{ m_dir_path, fs::directory_options::skip_permission_denied })
            {
                File f(fs::absolute(dir_entry.path()));

                if (dir_entry.is_directory()) 
                {
                    directoryCount++;
                    Directory subdir(dir_entry.path());
                    subdir.scan(v);
                    f.setDirectory(true);
                }
                
                if (dir_entry.is_regular_file())
                {
                    fileCount++;
                    // Open file and count lines if expected extension
                }
                v.visit(f);
                m_files.push_back(f);
            }
        }
        catch (...)
        {  
            
        }
    }
  
private:
    std::string m_dir_path;
    std::vector<File> m_files;
    
};

// Implémentation de type display, on se contente d'afficher le nom du fichier
class ConsoleFileDisplay : public IFileVisitor
{
public:
   virtual void visit(const File &f)
   {
         std::cout << "File: " << f.getFileName() << std::endl;
   }
};

class LinesCounter : public IFileVisitor
{
public:
   virtual void visit(const File &f)
   {
        std::string extension = fs::path(f.getFileName()).extension();
        if (!f.isDirectory() && (extension == ".txt"))
        {
            std::cout << "Opening: " << f.getFileName() << std::endl;
            std::ifstream file(f.getFileName());
            if (!file.is_open()) {
                std::cerr << "Erreur : Impossible d'ouvrir le fichier " << f.getFileName() << std::endl;
                return;
            }

            int lineCount = 0;
            std::string line;

            while (std::getline(file, line)) {
                lineCount++;
            }

            file.close();

            m_totalLines += lineCount;
        }
   }

    int getTotalLines() const {
        return m_totalLines;
    }

private:
    int m_totalLines{0};
};

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        std::cout << "Scaning directory: " << fs::absolute(fs::path(argv[1])) << std::endl;
        Directory dir(argv[1]);

        ConsoleFileDisplay display;
        dir.scan(display);

        std::cout << "------------------------------" << std::endl;

        LinesCounter counter;
        dir.scan(counter);

        std::cout << "Total lines: " << counter.getTotalLines() << std::endl;
    }

    return 0;
}

