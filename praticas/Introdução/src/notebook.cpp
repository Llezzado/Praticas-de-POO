//#include "fn.hpp"
#include <iostream>
#include <sstream>
#include <memory>

#define limite_carga 100

class bateria
{
private:
    int carga,capacidade;
    /* data */
public:

    bateria(int lim){
        capacidade = lim;
        carga = 0;
    }

    void carrega(int x){
        this->carga += x;
    }

    void descarrega(int x){
        this->carga -= x;
        if (this->carga < 0)
        {
            this->carga = 0;
        }
        
    }

    bool chk_carga(){
        if (carga == 0)
        {
            return false;
        }
        return true;
    }

    int get_carga(){
        return carga;
    }

};


class notebook
{
private:
    /* data */
    bool energia;
    std::shared_ptr<bateria> Bateria;
public:
    notebook(){
        energia = false;
        Bateria = nullptr;
        //Bateria.carrega(limite_carga);// = 100;
    };
    //~notebook();
    void put_bateria(std::shared_ptr<bateria> bat){
        this->Bateria = bat;
    }
    void liga(){

        if (energia)
        {
            /* code */
            std::cout << "ja esta ligado.\n";
            return;
        }
        

        this->energia = true;
    }
    
    void desliga(){

        if (~energia)
        {
            std::cout << "ja esta desligado.\n";
            return;
                /* code */
        }
        

        this->energia = false;
    }

    void str()
    {
        std::cout << "status: " << energia << " bateria: " << Bateria.get_carga() << std::endl;

        
    }

    void usar(int tempo){
        

        if (~ (this->energia))
        {
            std::cout << "O notebook esta desligado\n";
            return;
        }
        
        for (int i = 0; i < tempo; i++)
        {
            Bateria.descarrega(1);
            
            if (~Bateria.chk_carga())
            {
                std::cout << "descarregou apos tempo " << i << std::endl; 
                return;
            }
            
        }
        

    }

    void recarregar(){

    }
};


int main()
{
    /* code */

    notebook positivo;
    std::shared_ptr<bateria> pilha = new bateria(limite_carga);

    positivo.str();

    positivo.usar(45);

    positivo.desliga();

    positivo.liga();
    positivo.liga();
    
    positivo.str();

    positivo.usar(75);

    positivo.usar(30);
    
    delete pilha;

    return 0;
}
