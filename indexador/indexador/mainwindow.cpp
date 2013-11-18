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
    cout << "\n\n";

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

    arqChaves.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

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


void MainWindow::escreveNaTable ()
{
    // Escreve no tableWidget
    for (unsigned i = 0; i < vecProfessor.size(); i++)
    {

        QString nome = (vecProfessor.at(i)).nome;
        //nome.replace("Ã","a");

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

void MainWindow::escreveNaTableInverso ()
{
    for (int i = 0; i < vecProfessor.size(); i++)
        ui->tableWidget->insertRow(i);
    // Escreve no tableWidget
    for (int i = 0; i < vecProfessor.size(); i++)
    {

        QString nome = (vecProfessor.at(i)).nome;
        //nome.replace("Ã","a");

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
    if (lastOrd != 'A')
    {
        sort (vecProfessor.begin(), vecProfessor.end(), comparaNome);
        lastOrd = 'A';
    }

    for (int i = 0; i < vecProfessor.size(); i++)
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

    for (int i = 0; i < vecProfessor.size(); i++)
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

    for (int i = 0; i < vecProfessor.size(); i++)
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

    for (int i = 0; i < vecProfessor.size(); i++)
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
