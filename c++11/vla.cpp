
#include <iostream>
    
    
// Support des VLA (Variable Length Arrays) avec les compilateurs
int main()
{
    {
        // Ne fonctionne pas en C++ "pur", mais fonctionne en C99
        // GCC l'accèpte, mais pas Clang (Apple)
        int n = 5; 
        int array[n] = { 1, 2, 3, 5 };
        std::cout << array[2];
    }
    
    {
        /* Solutions possible :
          - ajouter un const devant
          - si la tille du tableau n'est pas connu, utiliser new() ou un conteneur comme std::vector (allocation dynamique)
        */
        const int n = 5; 
        int array[n] = { 1, 2, 3, 5 };
        std::cout << array[2];
    }
}
