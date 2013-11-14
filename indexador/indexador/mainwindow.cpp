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

#define ERROR -1
#define SUCCESS 0
using namespace std;


MainWindow::MainWindow(QWidget *parent) :  QMainWindow(parent),  ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    chavesProfessor *prof = new chavesProfessor;
    ifstream arqCurriculos ("files.txt"); // ls > files.txt
    ofstream arqChaves ("chaves.bin",std::ofstream::binary);
    string nomeArquivo;
    int nProfs = 0;
    int letras [27];
    vector <chavesProfessor> ordNome;


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
                ordNome.push_back(*prof);

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
    sort (ordNome.begin(),ordNome.end(),comparaNome);
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
    for (unsigned i = 0; i < ordNome.size(); i++)
    {
        arqChaves << (ordNome.at(i)).nome;
        arqChaves << (ordNome.at(i)).nomeArquivo;
    }


    for (unsigned i = 0; i < ordNome.size(); i++)
    {
        //string nome = (string) (ordNome.at(i)).nome;

        //ui->Logo->setText("hue");
    }

    for (unsigned i = 0; i < ordNome.size(); i++)
    {
        // Escreve no tableWidget
        QString text = (ordNome.at(i)).nome;
        QTableWidgetItem *item = new QTableWidgetItem(text);
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i,0,item);
    }


    arqChaves.close();

}

MainWindow::~MainWindow()
{
    delete ui;
}
