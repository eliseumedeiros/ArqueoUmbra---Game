#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "GameObject.h"
#include "Retangulo.h"

Retangulo::Retangulo(){}

Retangulo::Retangulo(std::string nome, float posicao_x, float posicao_y, float velocidade_x, float velocidade_y, float atrito, float espessura, int R, int G, int B, float altura,  float largura){
	this->nome = nome;
	this->posicao_x = posicao_x;
	this->posicao_y = posicao_y;
	this->velocidade_x = velocidade_x;
	this->velocidade_y = velocidade_y;
	this->atrito = atrito;
	this->espessura = espessura;
	this->altura = altura;
	this->largura =largura;

	this->corRetangulo.R = R;
	this->corRetangulo.G = G;
	this->corRetangulo.B = B;
	// CALCULO DAS COORDENADAS DO PONTO SUPERIOR ESQUERDO E DO PONTO INFERIOR DIREITO
	this->x_superior = (this->posicao_x - (this->largura/2));
	this->y_superior = (this->posicao_y + (this->altura/2));
	this->x_inferior = (this->posicao_x + (this->largura/2));
	this->y_inferior = (this->posicao_y - (this->altura/2));
}

void Retangulo::Render(){
	this->x_superior = (this->posicao_x - (this->largura/2));
	this->y_superior = (this->posicao_y + (this->altura/2));
	this->x_inferior = (this->posicao_x + (this->largura/2));
	this->y_inferior = (this->posicao_y - (this->altura/2));
	//al_draw_rectangle( this->x_superior, this->y_superior, this->x_inferior, this->y_inferior, al_map_rgb(this->corRetangulo.R, this->corRetangulo.G, corRetangulo.B), this->espessura);
}

int Retangulo::mouseDown_Move(float x, float y, int comportamento=1){ // Verificando se o clique foi sobre esse GameObject
	if (x >= this->x_superior && y <= this->y_superior){
		if(x <= this->x_inferior && y >= this->y_inferior){
			if(comportamento == 1){
				this->corRetangulo.R = 255;
				return 1; // Se o ponteiro do mouse esta sobre esse GameObject, retorna 1
			}
			else if(comportamento == 2){
				return 1; // Se o clique foi nesse GameObject, retorna 1
			}
		}
	}
	this->corRetangulo.R = 0;

	return 0; // Retorna 0 se o mouse nao clicou nesse GameObject
}
