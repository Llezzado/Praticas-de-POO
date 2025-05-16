#include "fn.hpp"

class Carro
{
    int tanque = 0;
    int passageiros = 0;
    int percorrido = 0; // 2 pessoas max, 100L max

    /* data */
public:

    void init()
    {
        this->tanque = 0;
        this->passageiros = 0;
        this->percorrido = 0;
    }
    
    void enter(){
        if (passageiros >= 2)
        {

         std::cout << "fail: limite de pessoas atingido\n";
         passageiros = 2;
         return;   
        }
        passageiros++;
    }

    void leave(){
        if (passageiros == 0)
        {

         std::cout << "fail: nao ha ninguem no carro\n";
         return;   
        }
        passageiros--;
    }

    std::string str()
    {
        return fn::format("pass: {}, gas: {}, km: {}",passageiros,tanque, percorrido);
    }

    void fuel(int qtd){

        if(
            (tanque + qtd) >= 100 
        ){
            tanque = 100;
        }else{
            tanque = tanque + qtd;
        }

        
    }

    void drive(int dist){
        if(passageiros == 0){
            std::cout << "fail: nao ha ninguem no carro\n";
            return;
        }
        if(tanque == 0){
            
            std::cout << "fail: tanque vazio\n";
            return;
        }

        int avanco = 0;
        while(dist){
            dist--;
            tanque--;
            percorrido++;
            avanco++;

            if(tanque == 0){
              std::cout <<  "fail: tanque vazio apos andar " << avanco << " km\n";
              return;
            }

        }


    }

};

struct Student {
    Carro car;
    Student() {}

    void enter() {
        car.enter();
    }
    void leave() {
        car.leave();
    }
    void fuel(int q) {
        car.fuel(q);
        //(void) q;
    }
    void drive(int q) {
        car.drive(q);
        //(void) q;
    }
    void show() {
        std::cout << car.str() << std::endl;
    }
};

struct Debug {
    // Se a variável debug for true, os testes não serão executados
    // Apenas o conteúdo do método run() será executado
    // Você pode usar isso para testar seu código manualmente
    static const bool debug = false;
    static void run() {
        std::cout << "Debug ativado" << std::endl;
    }
};
