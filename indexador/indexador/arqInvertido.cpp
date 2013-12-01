#include <fstream>
#include <string>
#include <stdio.h>
#include "Markup.h"
#include "professor.h"

#define XMLINDEX "files.txt"
#define COAUTORESPATH "coautores.txt"

void coAutores(){

    CMarkup xml;
    string xmlPath, artigo;
    ifstream Fchaves(XMLINDEX);
    ofstream FCoAutores(COAUTORESPATH);

    if(Fchaves.is_open()){
        while(getline(Fchaves, xmlPath)){ // para cada arquivo xml, pega o nome dos co Autores
            xml.Load(xmlPath);
            cout << xmlPath << endl;
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

            while(xml.FindElem("TRABALHO-EM-EVENTOS")){
                xml.FindChildElem("DADOS-BASICOS-DO-TRABALHO");
                artigo = xml.GetChildAttrib("TITULO-DO-TRABALHO");
                cout << artigo << endl << endl;
                FCoAutores << artigo << endl;
                while(xml.FindChildElem("AUTORES")){
                    cout << xml.GetChildAttrib("NOME-COMPLETO-DO-AUTOR") << endl;
                    FCoAutores << xml.GetChildAttrib("NOME-COMPLETO-DO-AUTOR") << ',';
                }
                cout << endl;
                FCoAutores << endl << endl;

            }
        }
    }

    Fchaves.close();
    FCoAutores.close();


}
