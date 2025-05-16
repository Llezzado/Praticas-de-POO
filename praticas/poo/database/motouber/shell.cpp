#include <iostream>
#include "fn.hpp"

#include <memory>
class Pessoa{

    std::string nome;
    int dinheiro;

  public:

    Pessoa(std::string nome, int dinheiro): nome(nome), dinheiro(dinheiro) {
    }

    std::string str() const{
        return fn::format("{}:{}",this->nome,this->dinheiro);
    }

    std::string get_name(){
        return this->nome;
    }

    int get_money(){
        return this->dinheiro;
    }

    void set_money(int money){
        dinheiro = money;
    }
};

std::ostream& operator<<(std::ostream& os, const Pessoa& pessoa){
    return os << pessoa.str();
} 

class Moto{

    int custo = 0;

    std::shared_ptr<Pessoa> piloto {nullptr};
    std::shared_ptr<Pessoa> passageiro {nullptr};

  public:
    
    void sobe_piloto(std::shared_ptr<Pessoa> pessoa){
     if (this->piloto != nullptr)
     {
        fn::write("fail: busy motorcycle");
        return;
     }
     this->piloto = pessoa;
    }

    void sobe_passageiro(std::shared_ptr<Pessoa> pessoa){
     if (this->passageiro != nullptr)
     {
        fn::write("fail: busy motorcycle");
        return;
     }
     if (
        this->piloto == nullptr
     )
     {
        fn::write("fail: empty motorcycle");
        return;
     }
     
     this->passageiro = pessoa;
    }
    
    std::shared_ptr<Pessoa> desce_passageiro(){
        if(this->passageiro==nullptr){
            fn::write("fail: empty motorcycle");
            return nullptr;
        }
        
        auto backup = this->passageiro;
        
        
        while (
            (passageiro->get_money() > 0) &&
            custo > 0

        )
        {
            /* code */
            custo--;
            passageiro->set_money(passageiro->get_money() -1);
            piloto->set_money(piloto->get_money() +1);
            

        }
        


        if (custo > 0)
        {
            fn::write("fail: Passenger does not have enough money");
            //dinheiro induficiente
            piloto->set_money(piloto->get_money() + custo);
            custo = 0;          
        }

        std::string cliente;
        cliente = this->passageiro->str();
        fn::write(cliente, " leave\n");

        this->passageiro = nullptr;


        return backup;
    }

    void add_custo(int custo){
        this->custo += custo;
    }

    void dirigir(int custo){
        if(this->piloto == nullptr){
            fn::write("fail: empty motorcycle");
            return;
        }

        if(this->passageiro == nullptr){
            fn::write("fail: empty motorcycle pass");
            return;
        }

        this->custo += custo;
    }

    std::string str() const{
        std::string nome("None");
        std::string cliente("None");
        if (this->piloto != nullptr)
            nome = this->piloto->str();

        if (this->passageiro != nullptr)
            cliente = this->passageiro->str();
        return fn::format("Cost: {}, Driver: {}, Passenger: {}",this->custo, nome,cliente);
    }
    
};

std::ostream& operator<<(std::ostream& os, const Moto& moto){
    return os << moto.str();
}


class Adapter {
    Moto motocicleta;

public:
    void setDriver(std::string name, int money) {
        auto person = std::make_shared<Pessoa>(name, money);
        motocicleta.sobe_piloto(person);
    }
    void setPass(std::string name, int money) {
        auto person = std::make_shared<Pessoa>(name, money);
        motocicleta.sobe_passageiro(person);
    }
    void drive(int distance) {
        motocicleta.dirigir(distance);
    }
    void leavePass() {
        motocicleta.desce_passageiro();
    }
    void show() {
        fn::write(motocicleta);
    }
};

int main() {
    Adapter adp;
    while (true) {
        fn::write("$", "");
        auto line = fn::input();
        auto args = fn::split(line, ' ');
        fn::write(line);

        if      (args[0] == "end")       { break;                                  }
        else if (args[0] == "setDriver") { adp.setDriver(args[1], +args[2]);       }
        else if (args[0] == "setPass")   { adp.setPass(args[1], +args[2]);         }
        else if (args[0] == "drive")     { adp.drive(+args[1]);                    }
        else if (args[0] == "leavePass") { adp.leavePass();                        }
        else if (args[0] == "show")      { adp.show();                             }
        else                             { fn::write("fail: command not found\n"); }
    }
}