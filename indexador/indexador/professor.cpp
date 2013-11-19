#include <iostream>
#include <cstdio>
#include <Markup.h>
#include <string>
#include <vector>
#include <wchar.h>
#include "professor.h"

#define ERROR -1
#define SUCCESS 0
using namespace std;

int parseProfessor(string path, dadosProfessor *temp){

    CMarkup xml;
    string data;
    int nTrab = 0, nArt = 0;

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
    temp->nome = (xml.GetAttrib("NOME-COMPLETO"));
    //cout << temp.nome << endl;
    xml.IntoElem(); // define DADOS-GERAIS como parent

    if(!xml.FindElem("ATUACOES-PROFISSIONAIS")){
        cout << "Sem ATUACOES-PROFISSIONAIS" <<endl;
        //return ERROR;
    }
    if(!xml.FindChildElem("ATUACAO-PROFISSIONAL")){
        cout << "Sem ATUACAO-PROFISSIONAL" << endl;
        //return ERROR;
    }
    temp->instituicao = xml.GetChildAttrib("NOME-INSTITUICAO");
    //cout << temp.instituicao << endl;
    xml.IntoElem(); // define ATUACAO-PROFISSIONAL como parent

    if(!xml.FindChildElem("ATIVIDADES-DE-PESQUISA-E-DESENVOLVIMENTO")){
        temp->area = "Sem linha de pesquisa especificada";
        //return ERROR;
    }
    xml.IntoElem(); //define APD como parent

    if(!xml.FindChildElem("PESQUISA-E-DESENVOLVIMENTO")){
        cout << "Sem linha de pesquisa" << endl;
        temp->area = "Sem linha de pesquisa especificada";

        //return ERROR;
    }
    xml.IntoElem(); // define PD como parent

    if(!xml.FindChildElem("LINHA-DE-PESQUISA")){
        cout << "Sem linha de pesquisa" << endl;
        temp->area = "Sem linha de pesquisa especificada";

        //return ERROR;
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
        //return ERROR;
    }
    xml.IntoElem();

    if(!xml.FindElem("TRABALHOS-EM-EVENTOS")){
        cout << "Sem TRABALHOS-EM-EVENTOS." << endl;
        //return ERROR;
    }
    xml.IntoElem();// define TRABALHOS-EM-EVENTOS como parent

    while(xml.FindElem()){
        Trabalho trab;
        xml.FindChildElem("DADOS-BASICOS-DO-TRABALHO");
        trab.titulo = xml.GetChildAttrib("TITULO-DO-TRABALHO");
        trab.ano = xml.GetChildAttrib("ANO-DO-TRABALHO");
        temp->pubEventos.push_back(trab);
        nTrab++;
    }
    temp->nPubEventos = nTrab;
    xml.ResetPos();


// ========= ARTIGOS PUBLICADOS ===================
    xml.FindElem("CURRICULO-VITAE"); // se passou pelo primeiro findelem(curriculo vitae)
    //passa por esse
    xml.IntoElem(); //seta CV como tag pai

    if(!xml.FindElem("PRODUCAO-BIBLIOGRAFICA")){
        cout << "Sem PRODUCAO-BIBLIOGRAFICA." << endl;
        //return ERROR;
    }
    xml.IntoElem();

    if(!xml.FindElem("ARTIGOS-PUBLICADOS")){
        cout << "Sem ARTIGOS-PUBLICADOS." << endl;
        //return ERROR;
    }
    xml.IntoElem();// define ARTIGOS-PUBLICADOS como parent

    while(xml.FindElem()){
        Artigo artigo;
        xml.FindChildElem("DADOS-BASICOS-DO-ARTIGO");
        artigo.titulo = xml.GetChildAttrib("TITULO-DO-ARTIGO");
        artigo.ano = xml.GetChildAttrib("ANO-DO-ARTIGO");
        temp->pubPeriodicos.push_back(artigo);
        nArt++;
    }
    temp->nPubPeriodicos = nArt;


    return SUCCESS;
}


