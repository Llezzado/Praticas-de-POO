#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Roupa
{
private:
    /* data */
    std::string tamanho;
    
public:
    void str(){
        cout << "size: (" << tamanho << ")\n";
    };

    void put_tam(string val){
        if (
            val != "PP" &&
            val != "P" &&
            val != "M" &&
            val != "G" &&
            val != "GG" &&
            val != "XG"
        
        )
        {
            cout << "fail: Valor inválido, tente PP, P, M, G, GG ou XG" << endl;
            return;
        }

        tamanho = val;
        
    }

};



int main() {
    // CRIE SEU OBJETO AQUI
    Roupa vestimeta;
    
    while (true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if (cmd == "size") { // TENTE ATRIBUIR UM TAMANHO
            string size;
            ss >> size;
            vestimeta.put_tam(size);
        } else if (cmd == "show") { // MOSTRE AS INFORMAÇÕES DO OBJETO
        vestimeta.str();
        } else if (cmd == "end") {
            break;
        } else {
            cout << "fail: Comando inválido" << endl;
        }
    }
}
