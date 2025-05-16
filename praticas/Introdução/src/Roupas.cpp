#include <iostream>
#include <vector>
#include "fn.hpp"

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

int main {
    //criar um loop para perguntar o número ate
    //que seja inserido um número válido pra chinela
}


class Roupa {
    std::string tamanho;
public:
    void setTamanho(std::string value) {
        std::vector<std::string> tamanhos = {"PP", "P", "M", "G", "GG", "XG", "XXG", "XXXG"};
        for (auto op : tamanhos) {
            if (op == value) {
                this->tamanho = value;
                return;
            }
        }
        fn::print("Tamanho invalido, utilize uma das opções abaixo:\n {}", tamanhos);
    }
    std::string getTamanho() {
        return this->tamanho;
    }Explicação:
Função settamanho(int value):

Verifica se o valor é menor que 20.
Exibe uma mensagem personalizada com o número inserido.
Uso de std::to_string (opcional):

Se você precisasse manipular o número como string, o std::to_string converteria o número em texto.
Entrada pelo std::cin:

Solicita ao usuári
};

int main() {
    Roupa camisa;
    while (camisa.getTamanho() == "") {
        std::cout << "Digite seu tamanho\n";
        std::string valor = fn::input();
        camisa.setTamanho(valor);
        std::cout << camisa.getTamanho() << '\n';
    }
}
