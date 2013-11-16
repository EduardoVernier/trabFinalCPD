#include "details.h"
#include "ui_details.h"
#include <QTextFormat>

Details::Details(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Details)
{
    ui->setupUi(this);
}

void Details::setLabelText(QString str){

    ui->label->setText(str);
    setWindowTitle(str);
    ui->label->setFont(QFont("Sans Serif",12,QFont::Bold));

}

void Details::setInfoText(QString text){
    ui->infoBox->setText(text);
}

Details::~Details()
{
    delete ui;
}
