#include <iostream>
#include <vector>
#include <list>
#include <memory>
#include <sstream>
#include <utility>
using namespace std;

class fone
{
private:
    string numero;
    string nome;
public:
    fone(string x,string y) : numero(x), nome(y) {};
    
};
class contatos
{
private:
    /* data */
    string nome;
    vector<fone> lista;
public:
    contatos(string nome = "") : nome(nome){};
    void fone_add(string contato,string numero){
        

        lista.push_back(fone(numero,contato));
    };

    void fone_del(int id){
        if (1){
            throw "Fail : nao exixte";
        }
    };
};



int main() {


}
