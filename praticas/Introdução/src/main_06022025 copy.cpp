#include <iostream>
#include <vector>
#include <list>
#include <memory>
#include <sstream>
#include <utility>
using namespace std;

class Pessoa
{
private:
    string nome;
public:
    Pessoa(string x = "Imbu") : nome(x) {};
};


int main()
{
    vector<Pessoa> pessoas;


    cout << "Hello World!";
    return 0;
}