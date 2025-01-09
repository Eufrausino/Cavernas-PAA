
#include "../Headers/arquivo.h"

int main(int argc, char const *argv[])
{
 
 
    // olho se o usuario passou o nome do arquivo, se não passou, mstro como usar:
    //se passou correto vida que segue!
    if (argc != 5) {
        fprintf(stderr, "Use: %s <string-nome> <int-linha> <int-coluna> <int-vida>\n", argv[0]);
        return 1;
    }

    string nomeArquivo = (string) malloc(strlen(argv[1]) + 1);
    int linha, coluna, vida;

    strcpy(nomeArquivo, argv[1]);
    linha = atoi(argv[2]);
    coluna = atoi(argv[3]);
    vida = atoi(argv[4]);


    gerarArquivo(nomeArquivo,linha,coluna,vida);

    return 0;
}
