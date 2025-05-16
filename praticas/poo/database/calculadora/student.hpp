#pragma once
#include "fn.hpp"

class Calculator
{
    int bateria = 0;
    int bateria_max = 0;
    float display = 0;

    /* data */
public:

    Calculator(){
        this->bateria = 0;
        this->bateria_max = 0;
        this->display = 0;
    }
    
    Calculator(int limit) {
        this->bateria = 0;
        this->bateria_max = limit;
        this->display = 0;
    }
    
    void init(int limit)
    {
        this->bateria = 0;
        this->bateria_max = limit;
        this->display = 0;
    }
    

    
    void chargeBattery(int val){
        
        bateria += val;
        

        if (bateria > bateria_max)
        {
            bateria = bateria_max;
        }
    }

    void soma(int x, int y){
        if (bateria == 0)
        {

         std::cout << "fail: bateria insuficiente\n";
         return;   
        }
        bateria--;
        display = x + y;
    }

    void div(int x, int y){
        
        if (bateria == 0)
        {

         std::cout << "fail: bateria insuficiente\n";
         return;   
        }
        bateria--;
        if (y == 0)
        {

         std::cout << "fail: divisao por zero\n";
         return;   
        }

        
        display = float(x)/y;
    }

    std::string str()
    {
        
        return fn::format("display = {%0.2f}, battery = {}",display,bateria);
    }


};

class Student {
    Calculator c;
public:
    Student() {
        c = Calculator(0);
    }
    void show() {
        std::cout << std::setprecision(2) << c.str() << std::endl;
    }
    void init(int batteryMax) {
        c = Calculator(batteryMax);
        //(void) batteryMax;
    }
    void charge(int value) {
        
        c.chargeBattery(value);
        // // ACT!
        // // (void) value;
    }
    void sum(int a, int b) {
        c.soma(a, b);
        // // ACT!
        // // (void) a;
        // // (void) b;
    }
    void div(int num, int den) {
        c.div(num, den);
        // // ACT!
        // // (void) num;
        // // (void) den;
    }
};
