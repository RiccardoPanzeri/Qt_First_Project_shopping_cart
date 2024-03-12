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
    int quantitàIniziale;
    bool selezionato;


public:
    Prodotto(string newid, string newNome, float newPrezzo, string newCategoria, int newQuantità, int newIniziale) : id(newid), nome(newNome), prezzo(newPrezzo), categoria(newCategoria), quantità(newQuantità), quantitàIniziale(newIniziale), selezionato(false) {};

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
    void setIniziale(int newQuantità);
    int getIniziale();
    void decrementaQuantità();
    void incrementaQuantità();
    bool getSelezionato();
    void setSelezionato(bool tf);
};


