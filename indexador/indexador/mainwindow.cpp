#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <cstdio>
#include <Markup.h>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include "professor.h"
#include "details.h"


#define ERROR -1
#define SUCCESS 0

using namespace std;

int flagAlfa = 0;
char lastOrd = ' ';

MainWindow::MainWindow(QWidget *parent) :  QMainWindow(parent),  ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->tableWidget->setColumnWidth(0,350);


    ifstream arqCurriculos ("files.txt"); // ls > files.txt
    ofstream arqChaves ("chaves.bin",std::ofstream::binary);
    string nomeArquivo;
    int nProfs = 0;
    int letras [27];


    // Inicializa array de iniciais
    for (int i=0; i < 27; i++)
        letras[i] = 0;

    // Processa todos os XMLs
    if (arqCurriculos.is_open())
    {
        while (getline(arqCurriculos,nomeArquivo))
        {
            if (getChavesProfessor(nomeArquivo,prof)==0) // XML bem formado
            {
                nProfs++;
                vecProfessor.push_back(*prof);

                if (int (prof->nome[0]) - 65 >= 0 ) // Preenche array com as iniciais de cada pessoa
                    letras[int (prof->nome[0]) - 65]++;
                else letras [26]++;
            }
        }
        arqCurriculos.close();
    }

    /*   The GNU Standard C++ library uses a 3-part hybrid sorting algorithm: introsort is performed
     * first (introsort itself being a hybrid of quicksort and heap sort),to a maximum depth given
     * by 2×log2 n, where n is the number of elements, followed by an insertion sort on the result. */

    // Imprime nome de todos os professores contabilizados
    // for (unsigned i = 0; i < ordNome.size();i++)
    //     cout << (ordNome.at(i)).nome << "  " << (ordNome.at(i)).nomeArquivo << endl;


    // Acumula array de letras
    int cumulativo[27];
    cumulativo[0] = 0;
    for (int i=1; i < 27; i++)
        cumulativo[i] = letras[i-1] + cumulativo[i-1];



    // Escreve o array cumulativo no arquivo como um inteiro de 4 bytes
    for (int i=0; i < 27; i++)
        arqChaves.write((char*)(cumulativo+i), sizeof(int));



    // Escreve os nomes dos professores e nomes dos arquivos XML no arquivo de chaves
    for (unsigned i = 0; i < vecProfessor.size(); i++)
    {
        arqChaves << (vecProfessor.at(i)).nome;
        arqChaves << (vecProfessor.at(i)).nomeArquivo;
    }


    // Escreve no tableWidget
    //escreveNaTable();

    //ui->tableWidget->clearContents();

}

MainWindow::~MainWindow()
{
    delete ui;
}

// Cria a janela de detalhes e a preenche
void MainWindow::on_tableWidget_itemDoubleClicked(QTableWidgetItem *item)
{
    string path;
    QString professorName = ui->tableWidget->item(item->row(),0)->text();
    Details *detWindow = new Details;
    detWindow->setLabelText(professorName);
    detWindow->show();
    path = vecProfessor.at(item->row()).nomeArquivo;
    QString informacoes = QString::fromStdString(Informacoes(path));
    detWindow->setInfoText(informacoes);
}

// Povoa o tableWidget
void MainWindow::escreveNaTable ()
{
    for (unsigned i = 0; i < vecProfessor.size(); i++)
    {

        QString nome = (vecProfessor.at(i)).nome;

        int nPP = (vecProfessor.at(i)).nPPeriodicos;
        int nPE = (vecProfessor.at(i)).nPEventos;

        QString TotalPub =  QString::fromStdString(to_string(nPP + nPE));

        QString nPeriodicos = QString::fromStdString(to_string( (vecProfessor.at(i)).nPPeriodicos ));
        QString nEventos = QString::fromStdString(to_string( (vecProfessor.at(i)).nPEventos));

        QTableWidgetItem *nomeItem = new QTableWidgetItem(nome);
        QTableWidgetItem *periodicosItem = new QTableWidgetItem(nPeriodicos);
        QTableWidgetItem *eventosItem = new QTableWidgetItem(nEventos);
        QTableWidgetItem *TotPubItem = new QTableWidgetItem(TotalPub);

        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i,0, nomeItem);
        ui->tableWidget->setItem(i,1, periodicosItem);
        ui->tableWidget->setItem(i,2, eventosItem);
        ui->tableWidget->setItem(i,3, TotPubItem);
    }
}

// Escreve no tableWidget
void MainWindow::escreveNaTableInverso ()
{
    // Faxina
    for (unsigned i = 0; i < vecProfessor.size(); i++)
        ui->tableWidget->insertRow(i);

    for (unsigned i = 0; i < vecProfessor.size(); i++)
    {

        QString nome = (vecProfessor.at(i)).nome;

        int nPP = (vecProfessor.at(i)).nPPeriodicos;
        int nPE = (vecProfessor.at(i)).nPEventos;

        QString TotalPub =  QString::fromStdString(to_string(nPP + nPE));

        QString nPeriodicos = QString::fromStdString(to_string( (vecProfessor.at(i)).nPPeriodicos ));
        QString nEventos = QString::fromStdString(to_string( (vecProfessor.at(i)).nPEventos));


        QTableWidgetItem *nomeItem = new QTableWidgetItem(nome);
        QTableWidgetItem *periodicosItem = new QTableWidgetItem(nPeriodicos);
        QTableWidgetItem *eventosItem = new QTableWidgetItem(nEventos);
        QTableWidgetItem *TotPubItem = new QTableWidgetItem(TotalPub);

        ui->tableWidget->setItem(vecProfessor.size()-1-i, 0, nomeItem);
        ui->tableWidget->setItem(vecProfessor.size()-1-i, 1, periodicosItem);
        ui->tableWidget->setItem(vecProfessor.size()-1-i, 2, eventosItem);
        ui->tableWidget->setItem(vecProfessor.size()-1-i, 3, TotPubItem);
    }
}



