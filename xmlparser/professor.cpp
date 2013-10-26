#include <iostream>
#include <cstdio>
#include <Markup.h>
#include <string>
#include <vector>
#include "professor.h"

#define ERROR -1
#define SUCCESS 0
using namespace std;

int parseProfessor(string path, dadosProfessor *temp){
    CMarkup xml;
    int sizeTrab = 0, sizeArt = 0;

    if(!xml.Load(path)){
        cout << "Erro de abertura do arquivo xml." << endl;
        return 1;
    }

// ========= DADOS GERAIS ===================
    if (!xml.FindElem("CURRICULO-VITAE")){
        cout << "Sem CV" << endl;
        return ERROR;
    }
    xml.IntoElem(); //seta CV como tag pai

    if(!xml.FindElem("DADOS-GERAIS")){
        cout << "Sem DADOS-GERAIS." << endl;
        return ERROR;
    }
    temp->nome = xml.GetAttrib("NOME-COMPLETO");
    //cout << temp.nome << endl;
    xml.IntoElem(); // define DADOS-GERAIS como parent

    if(!xml.FindElem("ATUACOES-PROFISSIONAIS")){
        cout << "Sem ATUACOES-PROFISSIONAIS" <<endl;
        return ERROR;
    }
    if(!xml.FindChildElem("ATUACAO-PROFISSIONAL")){
        cout << "Sem ATUACAO-PROFISSIONAL" << endl;
        return ERROR;
    }
    temp->instituicao = xml.GetChildAttrib("NOME-INSTITUICAO");
    //cout << temp.instituicao << endl;
    xml.IntoElem(); // define ATUACAO-PROFISSIONAL como parent

    if(!xml.FindChildElem("ATIVIDADES-DE-PESQUISA-E-DESENVOLVIMENTO")){
        cout << "Sem linha de pesquisa" << endl;
        return ERROR;
    }
    xml.IntoElem(); //define APD como parent

    if(!xml.FindChildElem("PESQUISA-E-DESENVOLVIMENTO")){
        cout << "Sem linha de pesquisa" << endl;
        return ERROR;
    }
    xml.IntoElem(); // define PD como parent

    if(!xml.FindChildElem("LINHA-DE-PESQUISA")){
        cout << "Sem linha de pesquisa" << endl;
        return ERROR;
    }
    temp->area = xml.GetChildAttrib("TITULO-DA-LINHA-DE-PESQUISA");
    //cout << temp.area << endl;

    xml.ResetPos();


// ========= TRABALHOS EM EVENTOS ===================
    xml.FindElem("CURRICULO-VITAE"); // se passou pelo primeiro findelem(curriculo vitae)
    //passa por esse
    xml.IntoElem(); //seta CV como tag pai

    if(!xml.FindElem("PRODUCAO-BIBLIOGRAFICA")){
        cout << "Sem PRODUCAO-BIBLIOGRAFICA." << endl;
        return ERROR;
    }
    xml.IntoElem();

    if(!xml.FindElem("TRABALHOS-EM-EVENTOS")){
        cout << "Sem TRABALHOS-EM-EVENTOS." << endl;
        return ERROR;
    }
    xml.IntoElem();// define TRABALHOS-EM-EVENTOS como parent

    while(xml.FindElem()){
        Trabalho trab;
        xml.FindChildElem("DADOS-BASICOS-DO-TRABALHO");
        trab.titulo = xml.GetChildAttrib("TITULO-DO-TRABALHO");
        trab.ano = xml.GetChildAttrib("ANO-DO-TRABALHO");
        temp->pubEventos.push_back(trab);
        sizeTrab++;
    }
    temp->sizePubEventos = sizeTrab;
    xml.ResetPos();


// ========= ARTIGOS PUBLICADOS ===================
    xml.FindElem("CURRICULO-VITAE"); // se passou pelo primeiro findelem(curriculo vitae)
    //passa por esse
    xml.IntoElem(); //seta CV como tag pai

    if(!xml.FindElem("PRODUCAO-BIBLIOGRAFICA")){
        cout << "Sem PRODUCAO-BIBLIOGRAFICA." << endl;
        return ERROR;
    }
    xml.IntoElem();

    if(!xml.FindElem("ARTIGOS-PUBLICADOS")){
        cout << "Sem ARTIGOS-PUBLICADOS." << endl;
        return ERROR;
    }
    xml.IntoElem();// define ARTIGOS-PUBLICADOS como parent

    while(xml.FindElem()){
        Artigo artigo;
        xml.FindChildElem("DADOS-BASICOS-DO-ARTIGO");
        artigo.titulo = xml.GetChildAttrib("TITULO-DO-ARTIGO");
        artigo.ano = xml.GetChildAttrib("ANO-DO-ARTIGO");
        temp->pubPeriodicos.push_back(artigo);
        sizeArt++;
    }
    temp->sizePubPeriodicos = sizeArt;


    return SUCCESS;
}
