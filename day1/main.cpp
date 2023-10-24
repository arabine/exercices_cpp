#include <iostream>
#include <string>
#include "teacher.h"
#include "array.h"

void TestTeacher()
{
   
    
    Teacher t1("François", "Vincent", 52); 
 //   t1.setIdentity("François", "Vincent", 52);
    Teacher t2("Paul", "Bismuth", 42);
//    t2.setIdentity("Paul", "Bismuth", 42);
    Teacher t3;
    std::cout << t1.getFullName() << std::endl;
    std::cout << t2.getFullName() << std::endl;
    
    
    
    for (int i = 0; i < 9807; i++) {
        new Teacher(); // on perd les pointeurs, et on ne désaloue pas la mémoire !
    }
    
    std::cout << "Nombre de profs: " << Teacher::getTeachersNumber() << std::endl;
}

void TestArray()
{
    Array a(5);
    
    a.show();
    
    Array b(10);
    
    b.show();
    
    a = b;
    
    a.show();
    
}

int main(int argc, char **argv)
{
     std::cout << "Starting "  << argv[0]<< std::endl;
     
  //  TestTeacher();
    
    
    TestArray();
    
    return 0;
}
