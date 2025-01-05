/**************************************************************
 * Nome do arquivo: mapa.c
 * Projeto: Caverna-PAA
 * Descrição: prototipos e declarações de funções e tipos abstratos de dados. 
 * 
 * Autor(es): Gabriel de Pádua
 * Data de criação: 04/01/2025
 *
 * Histórico de versões:
 *    - v1.0 (gabriel)- 04/01/2025: criado cabeçalho de função lerArquivo e estrutura de informaçoes 
 * 
 * Dependências:
 *    - stdio.h
 *    - stdlib.h
 *    - string.h
 *    - mapa.h
 *     
 * 
 * Observações:
 *    - 
 **************************************************************/
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