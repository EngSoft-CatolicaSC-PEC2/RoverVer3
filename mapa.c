//
// Created by dvw on 27/03/23.
//

#include <stdio.h>

#include "mapa.h"

int contaImpressao = 0;
char mapa[TAM_MAPA][TAM_MAPA];

void mapaMarcar(int linha, int coluna, char marca)
{
    mapa[linha][coluna] = marca;
}

char mapaLer(int linha, int coluna)
{
    return mapa[linha][coluna];
}

void mapaCarregar()
{
    contaImpressao = 0;
    for (int linha = 0; linha < TAM_MAPA; linha++)
    {
        for (int coluna = 0; coluna < TAM_MAPA; coluna++)
        {
            mapa[linha][coluna] = TERRENO;
        }
    }
}

void mapaImprimir()
{
    contaImpressao++;
    printf("\nPrint:%d\n",contaImpressao);
    for (int linha = 0; linha < TAM_MAPA; linha++)
    {
        for (int coluna = 0; coluna < TAM_MAPA; coluna++)
        {
            printf("%c ", mapa[linha][coluna]);
        }
        printf("\n"); // Quebra de linha
    }
}