void MainWindow::on_alfaButton_clicked()
{
    // Testa qual foi a última chave de ordenamento e apenas reordena caso necessário
    if (lastOrd != 'A')
    {
        sort (vecProfessor.begin(), vecProfessor.end(), comparaNome);
        lastOrd = 'A';
    }

    // Faxina
    for (unsigned i = 0; i < vecProfessor.size(); i++)
        ui->tableWidget->removeRow(0);


    if (flagAlfa == 0)
    {
        escreveNaTable();
        flagAlfa = 1;
    }
    else
    {
        escreveNaTableInverso();
        flagAlfa = 0;
    }

}


void MainWindow::on_perButton_clicked()
{
    if (lastOrd != 'P')
    {
        sort (vecProfessor.begin(), vecProfessor.end(), comparaNP);
        lastOrd = 'P';
    }

    for (unsigned i = 0; i < vecProfessor.size(); i++)
        ui->tableWidget->removeRow(0);


    if (flagAlfa == 0)
    {
        escreveNaTable();
        flagAlfa = 1;
    }
    else
    {
        escreveNaTableInverso();
        flagAlfa = 0;
    }
}

void MainWindow::on_eventsButton_clicked()
{
    if (lastOrd != 'E')
    {
        sort (vecProfessor.begin(), vecProfessor.end(), comparaNE);
        lastOrd = 'E';
    }

    for (unsigned i = 0; i < vecProfessor.size(); i++)
        ui->tableWidget->removeRow(0);


    if (flagAlfa == 0)
    {
        escreveNaTable();
        flagAlfa = 1;
    }
    else
    {
        escreveNaTableInverso();
        flagAlfa = 0;
    }
}

void MainWindow::on_totalButton_clicked()
{
    if (lastOrd != 'T')
    {
        sort (vecProfessor.begin(), vecProfessor.end(), comparaNT);
        lastOrd = 'T';
    }

    for (unsigned i = 0; i < vecProfessor.size(); i++)
        ui->tableWidget->removeRow(0);


    if (flagAlfa == 0)
    {
        escreveNaTable();
        flagAlfa = 1;
    }
    else
    {
        escreveNaTableInverso();
        flagAlfa = 0;
    }

}

// Sugere professores a partir da substring dada pelo usuário
void MainWindow::on_searchBar_textChanged(const QString &arg1)
{
    ui->tableWidget->clearContents();

    for (unsigned i = 0, j = 0; i < vecProfessor.size(); i++)
    {
        QString s = ((vecProfessor.at(i)).nome);

        if (s.contains(arg1,Qt::CaseInsensitive))
        {

            QString nome = (vecProfessor.at(i)).nome;


            int nPP = (vecProfessor.at(i)).nPPeriodicos;
            int nPE = (vecProfessor.at(i)).nPEventos;

            QString TotalPub =  QString::fromStdString(to_string(nPP + nPE));

            QString nPeriodicos = QString::fromStdString(to_string( (vecProfessor.at(i)).nPPeriodicos ));
            QString nEventos = QString::fromStdString(to_string( (vecProfessor.at(i)).nPEventos));


            QTableWidgetItem *nomeItem = new QTableWidgetItem(nome);
            QTableWidgetItem *periodicosItem = new QTableWidgetItem(nPeriodicos);
            QTableWidgetItem *eventosItem = new QTableWidgetItem(nEventos);
            QTableWidgetItem *TotPubItem = new QTableWidgetItem(TotalPub);

            ui->tableWidget->insertRow(j);
            ui->tableWidget->setItem(j,0, nomeItem);
            ui->tableWidget->setItem(j,1, periodicosItem);
            ui->tableWidget->setItem(j,2, eventosItem);
            ui->tableWidget->setItem(j,3, TotPubItem);
            j++;
            ui->tableWidget->setRowCount(j);
        }
    }
}

void MainWindow::on_addCurriculoButton_triggered()
{
    this->addQ();
}


bool MainWindow::on_go(QString a)
{
    //ui->Logo->setText(a);
    if (getChavesProfessor(a.toStdString() ,prof)==0) // XML bem formado
    {
        //nProfs++;
        vecProfessor.push_back(*prof);
        on_alfaButton_clicked();


        //if (int (prof->nome[0]) - 65 >= 0 ) // Preenche array com as iniciais de cada pessoa
        //    letras[int (prof->nome[0]) - 65]++;
        //else letras [26]++;

        //arqChaves << (vecProfessor.at(i)).nome;
        //arqChaves << (vecProfessor.at(i)).nomeArquivo;
    }

}
