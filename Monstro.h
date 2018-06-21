#ifndef MONTRO_H
#define MONSTRO_H
#include "Personagem.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>

void implementa_montro (Personagem *mau1, GameObject *mau_aux, float hx = 0.0f, float hy = 0.0f){

    mau1->velocidade_y = 0;
    mau1->velocidade_x = 0;
    mau_aux->velocidade_y = 0;
    mau_aux->velocidade_x = 0;

    float ang, h, dpm, aux;

    h = sqrt((mau1->posicao_x - hx)*(mau1->posicao_x - hx) + (mau1->posicao_y - hy)*(mau1->posicao_y - hy));
    dpm = mau1->posicao_y - hy;
    aux = dpm/h;
    aux = asin(aux);

if(mau1->posicao_x <hx){
    mau1->velocidade_y -= 1.3*sin(aux);
    mau1->velocidade_x += 1.3*cos(aux);
}

else{
    mau1->velocidade_y -= 1.3*sin(aux);
    mau1->velocidade_x -= 1.3*cos(aux);
}
    mau_aux->velocidade_y = mau1->velocidade_y;
    mau_aux->velocidade_x = mau1->velocidade_x;


    /*
    int random_velocidade;

   // srand = time(NULL);

    random_velocidade=rand()%4;


    if(random_velocidade==1){
        mau1->velocidade_x+=2;
        mau_aux->velocidade_x+=2;
    }
    else if(random_velocidade==2){
        mau1->velocidade_x -=2;
        mau_aux->velocidade_x -=2;
    }
    else if(random_velocidade==3){
        mau1->velocidade_y +=2;
        mau_aux->velocidade_y +=2;

    }
    else if(random_velocidade==4){
        mau1->velocidade_y -=2;
        mau_aux->velocidade_y -=2;

    }
    */
}

#endif // MONTRO_H
