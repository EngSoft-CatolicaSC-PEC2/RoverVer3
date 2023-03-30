

#include <stdio.h>
#include "mapa.h"
#include "rover.h"

int roverLinha = 0;
int roverColuna = 0;
int destinoLinha = 0;
int destinoColuna = 0;

int roverMoverMatrizBloqueio(){
    if (roverColuna < destinoColuna) {
        return roverMoverBloqueio(DIREITA);
    } else if (roverColuna > destinoColuna) {
        return roverMoverBloqueio(ESQUERDA);
    }else if (roverLinha < destinoLinha) {
        return roverMoverBloqueio(BAIXO);
    } else if (roverLinha > destinoLinha) {
        return roverMoverBloqueio(CIMA);
    }
}

int roverMoverMatriz() {
    if (roverColuna < destinoColuna) {
        return roverMover(DIREITA);
    } else if (roverColuna > destinoColuna) {
        return roverMover(ESQUERDA);
    }else if (roverLinha < destinoLinha) {
        return roverMover(BAIXO);
    } else if (roverLinha > destinoLinha) {
        return roverMover(CIMA);
    }
}

int roverMoverLinha() {

    if (roverLinha != destinoLinha) {
        return MOVIMENTO_LINHA_ERRADA;
    } else if (roverColuna < destinoColuna) {
        return roverMover(DIREITA);
    } else if (roverColuna > destinoColuna) {
        return roverMover(ESQUERDA);
    } else {
        return MOVIMENTO_FINAL;
    }
}


int roverLerMapa(char comando){
    if (comando == DIREITA && ehLimiteDiretoMapa() != 0) {
        return mapaLer(roverLinha,roverColuna+1);
    } else if (comando == ESQUERDA && ehLimiteEsquerdoMapa() != 0) {
        return mapaLer(roverLinha,roverColuna-1);
    } else if (comando == CIMA && ehLimiteSuperiorMapa() != 0) {
        return mapaLer(roverLinha-1,roverColuna);
    } else if (comando == BAIXO && ehLimiteInferiorMapa() != 0) {
        return mapaLer(roverLinha+1,roverColuna);
    } else {
        return INVALIDO;
    }
}

void roverSetInicio(int linha, int coluna) {
    roverLinha = linha;
    roverColuna = coluna;
    roverFazerRastro();
}

void roverSetDestino(int linha, int coluna) {
    destinoLinha = linha;
    destinoColuna = coluna;
    mapaMarcar(linha, coluna, DESTINO);
}


int roverMoverBloqueio(char comando) {
    char infoMapa = roverLerMapa(comando);
    if(infoMapa == INVALIDO || infoMapa == BLOQUEIO || infoMapa == RASTRO)
    {
        comando = roverGirarRobo(comando);
        return roverMoverBloqueio(comando);
    }
    return roverMover(comando);

}

int roverGirarRobo (char comando){
    if(comando == DIREITA)
        if(ehLimiteInferiorMapa() != 0)
            return BAIXO;
        else
            return CIMA;
    if(comando == BAIXO)
        if(ehLimiteEsquerdoMapa() != 0)
            return ESQUERDA;
        else
            return DIREITA;
    if(comando == ESQUERDA)
        if(ehLimiteSuperiorMapa() != 0)
            return CIMA;
        else
            return BAIXO;
    if(comando == CIMA)
        if(ehLimiteDiretoMapa() != 0)
            return DIREITA;
        else
            return ESQUERDA;
}

int roverMover(char comando) {
    if (comando == DIREITA && ehLimiteDiretoMapa() != 0) {
        roverColuna++;
    } else if (comando == ESQUERDA && ehLimiteEsquerdoMapa() != 0) {
        roverColuna--;
    } else if (comando == CIMA && ehLimiteSuperiorMapa() != 0) {
        roverLinha--;
    } else if (comando == BAIXO && ehLimiteInferiorMapa() != 0) {
        roverLinha++;
    } else {
        return MOVIMENTO_ERROR;
    }
    roverFazerRastro();

    if (encontrouFinal() != 0) {
        return MOVIMENTO_FINAL;
    } else {
        return MOVIMENTO_SUCESSO;
    }
}

int encontrouFinal() {
    return roverColuna == destinoColuna && roverLinha == destinoLinha;
}

int ehLimiteDiretoMapa() {
    return roverColuna < TAM_MAPA-1;
}

int ehLimiteEsquerdoMapa() {
    return roverColuna > 0;
}

int ehLimiteSuperiorMapa() {
    return roverLinha > 0;
}

int ehLimiteInferiorMapa() {
    return roverLinha < TAM_MAPA-1;
}

void roverFazerRastro() {
    mapaMarcar(roverLinha, roverColuna, RASTRO);
}