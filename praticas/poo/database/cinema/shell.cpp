#include <iostream>
#include <vector>
#include <sstream>
#include <memory>
#include "fn.hpp"
using namespace std;
#define Error  999

template<class CONTAINER, class FUNC>
string map_join(const CONTAINER& c, FUNC f, string sep) {
    stringstream ss;
    for (auto it = c.begin(); it != c.end(); it++) {
        ss << (it == c.begin() ? "" : sep);
        ss << f(*it);
    }
    return ss.str();
}

class cliente
{
private:
    /* data */
    string id;
    int phone;
public:
    cliente(string idex,int num):id(idex),phone(num){};
    string get_id(){return id;}
    int get_phone(){return phone;}
    void set_id(string x){id = x;}
    void set_phone(int x){phone = x;}
    
    string str() const{
        return fn::format("{}:{}",id,phone);
    }
};


class sala
{
private:
    vector<shared_ptr<cliente>> poltronas;
    
    int pesquisa(string nome){
        for (auto i = 0; i < static_cast<int>(poltronas.size()); i++)
        {
            if (poltronas[i] == nullptr)
            {
                continue;
            }
            

            if (poltronas[i]->get_id() == nome)
            {
                return i;
            }
            
        }
        return Error; // se nao existe ngm com esse indice oq fazer? Throw?
    }

    bool verifica_id(int id){

        if (id >= static_cast<int>(poltronas.size()))
        {
            
            return false;
        }
        return true;
    }

public:
    sala(int x = 0){
        while (x)
        {
            poltronas.push_back(nullptr);
            x--;
        }
        
    };

    bool reserve(string id, int num, int idex){

        if (!verifica_id(idex))
        {
            fn::write("fail: cadeira nao existe");
            return false;
        }

        if (poltronas[idex] != nullptr)
        {
            fn::write("fail: cadeira ja esta ocupada");
            return false;
        }
        

        for (auto i = 0; i < static_cast<int>(poltronas.size()); i++)
        {
            if (poltronas[i] == nullptr)
            {
                continue;
            }
            

            if (poltronas[i]->get_id() == id)
            {
            fn::write("fail: cliente ja esta no cinema");
            return false;
            }
            
        }     
        

        poltronas[idex] = make_shared<cliente>(id,num);
        return true;
    }

    void cancelar(string id){
        if(pesquisa(id) != Error){
            
             poltronas[pesquisa(id)] = nullptr;
        }else{
            fn::write("fail: cliente nao esta no cinema");
        }
    }

    string str() const{
        
        string saida;

        for (auto i = 0; i < static_cast<int>(poltronas.size()); i++)
        {
            if (poltronas[i] == nullptr)
            {
                saida += "-";
            }else{
                saida += poltronas[i]->str();
            }

            if ((i+1) != static_cast<int>(poltronas.size()))
            {
                /* code */
                saida += " ";
            }
            
            
        }
        return fn::format("[{}]",saida);
    }
};


int main() {
    sala cinema;

    while (true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if (cmd == "end") {
            break;    
        } else if (cmd == "show") {
            cout << cinema.str() << endl;
        } else if (cmd == "init") {
            int qtd;
            ss >> qtd;
            auto aux = sala(qtd);
            cinema = aux;

        } else if (cmd == "reserve") {
             string id;
             int phone;
             int index;
             ss >> id >> phone >> index;
            if(!cinema.reserve(id,phone,index)){
                

            }

        } else if (cmd == "cancel") {
             string id;
             ss >> id;
             cinema.cancelar(id);

        } else {
            cout << "fail: comando invalido" << endl;
        }
    }
}
