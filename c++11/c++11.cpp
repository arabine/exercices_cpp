
#include <iostream>
    
class UserCtor {
    public:
    UserCtor(){}
    int i;
    int j;
};
    
class DefaultCtor {
    public:
    DefaultCtor() = default; // uniquement depuis C++0x11, génère un constructeur par défaut qui initialise 
                    // toutes les variables membres.
    int i;
    int j;
};

int main()
{   
    for( int i = 0; i < 10; ++i) {
        UserCtor* pa = new UserCtor();
        DefaultCtor* pb = new DefaultCtor();
        std::cout << "UserCtor: " << pa->i << "," << pa->j << std::endl;
        std::cout << "DefaultCtor: " << pb->i << "," << pb->j << std::endl;
        delete pa;
        delete pb;
    }
    return 0;
}
 
 
