#include <iostream>
#include <string.h>
#include "fn.hpp"
using namespace std;

class Toalha
{
private:
    /* data */
    std::string color;
    std::string size;
    int humidade;
public:
    Toalha(string x, string y):
     color(x), size(y){
        humidade = 0;
    };
    void secar(int quantidade){
        
        if (humidade >= get_max_humidade())
        {
            fn::write("msg: toalha encharcada");
            return;
        }
        

        humidade += quantidade;
    }
    void torcer(){humidade = 0;}
    int get_max_humidade(){
        
        if (size == "P")
        {
            /* code */
            return 10;
        }else{
            if (size == "M")
            {
                /* code */
                return 20;
            }else{
                return 30;
            }
            
        }
        
        
        }
   
    bool esta_seco(){
        if (!humidade)
        {
            return true;
        }else{
            return false;
        }
        
    }

    std::string str(){
        string saida = "";
        saida += color + " " + size;
        return fn::format("{} {}",saida,humidade);

    }
    void show(){
        cout << str() << endl;
    }
};



int main() {
    Toalha towel("Azul", "M");
    std::cout << "qxcode\n";
    std::cout << "Testes:\n";

    towel = Toalha("Azul", "P");

    towel.show(); //  # Azul P 0
    towel.secar(5);
    towel.show(); // # Azul P 5

    cout << towel.esta_seco() << endl;// # False
    


    towel.secar(5);
    towel.show();  //# Azul P 10
    towel.secar(5);// # msg: toalha encharcada
    towel.show();//  # Azul P 10

    towel.torcer();
    towel.show();//  # Azul P 0

    towel = Toalha("Verde", "G");

    cout << towel.esta_seco() << endl;// # True

    towel.secar(30);
    towel.show(); //# Verde G 30

    cout << towel.esta_seco() << endl;// # False

    towel.secar(1);  //# msg: toalha encharcada

}

