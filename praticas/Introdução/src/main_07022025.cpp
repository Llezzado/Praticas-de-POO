#include <iostream>
#include <vector>
#include <list>
#include <memory>
#include <sstream>
#include <utility>

#include <map>
#include <unordered_map>


#include <algorithm> //sort


using namespace std;

class Pessoa
{
private:
    string nome;
public:
    Pessoa(string x = "Imbu") : nome(x) {};
    string get_name(){return nome;};
};


int main()
{
    //vector<Pessoa> pessoas = {new Pessoa("juju"), new Pessoa("zacarias")};

    map<string,int> mapa;
    mapa["bolo"] = 178;
    mapa["bolo"] = 111;
    mapa["lobo"] = 139;

    auto x = mapa.find("bolo");

    if (x == mapa.end())
    {
        cout << "erro" << endl;
    }else{

        cout << ":)" << endl;
        x->second = mapa["bolo"] + mapa["lobo"];
    }
    

    cout << mapa["bolo"] << "\n";
    try
    {
        cout << mapa["lobo"] << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    mapa.erase("lobo");
    mapa.erase("bolo");

    cout << "Hello World!";
    return 0;
}