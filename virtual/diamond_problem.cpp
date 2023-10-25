 
#include <iostream>
 
struct A {
    A(int a = 0) : age(a) { std::cout << " A(), age = " << age; }
    void MethodA() { std::cout << " MethodA(), age = " << age; }
    
private:
    int age{42};
};

// Two classes inheriting A:
struct B: A {
    B() { std::cout << " B()"; }
};

struct C: A {
    C() { std::cout << " C()"; }

};

struct D: public B, public C 
{
    D()  { std::cout << " D()"; }
};

/*

Voilà ce que l'on a en mémoire : A a été créé deux fois, il est en double !

A   A  
|   |
B   C  
 \ /  
  D 
  
Alors que l'on veut ça :

  A  
 / \  
B   C  
 \ /  
  D 


La sortie donne bien deux appel au constructeur par défaut de A (qui vaut zéro)
  
 A(), age = 0 B() A(), age = 0 C() D()

 MethodA(), age = 0
  

*/
int main()
{
    D d; std::cout << std::endl << std::endl;
    d.B::MethodA();
    
    d.MethodA(); // Ici ça génère une erreur à la compilation : l'appel est ambigu, car le compilateur ne sait pas quel chemin utiliser (A existe deux fois, via B et C).
    std::cout << std::endl;
    return 0;
}
