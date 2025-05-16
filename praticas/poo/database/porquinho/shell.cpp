#include <iostream>
#include <vector>
#include <sstream>
#include <utility>
#include <iomanip>
#include <memory>
using namespace std;

#include "fn.hpp"



class Moeda
{
private:
    double valor;
    int volume;
    string label;
    /* data */
    
public:
    Moeda(double val, int vol, string tag): valor(val),volume(vol),label(tag) {};
    double get_valor(){return valor;}
    int get_volume(){return volume;}
    string get_label(){return label;}

    string str() const{
        return fn::format("{%.2f}:{}",valor,volume);
    }

    // Membros estáticos
    static Moeda C10;
    static Moeda C25;
    static Moeda C50;
    static Moeda C100;
    
};

Moeda Moeda::C10(0.10, 1, "C10");
Moeda Moeda::C25(0.25, 2, "C25");
Moeda Moeda::C50(0.50, 3, "C50");
Moeda Moeda::C100(1.0, 4, "C100");

class Item
{
private:
    /* data */
    string label;
    int volume;
public:
    Item(string tag, int vol): label(tag), volume(vol){};
    
    void set_volume(int vol){volume = vol;}
    int get_volume(){return volume;}

    void set_label(string tag){label = tag;}
    string get_label(){return label;}

    string str() const{
        return fn::format("{}:{}",label,volume);
    }
};

class pig
{
private:
    /* data */
    bool quebrado;
    vector<std::shared_ptr<Moeda>> reais;
    vector<std::shared_ptr<Item>> itens;
    int volume_max;
public:
    pig(int vol_max = 0): volume_max(vol_max){
        quebrado = false;
    };
    bool add_moeda(shared_ptr<Moeda> coin) {
        if (quebrado)
        {
            fn::write("fail: the pig is broken");
            return false;
        }
        if (
            (coin->get_volume() + get_volume()) > get_volume_max()
        )
        {

            fn::write("fail: the pig is full");
            return false;
        }
        
        

        reais.push_back(coin);
        return true;
    }

    bool add_item(shared_ptr<Item> obj) {
        if (quebrado)
        {
            fn::write("fail: the pig is broken");
            return false;
        }
        if (
            (obj->get_volume() + get_volume()) > get_volume_max()
        )
        {

            fn::write("fail: the pig is full");
            return false;
        }
        

        itens.push_back(obj);
        return true;
    }

    bool quebar(){
        if (quebrado)
        {

            return false;
        }else{
            quebrado = true;
            return true;
        }
        
    }

    vector<std::shared_ptr<Moeda>> extrair_moedas(){
        vector<std::shared_ptr<Moeda>> out;
        string out_extract = "";
        if (!quebrado)
        {
            fn::write("fail: you must break the pig first");
        }else{
            out = move(reais);
            reais.clear();

            for (auto i = 0; i < static_cast<int>(out.size()); i++)
            {
                out_extract += out[i]->str();
                if ((i+1) != static_cast<int>(out.size())){out_extract += ", ";}
            }  

        }
        fn::write(fn::format("[{}]",out_extract));
        return out;
    }

    vector<std::shared_ptr<Item>> extrair_itens(){
        vector<std::shared_ptr<Item>> out;
        string out_extract = "";
        if (!quebrado)
        {
            fn::write("fail: you must break the pig first");
        }else{
            out = move(itens);
            itens.clear();

            for (auto i = 0; i < static_cast<int>(out.size()); i++)
            {
                out_extract += out[i]->str();
                if ((i+1) != static_cast<int>(out.size())){out_extract += ", ";}
            }  
        }
        
        fn::write(fn::format("[{}]",out_extract));
        //out = itens;
        return out;
    }

