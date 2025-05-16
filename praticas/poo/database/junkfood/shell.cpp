#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

#include "fn.hpp"

using namespace std;

template<typename CONTAINER, typename FUNC>
string map_join(const CONTAINER& cont, FUNC func, string delim) {
    stringstream ss;
    for (auto it = cont.begin(); it != cont.end(); it++) {
        ss << (it == cont.begin() ? "" : delim);
        ss << func(*it);
    }
    return ss.str();
}

class Slot
{
private:
    string nome;
    int quantidade;
    float valor;
public:
    Slot(string x = "  empty",int y = 0, float z = 0.0) : nome(x),quantidade(y),valor(z) {};
    
    string get_nome(){return nome;};
    int get_quantidade(){return quantidade;};
    float get_valor(){return valor;};

    void set_nome(string x){nome = x;};
    void set_quantidade(int x){quantidade = x;};
    void set_valor(float x){valor  = x;};

    string str() const{
        return fn::format("[ {} : {} U : {%0.2f} RS]",nome,quantidade,valor);
    }

};


class Machine
{
private:
    vector<Slot> fila;
    float lucro,dinheiro;
    int capacidade;

public:
    Machine(int x = 1) : capacidade(x) {
        while (x)
        {
            fila.push_back(Slot());
            x--;
        }
        lucro = 0;
        dinheiro = 0;

    };

    Slot getSlot(int idex){return fila[idex];};

    void setSlot (int id,string name,int  qtd,float  price){

        if (id > capacidade)
        {
            cout << "fail: indice nao existe" << endl;
            return;
        }
        

        fila[id] = Slot(name,qtd,price);
    }
    
    void clear_slot(int id){
        fila[id] = Slot();
    };

    void depositar(int val){dinheiro += val;};
    
    float sacar(int val){
        if (val > dinheiro)
        {
            cout << "fail";
            dinheiro = 0;
            return val;
        }

        dinheiro -= val;
        return val;
        
    };

    float trocado(){
        float x = dinheiro;
        dinheiro = 0;
        cout << "voce recebeu " << x << " RS\n";
        return x;
    }

    float get_dinheiro(){return dinheiro;};
    float get_lucro(){return lucro;};

    void comprar(int id){

        if (id > capacidade)
        {
            cout << "fail: indice nao existe" << endl;
            return;
        }
        

        if (fila[id].get_valor() > dinheiro)
        {
            cout << "fail: saldo insuficiente" << endl;
            return;
        }

        if (fila[id].get_quantidade() == 0)
        {
            cout << "fail: espiral sem produtos" << endl;
            return;
        }
        


        dinheiro -= fila[id].get_valor();

        cout << "voce comprou um " << fila[id].get_nome() << endl;
        fila[id].set_quantidade( fila[id].get_quantidade() - 1 );
        
    }

    void str() {

        cout << "saldo: "<< fixed << setprecision(2) << dinheiro << endl;

        for (int i = 0; i < capacidade; i++)
        {
            cout << i << " ";
            fn::write(fila[i].str(),"\n");
        }

    }   

};



int main() {
    Machine Caixa;

    while (true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        try {
            if (cmd == "show") {
                // IMPRIMIR
                Caixa.str();
            } else if (cmd == "init") {
                int n_espirais {};
                ss >> n_espirais;
                Machine x(n_espirais);
                Caixa = x;
            } else if (cmd == "limpar") {
                 int indice {};
                 ss >> indice;
                 Caixa.clear_slot(indice);

            } else if (cmd == "dinheiro") {
                 int value {};
                 ss >> value;
                 Caixa.depositar(value);
            } else if (cmd == "comprar") {
                 int index {};
                 ss >> index;
                 Caixa.comprar(index);
            } else if (cmd == "set") {
                 int index {};
                 string name;
                 int qtd {};
                 double price {};
                 ss >> index >> name >> qtd >> price;

                 Caixa.setSlot(index,name,qtd,price);

            } else if (cmd == "troco") {
                Caixa.trocado();

            } else if (cmd == "end") {
                break;
            } else {
                cout << "comando invalido" << endl;
            }
        } catch (const char* e) {
            cout << e << endl;
        }
    }
}
