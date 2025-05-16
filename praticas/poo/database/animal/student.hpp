#pragma once
#include "fn.hpp"

class Animal
{
    int idade = 0;
    std::string especie;
    std::string barulho;

    /* data */
public:

    Animal(std::string especie = "", std::string barulho = "")
    {

        this->idade = 0;
        this->especie = especie;
        this->barulho = barulho;
    }

    std::string str()
    {
        return fn::format("{}:{}:{}", especie, idade, barulho);
    }

    void crescer(int etapas){
        this->idade += etapas;
        if(idade >= 4){
            std::cout << "warning: " << especie << " morreu\n";
            idade  = 4;
        }
        
    }

    std::string faz_barulho(){
        if(idade == 0){
            return "---";
        }
        else if(idade >= 4){
            return "RIP";
        }else{
            return barulho;
        }
    }
};

struct Student {
    
    Animal animal;
    Student(std::string especie = "", std::string barulho = ""){        

        
        //bicho(especie,barulho);
        //ACT
        // (void) especie;
        // (void) barulho;
        animal = Animal(especie, barulho);
    }

    void grow(int nivel) {
        animal.crescer(nivel);
        //(void) nivel;

        // animal.envelhecer(nivel);
    }

    void noise() {
        
         std::cout << animal.faz_barulho() << std::endl;
    }

    void show() {
        
        std::cout << animal.str() << std::endl;
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