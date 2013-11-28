#include "addquerido.h"
#include "ui_addquerido.h"

AddQuerido::AddQuerido(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddQuerido)
{
    ui->setupUi(this);
}

AddQuerido::~AddQuerido()
{
    delete ui;
}


void AddQuerido::on_goButton_clicked()
{
    this->go(ui->lineEdit->text());
}
