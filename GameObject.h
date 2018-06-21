#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_
#include <string>
class GameObject {
public:
	std::string nome;
    int altura, largura;
	float posicao_x, posicao_y;
	float velocidade_x, velocidade_y;
	float atrito;
	enum Direcao {NEUTRA, CIMA, BAIXO, DIREITA, ESQUERDA}; // Indica para qual lado o GameObject se movera
	Direcao direcao;

	GameObject();
	void Start(); // RODA SOMENTE UMA VEZ QUANDO O OBJETO É CRIADO
	virtual void Update(); // RODA A CADA FRAME E DEVE CONTER AS MUDANCAS FISICAS DE MOVIMENTO
	virtual void Render(); // TAMBÉM RODA A CADA FRAME E DEVE CONTER AS ROTINAS DE DESENHO DO OBJETO NA TELA  No GameObject Render() não faz nada, deixando esse comportamento para suas subclasses
	virtual int mouseDown_Move(float x, float y, int comportamento); // VERIFICA SE O CLIQUE DO MOUSE FOI SOBRE UM GAMEOBJECT E TAMBEM PODE VERIFICAR SE O CURSOR ESTA SOBRE UM GAMEOBJECT DEPENDENDO DO COMPORTAMENTO ENVIADO, 1 - MouseDown(clique) / 2- MouseMove
};

#endif
