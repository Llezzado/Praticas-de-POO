#include <iostream>
#include <vector>
#include <sstream>

#include "fn.hpp"

using namespace std;

class Player
{
private:
    /* data */
    int label;
    int pos;
    bool free;
public:
    Player(int x) : label(x){
        pos = 0;
        free = true;
    };
    bool esta_livre(){return free;}
    
    int get_label(){return label;}
    
    int get_pos(){return pos;}

    void set_pos(int numero){ pos = numero;}
    void set_free(bool libertar){free = libertar;}

    std::string str() const{
        return fn::format("player{}",label);
    };
    
};




class tabuleiro
{
private:
    vector<int> armadilhas;
    vector<Player> Jogadores;
    int running;
    int board_size;

public:
    tabuleiro(int nPlayers = 2 ,int size = 5): board_size(size+ 1) {
        for (auto i = 0; i < nPlayers; i++)
        {
            Jogadores.push_back(Player(i+1));
        }
        
    };

    string  str(){

        string buffer = "";

        for (auto i = 0; i < static_cast<int>(Jogadores.size()); i++)
        {
            buffer += Jogadores[i].str() + ": ";
            
            for (int j = 0; j < board_size; j++)
            {
                
                if ( Jogadores[i].get_pos() == j)
                {
                    /* code */
                    buffer += to_string(Jogadores[i].get_label());
                    continue;
                }
                


                buffer += ".";
            }
            
            buffer += "\n";

        }

        buffer += "traps__: ";
        bool no_trap;
        for (auto i = 0; i < board_size; i++)
        {   
            no_trap = true;
            for (auto j = 0; j < static_cast<int>(armadilhas.size()); j++)
            {
                
                if (armadilhas[j] == i)
                {
                    buffer += "x";
                    no_trap = false;
                }
                
            }
            
            if (no_trap)
            {
                buffer += ".";
            }
            
        }


        return buffer;
        
        
    };
    
    void add_trap(int trap){
        armadilhas.push_back(trap);
    };
    
    void roll(int passos){
        if (Jogadores[running].get_pos() == (board_size-1))
        {
            cout << "game is over" << endl;
            return;
        }
        

        if (running >= static_cast<int>(Jogadores.size())){running = 0;}

        if (!Jogadores[running].esta_livre())
        {
            if (passos%2 == 0)
            {
                cout << Jogadores[running].str() << " se libertou" << endl;
                Jogadores[running].set_free(true);
            }else{
                cout << Jogadores[running].str() << " continua preso" << endl;
            }
            running++;
            return;
        }
        
        
        Jogadores[running].set_pos(Jogadores[running].get_pos() + passos);

        if (Jogadores[running].get_pos() >= board_size)
        {
            cout << Jogadores[running].str() << " ganhou"<< endl;
            Jogadores[running].set_pos(board_size - 1);
            return;
        }

        cout << Jogadores[running].str() << " andou para " << Jogadores[running].get_pos() << endl;
        
        for (auto i = 0; i < static_cast<int>(armadilhas.size()); i++)
        {
            if (Jogadores[running].get_pos() == armadilhas[i])
            {
                cout << Jogadores[running].str() << " caiu em uma armadilha"<< endl;
                Jogadores[running].set_free(false);
            }
        }
        

        
        

        running++;
    };

};


int main() {

    auto Jumanji = tabuleiro();

    while(true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if (cmd == "end") {
            break;
        } else if (cmd == "init") {
             int nPlayers, size;
             ss >> nPlayers >> size;
             Jumanji = tabuleiro(nPlayers, size);
        } else if (cmd == "addTrap") {
             int pos;
             ss >> pos;
             Jumanji.add_trap(pos);
        } else if (cmd == "roll") {
             int value;
             ss >> value;
             Jumanji.roll(value);
        } else if (cmd == "show") {
            cout << Jumanji.str() << endl;
        } else {
            cout << "fail: command not found" << endl;
        }

    }
}
