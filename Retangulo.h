#ifndef _RETANGULO_H_
#define _RETANGULO_H_

class Retangulo : public GameObject {
public:
	//float altura;
	//float largura;
	float espessura;
	float x_superior, y_superior;
	float x_inferior, y_inferior;
	typedef struct corRetangulo{
		int R;
		int G;
		int B;
	} Cor; Cor corRetangulo;

	Retangulo(); // Construtor padrao
	Retangulo(std::string nome, float posicao_x, float posicao_y, float velocidade_x, float velocidade_y, float atrito, float espessura, int R, int G, int B, float altura,  float largura);
	void Render();
	virtual int mouseDown_Move(float x, float y, int comportamento);
};

#endif
