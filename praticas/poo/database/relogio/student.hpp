#pragma once
#include "fn.hpp"

class Relogio{
    private:
        int hora = 0;
        int minuto = 0;
        int segundo = 0;

    public:

        Relogio(){
            this->set_hr(0);
            this->set_min(0); 
            this->set_seg(0);
        }
        Relogio(int hora, int min, int seg){
            this->set_hr(hora);
            this->set_min(min);
            this->set_seg(seg);
        }

        int get_hr(){
            return this->hora;
        }

        int get_min(){
            return this->minuto;
        }

        int get_seg(){
            return this->segundo;
        }

        void set_hr(int hr){
            if(hr < 0 || hr > 23){
                std::cout << "fail: hora invalida\n";
                return;
            }
            this->hora = hr;
        }

        void set_min(int min){
            if(min < 0 || min >59){
                std::cout << "fail: minuto invalido\n";
                return;
            }
            this->minuto= min;
        }
        void set_seg(int min){
            if(min < 0 || min > 59){
                std::cout << "fail: segundo invalido\n";
                return;
            }
            this->segundo= min;
        }
        std::string str()
        {  
            return fn::format("{%0.2d}:{%0.2d}:{%0.2d}",get_hr(), get_min(), get_seg());

        }

        void Proximo_seg(){

            int atual_seg=segundo+1;

            if (atual_seg>59)
            {
                this->set_seg(0);
                int atual_min=minuto+1;

                if (atual_min>59)
                {
                    this->set_min(0);
                    int atual_hr=hora+1;
                    
                    if (atual_hr>23)
                        this->set_hr(0);
                    else 
                        this->set_hr(atual_hr);

                }     
            }
        }
};

class Student {
private:
    Relogio time;


public:
    void init(int hour = 0, int minute = 0, int second = 0) {
        this->time = Relogio(hour, minute, second);
    }

    void setHour(int hour) {
          this->time.set_hr(hour);
        // this->time.setHour(hour);
    }

    void setMinute(int minute) {
        this->time.set_min(minute);
        // this->time.setMinute(minute);
    }
    void setSecond(int second) {
        this->time.set_seg(second);
        // this->time.setSecond(second);
    }

    void nextSecond() {
       this->time.Proximo_seg();
    }
    
    void show() {
        std::cout << time.str() << std::endl;
        // fn::write(time);
    }
};