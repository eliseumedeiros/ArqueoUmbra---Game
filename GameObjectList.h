#ifndef _GAME_OBJECT_LIST_H_
#define _GAME_OBJECT_LIST_H_
#include "GameObject.h"
class No;
class  GameObjectList{
public:
	No *inicio;

	GameObjectList();
	bool Adicionar(GameObject *gobj);
	bool Remover(std::string nome);
	bool Buscar(std::string nome);
	void Update();  // percorre todos os elementos cadastrados executando o m�todo Update()
	void Render();  // que percorre todos os elementos cadastrados executando o m�todo Render()
	std::string mouseDown_Move(float x, float y, int comportamento);
	int DetectaColisao();
	void limpar_lista();
};

#endif
