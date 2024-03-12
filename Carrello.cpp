#include "Carrello.h"
#include "Prodotto.h"
#include <iostream>
#include <QMainWindow>

void Carrello::aggiungiProdotto(Prodotto prodotto) {

    prodotti.push_back(prodotto);

}

void Carrello::rimuoviProdotto(){
    prodotti.pop_back();
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


QString Carrello::mostra(vector<Prodotto> elenco){
    QString riepilogo;
    QString differenzaS;
    for(Prodotto &i : elenco){

        if(i.getSelezionato()){

            differenzaS = QString::number(i.getIniziale() - i.getQuantità());
            riepilogo += QString::fromStdString(i.getNome()) + ":    ";
            riepilogo +=  QString::number(i.getPrezzo()) + " euro  ";
            riepilogo += "X" + differenzaS + "\n\n";
            //i.setIniziale(i.getQuantità());
             qDebug()<<"NEW INIZIALE"<<i.getIniziale();

        }
        qDebug()<<i.getNome()<<": quantita:"<< i.getQuantità()<<" qIniziale: "<<i.getIniziale()<<"\n";
    }

    riepilogo += "\nTOTALE: " + QString::number(totale) + " euro\n";

    return riepilogo;
}


Prodotto Carrello::getProdotto(int indice){
    return prodotti.at(indice);
}


Prodotto Carrello::getUltimoProdotto(){
    return prodotti.back();
}


void Carrello::visualizza(){
    cout<<"CARRELLO: "<<endl;
    for (Prodotto x : prodotti) {
        cout<<x.getNome() <<" "<< x.getQuantità()<<endl;
    }
}


bool Carrello::vuoto(){
    if(prodotti.empty()){
        return true;
    }else{
        return false;
    }
}

void Carrello::svuota(){
    prodotti.clear();
}
