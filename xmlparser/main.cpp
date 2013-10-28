#include <iostream>
#include <cstdio>
#include <Markup.h>
#include <string>
#include <vector>
#include <fstream>
#include "professor.h"

#define ERROR -1
#define SUCCESS 0
using namespace std;

int main()
{
    dadosProfessor *prof = new dadosProfessor;
    ifstream arqCurriculos ("files.txt");
    string nomeArquivo;

    if (arqCurriculos.is_open())
    {
        while (getline(arqCurriculos,nomeArquivo))
        {
            parseProfessor(nomeArquivo,prof);

            cout << prof->nome << endl;
            cout << prof->instituicao << endl;
            cout << prof->area << endl;
            cout << "Numero de Publicacoes em Eventos: " << prof->nPubEventos << endl;
            cout << "Numero de Publicacoes em Periodicos: " << prof->nPubPeriodicos << endl;

            cout << endl;
        }
        arqCurriculos.close();
    }



    //parseProfessor("0455487141833418.xml",prof);

}

// Dica: ls > files.txt
