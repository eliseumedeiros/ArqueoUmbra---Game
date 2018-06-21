#include <iostream>
#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include "GameObject.h"
#include "No.h"
#include "Circulo.h"
#include "Retangulo.h"
#include "Personagem.h"
#include "GameObjectList.h"
#include <cmath>

using namespace std;

 GameObjectList::GameObjectList(){
	 this->inicio = NULL;
}
 bool GameObjectList::Adicionar(GameObject *gobj_argumento){
	 No *novo_no = new No();
		 novo_no->valor_gobj = gobj_argumento;
		 novo_no->prox_gobj = NULL;
	 if(this->inicio == NULL){ // SE LISTA VAZIA
		 this->inicio = novo_no;       // PRIMEIRO ELEMENTO SERA O ENVIADO COMO ARGUMENTO
		 return true;
	 } else if (this->Buscar(gobj_argumento->nome) == 1){ // JAH EXISTE GAMEOBJECT COM ESSE NOME NA LISTA
				al_show_native_message_box(NULL, "Imagem nao carregada", "Erro na classe Personagem", ".", NULL, ALLEGRO_MESSAGEBOX_ERROR);// EXIBIR ALERTA QUE JAH EXISTE GAME OBJECT COM MESMO NOME NA LISTA
		 return false;
	 }

	 else{
		 No *no_aux;
		 no_aux = this->inicio;
		 while (no_aux->prox_gobj != NULL){ // PERCORRIDO ATE O FIM
			 no_aux = no_aux->prox_gobj;
		 }
		 no_aux->prox_gobj = novo_no;
		 return true;  // INSERIDO NO FIM
	 }
	 return false;
 }

bool GameObjectList::Remover(std::string nome){
	if(this->inicio == NULL){ // SE LISTA VAZIA
		return false;  // NAO TEM ELEMENTOS PRA REMOVER
	}
	else if (this->inicio->valor_gobj->nome == nome){ // O PRIMEIRO EH O PROCURADO
		this->inicio = NULL; 	 // REMOVIDO COM SUCESSO
		return true;
	}
	else if(this->Buscar(nome) == false){
		return false;
	}
	No *no_anterior = this->inicio;
	No *no_atual = this->inicio;
	while (no_atual != NULL){
		no_atual = no_atual->prox_gobj;
		if (no_atual->valor_gobj->nome == nome){
			no_anterior->prox_gobj = no_atual->prox_gobj;
			no_atual = NULL; // REMOVIDO COM SUCESSO
			return true;
		}
		no_anterior = no_anterior->prox_gobj;
	}
	return false;
 }

bool GameObjectList::Buscar(std::string nome){
	if(this->inicio == NULL){ // SE LISTA VAZIA
		return false;  // NAO TEM ELEMENTOS PRA Buscar
	}
	else{
		No *no_atual = this->inicio;
		while (no_atual != NULL){
			if (no_atual->valor_gobj->nome == nome){
				return true;   // ACHADO
			}
			no_atual = no_atual->prox_gobj;

		}

	}
	return false;
}

void GameObjectList::Update(){ // RODA A CADA FRAME E DEVE CONTER AS MUDANCAS FISICAS DE MOVIMENTO
	No *no_atual = this->inicio;
		while (no_atual != NULL){
			no_atual->valor_gobj->Update();
			no_atual = no_atual->prox_gobj;
		}
}

void GameObjectList::Render(){
	No *no_atual = this->inicio;
		while (no_atual != NULL){
			no_atual->valor_gobj->Render();
			no_atual = no_atual->prox_gobj;
		}
}

