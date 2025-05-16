#include <iostream>
#include <vector>
#include <list>
#include <memory>
#include <sstream>
#include <utility>
using namespace std;


class MoedaOO {
private:
    std::string nome;
    float valor;
    int tamanho;
    MoedaOO(std::string nome, float valor, int tamanho) : nome(nome), valor(valor), tamanho(tamanho) {}
public:
    static const MoedaOO C5, C10, C25, C50, C100;
    int getTamanho() const { return tamanho; }
    float getValor() const { return valor; }
    std::string getNome() const { return nome; }

    std::string toString() const {
        return "Moeda: " + nome + " (Valor: R$ " + std::to_string(valor) + ")";
    }
};

const MoedaOO MoedaOO::C5("5 centavos", 0.05, 1);
const MoedaOO MoedaOO::C10("10 centavos", 0.10, 2);
const MoedaOO MoedaOO::C25("25 centavos", 0.25, 3);
const MoedaOO MoedaOO::C50("50 centavos", 0.50, 4);
const MoedaOO MoedaOO::C100("1 real", 1.00, 5);

// enum Moeda {
//     C5, C10, C25, C50, R1
// };

// float pegarValor(Moeda moeda) {
//     switch (moeda) {
//         case C5: return 0.05;
//         case C10: return 0.10;
//         case C25: return 0.25;
//         case C50: return 0.50;
//         case R1: return 1.00;
//     }
//     return 0.0;
// }

// std::string pegarNome(Moeda moeda) {
//     switch (moeda) {
//         case C5: return "5 centavos";
//         case C10: return "10 centavos";
//         case C25: return "25 centavos";
//         case C50: return "50 centavos";
//         case R1: return "1 real";
//     }
//     return "";
// }
#include <vector>

int main() {
    std::vector<MoedaOO> moedas;
    moedas.push_back(MoedaOO::C5);
    moedas.push_back(MoedaOO::C10);
    moedas.push_back(MoedaOO::C25);
    moedas.push_back(MoedaOO::C50);
    moedas.push_back(MoedaOO::C100);

    for (const MoedaOO& moeda : moedas) {
        std::cout << moeda.toString() << std::endl;
    }

}
