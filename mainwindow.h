#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Carrello.h"
#include "Prodotto.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_aggiungi_clicked();


    void on_pushButton_procedi_clicked();

    void on_pushButton_rimuovi_clicked();

private:
    Ui::MainWindow *ui;
    Prodotto prodotto1;
    Prodotto prodotto2;
    Prodotto prodotto3;
    Prodotto prodotto4;
    Prodotto prodotto5;
    Prodotto prodotto6;
    vector<Prodotto> elenco;
    Carrello carrello1;

};
#endif // MAINWINDOW_H
