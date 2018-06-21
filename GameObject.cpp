#include <iostream>
#include <string>
#include "GameObject.h"

using namespace std;

GameObject::GameObject(){
	this->direcao = NEUTRA;
	Start();
}

void GameObject::Start(){

}

void GameObject::Update(){
	this->posicao_x += this->velocidade_x;
	this->posicao_y += this->velocidade_y;
}

void GameObject::Render(){}

int GameObject::mouseDown_Move(float x, float y, int comportamento){ return NULL; }
