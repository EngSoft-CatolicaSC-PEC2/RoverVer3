#include <stdio.h>
#include "mapa.h"
#include "rover.h"

void exercicio2_1();
void exercicio2_2();
void exercicio2_3();
void exibirResultadoFinal(int);
int menu();

int main() {
    menu();
}

void exercicio2_1()
{
    printf("\n Exercício 2-1\n");
    printf("\n Procura em uma mesma linha 2-1\n");

    mapaCarregar();
    roverSetInicio(2,1);
    roverSetDestino(2,7);

    mapaImprimir();

    int resultadoMovimento =0;
    do
    {
        resultadoMovimento = roverMoverLinha();
        mapaImprimir();
    } while (resultadoMovimento != MOVIMENTO_FINAL && resultadoMovimento != MOVIMENTO_LINHA_ERRADA)  ;
    exibirResultadoFinal(resultadoMovimento);

}


void exercicio2_2()
{
    printf("\n Exercício 2-2\n");

    mapaCarregar();
    roverSetInicio(7,7);
    roverSetDestino(1,1);

    mapaImprimir();

    int resultadoMovimento =0;
    do
    {
        resultadoMovimento = roverMoverMatriz();
        mapaImprimir();
    } while (resultadoMovimento != MOVIMENTO_FINAL)  ;
    exibirResultadoFinal(resultadoMovimento);
}

void exercicio2_3()
{
    printf("\n Exercício 2-2\n");

    mapaCarregar();
    roverSetInicio(0,0);
    roverSetDestino(0,7);
    mapaMarcar(0,2,BLOQUEIO);
    mapaMarcar(1,2,BLOQUEIO);
    mapaMarcar(2,2,BLOQUEIO);
    mapaMarcar(3,2,BLOQUEIO);
    mapaMarcar(4,2,BLOQUEIO);
    mapaMarcar(4,1,BLOQUEIO);
    mapaMarcar(6,1,BLOQUEIO);
    mapaMarcar(7,1,BLOQUEIO);
    mapaMarcar(6,4,BLOQUEIO);
    mapaMarcar(7,6,BLOQUEIO);
    mapaMarcar(2,0,BLOQUEIO);

    mapaImprimir();

    int resultadoMovimento =0;
    do
    {
        resultadoMovimento = roverMoverMatrizBloqueio();
        mapaImprimir();
    } while (resultadoMovimento != MOVIMENTO_FINAL)  ;

    exibirResultadoFinal(resultadoMovimento);
}

void exibirResultadoFinal(int resultadoMovimento){
    if(resultadoMovimento == MOVIMENTO_FINAL)
    {
        printf("\n\nSUCESSO! \n - Rover chegou em Linha: %d  e  Coluna: %d", roverLinha, roverColuna);
        printf("\n - Destino  Linha: %d  e  Coluna: %d\n", destinoLinha, destinoLinha);
    }
    else if(resultadoMovimento == MOVIMENTO_LINHA_ERRADA)
    {
        printf("\n\nFALHA - Linha errada! \n - Rover está em Linha: %d  e  Coluna: %d", roverLinha, roverColuna);
        printf("\n - Destino  Linha: %d  e  Coluna: %d\n", destinoLinha, destinoLinha);
    }
}


int menu(){
    int opcao=1;

    do
    {
        printf("\n\nEscolha o exercício:\n\n");
        printf("1. Exercício 1 - procura em linha\n");
        printf("2. Exercicio 2 - procura na mapa\n");
        printf("3. Exercícios 3 e 4 - procura com bloqueio\n");
        printf("0. Sair\n");
        scanf("%d", &opcao);
        switch(opcao)
        {
            case 1:
                exercicio2_1();
                break;

            case 2:
                exercicio2_2();
                break;

            case 3:
                exercicio2_3();
                break;

            case 0:
                break;

            default:
                printf("Digite a opção:\n");
        }
    } while(opcao != 01);
}