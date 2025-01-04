#ifndef LEITURA_H
#define LEITURA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Headers/mapa.h"

//------------------------Estruturas---------------------------
typedef struct informacoes
{
    int linhas;
    int colunas;
    int HP;

}informacoes;

typedef informacoes *ponteiroInformçaoes;
typedef char* string;

//------------------------Funções---------------------------
void lerArquivo(const char* nomeArquivo, ponteiroInformçaoes informacoes, ApontadorMapa mapa);


#endif