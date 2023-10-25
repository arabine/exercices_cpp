 
#include <iostream>
 
struct A {
    A(int a = 0) : age(a) { std::cout << " A(), age = " << age; }
    void MethodA() { std::cout << " MethodA(), age = " << age; }
    
private:
    int age{42};
};

// Two classes virtually inheriting Animal:
struct B: virtual A {
    B() { std::cout << " B()"; }
};

struct C: virtual A {
    C() { std::cout << " C()"; }

};

// A bat is still a winged mammal
struct D: public B, public C 
{
    D() : A(23) { std::cout << " D()"; }
};

/*

Maintenant on a bien cela, A est créé de manière unique par D :

  A  
 / \  
B   C  
 \ /  
  D 


La sortie donne bien un seul appel, on peut même appeler directement le construteur de A à partir de D.
EN effet, l'héritage virtuel par B et C ont délégué l'instanciation à D. Cela signifie, en gros : nous on s'en occupe pas !
  
 A(), age = 23 B() C() D()

 MethodA(), age = 23


Hériter de A a plusieurs avantages quand même (méthode virtuelles et stockage dans un conteneur d'éléments hétérogènes).

*/
int main()
{
    D d; std::cout << std::endl << std::endl;
    d.B::MethodA();
    std::cout << std::endl;
    return 0;
}
