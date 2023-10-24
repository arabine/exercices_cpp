#include <iostream>
#include <string>

class Tree
{
public:
    Tree(const std::string &species = "", int age = 0, int height = 0, bool deciduous = 0)
        : m_species(species)
        , m_age(age)
        , m_height(height)
        , m_deciduous(deciduous)
    {
    }
    
    ~Tree()
    {
    }
    
    void show() const 
    {
        std::cout << "Tree: " << m_species << ", age: " << m_age << ", height: " << m_height << ", deciduous: " << m_deciduous << std::endl;
    }
     
    
protected:
    std::string m_species;
    int m_age;
    int m_height;
    bool m_deciduous; // vrai si feuilles caduques
};


class Conifere : public Tree
{
public:
    
    Conifere(const std::string &species = "", int age = 0, int height = 0) : Tree(species, age, height, false)
    {
    }
    
};


class Caduque : public Tree
{
public:
    Caduque(const std::string &species = "", int age = 0, int height = 0) : Tree(species, age, height, true)
    {
    }    
};



int main(int argc, char **argv)
{
     std::cout << "Starting "  << argv[0]<< std::endl;
     
    
     Conifere sapin("Sapin", 25, 18);
     Caduque albizia("Albizia", 4, 2);
    
     sapin.show();
     
     albizia.show();
     
    return 0;
}
