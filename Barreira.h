#ifndef _BARREIRA_H_
#define _BARREIRA_H_

class Barreira : public Retangulo{
   public:
    bool removivel;
    ALLEGRO_BITMAP *imagens[5];
    int conta_frames;

	Barreira(std::string nome, float posicao_x, float posicao_y,  float altura, float largura, std::string diretorio, std::string nome_img, std::string extensao_img, int qt_img); // Construtor recebe nome, posicao X e Y, velocidade X e Y, atrito, diretorio das imagens, nome imagem do personagem, extensao do arquivo de imagem e quantidade de imagens

	void Update();
	void Render();
};

#endif // _BARREIRA_H_
