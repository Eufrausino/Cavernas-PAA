#include "../Headers/tempoExecucao.h"

int main(int argc, char const *argv[])
{

    if (argc != 2) {
        fprintf(stderr, "Use: %s MAPA=<nome_do_arquivo_mapa>\n", argv[0]);
        return 1;
    }
    string camihhoEntrada = (string) malloc(strlen("Lib/") + strlen(argv[1]) + strlen(".txt") + 1);
    strcpy(camihhoEntrada, "Lib/");
    strcat(camihhoEntrada, argv[1]);
    strcat(camihhoEntrada, ".txt");

    //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    //programa pra calcular o tempo normalmente ai em baxo: 
    //faz o rodar o tempo com o caminho de entrada, pq ai vai funcionar medir o tempo com qualquer mapa: 
    



    return 0;
}
