#include <iostream>
#include <memory>
#include <utility>
#include "fn.hpp"


class Bateria
{
private:
    int carga_max,carga_atual;
    bool tem_carga;
public:
    
    Bateria(int max = 50, int atual = 50){
        this->carga_max = max;
        this->carga_atual = atual;
        tem_carga = true;
    }

    void set_Bateria(int max){

        this->carga_max = max;
        this->carga_atual = max;
        this->tem_carga = true;
    } 

    void gastar(int x){
        carga_atual -= x;
        if (carga_atual <= 0)
        {
            carga_atual = 0;
            std::cout << "fail: descarregou\n";
            tem_carga = false;
        }
        
    }

    bool carga_chk(){
        return tem_carga;
    }

    void recarregar(int x){
        carga_atual += x;
        if (carga_atual > carga_max)
        {
            carga_atual = carga_max;
        }
                
    }

    std::string str() const{
        return fn::format("{}/{}",carga_atual,carga_max);
    }

};

class Carregador
{
private:
    int charger;
    bool esta_carregando;
public:

    Carregador(int x = 0,bool y = false){
        charger = x;
        esta_carregando = y;
    };

    void set_charger(int x){
        charger = x;

        if (charger)
        {
            esta_carregando = true;
        }
        
    }

    void rm_charger(){
        esta_carregando = false;
        charger = 0;
    }

    int get_charger(){
        return charger;
    }

    bool chk(){
        return esta_carregando;

    }

    std::string str() const{
        return fn::format(", Carregador {}W",this->charger);
    }
};



class Notebook
{
private:

    std::shared_ptr<Bateria> Pilha {nullptr};
    std::shared_ptr<Carregador> cabo {nullptr};
    bool esta_ligado,tem_bateria;
    int tempo;
public:
    
    Notebook(){
        esta_ligado = false;
        tem_bateria = false;
        tempo = 0;
    };


    void turn_off(){ esta_ligado = 0;}

    void turn_on(){

        if (
            (cabo == nullptr) &&
            (Pilha == nullptr)
        )
        {
            std::cout << "fail: não foi possível ligar\n";
            return;
        }
        
        
        
        esta_ligado = 1;
        }

    void use(int x){
        

        if (!esta_ligado)
        {
            std::cout << "fail: desligado\n";
            return;
        }

        if (
            (cabo == nullptr) &&
            (Pilha == nullptr)
        )
        {
            std::cout << "fail: sem energia\n";
            return;
        }

        tempo += x;

        if (Pilha != nullptr)
        {

            if (cabo == nullptr)
            {
               Pilha->gastar(x);

                if (!Pilha->carga_chk())
                {
                    esta_ligado = false;
                }
            }else{

                Pilha->recarregar(x * cabo->get_charger());
            }
            
            


            
        }
        



        if (cabo != nullptr)
        {
            return;
        }
        
       
    }

    void set_bateria(std::shared_ptr<Bateria> pilha){
        this->Pilha = pilha;
        tem_bateria = true;
    }

    std::shared_ptr<Bateria> rm_bateria(){
        
        if (Pilha == nullptr)
        {
            std::cout << "fail: Sem bateria\n";
            return nullptr;
        }
        
        std::string Pilha_str = Pilha->str();

        std::cout << "Removido " << Pilha_str << "\n";
    
        tem_bateria = false;

        if (cabo == nullptr)
        {

            esta_ligado = false;
        }
        

        auto old_pilha = Pilha;

        Pilha = nullptr;
        return old_pilha;

    }

    void set_charger(std::shared_ptr<Carregador> cabo){

        if (this->cabo != nullptr)
        {
            std::cout << "fail: carregador já conectado\n";
            return;
        }
        

        this->cabo = cabo;
    }

    std::shared_ptr<Carregador> rm_charger(){

        if (cabo == nullptr)
        {
            std::cout << "fail: Sem carregador\n";
            return nullptr;
        }
        
        std::cout << "Removido " << cabo->get_charger() << "W\n";
        

        cabo->rm_charger();
        esta_ligado = false;

        auto old_cabo = cabo;
        cabo = nullptr;
        return old_cabo;
        
    }

    std::string str() const{
        std::string status("desligado");
        std::string Carregador_str("");
        std::string bateria_str("");

        if (cabo != nullptr)
        {
            
            Carregador_str = cabo->str();
        }
        
        if (Pilha != nullptr)
        {
            bateria_str = ", Bateria ";
            bateria_str += Pilha->str();
        }
        
        
        if (esta_ligado)
        {
            return fn::format("Notebook: ligado por {} min{}{}", tempo,Carregador_str,bateria_str);
        }

        return fn::format("Notebook: {}{}{}", status,Carregador_str,bateria_str); 

        //

    }

};

std::ostream& operator<<(std::ostream& os, const Notebook& note){
    return os << note.str();
}

class Adapter {
    Notebook notebook;
public:
    void show() {
        fn::write(notebook);
        // std::cout << notebook.str() << '\n';
    }

    void turn_on() {
        notebook.turn_on();
    }

    void turn_off() {
        notebook.turn_off();
    }

    void set_charger(int power) {
        auto carregador_externo = std::make_shared<Carregador>(power);
        notebook.set_charger(carregador_externo);
    }
    void rm_charger() {
        auto old_charger = notebook.rm_charger();

        // auto charger = notebook.rmCharger();
        // if (charger != nullptr) {
        //     std::cout << "Removido " << charger->str() << '\n';
        // } else {
        //     std::cout << "fail: Sem carregador\n";
        // }
    }
    void set_battery(int capacity) {
        auto bateria_externa = std::make_shared<Bateria>(capacity,capacity);
        notebook.set_bateria(bateria_externa);
        //TODO: Implementar
    }

    void rm_battery() {
        auto old_bateria = notebook.rm_bateria();

        // auto battery = notebook.rmBattery();
        // if (battery != nullptr) {
        //     std::cout << "Removido " << battery->str() << '\n';
        // } else {
        //     std::cout << "fail: Sem bateria\n";
        // }
    }

    void use(int minutes) {

        notebook.use(minutes);
    }
};

int main() {

    Adapter adp;
    while (true) {
        auto line = fn::input();
        auto args = fn::split(line, ' ');
        fn::write("$" + line);

        if      (args[0] == "end")         { break;                                   }
        else if (args[0] == "show")        { adp.show();                              }
        else if (args[0] == "turn_on")     { adp.turn_on();                           }
        else if (args[0] == "turn_off")    { adp.turn_off();                          }
        else if (args[0] == "use")         { adp.use(+args[1]);                       }
        else if (args[0] == "set_charger") { adp.set_charger(+args[1]);               }
        else if (args[0] == "rm_charger")  { adp.rm_charger();                        }
        else if (args[0] == "set_battery") { adp.set_battery(+args[1]);               }
        else if (args[0] == "rm_battery")  { adp.rm_battery();                        }
        else                               { std::cout << "fail: comando inválido\n"; }
    }    
}
