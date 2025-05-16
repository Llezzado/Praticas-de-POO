#include <iostream>
#include <list>
#include <sstream>
#include <memory>

#include "fn.hpp"

using namespace std;


class grafite
{
private:
    /* data */
    
    float espessura;
    std::string duresa;
    int tamanho;

    

public:

    grafite(float x,std::string y, int z): espessura(x), duresa(y), tamanho(z){}

    int uso_por_escrita(int x){
        return x;
    };
    
    std::string str() const{
        return fn::format("[{}:{}:{}]",this->espessura,this->duresa,this->tamanho);
    };

    std::string get_hardness(){return duresa;};
    
    int get_tamanho(){return tamanho;};
    
    float get_espessura(){return espessura;};

    void set_tamanho(int x){
        tamanho = x;
    };
};

std::ostream& operator<<(std::ostream& os, const grafite& grafite){
    return os << grafite.str();
} 

class lapiseira
{
private:
 float espessura;
 shared_ptr<grafite> bico = nullptr; 
 vector<shared_ptr<grafite>> tambor;
    /* data */
public:

    lapiseira(float x = 1): espessura(x){

    }

    bool tem_grafite(){
        if (bico == nullptr)
        {
            return false;
        }
        return true;
    }

    void put_grafite(std::shared_ptr<grafite> grafite_new){
    

        if (
            grafite_new->get_espessura() != espessura
        )
        {
            fn::write("fail: calibre incompatível");
            return;
            /* code */
        }
        
        tambor.push_back(grafite_new);

        //  if (static_cast<int>(tambor.size()) == 1)
        //  {
        //        bico = std::make_shared<grafite>(tambor[0]);
        // }
        

    };
    
    void remove(){
        
        if(this->bico==nullptr){
            fn::write("fail: empty ");
            return;
        }
        

        bico = nullptr;
 
        //for ( int i = 0; i <= static_cast<int>(tambor.size()); i++){cout << tambor[i].str() << endl;}
        
    };
    
    bool pull(){
        if (tambor.empty())
        {
            return false;
        }

        if (bico != nullptr)
        {
            cout << "fail: ja existe grafite no bico" << endl;
            return false;
        }
        


        bico = std::make_shared<grafite>(*tambor.front());

        tambor.erase(tambor.begin());


        return true;


        
    }

    void escreve(){

        if (this->bico == nullptr)
        {
            fn::write("fail: nao existe grafite no bico");
            return;
            /* code */

        }
        if (bico->get_tamanho() <= 10 )
        {
            /* code */
            fn::write("fail: tamanho insuficiente");
            return;
        }
        


        /*caso cumpra os requisitos*/

        std::string duresa_atual = bico->get_hardness();
        int diferenca;

        if (duresa_atual == "HB")
        {
            diferenca = 1;
        }else
        if (duresa_atual == "2B")
        {
            diferenca = 2;
            /* code */
        }else
        if (duresa_atual == "4B")
        {
            /* code */
            diferenca = 4;
        }else
        {
            diferenca = 6;
            /* code */
        }



        auto tamanho_atual = bico->get_tamanho() - diferenca;

        if (tamanho_atual < 10)
        {
            fn::write("fail: folha incompleta");
            tamanho_atual = 10;
            
        }
        


        bico->set_tamanho(tamanho_atual);


        return;
    };
    
    std::string str() const{

        //for ( int i = 0; i < static_cast<int>(tambor.size()); i++){cout << tambor[i].str() << endl;}
        string tambor_str = "";


        //if (!tambor.empty())
        //{
            for (int i = 0; i < static_cast<int>(tambor.size()); i++)
            {
                tambor_str += tambor[i]->str();
                //cout << aux << endl;
            }
        //}
        
        
        string y = "[]";
        if (bico != nullptr)
        {
            y = bico->str();
        }
        
            

        return fn::format("calibre: {}, bico: {}, tambor: <{}>",this->espessura,y,tambor_str);
    }

    float get_thickness(){
        return espessura;
    };

};

// Função auxiliar para mapear e juntar elementos de um container
template <typename CONTAINER, typename FUNC>
auto map_join(const CONTAINER& c, FUNC f, const string& sep = ", ") {
    stringstream ss;
    for (auto it = c.begin(); it != c.end(); ++it) {
        ss << (it != c.begin() ? sep : "");
        ss << f(*it);
    }
    return ss.str();
}

int main() {

    lapiseira caneta;

    while (true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if (cmd == "end") {
            break;  
        }
        else if (cmd == "show") { fn::write(caneta.str());
        } 
        else if (cmd == "init") { 
             float calibre;
             ss >> calibre;

            caneta = lapiseira(calibre); 
        } 
        else if (cmd == "insert") { 
             float calibre;
             string dureza;
             int tamanho;
             ss >> calibre >> dureza >> tamanho;
             auto aux = std::make_shared<grafite>(calibre,dureza,tamanho);
             caneta.put_grafite(aux);

        } 
        else if (cmd == "remove") {
            caneta.remove();
        } 
        else if (cmd == "pull") {
            caneta.pull(); 
        } 
        else if (cmd == "write") {
            caneta.escreve();
        } 
        else {
            cout << "fail: comando invalido\n";
        }
    }
}
