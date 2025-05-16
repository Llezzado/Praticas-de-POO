/******************************************************************************

Atividade feita dia 22/11/2024

*******************************************************************************/

#include <iostream>

#define true 1

class Havaianas{
    
    private:
    int tam = 0;
    
    public:
    
    int get_tam(){
        return tam;    
    }
    
    bool set_tam(int tamanho){
    
        if(
            (tamanho >= 20) &&
            (tamanho <= 50) &&
            (tamanho%2 == 0)
        ){
            tam = tamanho;  
            return true;        
        }
        
        
        std::cout << "tamanho inválido \n";
        return false;
        
    }
};


int main()
{
    
    Havaianas chinelo;
    int aux;
    
    while(true){
    
        std::cout<<"Informe seu tamanho: \n";
        std::cin >> aux;
    
        if (chinelo.set_tam(aux))
        {
           std::cout<< "O tamanho de seu pé é: " << chinelo.get_tam() << "\n";
           break;
        }
        
    }

    return 0;
}