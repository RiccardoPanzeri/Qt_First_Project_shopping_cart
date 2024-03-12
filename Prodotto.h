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
    Prodotto(string newid, string newNome, float newPrezzo, string newCategoria, int newQuantità) : id(newid), nome(newNome), prezzo(newPrezzo), categoria(newCategoria), quantità(newQuantità) {};

    float getPrezzo();
    void setPrezzo(float newPrezzo);
    string getId();
    void setId(string newId);
    string getCategoria();
    void setCategoria(string newCategoria);
    string getNome();
    void setNome(string newNome);
    int getQuantità();
    void setQuantità(int newQuantità);
    void decrementaQuantità();

};


