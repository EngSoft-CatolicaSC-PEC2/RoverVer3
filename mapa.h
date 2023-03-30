//
// Created by dvw on 27/03/23.
//

#ifndef MULTIEXAMPLE_MAPA_H
#define MULTIEXAMPLE_MAPA_H


#define TAM_MAPA 8
#define DESTINO 'D'
#define RASTRO 'R'
#define BLOQUEIO 'B'
#define TERRENO '*'
#define INVALIDO 'I'

extern char mapa[TAM_MAPA][TAM_MAPA];

void mapaCarregar();
void mapaMarcar(int, int, char);
void mapaImprimir();
char mapaLer(int , int );


#endif //MULTIEXAMPLE_MAPA_H
