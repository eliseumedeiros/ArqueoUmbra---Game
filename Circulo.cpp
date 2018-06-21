#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "GameObject.h"
#include "Circulo.h"

Circulo::Circulo(std::string nome, float posicao_x, float posicao_y, float velocidade_x, float velocidade_y, float atrito, float raio, float espessura, int R, int G, int B){
	this->nome = nome;
	this->posicao_x = posicao_x;
	this->posicao_y = posicao_y;
	this->velocidade_x = velocidade_x;
	this->velocidade_y = velocidade_y;
	this->atrito = atrito;
	this->raio = raio;
	this->espessura = espessura;
	this->corCirculo.R = R;
	this->corCirculo.G = G;
	this->corCirculo.B = B;
}

void Circulo::Render(){
	//al_draw_circle(this->posicao_x , this->posicao_y, this->raio, al_map_rgb(this->corCirculo.R, this->corCirculo.G, this->corCirculo.B), 3);
}

int Circulo::mouseDown_Move(float x, float y, int comportamento){ // Verificando se o evento do mouse foi sobre esse GameObject. x, y indicam onde houve o evento e comportamento indica se o evento analisado é o clique ou apenas o passar do ponteiro sobre um gameobject
	if (x >= this->posicao_x - this->raio && x <= this->posicao_x + this->raio)
		if(y >= this->posicao_y - this->raio && y <= this->posicao_y + this->raio)
			if(comportamento == 1){ // O numero > 1 < indica acao a ser realizada se o evento analisado for o passar do ponteiro do mouse sobre um GameObject
				return 1; // Se o ponteiro do mouse esta sobre esse GameObject, retorna 1
			}
			else if(comportamento == 2){ // O numero > 2 < indica acao a ser realizada se o evento analisado for clique do mouse
				return 1; // Se o clique foi nesse GameObject, retorna 1
			}
	return 0; // Retorna 0 se o mouse nao clicou nesse GameObject
}
