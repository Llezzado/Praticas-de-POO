#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "fn.hpp"

class grafite
{
private:
    /* data */
    
    double espessura;
    std::string duresa;
    int tamanho;

    

public:

    grafite(double x,std::string y, int z): espessura(x), duresa(y), tamanho(z){}

    int uso_por_escrita(int x){
        return x;
    };
    
    std::string str() const{
        return fn::format("[{}:{}:{}]",this->espessura,this->duresa,this->tamanho);
    };

    std::string get_hardness(){return duresa;};
    
    int get_tamanho(){return tamanho;};
    
    float get_espessura(){return espessura;};

    void set_tamanho(int x){
        tamanho = x;
    };
};

std::ostream& operator<<(std::ostream& os, const grafite& grafite){
    return os << grafite.str();
} 

class lapiseira
{
private:
 float espessura;
 std::shared_ptr<grafite> grafite_da_lapiseira {nullptr};
    /* data */
public:

    lapiseira(float x = 1): espessura(x){

    }

    bool tem_grafite(){
        if (grafite_da_lapiseira == nullptr)
        {
            return false;
        }
        return true;
    }

    void put_grafite(std::shared_ptr<grafite> grafite){
    
        if (this->grafite_da_lapiseira != nullptr)
     {
        fn::write("fail: ja existe grafite");
        return;
     }

        if (
            grafite->get_espessura() != espessura
        )
        {
            fn::write("fail: calibre incompativel");
            return;
            /* code */
        }
        


     this->grafite_da_lapiseira = grafite;
    };
    
    void remove(){
        if(this->grafite_da_lapiseira==nullptr){
            fn::write("fail: empty ");
            return;
        }
        grafite_da_lapiseira = nullptr;
    };
    
    void escreve(){

        if (this->grafite_da_lapiseira == nullptr)
        {
            fn::write("fail: nao existe grafite");
            return;
            /* code */

        }
        if (grafite_da_lapiseira->get_tamanho() <= 10 )
        {
            /* code */
            fn::write("fail: tamanho insuficiente");
            return;
        }
        


        /*caso cumpra os requisitos*/

        std::string duresa_atual = grafite_da_lapiseira->get_hardness();
        int diferenca;

        if (duresa_atual == "HB")
        {
            diferenca = 1;
        }else
        if (duresa_atual == "2B")
        {
            diferenca = 2;
            /* code */
        }else
        if (duresa_atual == "4B")
        {
            /* code */
            diferenca = 4;
        }else
        {
            diferenca = 6;
            /* code */
        }



        auto tamanho_atual = grafite_da_lapiseira->get_tamanho() - diferenca;

        if (tamanho_atual < 10)
        {
            fn::write("fail: folha incompleta");
            tamanho_atual = 10;
            
        }
        


        grafite_da_lapiseira->set_tamanho(tamanho_atual);


        return;
    };
    
    std::string str() const{
        return fn::format("calibre: {}, grafite: {}",this->espessura,this->grafite_da_lapiseira);
    }

    float get_thickness(){
        return espessura;
    };

};

class Student {
private:
    
    lapiseira pencil;
public:
    Student(double thickness = 1){

        pencil = lapiseira(thickness);
    };
    
    void insert(double thickness, std::string hardness, int length) {
        auto grafite_pencil = std::make_shared<grafite>(thickness,hardness,length);
        pencil.put_grafite(grafite_pencil);
    }

    void remove() {
        pencil.remove();
    }

    void writePage() {
        pencil.escreve();
    }

    void show() {
        fn::write(pencil.str());
    }
};