std::string GameObjectList::mouseDown_Move(float x, float y, int comportamento){
	std::string nome = "vazio";
	No *no_atual = this->inicio;
		while (no_atual != NULL){
			if(no_atual->valor_gobj->mouseDown_Move(x, y, comportamento) == 1){
                nome = no_atual->valor_gobj->nome;
				return nome;
			}
			no_atual = no_atual->prox_gobj;
		}
	return nome;
}
void GameObjectList::limpar_lista(){
No *no_atual = this->inicio;
    while(this->inicio!=NULL){
		while (no_atual->prox_gobj != NULL){
			no_atual = no_atual->prox_gobj;
		}
		no_atual =NULL;
		no_atual = this->inicio;
    }
}
enum colisao{
    SEM_COLISAO=0,
    COLISAO_PAREDE=1,
    COLISAO_MONSTRO_MARCO=2,
    COLISAO_MONSTRO_BOMBA=3,
    COLISAO_MARCO_BOMBA=4
};
int GameObjectList::DetectaColisao(){
	No *no_atual1 = this->inicio;
	bool houve_colisao = false;
	while (no_atual1 != NULL)
	{
		No *no_atual = no_atual1;
		Retangulo *elemento1 = (Retangulo*) no_atual->valor_gobj;
		no_atual = no_atual->prox_gobj;

        while (no_atual != NULL){
            if(no_atual->valor_gobj->nome == "Bomba" && elemento1->nome == "_Marco_" || no_atual->valor_gobj->nome == "Bomba" && elemento1->nome == "_Mau_"){
                    Circulo *bomba = (Circulo*) no_atual->valor_gobj;

                    int d;
                    d = sqrt((elemento1->posicao_x - no_atual->valor_gobj->posicao_x)*(elemento1->posicao_x - no_atual->valor_gobj->posicao_x) + (elemento1->posicao_y - no_atual->valor_gobj->posicao_y)*(elemento1->posicao_y - no_atual->valor_gobj->posicao_y));

                    if(d > bomba->raio + elemento1->largura && d > bomba->raio + elemento1->altura)
                        { houve_colisao = false;}
                    else houve_colisao = true;
            }
            else if(no_atual->valor_gobj->nome!="Marco" &&  no_atual->valor_gobj->nome!="Mau" && elemento1->nome!="Marco" && elemento1->nome!="Mau"){
                if    (elemento1->posicao_x + elemento1->largura > no_atual->valor_gobj->posicao_x  &&
                        elemento1->posicao_x                      < no_atual->valor_gobj->posicao_x + no_atual->valor_gobj->largura  &&
                        elemento1->posicao_y + elemento1->altura  > no_atual->valor_gobj->posicao_y   &&
                        elemento1->posicao_y                      < no_atual->valor_gobj->posicao_y + no_atual->valor_gobj->altura   ) { houve_colisao = true;}
                }
            if(houve_colisao) {
                if(elemento1->nome=="_Marco_" && no_atual->valor_gobj->nome == "Bomba"){return COLISAO_MARCO_BOMBA;}
                else if(elemento1->nome=="_Mau_" && no_atual->valor_gobj->nome == "Bomba"){ return COLISAO_MONSTRO_BOMBA;}
                else if(elemento1->nome=="_Marco_" && no_atual->valor_gobj->nome =="_Mau_" ){return COLISAO_MONSTRO_MARCO;}
                else if(elemento1->nome == "_Marco_"){return COLISAO_PAREDE;}
            }
            no_atual = no_atual->prox_gobj;
        }
		no_atual1 = no_atual1->prox_gobj;
	}
	return SEM_COLISAO;
}

/*
((retangulo1.X + retangulo1.L > retangulo2.X) E
(retangulo1.X < retangulo2.X + retangulo2.L) E
(retangulo1.Y + retangulo1.A > retangulo2.Y) E
(retangulo1.Y < retangulo2.Y + retangulo2.A))
returne verdadeiro; //colidiu
senão
returne falso; //não colidiu
if (rect1.x < rect2.x + rect2.width &&
    rect1.x + rect1.width > rect2.x &&
    rect1.y < rect2.y + rect2.height &&
    rect1.height + rect1.y > rect2.y) {
    // collision detected!
}


*/