int getChavesProfessor(string path, chavesProfessor *temp)
{
    CMarkup xml;
    int nTrab = 0, nArt = 0;

    if(!xml.Load(path)){
        cout << "Erro de abertura do arquivo xml." << endl;
        return 1;
    }
    //
    //xml.FindNode(xml.MNT_PROCESSING_INSTRUCTION); // encontra a declaracao do xml
    //cout << xml.GetData() << endl;
    //cout << xml.GetAttrib("encoding") << endl; // muda o encoding
    //xml.SetAttrib( "encoding", "UTF-8" );
    //xml.Save(path);



    strcpy (temp->nomeArquivo, path.c_str());
    if (!xml.FindElem("CURRICULO-VITAE")){
        cout << "Sem CV" << endl;
        return ERROR;
    }
// ================ NOME ===================

    xml.IntoElem(); //seta CV como tag pai

    if(!xml.FindElem("DADOS-GERAIS")){
        cout << "Sem DADOS-GERAIS." << endl;
        return ERROR;
    }
    strcpy (temp->nome, xml.GetAttrib("NOME-COMPLETO").c_str());
    //cout << temp.nome << endl;
    xml.IntoElem(); // define DADOS-GERAIS como parent



    xml.ResetPos();


// ========= TRABALHOS EM EVENTOS ===================
    xml.FindElem("CURRICULO-VITAE"); // se passou pelo primeiro findelem(curriculo vitae)
    //passa por esse
    xml.IntoElem(); //seta CV como tag pai

    if(!xml.FindElem("PRODUCAO-BIBLIOGRAFICA")){
        cout << "Sem PRODUCAO-BIBLIOGRAFICA." <<temp->nome<< endl;
        return ERROR;
    }
    xml.IntoElem();

    if(!xml.FindElem("TRABALHOS-EM-EVENTOS")){
        cout << "Sem TRABALHOS-EM-EVENTOS." << endl;
        return ERROR;
    }
    xml.IntoElem();// define TRABALHOS-EM-EVENTOS como parent

    while(xml.FindElem()){
        nTrab++;
    }
    temp->nPEventos = nTrab;
    xml.ResetPos();


// ========= ARTIGOS PUBLICADOS ===================
    xml.FindElem("CURRICULO-VITAE"); // se passou pelo primeiro findelem(curriculo vitae)
    //passa por esse
    xml.IntoElem(); //seta CV como tag pai

    if(!xml.FindElem("PRODUCAO-BIBLIOGRAFICA")){
        cout << "Sem PRODUCAO-BIBLIOGRAFICA."<<temp->nome << endl;
        return ERROR;
    }
    xml.IntoElem();

    if(!xml.FindElem("ARTIGOS-PUBLICADOS")){
        cout << "Sem ARTIGOS-PUBLICADOS."<<temp->nome << endl;
        return ERROR;
    }
    xml.IntoElem();// define ARTIGOS-PUBLICADOS como parent

    while(xml.FindElem()){
        nArt++;
    }
    temp->nPPeriodicos = nArt;


    return SUCCESS;
}

bool comparaNome(const chavesProfessor &a, const chavesProfessor &b)
{
    return string (a.nome) < string (b.nome);
}

bool comparaNP(const chavesProfessor &a, const chavesProfessor &b)
{
    return a.nPPeriodicos < b.nPPeriodicos;
}

bool comparaNE(const chavesProfessor &a, const chavesProfessor &b)
{
    return a.nPEventos < b.nPEventos;
}

bool comparaNT(const chavesProfessor &a, const chavesProfessor &b)
{
    return (a.nPPeriodicos + a.nPEventos) < (b.nPPeriodicos + b.nPEventos);
}


string Informacoes(string path){
    CMarkup xml;
    string info;
    dadosProfessor *prof = new dadosProfessor;

    if(parseProfessor(path,prof) == SUCCESS)
    {
        info = prof->area + "\n\nPUBLICAÇÕES EM EVENTOS:\n";
        for (unsigned i = 0; i < prof->nPubEventos-1; i++)
            info.append("  "  + prof->pubEventos.at(i).titulo + " - (" + prof->pubEventos.at(i).ano + ")\n");
        info = info + "\n\nPUBLICAÇÕES EM PERIODICOS:\n";
        for (unsigned i = 0; i < prof->nPubPeriodicos-1; i++)
            info.append("  "  + prof->pubPeriodicos.at(i).titulo + "\n");


    }
    return info;
}


