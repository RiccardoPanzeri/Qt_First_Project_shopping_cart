#pragma once
#include <string>
using namespace std;


class Prodotto
{
private:
    string id;
    string nome;
    float prezzo;
    string categoria;
    int quantità;

public:
    Prodotto(string newid, string newNome, float newPrezzo, string newCategoria) : id(newid), nome(newNome), prezzo(newPrezzo), categoria(newCategoria) {};

    float getPrezzo();
    void setPrezzo(float newPrezzo);
    string getId();
    string getCategoria();
    string getNome();
    int getQuantità();
    void setQuantità(int newQuantità);

};


