/*
 * prog_dinamica.c
 *
 *  Created on: 4 de jan. de 2025
 *      Author: nalu
 */

#include "../Headers/prog_dinamica.h"

struct celulaProgD **fazMatrizProgDinamica(informacoes inf){
	struct celulaProgD **progD;
	progD = (struct celulaProgD **)malloc(inf.linhas * sizeof(struct celulaProgD *));
	for (int i = 0; i < inf.linhas; i++) {
	    progD[i] = (struct celulaProgD *)malloc(inf.colunas * sizeof(struct celulaProgD));
	    for (int j = 0; j < inf.colunas; j++) {
	    	progD[i][j].pv = 0;  // Inicializa o valor como o zero
	    	progD[i][j].letra = 'x';  // Inicializa a letra como valor padrão
	    	progD[i][j].posiX = i;
	    	progD[i][j].posiY = j;
	    }
	}
	return progD;
}

int maiorValor(int valor1, int valor2){
	int maior;
	if(valor1 > valor2){
		maior = valor1;
	}
	else if(valor1 <= valor2){
		maior = valor2;
	}
	return maior;
}


struct celulaProgD maiorCelula(struct celulaProgD valor1, struct celulaProgD valor2){
	struct celulaProgD maior;
	if(valor1.pv > valor2.pv){
		maior = valor1;
	}
	else if(valor1.pv <= valor2.pv){
		maior = valor2;
	}
	return maior;
}


void calcularSubproblemas(struct celulaProgD **progD, Mapa mapa, informacoes inf, int linhaF, int colunaF, int linhaI, int colunaI){
	//progD[linhaI][colunaI].pv = inf.HP; // posi de I
	//printf("AMEIXA I: %d\n", inf.HP);
	progD[linhaI][colunaI].letra = 'I';
	progD[linhaF][colunaF].pv = 0;
	progD[linhaF][colunaF].letra = 'F';
	int i, j;
	for(i = inf.linhas - 1; i >= 0; i--){
		for(j = inf.colunas - 1; j >= colunaF; j--){
			if(i == linhaI){ //se for a ultima linha do labirinto!
				if(progD[i][j].letra == 'I'){
					progD[i][j].pv = inf.HP + progD[i][j].pv;
					//printf("pv: %d\n ", progD[i][j].pv );
				}
				else if(progD[i][j].letra == 'F'){
					progD[i][j].pv = 0 + progD[i][j+1].pv;
					break;
				}
				else{
					progD[i][j].pv = mapa[i][j] + progD[i][j+1].pv;
					//printf("pv: %d\n ", progD[i][j].pv );
				}
			}
			else if(j == inf.colunas - 1){
				if(progD[i][j].letra == 'F'){
					progD[i][j].pv = 0 + progD[i+1][j].pv;
					break;
				}
				progD[i][j].pv = mapa[i][j] + progD[i+1][j].pv;
				//printf("pv: %d\n ", progD[i][j].pv );
			}
			else{
				if(progD[i][j].letra == 'F'){
					progD[i][j].pv = 0 + maiorValor(progD[i+1][j].pv, progD[i][j+1].pv);
					break;
				}
				progD[i][j].pv = mapa[i][j] + maiorValor(progD[i+1][j].pv, progD[i][j+1].pv);
				//printf("pv: %d\n ", progD[i][j].pv );
			}
		//printf("pv: %d\n ", progD[i][j].pv );
		
		}
		if(progD[i][j].letra == 'F') break;
	}
	//printf("UVA PV:%d\n", progD[linhaF][colunaF].pv);
}

int verificaPontosDeVidaFinal(struct celulaProgD **progD, int linhaF, int colunaF){
	//linhaF e colunaF são as coordenadas onde se enconta F
	printf("PV:%d\n", progD[linhaF][colunaF].pv);
	if(progD[linhaF][colunaF].pv <= 0){
		printf("Não eh possivel sair do labirinto! :(\n");
		
		return -1;
	}
	else{
		printf("Parabéns! Voce saiu do labirinto com %d pontos!\n",progD[linhaF][colunaF].pv);
		return progD[linhaF][colunaF].pv;
	}
}



void constroiCaminho(struct celulaProgD **progD, informacoes inf, int linhaF, int colunaF, int linhaI, int colunaI){
	int totalPontosDeVida = verificaPontosDeVidaFinal(progD, linhaF, colunaF);

	FILE* resultado;
	resultado = fopen("Out/resultado.txt", "w");
	if(resultado == NULL)
	{
		printf("Arquivo inexistente!\n");
		exit(1);
	}

	else
	{
		if(totalPontosDeVida > 0){ //indica que o problema tem solução
			struct celulaProgD maior;
			for(int i = inf.linhas - 1; i >= linhaF; i--){
				for(int j = inf.colunas - 1; j >= colunaF; j--){
					
					if(i == linhaI && j == colunaI){ //se for a posição do I
						fprintf(resultado,"%d %d\n", i, j);
						maior = (maiorCelula(progD[i-1][j], progD[i][j-1]));
					}
					
					else if(i == maior.posiX && j == maior.posiY){
						maior = (maiorCelula(progD[i-1][j], progD[i][j-1]));
						fprintf(resultado,"%d %d\n", i , j);
					}
				}
			}
		}
		else fprintf(resultado, "impossível\n");
	}
	fclose(resultado);
}



