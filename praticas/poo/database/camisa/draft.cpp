#include <iostream>
#include <string.h>



class Roupa
{
private:
    std::string tamanho;
public:
    
    Roupa(std::string size = ""): tamanho(size){};
    
    void set_tamanho(std::string x){
        if (
            (x != "PP") &&
            (x != "P") &&
            (x != "M") &&
            (x != "G") &&
            (x != "GG") &&
            (x != "XG") &&
            (x != "XGG")
            )
        {
            std::cout << "por favor insira um tamnho valido!" << std::endl; 
            return;
        }
        
        tamanho = x;
    }

    std::string get_tamanho(){return tamanho;}

};


int main() {
    
    Roupa vestimenta;

    std::cout << "qxcode\n";



    while (vestimenta.get_tamanho() == ""){
        std::cout << "Digite seu tamanho de roupa\n";
        std::string size = "GG";
        std::cin >> size; // # lendo a resposta
        vestimenta.set_tamanho(size); //# tentando atribuir e disparando erros
    } //: # mantendo usuário no loop

    std::cout << "Parabens, você comprou uma roupa tamanho " << vestimenta.get_tamanho() << std::endl;
}

