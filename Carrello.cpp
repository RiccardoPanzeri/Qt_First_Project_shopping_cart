#include "Carrello.h"
#include "Prodotto.h"
#include <iostream>
void Carrello::aggiungiProdotto(Prodotto prodotto) {

    prodotti.push_back(prodotto);

}

void Carrello::rimuoviProdotto(Prodotto prodotto){
    for (Prodotto x : prodotti) {
        if(x.getNome() == prodotto.getNome()){
            x.setQuantità(x.getQuantità() - 1);
        }
    }
}


void Carrello::checkout(){
    for (Prodotto x : prodotti){
        totale += x.getPrezzo();
    }

}


void Carrello::applicaSconto(float percentuale){
    totale -= ((totale * percentuale) / 100);

}


float Carrello::getTotale(){
    return totale;
}


void Carrello::setTotale(float newTotale){
    totale = newTotale;
}


string Carrello::mostra(){
    string riepilogo;
    for(Prodotto i : prodotti){
        riepilogo += i.getNome() + ":    ";
        riepilogo += to_string(i.getPrezzo()) + " euro\n";

    }

    riepilogo += "\nTOTALE: " + to_string(totale) + "euro\n";

    return riepilogo;
}

