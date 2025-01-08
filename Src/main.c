#include "../Headers/progDinamica.h"


// func de teste: 
//ta so pegando o arquivo e copiando ele pra outro arquivo
void processarMapa(const char* caminhoEntrada, const char* caminhoSaida);

int main(int argc, char* argv[]) {


    // olho se o usuario passou o nome do arquivo, se não passou, mstro como usar:
    //se passou correto vida que segue!
    if (argc != 2) {
        fprintf(stderr, "Use: %s MAPA=<nome_do_arquivo_mapa>\n", argv[0]);
        return 1;
    }
    string camihhoEntrada = (string) malloc(strlen("Lib/") + strlen(argv[1]) + strlen(".txt") + 1);
    strcpy(camihhoEntrada, "Lib/");
    strcat(camihhoEntrada, argv[1]);
    strcat(camihhoEntrada, ".txt");
    
    Mapa mapa;
    informacoes info;
    //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    int linhaF, colunaF, linhaI, colunaI;
    //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    lerArquivo(camihhoEntrada,&info,&mapa);
    
    MostrarMapa(mapa,info.linhas,info.colunas);

    printf("\n\n%d ",mapa[0][0]);
    //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

    printf("\n\nF: %d %d\nI: %d %d\n\n",info.linhaF, info.colunaF, info.linhaI, info.colunaI);

    struct celulaProgD **pd = fazMatrizProgDinamica(info);
    calcularSubproblemas(pd, mapa, info,  info.linhaF, info.colunaF, info.linhaI, info.colunaI);
    //printf("LINHA F: %d\n", pd[1][0]);
    constroiCaminho(pd, info, info.linhaF, info.colunaF, info.linhaI, info.colunaI);  

    printf("Resultado de bom!");
    return 0;
}





