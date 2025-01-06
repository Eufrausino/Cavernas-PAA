/**************************************************************
 * Nome do arquivo: mapa.c
 * Projeto: Labirinto-PAA
 * Descrição: prototipos e declarações de funções e tipos abstratos de dados. 
 * 
 * Autor(es): Gabriel de Pádua
 * Data de criação: 15/11/2024
 *
 * Histórico de versões:
 *    - v1.0 (gabriel)- 15/11/2024: criado cabeçalho de funçoes criar mapa e apagar mapa
 *    - v1.1 (gabriel)- 16/11/2014: criada cabeçalho de funções mostrar mapa e preencher mapa
 *    - v1.2 (matheus)- 20/11/2024: criado função de leitura de arquivo para o labirinto
 * 
 * Dependências:
 *    - stdio.h
 *    - stdlib.h
 *    - coordenadas.h
 *    - estudante.h
 *    - utilites.h
 *     
 * 
 * Observações:
 *    - 
 **************************************************************/
#ifndef MAPA_H
#define MAPA_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//-------------------Renomeando tipos de dados-------------------
typedef int*** ApontadorMapa;// apontador de matriz de inteiros
typedef int** Mapa; // matriz de inteiros 
//Antes era char

//-------------------Protótipos de funções-------------------
void CriaMapa(ApontadorMapa mapa, int linhas, int colunas);
void ApagaMapa(ApontadorMapa mapa, int linhas);
void MostrarMapa(Mapa mapa, int linhas, int colunas);
void PreencherMapa(ApontadorMapa mapa, int posicacaoLinha, char valores[],int qtdColunas);
void EncontraIeF(Mapa mapa, int linhas, int colunas, int *linhaF, int *colunaF, int *linhaI,int *colunaI);

#endif
