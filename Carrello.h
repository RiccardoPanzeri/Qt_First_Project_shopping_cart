#pragma once
#include <vector>
#include <string>
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
    void rimuoviProdotto(Prodotto prodotto);
    void checkout();
    void applicaSconto(float percentuale);
    void setTotale();
    float getTotale();

};

#
