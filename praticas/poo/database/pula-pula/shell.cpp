#include <iostream>
#include <memory>
#include <sstream>
#include <list>
#include "fn.hpp"
using namespace std;

class crianca
{
private:
    /* data */
    int idade;
    string nome;
public:
    
    crianca(int x,string y): idade(x), nome(y) {};
    int get_age(){return idade;}
    string get_name(){return nome;}
    void set_age(int x){idade = x;}
    void set_name(string x){nome = x;}

    string str() const{
        return fn::format("{}:{}",nome,idade);
    }

};

class pula_pula
{
private:
    vector<std::shared_ptr<crianca>> brincando;
    vector<std::shared_ptr<crianca>> fila;
public:
    //pula_pula();

    void chegar(std::shared_ptr<crianca> kid){
        fila.push_back(kid);
    }

    void entrar(){
        brincando.push_back(fila.front());
        fila.erase(fila.begin());
    }

    void sair(){
        if (brincando.empty())
        {
            /* code */
            return;
        }
        
        fila.push_back(brincando.front());
        brincando.erase(brincando.begin());
    }

    void remover(string nome){
        bool existe = false;
        for (auto it = fila.begin(); it != fila.end(); ) {
            if ((*it)->get_name() == nome) {
                // Remove o elemento atual
                it = fila.erase(it);
                existe = true;
            } else {
                // Avança para o próximo elemento
                ++it;
            }
        }

        for (auto it = brincando.begin(); it != brincando.end(); ) {
            if ((*it)->get_name() == nome) {
                // Remove o elemento atual
                it = brincando.erase(it);
                existe = true;
            } else {
                // Avança para o próximo elemento
                ++it;
            }
        }
        
        if (!existe)
        {
            string saida = fn::format("fail: {} nao esta no pula-pula",nome);
            cout << saida << endl;
        }
        
    }

    string str() const{

        string saida_fila = "";

        for (int i = static_cast<int>(fila.size()) - 1; i >= 0 ; i--)
        {
            saida_fila += fila[i]->str();

            if (i != 0)
            {
                saida_fila += ", ";
            }
            
            
        }

        string saida_playing = "";

        for (int i = static_cast<int>(brincando.size()) - 1; i >= 0 ; i--)
        {
            saida_playing += brincando[i]->str();

            if (i != 0)
            {
                saida_playing += ", ";
            }
            
            
        }

        return fn::format("[{}] => [{}]",saida_fila,saida_playing);
    }

};



int main() {
    pula_pula trampolim;

    while (true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if (cmd == "end") {
            break;
        } else if (cmd == "show") {
            cout << trampolim.str() << endl;
        } else if (cmd == "arrive") {
             string name;
             int age;
             ss >> name >> age;
            
             trampolim.chegar(std::make_shared<crianca>(age,name));
        } else if (cmd == "enter") {
            trampolim.entrar();
        } else if (cmd == "leave") {
            trampolim.sair();
        } else if (cmd == "remove") {
             string name;
             ss >> name;
             trampolim.remover(name);
        } else {
            cout << "fail: comando invalido" << endl;
        }
    }
}
