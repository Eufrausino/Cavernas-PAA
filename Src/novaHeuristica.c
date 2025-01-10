#include "../Headers/novaHeuristica.h"


int mValor(int a, int b, int c){
    int maior = (a > b) ? a : b;
    return maior = (maior > c) ? maior : c; 
}

resultado melhorPosicao(Mapa mapa,posicao atual,int linhaFinal,int colunaFinal){
    
    resultado r;

    //se tem como ir pra tres direçoes :
    if (atual.x > linhaFinal && atual.y > colunaFinal){
        int a = mapa[atual.x-1][atual.y];//cima
        int b = mapa[atual.x][atual.y-1];//esquerda 
        int c = mapa[atual.x-1][atual.y-1];//noroeste

        int melhorValor = (a > b) ? a : b;
        melhorValor = (melhorValor > c) ? melhorValor : c;

        if(melhorValor == a){
            r.pos.x = atual.x-1;
            r.pos.y = atual.y;
            r.valor = a;
        }else if(melhorValor == b){
            r.pos.x = atual.x;
            r.pos.y = atual.y-1;
            r.valor = b;
        }else{
            r.pos.x = atual.x-1;
            r.pos.y = atual.y-1;
            r.valor = c;
        }

    }
    
    //se tem como ir para esquerda
    if (atual.x == linhaFinal && atual.y > colunaFinal){
            int b = mapa[atual.x][atual.y-1];//esquerda 
            r.pos.x = atual.x;
            r.pos.y = atual.y-1;
            r.valor = b;
        }
    
    //se tem como ir para cima
    if (atual.x > linhaFinal && atual.y == colunaFinal){
        int a = mapa[atual.x-1][atual.y];//cima
        r.pos.x = atual.x-1;
        r.pos.y = atual.y;
        r.valor = a;
 
    }

    return r;
}

void progamaçaoD(Mapa mapa,informacoes info,caminhando aluno){

    
    //posiçao inicial do aluno
    aluno.pos.x = info.linhaI;
    aluno.pos.y = info.colunaI;

    //lista de posiçoes que ele ja passou
    ponteiroLista lista = criaLista(aluno.pos);

    resultado proximaPosicao;

int i = 1;//vai sair 


    //vou fazer o trajeto enquanto a vida dele for positiva e X e Y forem diferentes do final
    while(info.HP > 0 && aluno.pos.x != info.linhaF && aluno.pos.y != info.colunaF){

        proximaPosicao = melhorPosicao(mapa,aluno.pos,info.linhaF,info.colunaF);

        //atualizar a posiçao do aluno
        aluno.pos.x = proximaPosicao.pos.x;
        aluno.pos.y = proximaPosicao.pos.y;

        //inserir a posiçao na lista
        insereLista(lista,aluno.pos);

        //"somar" resultado à vida do aluno se nao for uma letra
        if (proximaPosicao.valor != 'F' && proximaPosicao.valor != 'I'){
            info.HP += proximaPosicao.valor;
        }
        

        printf("\n\n");
        printf("posição do aluno na iteração %d: X: %d Y: %d\n",i,aluno.pos.x,aluno.pos.y);
        printf("valor a ser somado na iteração %d: %d\n",i,proximaPosicao.valor);
        printf("HP do aluno na iteração %d: %d\n",i,info.HP);
        printf("\n\n");
        
        i++;

    }

    //verifica se ele morreu
    if(info.HP <= 0){
        printf("O aluno morreu\n");
    }

    //verifica se ele chegou ao final
    if(info.HP >10 && aluno.pos.x == info.linhaF && aluno.pos.y == info.colunaF){
        printf("O aluno chegou ao final\n");
    }

    printf("Vida do aluno: %d\n",info.HP);


    //imprimir a lista de posiçoes
    printf("\n\n\nLista de posições:\n");
    imprimeLista(lista);
}



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
    
    Mapa mapa;
    informacoes info;
    caminhando aluno;
    lerArquivo(camihhoEntrada, &info,&mapa);

    MostrarMapa(mapa, info.linhas, info.colunas);

    progamaçaoD(mapa,info,aluno);





    return 0;
}
