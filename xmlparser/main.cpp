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
    chavesProfessor *prof = new chavesProfessor;
    ifstream arqCurriculos ("files.txt"); // ls > files.txt
    string nomeArquivo;
    int nProfs = 0;

    vector <chavesProfessor> ordNome;

    if (arqCurriculos.is_open())
    {
        while (getline(arqCurriculos,nomeArquivo))
        {
            if (getChavesProfessor(nomeArquivo,prof)==0) // success
            {
                nProfs++;
                ordNome.push_back(*prof);
            }
        }
        arqCurriculos.close();
    }

    for (unsigned i = 0; i < ordNome.size();i++)
        cout << (ordNome.at(i)).nome << "  " << (ordNome.at(i)).nomeArquivo << endl;


    //parseProfessor("0455487141833418.xml",prof);

}

