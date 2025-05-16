#include "fn.hpp"
#include <string.h>
#include <iostream>

using namespace std;

class Adapter {
private:
    /* data */
    std::string color;
    std::string size;
    int humidade;
public:
    Adapter(string x = "", string y = ""):
     color(x), size(y){
        humidade = 0;
    };

    void criar(const std::string& cor, const std::string& tamanho) {
        color = cor;
        size = tamanho;
    }

    void enxugar(int quantidade) {
        humidade += quantidade;
        if (humidade >= get_max_humidade())
        {
            fn::write("toalha encharcada");
            humidade = get_max_humidade();
            return;
        }
        

    }
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
    

    
    void seca() {
        if (!humidade)
        {
            fn::write("sim");
        }else{
            fn::write("nao");
        }
    }

    void torcer() {
        humidade = 0;
    }
    std::string str() const{
        return fn::format("Cor: {}, Tamanho: {}, Umidade: {}",color,size,humidade);

    }
    void show(){
        cout << str() << endl;
    }
    void mostrar() const {
        fn::write(str());
    }
};

int main() {
    Adapter adapter;
    while (true) {
        fn::write("$", "");
        auto line = fn::input();
        auto args = fn::split(line, ' ');
        fn::write(line);

        if      (args[0] == "end"    ) { break;                           }
        else if (args[0] == "criar"  ) { adapter.criar(args[1], args[2]); }
        else if (args[0] == "enxugar") { adapter.enxugar(+args[1]);       }
        else if (args[0] == "seca"   ) { adapter.seca();                  }
        else if (args[0] == "torcer" ) { adapter.torcer();                }
        else if (args[0] == "mostrar") { adapter.mostrar();               }
        else                           { fn::write("comando invalido");   }
    }
}
