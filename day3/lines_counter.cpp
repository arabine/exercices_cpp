#include <iostream>
#include <string>
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

    std::string getFileName() const {
        return m_name;
    }
    
private:
    std::string m_name;
};


class IDisplayVisitor
{
public:
    virtual ~IDisplayVisitor() {}

    virtual void print(const File &dir) = 0;
};



class Directory
{

public:
    Directory(const std::string &dir_path)
        : m_dir_path(dir_path)
    {

    }

    void scan(IDisplayVisitor &v)
    {
        int directoryCount = 0;
        int fileCount = 0;
        
        try
        {
             
            for (auto const& dir_entry : fs::directory_iterator{ m_dir_path, fs::directory_options::skip_permission_denied })
            {
            
                if (dir_entry.is_directory()) 
                {
                    directoryCount++;
                    Directory subdir(dir_entry.path());
                    subdir.scan(v);
                }
                
                if (dir_entry.is_regular_file())
                {
                    fileCount++;
                    // Open file and count lines if expected extension
                }
                
                File f(fs::path(dir_entry.path()).filename());
                v.print(f);
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


class ConsoleDirectoryDisplay : public IDisplayVisitor
{
   virtual void print(const File &f)
   {
         std::cout << "File: " << f.getFileName() << std::endl;
   }
};

int main(int argc, char **argv)
{

    
    if (argc > 1)
    {
        std::cout << "Scaning directory: " << fs::absolute(fs::path(argv[1])) << std::endl;
        Directory dir(argv[1]);

        ConsoleDirectoryDisplay display;

        dir.scan(display);
    }

    return 0;
}