    string str() const{
        
        // state
        string status = "intact";
        if (quebrado){status = "broken";}
        
        //coins
        string out_coins = "";
        for (auto i = 0; i < static_cast<int>(reais.size()); i++)
        {
            out_coins += reais[i]->str();
            if ((i+1) != static_cast<int>(reais.size())){out_coins += ", ";}
            
        }

        //itens
        string out_itens = "";
        for (auto i = 0; i < static_cast<int>(itens.size()); i++)
        {
            out_itens += itens[i]->str();
            if ((i+1) != static_cast<int>(itens.size())){out_itens += ", ";}
        }       
        
        //value
        double out_value = 0;

        for (auto i = 0; i < static_cast<int>(reais.size()); i++)
        {
            out_value += reais[i]->get_valor();
            
        }

        

        //volume
        int out_volume = 0;

        if (!quebrado)
        {
            for (auto i = 0; i < static_cast<int>(reais.size()); i++)
            {
                out_volume += reais[i]->get_volume();
                
            }

            for (auto i = 0; i < static_cast<int>(itens.size()); i++)
            {
                out_volume += itens[i]->get_volume();
                
            }
        }
        


        return fn::format("state={} : coins=[{}] : items=[{}] : value={%.2f} : volume={}/{}",status,out_coins,out_itens,out_value,out_volume,volume_max);
    }

    int get_volume_max(){return volume_max;}
    int get_volume(){
        int out_volume = 0;

        if (!quebrado)
        {
            for (auto i = 0; i < static_cast<int>(reais.size()); i++)
            {
                out_volume += reais[i]->get_volume();
                
            }

            for (auto i = 0; i < static_cast<int>(itens.size()); i++)
            {
                out_volume += itens[i]->get_volume();
                
            }
        }
        return out_volume;
    }

    double get_valor(){
        double out_value = 0;

        for (auto i = 0; i < static_cast<int>(reais.size()); i++)
        {
            out_value += reais[i]->get_valor();
            
        }
        return out_value;
    }

    bool esta_quebrada(){return quebrado;}

};




template <typename CONTAINER, typename FN>
string map_join(const CONTAINER& container, FN fn, string sep = ", ", string prefix = "[", string suffix = "]") {
    stringstream ss;
    for (auto it = container.begin(); it != container.end(); ++it) {
        ss << (it != container.begin() ? sep : "") << fn(*it);
    }
    return prefix + ss.str() + suffix;
}

int main() {

    pig cofrinho;

    while (true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if (cmd == "end") {
            break;
        } else if (cmd == "init") {
             int volumeMax;
             ss >> volumeMax;
             cofrinho = pig(volumeMax);
        } else if (cmd == "show") {
            cout << cofrinho.str() << endl;
        } else if (cmd == "break") {
            cofrinho.quebar();
        } else if (cmd == "addCoin") {
            string label;
            ss >> label;
                if (label == "10"){
                    cofrinho.add_moeda(make_shared<Moeda>(Moeda::C10));
                    }else
                if (label == "25"){
                    cofrinho.add_moeda(make_shared<Moeda>(Moeda::C25));
                }else
                if (label == "50"){
                    cofrinho.add_moeda(make_shared<Moeda>(Moeda::C50));
                }else
                if (label == "100"){
                    cofrinho.add_moeda(make_shared<Moeda>(Moeda::C100));
                }else{
                    fn::write("valor invalido");
                }   
            
        } else if (cmd == "addItem") {
            string label;
            int volume;
            ss >> label >> volume;
            cofrinho.add_item(make_shared<Item>(label,volume));
        } else if (cmd == "extractItems") {
            // Obtenha os itens com o método extractItems
            // e imprima os itens obtidos
           vector<std::shared_ptr<Item>> novo = cofrinho.extrair_itens();
        } else if (cmd == "extractCoins") {
            // Obtenha as moedas com o método extractCoins
            // e imprima as moedas obtidas
           vector<std::shared_ptr<Moeda>> novo = cofrinho.extrair_moedas();
        } else {
            cout << "fail: invalid command\n";
        }
    }
}
