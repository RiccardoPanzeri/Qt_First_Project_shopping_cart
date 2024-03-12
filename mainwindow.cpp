#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Carrello.h"
#include <QMessageBox>
#include "Prodotto.h"
#include <QDebug>
#include <QPixmap>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    prodotto1 ("Id001", "Spaghetti", 5.50, "alimentare", 5, 5),
    prodotto2  ("Id002", "Scheda Grafica", 1200.99, "elettronica", 3, 3),
    prodotto3 ("Id003", "Maglietta", 25.99, "abbigliamento", 20, 20),
    prodotto4 ("Id004", "Jeans", 40.99, "abbigliamento", 30, 30),
    prodotto5 ("Id005", "Modulo RAM", 59.99, "elettronica", 60, 60),
    prodotto6 ("Id006", "Ciambelle", 4.90, "alimentare", 100, 100),
    carrello1("ID0001")
{
    ui->setupUi(this);


    //creo un vettoreche conterrà tutti gli articoli disponibili

    elenco.push_back(prodotto1);
    elenco.push_back(prodotto2);
    elenco.push_back(prodotto3);
    elenco.push_back(prodotto4);
    elenco.push_back(prodotto5);
    elenco.push_back(prodotto6);

    //inserisco tutti i prodotti nell'elenco
    for(Prodotto i : elenco){
        ui->comboBoxProdotti->addItem(QString::fromStdString(i.getNome()) + " Prezzo: " + QString::number(i.getPrezzo(), 'g') + "  euro  Disponibili: " + QString::number(i.getQuantità()));
    }

    QPixmap carrelloImg(":/img/img/carrello.png"); // creo un oggetto pixmap che conterrà il path dell'immagine.
    ui->label2_immagine->setPixmap(carrelloImg.scaled(200, 500, Qt::KeepAspectRatio));




}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_aggiungi_clicked()
{
    int index = ui->comboBoxProdotti->currentIndex();
    if(elenco.at(index).getQuantità() > 0){
        elenco.at(index).decrementaQuantità();
        carrello1.aggiungiProdotto(elenco.at(index));
        if(!elenco.at(index).getSelezionato()){
            elenco.at(index).setSelezionato(true);
        }
        carrello1.visualizza();


        qDebug() <<elenco.at(index).getId() + " " + to_string(elenco.at(index).getQuantità());
        ui->comboBoxProdotti->clear();
        for(Prodotto i : elenco){
            ui->comboBoxProdotti->addItem(QString::fromStdString(i.getNome()) + " Prezzo: " + QString::number(i.getPrezzo(), 'g') + " euro  Disponibili: " + QString::number(i.getQuantità()));
        }

        ui->comboBoxProdotti->setCurrentIndex(index);
        QListWidgetItem item(ui->comboBoxProdotti->currentText());
        ui->listWidgetCarrello->addItem(item.text());


    }else{
        QMessageBox::warning(this, "Prodotto Esaurito", "Siamo spiacenti, mail prodotto è esaurito");

    }

}


void MainWindow::on_pushButton_procedi_clicked()

{   if(!carrello1.vuoto()){

        carrello1.setTotale(0);
        QString riepilogo;
        carrello1.checkout();
        if(ui->line_codice->text() == "SCONTO20%"){
            carrello1.applicaSconto(20);


        }
        riepilogo = carrello1.mostra(elenco);

        QMessageBox::StandardButton risposta = QMessageBox::question(this, "Conferma Ordine", "Riepilogo ordine:\n " + riepilogo + "\nSei sicuro di voler confermare l'ordine?", QMessageBox::Yes|QMessageBox::No);

        if(risposta == QMessageBox::Yes){
            QMessageBox::information(this, "Riepilogo Ordine", "Il tuo Ordine è andato a buon fine!");
            ui->listWidgetCarrello->clear();
            carrello1.setTotale(0);
            ui->line_codice->setText("");
            carrello1.svuota();
            for(Prodotto &x : elenco){
                x.setSelezionato(false);
                x.setIniziale(x.getQuantità());
            }
            riepilogo.clear();

        }
    }else{
        QMessageBox::warning(this, "Carrello vuoto", "Non ci sono articoli all'interno del tuo carrello");
    }

}


void MainWindow::on_pushButton_rimuovi_clicked()
{   int index = ui->comboBoxProdotti->currentIndex();
    if(!carrello1.vuoto()){

        for(Prodotto &x : elenco){
            if(x.getId() == carrello1.getUltimoProdotto().getId()){
                x.incrementaQuantità();
                if(x.getQuantità() == x.getIniziale()){
                    x.setSelezionato(false);
                    qDebug()<<"deselezionato";
                }
                qDebug() << "Incrementato";
                qDebug() << to_string(x.getQuantità()) + " " + x.getId();
            }
        }
        carrello1.rimuoviProdotto();
        carrello1.visualizza();
        ui->listWidgetCarrello->takeItem(ui->listWidgetCarrello->count() - 1);
        ui->comboBoxProdotti->clear();
        for(Prodotto x : elenco){
            ui->comboBoxProdotti->addItem(QString::fromStdString(x.getNome()) + " Prezzo: " + QString::number(x.getPrezzo(), 'g') + " euro  Disponibili: " + QString::number(x.getQuantità()));

        }
        ui->comboBoxProdotti->setCurrentIndex(index);

    }else{
        QMessageBox::warning(this, "Carrello Vuoto", "Non sono presenti prodotti nel tuo carrello");
    }

}

