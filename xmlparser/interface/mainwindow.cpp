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
    ui->listWidget->addItem(new QListWidgetItem(text));

}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    QString text = ui->listWidget->currentItem()->text();
}

void MainWindow::on_descAlfa_clicked()
{
    QString string;
}
