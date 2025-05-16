#include <iostream>
#include <string>

#include <memory>

class pet
{
private:
    /* data */
    int energia_max;
    int energia;

    int fome;
    int fome_max;

    int clean_max;
    int clean;
    

    int idade = 0;
    int diamantes = 0;
    bool vivo = true;
    
public:
    
    pet(int energia, int fome, int clean):
     energia(energia), fome(fome), clean(clean) {
        //sdfs
        energia_max = energia;
        clean_max = clean;
        fome_max = fome;
    };

    bool esta_vivo(){return vivo;}

    void set_energia(int x){
        energia = x;
        if (energia > energia_max)
        {
            energia = energia_max;
        }

        if (energia <= 0){
            energia = 0;
            vivo = false;
            fn::write("fail: pet morreu de fraqueza"); 
        };
        
        
    };

    void set_clean(int x){
        clean = x;
        if (clean > clean_max)
        {
            clean = clean_max;
        }
        if (clean <= 0){
            clean = 0;
            vivo = false;
            fn::write("fail: pet morreu de sujeira"); 
        };
    };

    void set_fome(int x){
        fome = x;
        if (fome > fome_max)
        {
            fome = fome_max;
        }
        
        if (fome <= 0){
            fome = 0;
            vivo = false;
            fn::write("fail: pet morreu de fome"); 
        };
    };

    void set_idade(int x){
        idade = x;
    };

    void set_diamantes(int x){
        diamantes = x;
    };

    int get_clean(){return clean;};
    int get_clean_max(){return clean_max;};

    int get_energia(){return energia;};
    int get_energia_max(){return energia_max;};
    
    int get_idade(){return idade;};
    
    int get_diamantes(){return diamantes;};
    
    int get_fome(){return fome;};

    std::string str() const{
        return fn::format("E:{}/{}, S:{}/{}, L:{}/{}, D:{}, I:{}",this->energia,this->energia_max,this->fome,this->fome_max,this->clean,this->clean_max,this->diamantes,this->idade);
    }

};

class game
{
private:
    /* data */
    std::shared_ptr<pet> bicho = nullptr;
    int tempo = 0;
public:

    game(std::shared_ptr<pet> x){
        this->bicho = x;
    } 

    void play(){

        if (!bicho->esta_vivo())
        {
            fn::write("fail: pet esta morto"); 
            return;
        }
        

        bicho->set_energia(
            bicho->get_energia() - 2
        );

        bicho->set_fome(
            bicho->get_fome() - 1
        );

        bicho->set_clean(
            bicho->get_clean() - 3
        );
        
        bicho->set_diamantes(
            bicho->get_diamantes() + 1
        );

        bicho->set_idade(
            bicho->get_idade() + 1
        );

        tempo += 2;

    }

    void eat(){
        
        if (!bicho->esta_vivo())
        {
            fn::write("fail: pet esta morto"); 
            return;
        }

        bicho->set_energia(
            bicho->get_energia() - 1
        );

        bicho->set_fome(
            bicho->get_fome() + 4
        );

        bicho->set_clean(
            bicho->get_clean() - 2
        );
        
        bicho->set_idade(
            bicho->get_idade() + 1
        );
        tempo ++;
    }

    void shower(){

        if (!bicho->esta_vivo())
        {
            fn::write("fail: pet esta morto"); 
            return;
        }

        bicho->set_energia(
            bicho->get_energia() - 3
        );

        bicho->set_fome(
            bicho->get_fome() - 1
        );

        bicho->set_clean(
            bicho->get_clean_max()
        );
        
        bicho->set_idade(
            bicho->get_idade() + 2
        );

        tempo += 3;
    }
    void sleep(){

        if (!bicho->esta_vivo())
        {
            fn::write("fail: pet esta morto"); 
            return;
        }

        if (tempo < 5)
        {
            fn::write("fail: nao esta com sono"); 
            return;
        }

        bicho->set_energia(bicho->get_energia_max());

        while (tempo)
        {
            
            bicho->set_idade(bicho->get_idade() + 1);

            tempo--;
        }
        
        bicho->set_fome( bicho->get_fome() - 1 );

        
    }

    std::string str() const{

        std::string pet_str = this->bicho->str();

        return fn::format("{}",pet_str);
    }

};

std::ostream& operator<<(std::ostream& os, const game& jogo){
    return os << jogo.str();
}


class Student {
private:
    game pedrito;
public:

    Student(int energy, int hungry, int clean) : pedrito(std::make_shared<pet>(energy,hungry, clean)){

    }

    void show() {
        std::cout << this->pedrito.str() << std::endl;
    }

    void play() {
        pedrito.play();
    }

    void shower() {
        pedrito.shower();
    }

    void eat() {
        pedrito.eat();
    }

    void sleep() {
        pedrito.sleep();
    }
};
