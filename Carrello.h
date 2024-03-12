#pragma once
#include <vector>
#include <string>
#include<QMainWindow>
#include "Prodotto.h"
using namespace std;
class Carrello
{
private:
    string Id;
    vector<Prodotto> prodotti;
    float totale;

public:
    Carrello(string newId): Id(newId){};
    void aggiungiProdotto(Prodotto prodotto);
    void rimuoviProdotto();
    void checkout();
    void applicaSconto(float percentuale);
    void setTotale(float newTotale);
    float getTotale();
    Prodotto getProdotto(int indice);
    Prodotto getUltimoProdotto();
    QString mostra();
    void visualizza();
    bool vuoto();

};


