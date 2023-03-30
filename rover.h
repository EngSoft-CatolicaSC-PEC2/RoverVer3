//
// Created by dvw on 27/03/23.
//

#ifndef MULTIEXAMPLE_ROVER_H
#define MULTIEXAMPLE_ROVER_H

#define DIREITA 'D'
#define ESQUERDA 'E'
#define CIMA 'C'
#define BAIXO 'B'
#define MOVIMENTO_FINAL  10
#define MOVIMENTO_SUCESSO  1
#define MOVIMENTO_ERROR  -1
#define MOVIMENTO_LINHA_ERRADA  -2
extern int roverLinha;
extern int roverColuna;
extern int destinoLinha;
extern int destinoColuna;

int roverMoverLinha();
int roverMoverMatriz();
int roverMoverMatrizBloqueio();


int roverMover(char);
int roverMoverBloqueio(char);
int roverGirarRobo(char);
int roverLerMapa(char);

void roverSetInicio(int, int);
void roverSetDestino(int, int);
void roverFazerRastro();
int ehLimiteDiretoMapa();
int ehLimiteEsquerdoMapa();
int ehLimiteSuperiorMapa();
int ehLimiteInferiorMapa();
int encontrouFinal();



#endif //MULTIEXAMPLE_ROVER_H
