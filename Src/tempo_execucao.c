#include "../Headers/progDinamica.h"
#include <time.h>

int main(int argc, char* argv[]) {
    
    char* caminhoEntrada = "../Lib/teste_tempo";
    Mapa mapa;
    informacoes info;

    // Gerar arquivo de teste a cada execução
    gerarArquivo(caminhoEntrada, 10, 10, 40);

    lerArquivo("Lib/teste_tempo.txt", &info, &mapa);
    MostrarMapa(mapa, info.linhas, info.colunas);

    printf("\n\n%d ", mapa[0][0]);
    printf("\n\nF: %d %d\nI: %d %d\n\n", info.linhaF, info.colunaF, info.linhaI, info.colunaI);

    struct celulaProgD** pd = fazMatrizProgDinamica(info);

    // Medir tempo para calcularSubproblemas + constroiCaminho
    clock_t inicio = clock();  // Marca o início

    calcularSubproblemas(pd, mapa, info, info.linhaF, info.colunaF, info.linhaI, info.colunaI);
    constroiCaminho(pd, info, info.linhaF, info.colunaF, info.linhaI, info.colunaI);

    clock_t fim = clock();  // Marca o fim

    double tempoExecucao = (double)(fim - inicio) / CLOCKS_PER_SEC; // Calcula em segundos

    printf("\n\n");
    printf("Dimensoes da matriz: %d x %d\n", info.linhas, info.colunas);
    printf("Tempo de execucao: %.6f segundos\n", tempoExecucao);
    printf("\n\n");

    free(caminhoEntrada);
    return 0;
}