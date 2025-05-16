#include <iostream>
#include <vector>
#include <list>
#include <memory>
#include <sstream>
#include <utility>

#include "fn.hpp"
using namespace std;

class Person
{
private:
    string name;
public:
    Person(string x = "-----") : name(x) {};
    string get_name(){return name;};
    void set_name(string x){name = x;};

    string str() const{
        return fn::format("{}",name);
    };
};

std::ostream& operator<<(std::ostream& os, const Person& func){
    return os << func.str();
}

class Market
{
private:

    vector<shared_ptr<Person>> caixas;
    vector<Person> fila;
    
    int tam_caixas =0;


    int tam_filas =0;

    //bool validate(int id){};
public:

    Market(int x = 0){
        while (x)
        {
            auto aux = make_shared<Person>();
            caixas.push_back(aux);
            tam_caixas++;
            x--;
        }
        
    };

    void call(int x){
        
        if (!tam_filas)
        {
            cout << "fail: sem clientes\n";
            return;
        }
        

        if (caixas[x]->get_name() != "-----")
        {
            cout << "fail: caixa ocupado\n";
            return;
        }
        
        
        auto pessoa = fila[0].get_name();

        fila.erase(fila.begin() + x);
        
        caixas[x]->set_name(pessoa);
        tam_filas--;
    }

    void arrive(string nome_aux){
        fila.push_back(nome_aux);
        tam_filas++;
    }

    void finnish(int id){
        
        if (id >= tam_caixas)
        {
            cout << "fail: caixa inexistente\n";
            return;
        }

        if (caixas[id]->get_name() == "-----")
        {
            cout << "fail: caixa vazio\n";
            return;
        }

        caixas[id]->set_name("-----");
        
        
    }
    //bool cutInLine(Person x, string y){}
    //bool giveUp(string quitter){}

    void str() {
        //int x = tam;

            cout << "Caixas: [";
           for (auto i = 0; i < tam_caixas; i++)
           {
               cout << caixas[i]->str();

               if ( !((i+1) == tam_caixas) )
               {
                cout << ", ";
               }
               
           }    
           cout << "]\n";


            cout << "Espera: [";

            if (tam_filas)
            {
                for (auto i = 0; i < tam_filas; i++)
                {
                cout << fila[i].str();

                if ( !((i+1) == tam_filas))
                {
                    cout << ", ";
                }
                }
                /* code */
            }
            

            

            cout << "]\n";
        
    };

};


// Função auxiliar para mapear e juntar elementos de um container
template <typename CONTAINER, typename FUNC>
auto map_join(const CONTAINER& c, FUNC f, const string& sep = ", ") {
    stringstream ss;
    for (auto it = c.begin(); it != c.end(); ++it) {
        ss << (it != c.begin() ? sep : "") << f(*it);
    }
    return ss.str();
}

int main() {

    Market mercado;

    while (true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if (cmd == "end") {
            break;
        } else if (cmd == "show") {
            mercado.str();
        } else if (cmd == "init") { 
            int qtd_caixas;
            ss >> qtd_caixas;
            Market aux(qtd_caixas);

            mercado = aux;

        } else if (cmd == "arrive") { 
             string nome;
             ss >> nome;
             mercado.arrive(nome);
        } else if (cmd == "call") { 
             int indice;
             ss >> indice;
             mercado.call(indice);
        } else if (cmd == "finish") { 
             int indice;
             ss >> indice;
             mercado.finnish(indice);
        } else {
            cout << "fail: comando invalido\n";
        }
    }
}
