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
    char nomeArquivo [30];
    char nome [60];
    int nPEventos;
    int nPPeriodicos;
} chavesProfessor;

// == FUNCOES ==

int parseProfessor(string path, dadosProfessor *temp);
int getChavesProfessor(string path, chavesProfessor *temp);
bool comparaNome(const chavesProfessor &a, const chavesProfessor &b);


#endif // PROFESSOR_H
