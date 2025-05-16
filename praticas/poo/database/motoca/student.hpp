#pragma once
#include <iostream>
#include <memory>
#include "fn.hpp"

class Pessoa{

    std::string nome;
    int idade;

  public:

    Pessoa(std::string nome, int idade): nome(nome), idade(idade) {
    }

    std::string str() const{
        return fn::format("{}:{}",this->nome,this->idade);
    }

    std::string get_name(){
        return this->nome;
    }

    int get_age(){
        return this->idade;
    }
};

std::ostream& operator<<(std::ostream& os, const Pessoa& pessoa){
    return os << pessoa.str();
} 

class Moto{

    int potencia = 1;
    int tempo = 0;

    std::shared_ptr<Pessoa> pessoa {nullptr};

  public:
    
    Moto(int potencia = 1): potencia(potencia){
    }
    
    void sobe_pessoa(std::shared_ptr<Pessoa> pessoa){
     if (this->pessoa != nullptr)
     {
        fn::write("fail: busy motorcycle");
        return;
     }
     this->pessoa = pessoa;
    }
    
    std::shared_ptr<Pessoa> desce_pessoa(){
        if(this->pessoa==nullptr){
            fn::write("fail: empty motorcycle");
            return nullptr;
        }
        auto backup = this->pessoa;
        this->pessoa = nullptr;
        return backup;
    }

    void add_tempo(int tempo){
        this->tempo += tempo;
    }

    void dirigir(int tempo){
        if(this->tempo == 0){
            fn::write("fail: buy time first");
            return;
        }
        if(this->pessoa == nullptr){
            fn::write("fail: empty motorcycle");
            return;
        }
        if(this->pessoa->get_age() > 10){
            fn::write("fail: too old to drive");
            return;
        }
        if(this->tempo < tempo){
            fn::print("fail: time finished after {} minutes\n", this->tempo);
            this->tempo = 0;
            return;
        }
        this->tempo -= tempo;
    }

    std::string buzina() const{
        auto Saida = "P"s;
        for (int i=0; i<(int)this->potencia; i++)
            Saida += "e";
        return Saida + "m";
    }

    std::string str() const{
        std::string nome("empty");
        if (this->pessoa != nullptr)
            nome = this->pessoa->str();
        return fn::format("power:{}, time:{}, person:({})",this->potencia,this->tempo, nome);
    }
    
};

std::ostream& operator<<(std::ostream& os, const Moto& moto){
    return os << moto.str();
}

class Student {

   Moto motoca;
public:

    void init(int power = 1) {
        //auto person = std::make_shared<Pessoa>(name, age);
        this->motoca = Moto(power);
        // motorcycle = Motorcycle(power);
    }

    void enter(std::string name, int age) {
      auto person = std::make_shared<Pessoa>(name, age);
        motoca.sobe_pessoa(person);
        // auto person = std::make_shared<Person>(name, age);
        // motorcycle.insertPerson(person);
    }

    void leave() {
        auto person = motoca.desce_pessoa();
        fn::write(person == nullptr ? "---" : person->str());
        // auto person = motorcycle.remove();
        // fn::write(person == nullptr ? "---" : person->str());
    }

    void honk() const {
         fn::write(motoca.buzina());
        // fn::write(motorcycle.honk());
    }

    void buy(int time) {
        motoca.add_tempo(time);
        // motorcycle.buyTime(time);
    }

    void drive(int time) {
         motoca.dirigir(time);
        // motorcycle.drive(time);
    }

    void show() const {
        fn::write(motoca);
        // fn::write(motorcycle.str());
    }
};