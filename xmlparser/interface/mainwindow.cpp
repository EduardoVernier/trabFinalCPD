#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "detalhes.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_searchButton_clicked()
{
    QString text;
    text = ui->searchBar->text();
    QTableWidgetItem *item = new QTableWidgetItem(text);
    ui->tableWidget->insertRow(0);
    ui->tableWidget->setItem(0,0,item);

}

void MainWindow::on_descAlfa_clicked()
{
    QString string;
}

void MainWindow::on_tableWidget_itemDoubleClicked(QTableWidgetItem *item)
{
    Detalhes *dtwindow = new Detalhes;
    dtwindow->show();
}
