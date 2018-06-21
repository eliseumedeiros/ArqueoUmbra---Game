#include <iostream>
#include <string>
#include <sstream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "GameObject.h"
#include "Retangulo.h"
#include "Personagem.h"

using namespace std;

class Audio{

	// PREPARANDO OS AUDIOS
	ALLEGRO_SAMPLE *passo0;
	ALLEGRO_SAMPLE *passo1;
	ALLEGRO_SAMPLE *passo2;
	ALLEGRO_SAMPLE *passo3;
	ALLEGRO_SAMPLE *passo4;
	ALLEGRO_SAMPLE *passo5;

	void Set(int num_sample = 0){
		switch (num_sample){
		case 0:
			al_play_sample(passo0, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
			break;
		case 1:
			al_play_sample(passo1, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
			break;
		case 2:
			al_play_sample(passo2, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
			break;
		case 3:
			al_play_sample(passo3, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
			break;
		case 4:
			al_play_sample(passo4, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
			break;
		case 5:
			al_play_sample(passo5, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
			break;
		default:
			al_play_sample(passo0, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
			break;
		}
	}

	void Set_Play_Audio(int audio = 0, bool play = true, bool set = false){
		this->passo0 = al_load_sample("audio/passo0.wav");
		this->passo0 = al_load_sample("audio/passo1.wav");
		this->passo0 = al_load_sample("audio/passo2.wav");
		this->passo0 = al_load_sample("audio/passo3.wav");
		this->passo0 = al_load_sample("audio/passo4.wav");
		this->passo0 = al_load_sample("audio/passo5.wav");
	}
};

Personagem::Personagem(std::string nome, float posicao_x, float posicao_y, float velocidade_x, float velocidade_y, float altura, float largura,int vida_qt, std::string diretorio, std::string nome_img, std::string extensao_img, int qt_img = 9){
    this->vida_qt = vida_qt;
    this->frames_decrementoDeVida = 1;
    this->mover = false; // medida de parada, para o controle de passagem (movimentos) das imagens do personagem
	this->nome = nome;
	this->altura = altura;
	this->largura = largura;
	this->posicao_x = posicao_x;
	this->posicao_y = posicao_y;
	this->velocidade_x = velocidade_x;
	this->velocidade_y = velocidade_y;
	this->atrito = atrito;

	this->x_superior = (this->posicao_x - (this->largura/2));
	this->y_superior = (this->posicao_y - (this->altura/2));
	this->x_inferior = (this->posicao_x + (this->largura/2));
	this->y_inferior = (this->posicao_y + (this->altura/2));

	this->conta_frames = 1;
// PREPARANDO AS IMAGENS DO PERSONAGEM
	std::string caminho_final = (char*) malloc(2*qt_img * sizeof(char*));

	for (int i = 0; i <= qt_img; i++) {
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

		const char *caminho = caminho_final.c_str(); // Convertendo string para CONST*char para poder passar para o Allegro
		this->imagens[i] = al_load_bitmap(caminho);  // Caminho da imagem 1 passado para a primeira posicao do vetor de imagens
	}

	for(int i = 0; i < 3; i++){ // Verificando se as imagens carregaram corretamente
		if(imagens[i] == NULL){
			al_show_native_message_box(NULL, "Imagem nao carregada", "Erro na classe Personagem", ".", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		}
	}

	this->vida[0] = al_load_bitmap("img/coracao_life.png");
}

void Personagem::Update(){
	this->posicao_x += this->velocidade_x;
	this->posicao_y += this->velocidade_y;
	this->conta_frames++;

	this->x_superior = (this->posicao_x - (this->largura/2));
	this->y_superior = (this->posicao_y - (this->altura/2));
	this->x_inferior = (this->posicao_x + (this->largura/2));
	this->y_inferior = (this->posicao_y + (this->altura/2));
	//std::cout<<"x_superior: "<<this->x_superior<<"\t y_superior: "<<y_superior<<std::endl;
}

void Personagem::Render(){
    if(this->nome == "Marco"){
    float posx_coracao = 75;
		for (int i = 0; i < this->vida_qt; i++){
			al_draw_bitmap(vida[0], posx_coracao, 5, 0);
			posx_coracao += 35;
		}
    }
    else if(this->nome == "Mau"){
            float posx_coracao = 75;
		for (int i = 0; i < this->vida_qt; i++){
			al_draw_bitmap(vida[0], posx_coracao, 565, 0);
			posx_coracao += 35;
		}
    }
    int aux;
	if(this->direcao == NEUTRA){
            aux = 0;
	}
	else{

	if(this->direcao == BAIXO ){
        aux = 0;

		if(this->conta_frames > 15 && this->conta_frames <= 30 && this->mover == true){
		    aux = 1;
        }
		if(this->conta_frames > 30 && this->conta_frames <= 45 && this->mover == true){
		    aux = 2;
		}
		if(this->conta_frames > 45){
			this->conta_frames = 1;
            aux = 0;
		}
	} else
	if(this->direcao == CIMA){
        aux = 5;

		if(this->conta_frames > 15 && this->conta_frames <= 30 && this->mover == true){
		    aux = 6;
		}
		if(this->conta_frames > 30 && this->conta_frames <= 45 && this->mover == true){
            aux = 7;
        }
		if(this->conta_frames > 45){
			this->conta_frames = 1;
            aux = 5;
		}
	} else
	if(this->direcao == ESQUERDA){
            aux = 8;
		if(this->conta_frames > 15 && this->conta_frames <= 30 && this->mover == true){
            aux = 9;
		}
		if(this->conta_frames > 30){
			this->conta_frames = 1;
            aux = 8;
		}
	} else
	if(this->direcao == DIREITA){
                aux = 3;
		if(this->conta_frames > 15 && this->conta_frames <= 30 && this->mover == true){
		    aux = 4;
		}
		if(this->conta_frames > 30){
			this->conta_frames = 1;
            aux = 3;
		}
	}
    }
    al_draw_bitmap(this->imagens[aux], this->x_superior, this->y_superior, 0); // Para baixo, imagens 8 e 9
}

void Personagem:: put_bomba (){

	al_draw_circle(this->bombas.x, this->bombas.x, 3, al_map_rgb(255, 0, 0), 3);

}
