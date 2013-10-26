#include <iostream>
#include <cstdio>
#include <Markup.h>
#include <string>
#include <vector>
#include "professor.h"

#define ERROR -1
#define SUCCESS 0
using namespace std;

int main()
{
    dadosProfessor *prof = new dadosProfessor;

    parseProfessor("0455487141833418.xml",prof);

    cout << prof->nome << endl;
    cout << prof->instituicao << endl;
    cout << prof->area << endl;
    cout << "Numero de Publicacoes em Eventos: " << prof->sizePubEventos << endl;
    cout << "Numero de Publicacoes em Periodicos: " << prof->sizePubPeriodicos << endl;
    cout << endl;
}
