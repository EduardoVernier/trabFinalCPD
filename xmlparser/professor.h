#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct
{
    string titulo;
    string ano;
} Artigo;

typedef struct
{
    string titulo;
    string ano;
} Trabalho;

typedef struct
{
    string nome;
    int nPubEventos;
    int nPubPeriodicos;
    string instituicao;
    string area;
    vector <Trabalho> pubEventos;
    vector <Artigo> pubPeriodicos;
} dadosProfessor;

typedef struct
{
    int posNoArq;
    string nome;
    int nPEventos;
    int nPPeriodicos;
} chavesProfessor;

// == FUNCOES ==

int parseProfessor(string path, dadosProfessor *temp);

#endif // PROFESSOR_H
