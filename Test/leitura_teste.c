
#include "../Headers/leitura.h"

int main(int argc, char const *argv[])
{
    Mapa mapa;
    informacoes info;
    //lerAquivo("test.txt",&info,&mapa);
    lerArquivo("Lib/test.txt",&info,&mapa);
    return 0;
}
