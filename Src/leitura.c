/**************************************************************
 * Nome do arquivo: leitura.c
 * Projeto: Caverna-PAA
 * Descrição: definições de funcionalidades para ler o Arquivo de acordo com as 
 * 
 * Autor(es): Gabriel de Pádua 
 * Data de criação: 04/01/2025
 * 
 * Histórico de versões:
 *    - v1.0 (gabriel)- 15/11/2024: criada função lerArquivo
 * 
 * Dependências:
 *    - mapa.h
 * 
 * Observações:
 *    - 
 **************************************************************/
#include "../Headers/leitura.h"

void lerArquivo(const char* nomeArquivo, ponteiroInformçaoes informacoes, ApontadorMapa mapa) {
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    // Ler a primeira linha do arquivo (dimensões e HP)
    fscanf(arquivo, "%d %d %d\n", &informacoes->linhas, &informacoes->colunas, &informacoes->HP);

    // Criar o mapa com base nas dimensões
    CriaMapa(mapa, informacoes->linhas, informacoes->colunas);

    // Ler as linhas restantes do arquivo e preencher o mapa
    char linha[1000]; // Buffer para armazenar a linha do arquivo
    for (int i = 0; i < informacoes->linhas; i++) {
        // Ler uma linha inteira do arquivo
        if (fgets(linha, sizeof(linha), arquivo) != NULL) {
            // Remover a quebra de linha, se presente
            linha[strcspn(linha, "\n")] = '\0';

            // Processar os valores da linha
            int coluna = 0;
            char* token = strtok(linha, " ");
            while (token != NULL) {
                // Verificar se o valor é um caractere ou número
                if (token[0] == 'F' || token[0] == 'I') {
                    (*mapa)[i][coluna] = token[0]; // Armazenar caracteres
                } else {
                    (*mapa)[i][coluna] = atoi(token); // Converter strings numéricas em inteiros
                }
                coluna++;
                token = strtok(NULL, " ");
            }

            // Verificação de segurança para número de colunas
            if (coluna != informacoes->colunas) {
                printf("Aviso: Linha %d tem número inesperado de colunas (%d em vez de %d).\n", 
                        i + 1, coluna, informacoes->colunas);
            }
        } else {
            printf("Erro ao ler a linha %d do arquivo.\n", i + 1);
        }
    }

    fclose(arquivo);

    // Exibir o mapa
    // if (mapa != NULL) {
    //     MostrarMapa(*mapa, informacoes->linhas, informacoes->colunas);
    // }

    printf("Mapa lido com sucesso!\n");
}
