#include "../Headers/leitura.h"
#include "../Headers/prog_dinamica.h"
#include "../Headers/mapa.h"

int main(int argc, char const *argv[])
{
    Mapa mapa;
    informacoes info;
    //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    int linhaF, colunaF, linhaI, colunaI;
    //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    lerArquivo("Lib/test.txt",&info,&mapa);
    MostrarMapa(mapa,info.linhas,info.colunas);

    printf("\n\n%d ",mapa[0][0]);
    //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    EncontraIeF(mapa, info.linhas, info.colunas, &linhaF, &colunaF, &linhaI, &colunaI);
    printf("%d, %d, %d, %d\n\n",linhaF, colunaF, linhaI, colunaI);

    struct celulaProgD **pd = fazMatrizProgDinamica(info);
    calcularSubproblemas(pd, mapa, info,  linhaF, colunaF, linhaI, colunaI);
    printf("LINHA F: %d\n", pd[1][0]);
    constroiCaminho(pd, info, linhaF, colunaF, linhaI, colunaI);
    //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    // teste de conversao ASCII
    // char c;
    // printf("Digite um caractere: ");
    // scanf("%c",&c);
    // printf("valor de %c em ASCII: %d\n",c,c);



    // printf("Digite um número: ");
    // int n;
    // scanf("%d",&n);
    // printf("valor de %d em ASCII: %c\n",n,n);
    return 0;
}
