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
    
    //nome da saida tem q ser sempre assim: 
    const char* caminhoSaida = "resultado.txt";


    //teste
    processarMapa(camihhoEntrada, caminhoSaida);
    //teste 
    
    printf("Resultado salvo em: %s\n", caminhoSaida);
    return 0;
}


void processarMapa(const char* caminhoEntrada, const char* caminhoSaida) {
    // Abre o arquivo de entrada
    FILE* arquivoEntrada = fopen(caminhoEntrada, "r");
    if (arquivoEntrada == NULL) {
        perror("Erro ao abrir arquivo de entrada");
        exit(1);
    }

    // Cria o arquivo de saída
    FILE* arquivoSaida = fopen(caminhoSaida, "w");
    if (arquivoSaida == NULL) {
        perror("Erro ao criar arquivo de saída");
        fclose(arquivoEntrada);
        exit(1);
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), arquivoEntrada)) {
        // Apenas copia as linhas do mapa para o arquivo de saída
        fprintf(arquivoSaida, "%s", linha);
    }

    fclose(arquivoEntrada);
    fclose(arquivoSaida);
}


