
#pragma once

#include <iostream>
#include <random>



class Array
{
public:
    Array(int size = 1) {
        m_size = size;
        create();
        std::cout << "created Array of size: " << m_size << std::endl;
        
         for (int i = 0; i < m_size; i++) {
            m_data[i] = fill();
        }
    }
    ~Array()
    {
        destroy();
            
        std::cout << "Array destroyed" << std::endl;
    }
    
    Array &operator=(const Array &r) {
        
        destroy();
        
        m_size = r.m_size;
        create();
        
        for (int i = 0; i < m_size; i++) {
            m_data[i] = r.m_data[i];
        }
        
        return *this;
    }
    
    void show() const {
        for (int i = 0; i < m_size; i++) {
            std::cout << m_data[i] << ", ";
        }
        std::cout << std::endl;
    }
    
private:
    int *m_data;
    int m_size;
    
    void create() {
        if (m_size > 0) {
            m_data = new int[m_size];
        } else {
            m_data = nullptr;
        }
    }
    
    void destroy() {
        if (m_data != nullptr) {
            delete[] m_data;
        }
    }
    
    int fill() {
        // Créez un générateur de nombres aléatoires en utilisant la fonction std::random_device comme source d'entropie.
        std::random_device rd;
        std::mt19937 gen(rd());
        
        // Créez une distribution uniforme entre 0 et 20.
        std::uniform_int_distribution<int> dis(0, 20);
        
        // Générez et renvoyez un nombre aléatoire.
        return dis(gen);
    }
};
