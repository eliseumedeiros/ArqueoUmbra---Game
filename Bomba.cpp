#include <iostream>
#include <string>
#include "Bomba.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

using namespace std;

Bomba::Bomba(){
    this->conta_frame  = 1;
    this->existe_bomba = false;
    this->explodir = false;
    this->imagens[0] = al_load_bitmap("img/bomba0.png");  // Caminho da imagem 1 passado para a primeira posicao do vetor de imagens
    this->imagens[1] = al_load_bitmap("img/explosao0.png");
}

void Bomba::Put_bomba(int x, int y){
    this->x = x;
    this->y = y;
    //al_draw_circle(x , y, 10, al_map_rgb(255, 0, 0), 3);
    this->existe_bomba = true;

}
void Bomba::checar_explosao(){
     if(this->conta_frame/60== TEMPO_EXPLOSAO){
                this->explodir = true;
                std::cout<<"Explodiu"<<std::endl;
            }
}
void Bomba::explode(){
    this->conta_frame = 1;
    this->explodir = false;
    this->explodindo =true;
}

void Bomba::update(){
    this->conta_frame+=1;
}

void Bomba::Render(){
    if(existe_bomba && !explodindo){
       // al_draw_circle(this->x , this->y, 60, al_map_rgb(255, 0, 0), 3);
        al_draw_bitmap(this->imagens[0], this->x - 35/2, this->y- 34/2, 0); // Para baixo, imagens 8 e 9
        return;
    }
    if(existe_bomba && explodindo && this->conta_frame/60 < 1){
        al_draw_bitmap(this->imagens[1], this->x - 90/2, this->y- 77/2, 0); // Para baixo, imagens 8 e 9
        conta_frame++;
        return;
    }
    this->explodindo = false;
    this->existe_bomba = false;

}
