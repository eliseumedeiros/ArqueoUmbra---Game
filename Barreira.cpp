#include <iostream>
#include <string>
#include <sstream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include "GameObject.h"
#include "Retangulo.h"
#include "Barreira.h"
using namespace std;

Barreira::Barreira(std::string nome, float posicao_x, float posicao_y,  float altura, float largura, std::string diretorio, std::string nome_img, std::string extensao_img, int qt_img){
	this->nome = nome;
	this->altura = altura;
	this->largura = largura;
	this->posicao_x = posicao_x;
	this->posicao_y = posicao_y;

	this->x_superior = (this->posicao_x - (this->largura/2));
	this->y_superior = (this->posicao_y - (this->altura/2));
	this->x_inferior = (this->posicao_x + (this->largura/2));
	this->y_inferior = (this->posicao_y + (this->altura/2));

	this->conta_frames = 1;
// PREPARANDO AS IMAGENS DO PERSONAGEM
/*	std::string caminho_final = (char*) malloc(2*qt_img * sizeof(char*));

	for (int i = 1; i <= qt_img; i++) {
		string indice_aux;
		 switch(i){
			case 0: indice_aux = '0'; break;
			case 1: indice_aux = '1'; break;
			case 2: indice_aux = '2'; break;
			case 3: indice_aux = '3'; break;
            case 4: indice_aux = '4'; break;
            case 5: indice_aux = '5'; break;
            case 6: indice_aux = '6'; break;
            case 7: indice_aux = '7'; break;
            case 8: indice_aux = '8'; break;
            case 9: indice_aux = '9'; break;
        }

		 caminho_final = diretorio + nome_img + indice_aux + extensao_img;

		const char *caminho = caminho_final.c_str(); // Convertendo string para CONST*char para poder passar para o Allegro */
		this->imagens[0] = al_load_bitmap("img/barreira3.png");  // Caminho da imagem 1 passado para a primeira posicao do vetor de imagens
//
}

void Barreira::Update(){}

void Barreira::Render(){
    al_draw_bitmap(this->imagens[0], this->x_superior, this->y_superior , 0); // Para baixo, imagens 8 e 9
}

