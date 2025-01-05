
#include "../Headers/leitura.h"

int main(int argc, char const *argv[])
{
    Mapa mapa;
    informacoes info;
    lerArquivo("Lib/test.txt",&info,&mapa);


    MostrarMapa(mapa,info.linhas,info.colunas);

    printf("\n\n%d ",mapa[0][0]);

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
