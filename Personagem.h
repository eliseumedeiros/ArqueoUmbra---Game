#ifndef _PERSONAGEM_H_
#define _PERSONAGEM_H_
#include "Bomba.h"
class Personagem : public Retangulo{ // Heranca multipla, pois o personagem eh um GameObject e tambem sera considerado um retangulo
public:
    int vida_qt; //quantidade de vida
    int frames_decrementoDeVida;
	Bomba bombas;
    bool mover; // medida de parada, para o controle de passagem (movimentos) das imagens do personagem
	ALLEGRO_BITMAP *imagens[20];
    ALLEGRO_BITMAP *vida[1];
	int conta_frames;

	Personagem(std::string nome, float posicao_x, float posicao_y, float velocidade_x, float velocidade_y, float altura, float largura ,int vida_qt, std::string diretorio, std::string nome_img, std::string extensao_img, int qt_img); // Construtor recebe nome, posicao X e Y, velocidade X e Y, atrito, diretorio das imagens, nome imagem do personagem, extensao do arquivo de imagem e quantidade de imagens

	void Update();
	void Render();
	void put_bomba();
};

#endif
