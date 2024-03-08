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

public:
    Carrello(string newId): Id(newId){};
    void aggiungiProdotto(Prodotto prodotto);
    void rimuoviProdotto(Prodotto prodotto);

};

#
