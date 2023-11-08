#include <iostream>
#include <string>

class Gate
{

public:
    Gate(int inputs) {
        m_inputs = new bool[inputs];
        m_intputs_size = inputs;
        
        for (int i = 0; i < m_intputs_size; i++) {
            
            m_inputs[i] = false;;
        }
    }
    virtual ~Gate() {
        delete m_inputs;
    }
    
    bool getInput(int index) { 
        bool state{false};
        
        if (index < m_intputs_size) {
            state = m_inputs[index];
        }
        
        return state;
    }
    int inputs() { return m_intputs_size; };
    
    void setInput(int index, bool state) { 
       if (index < m_intputs_size) {
            m_inputs[index] = state;
        }
        
    }
    virtual bool output() = 0;
    
    
    void display() {
        std::cout << "Sortie: " << output() << std::endl;
    }
    
    
private:
    int m_intputs_size{0};
    bool *m_inputs{nullptr};
    
};


class And : public Gate
{
public:
    And(int inputs)
        : Gate(inputs)
    {

    }

    bool output() {
        bool state = true;
        for (int i = 0; i < inputs(); i++) {
            
            state &= getInput(i);
        }
        return state;
    }

private:

};


int main()
{
    And and1(2);
    
    and1.setInput(0, true);
    and1.setInput(1, true);
    
    and1.display();
    

    return 0;
}

