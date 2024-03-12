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
    prodotto1 ("Id001", "Prodotto1", 530, "alimentare", 5 ),
    prodotto2  ("Id002", "Prodotto2", 1200, "elettronica", 3 ),
    prodotto3 ("Id003", "Prodotto3", 25, "abbigliamento", 20 ),
    carrello1("ID0001")
{
    ui->setupUi(this);


    //creo un vettoreche conterrà tutti gli articoli disponibili

    elenco.push_back(prodotto1);
    elenco.push_back(prodotto2);
    elenco.push_back(prodotto3);

    //inserisco tutti i prodotti nell'elenco
    for(Prodotto i : elenco){
        ui->comboBoxProdotti->addItem(QString::fromStdString(i.getNome()) + " Prezzo: " + QString::number(i.getPrezzo(), 'g') + "euro  Disponibili: " + QString::number(i.getQuantità()));
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
        carrello1.aggiungiProdotto(elenco.at(index));
        QListWidgetItem item(ui->comboBoxProdotti->currentText());
        ui->listWidgetCarrello->addItem(item.text());
        elenco.at(index).decrementaQuantità();
        ui->comboBoxProdotti->clear();
        for(Prodotto i : elenco){
            ui->comboBoxProdotti->addItem(QString::fromStdString(i.getNome()) + " Prezzo: " + QString::number(i.getPrezzo(), 'g') + "euro  Disponibili: " + QString::number(i.getQuantità()));
        }

        carrello1.mostra();
        ui->comboBoxProdotti->setCurrentIndex(index);
    }else{
        QMessageBox::warning(this, "Prodotto Esaurito", "Siamo spiacenti, mail prodotto è esaurito");

    }

}


void MainWindow::on_pushButton_procedi_clicked()

{   carrello1.setTotale(0);
    QString riepilogo;
    carrello1.checkout();
    if(ui->line_codice->text() == "SCONTO20%"){
        qDebug()<<"Sconto applicato\n";
        carrello1.applicaSconto(20);


    }
    riepilogo = QString::fromStdString(carrello1.mostra());

    QMessageBox::StandardButton risposta = QMessageBox::question(this, "Conferma Ordine", "Riepilogo ordine:\n " + riepilogo + "\nSei sicuro di voler confermare l'ordine?", QMessageBox::Yes|QMessageBox::No);

    if(risposta == QMessageBox::Yes){
        QMessageBox::information(this, "Riepilogo Ordine", "Il tuo Ordine è andato a buon fine!");
        ui->listWidgetCarrello->clear();
        carrello1.setTotale(0);
        ui->line_codice->setText("");
    }


}

