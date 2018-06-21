#ifndef _CIRCULO_H_
#define _CIRCULO_H_

class Circulo : public GameObject {
public:
	float raio;
	float espessura;
	typedef struct corCirculo{
		int R;
		int G;
		int B;
	} Cor; corCirculo corCirculo;

	Circulo(std::string nome, float posicao_x, float posicao_y, float velocidade_x, float velocidade_y, float atrito, float espessura, float raio, int R, int G, int B);
	void Render();
	int mouseDown_Move(float x, float y, int comportamento);
};

#endif