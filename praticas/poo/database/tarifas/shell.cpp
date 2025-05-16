#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

#include "fn.hpp"

using namespace std;

    enum Label {
        DEPOSIT,
        FEE,
        OPENING,
        REVERSE,
        WITHDRAW,
        ERROR
    };


class operation
{
private:
        /* data */
    int idex;
    Label label;
    int value;
    int balance;

    
public:
    operation(int id, Label tag,int val, int bal): idex(id),label(tag),value(val),balance(bal){
        switch (tag)
        {
        case DEPOSIT:
            if (value < 0)
            {
                fn::write("fail: invalid value");
                return;
            }
            balance += val;
        break;
        case WITHDRAW:
            if (balance < value)
            {
                fn::write("fail: invalid value");
                return;
            }

            balance -= value;

        break;
        case FEE:
        break;
        case OPENING:
        break;
        case REVERSE:
        break;
        default:
            break;
        }
    };
    int get_balance(){return balance;}
    int get_value(){return value;}
    int get_idex(){return idex;}
    auto get_label(){return idex;}
};


class balanceManager
{
private:
    /* data */
    int balance = 0;
    vector<operation> historico;
    int nextid = 0;
public:
    
    void add_operacao(Label op,int val){

        historico.push_back(operation(nextid,op,val,balance));
        balance = historico.back().get_balance();
        nextid++;
        
    }

    // void get_operacao(int id){}
    int get_balance(){return balance;}

    auto get_historico(){return historico;}

    string str() const{
        return fn::format("{}",balance);
    }
};


class account
{
private:
    balanceManager gerenciador;
    int id;
public:
    account(int idex = 0): id(idex){};
    void depositar(int valor){
        gerenciador.add_operacao(DEPOSIT,valor);
    }
    void saque(int valor){
        gerenciador.add_operacao(WITHDRAW,valor);
    }
    // void fee(int valor){}
    // void reverter(int valor){}
    string str() const{
        return fn::format("account:{} balance:{}",id,gerenciador.str());
    }
    auto get_balanceManager(){return gerenciador;}
};



template<typename CONTAINER, typename FUNC>
string join(const CONTAINER& cont, FUNC func, const string& delim) {
    stringstream ss;
    for (auto it = cont.begin(); it != cont.end(); it++) {
        ss << (it == cont.begin() ? "" : delim) << func(*it);
    }
    return ss.str();
}

int main() {
    account conta;
    while(true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        
        if (cmd == "end") {
            break;
        }
        else if (cmd == "init") {
             int number;
             ss >> number;
             conta = account(number);
        }
        else if (cmd == "show") {
            fn::write(conta.str());
        }
        else if (cmd == "deposit") {
            float value{};
            ss >> value;
            conta.depositar(value);

        }
        else if (cmd == "withdraw") {
             float value{};
             ss >> value;
             conta.saque(value);
        }
        else if (cmd == "fee") {
            // float value{};
            // ss >> value;
        }
        else if (cmd == "extract") {
            // int qtd{};
            // ss >> qtd;
        }
        else if (cmd == "reverse") {
            // int index{};
            // while(ss >> index) {
            // }
        }
        else {
            cout << "fail: invalid command\n";
        }
    }
    return 0;
}
