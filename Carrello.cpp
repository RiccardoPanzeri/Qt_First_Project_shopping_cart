#include "Carrello.h"

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

    }
}
