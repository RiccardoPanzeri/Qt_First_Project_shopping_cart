#include "Prodotto.h"

string Prodotto::getNome() {
    return nome;


}

void Prodotto::setNome(string newNome){
    nome = newNome;
}


int Prodotto::getQuantità(){
    return quantità;
}

void Prodotto::setQuantità(int newQuantità){
    quantità = newQuantità;

}

float Prodotto::getPrezzo(){

    return prezzo;
}


void Prodotto::setPrezzo(float newPrezzo){
    prezzo = newPrezzo;
}


string Prodotto::getId(){
    return id;
}

void Prodotto::setId(string newId){
    id = newId;
}

string Prodotto::getCategoria(){
    return categoria;
}

void Prodotto::setCategoria(string newCategoria){
    categoria = newCategoria;
}

void Prodotto::decrementaQuantità(){
    quantità--;
}
