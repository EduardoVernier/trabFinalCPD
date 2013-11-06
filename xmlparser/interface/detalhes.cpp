#include "detalhes.h"
#include "ui_detalhes.h"

Detalhes::Detalhes(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Detalhes)
{
    ui->setupUi(this);
}

Detalhes::~Detalhes()
{
    delete ui;
}
