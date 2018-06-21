#include <iostream>
#include <stdio.h>
#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "define_allegro.h"
#include "teclado_key_down_up.h"
#include "teclado_down_up.h"
#include "GameObject.h"
#include "No.h"
#include "GameObjectList.h"
#include "Retangulo.h"
#include "Circulo.h"
#include "Bomba.h"
#include "Personagem.h"
#include "Barreira.h"
#include "Fase_1.h"
#include "Menu.h"
#include "Abertura.h"
#include "Monstro.h"
#include "FimDoJogo.h"
using namespace std;

int larguraTela = 800;
int alturaTela = 600;
int larguraTelaJogada = 780;
int alturaTelaJogada = 585;
//PARA INDICAR EM QUE FASE PAROU (ainda tô trabalhando nisso...)
int Velocidade = 2;
enum situacao{ CARREGARIMAGEM, VITORIA, DERROTA, EMJOGO};
enum colisao{
    SEM_COLISAO=0,
    COLISAO_PAREDE=1,
    COLISAO_MONSTRO_MARCO=2,
    COLISAO_MONSTRO_BOMBA=3,
    COLISAO_MARCO_BOMBA=4
};
enum Fases{
FASE_1_EXC,
FASE_2_EXC,
FASE_1_FIM,
FASE_2_FIM,
FASE_3_FIM
};

int main()
{
//INICIA ALLEGRO
	if (!al_init()) {                   // Iniciando o Allegro e verificando se occoreu tudo bem
		std::cout << "Erro ao tentar iniciar o allegro" << std::endl;
		return -1;                      // Caso nao consiga iniciar o Allegro retorna o valor -1 indicando erro
	}
//INICIA OS COMPONENTES DO ALLEGRO
    DefineAllegro *set_allegro = new DefineAllegro();

//COMANDOS DO TECLADO
    comandosTeclado *teclas_teclado = new comandosTeclado();
    ALLEGRO_BITMAP *imagemFinal[2];
    imagemFinal[0] = al_load_bitmap("img/vitoria0.jpg");  // Caminho da imagem 1 passado para a primeira posicao do vetor de imagens
    imagemFinal[1] = al_load_bitmap("img/derrota0.jpg");
    if(set_allegro->iniciar_allegro() < 0) {return -1;}
/**----------------------------------------------------------------------------------------------------------------**/
//                                      ADICIONA E DEFINE OS ELEMENTOS DO JOGO
/**----------------------------------------------------------------------------------------------------------------**/
    GameObjectList *lista_gameobjects = new GameObjectList();  // Essa lista devera conter todos os game objects criados no jogo, ou seja, todos os elementos visiveis de cena
    Bomba *bomba = new Bomba();
	Circulo *area_bomba = new Circulo("Bomba", 200, 75, 0, 0, 0.1, 30, 60, 255, 0, 0);

                      // Personagem (nome, posicao_x, posicao_y, velocidade_x, velocidade_y, altura, largura, atrito, diretorio, nome_img, extensao_img, qt_img = 9)
	Personagem *marco = new Personagem("Marco", 200, 55, 0, 0, 60, 25, 5,"img/", "marco", ".png", 10); // Personagem Principal do jogo iniciado com campos (std::string nome, float posicao_x, float posicao_y, float velocidade_x, float velocidade_y, float altura, float largura,int atrito, std::string diretorio, std::string nome_img, std::string extensao_img, int qt_img = 9) da imagem e quantidade de imagens a serem carregadas)
    GameObject *marco_aux = new Retangulo("_Marco_", 200, 80, 0, 0, 0.1, 9, 116, 89, 74, 30, 30); // Retangulo criado com campos (Nome, posX, posY, velX, velY, Atrito, Espessura, Red, Green, Blue, Altura, Largura)
	Personagem *mau1 = new Personagem("Mau", 620, 55, 0, 0, 60, 25, 18, "img/", "mau", ".png", 11);
	GameObject *mau_aux = new Retangulo("_Mau_", 660, 80, 0, 0, 0.1, 9, 116, 89, 74, 40, 40);
	GameObject *botao_pause = new Retangulo("botao_pause", 390, 20, 0, 0, 0.1, 9, 116, 89, 74, 50, 220); // Retangulo criado com campos (Nome, posX, posY, velX, velY, Atrito, Espessura, Red, Green, Blue, Altura, Largura)
//INICIA A FASE 1
	lista_gameobjects->Adicionar(marco_aux); // Adicionando o personagem Marco na lista
	lista_gameobjects->Adicionar(mau_aux);
    fase_1(lista_gameobjects); // Adiciona as barreiras do jogo
	lista_gameobjects->Adicionar(botao_pause);
	lista_gameobjects->Adicionar(mau1);
	lista_gameobjects->Adicionar(marco); // Adicionando o personagem Marco na lista
// Adicionando o personagem Marco na lista
	bool finalizar = false;              // Enquanto finalizar for falsa, o jogo continua
	int opcao_escolhida = 4;             // Inicia com opcao 4, que eh a opcao NEUTRA
	int situacao_game = CARREGARIMAGEM;

/**----------------------------------------------------------------------------------------------------------------**/
//                                      ADICIONA E DEFINE OS PRINCIPAIS AUDIOS DO JOGO
/**----------------------------------------------------------------------------------------------------------------**/

	ALLEGRO_SAMPLE *audio_passo1 = al_load_sample("audio/passo1.ogg");
	ALLEGRO_SAMPLE *audio_passo2 = al_load_sample("audio/passo2.ogg");
	ALLEGRO_SAMPLE *audio_tema = al_load_sample("audio/tema.wav");
	if(audio_passo1 == NULL || audio_passo2 == NULL)
		al_show_native_message_box(NULL, "Som nao carregado", "Erro ao adicionar som.  Verifique caminho do som", ".", NULL, ALLEGRO_MESSAGEBOX_ERROR);

/**----------------------------------------------------------------------------------------------------------------**/
//                                                  LOOP DO JOGO
/**----------------------------------------------------------------------------------------------------------------**/
bool fim=false;
while(!fim){
	//Abertura(); // Chamo menu aki pra evitar gasto excessivo de momoria, pois no menu há instancia de lista e retangulos
	opcao_escolhida=Menu();
	switch (opcao_escolhida)
				{
				case 0:
					cout << "NOVO JOGO" << endl;
					delete(lista_gameobjects);
                    lista_gameobjects = new GameObjectList();  // Essa lista devera conter todos os game objects criados no jogo, ou seja, todos os elementos visiveis de cena

					marco = new Personagem("Marco", 200, 55, 0, 0, 60, 25, 5,"img/", "marco", ".png", 10);
                    marco_aux = new Retangulo("_Marco_", 200, 80, 0, 0, 0.1, 9, 116, 89, 74, 30, 30);
                    mau1 = new Personagem("Mau", 620, 55, 0, 0, 60, 25, 18, "img/", "mau", ".png", 11);
                    mau_aux = new Retangulo("_Mau_", 660, 80, 0, 0, 0.1, 9, 116, 89, 74, 40, 40);
                    botao_pause = new Retangulo("botao_pause", 390, 20, 0, 0, 0.1, 9, 116, 89, 74, 50, 220);
                    lista_gameobjects->Adicionar(marco_aux); // Adicionando o personagem Marco na lista
                    lista_gameobjects->Adicionar(mau_aux);
                    fase_1(lista_gameobjects); // Adiciona as barreiras do jogo
                    lista_gameobjects->Adicionar(botao_pause);
                    lista_gameobjects->Adicionar(mau1);
                    lista_gameobjects->Adicionar(marco); // Adicionando o personagem Marco na lista
                    finalizar = false;
					break;
				case 1:
					cout << "CONTINUAR" << endl;
					break;
				case 2:
					cout << "INSTRUCOES" << endl;

					break;
				case 3:
					finalizar = true;
					fim=true;
				case 4:
					cout << "NEUTRO" << endl;
					break;
				default:

					break;
				}

	al_start_timer(set_allegro->timer);

	while (!finalizar) {
    //COLOCA IMAGEM DE FUNDO
		al_draw_bitmap(set_allegro->imagem, 0, 0, 0);

		ALLEGRO_EVENT event;    // Armazaena todos os eventos que acontecem, no caso do game, recebera eventos do teclado ou mouse
		al_wait_for_event(set_allegro->fila_eventos, &event);  // Esperando possiveis eventos*/

		if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
			finalizar = true;
			fim = true;
		} else
		if(event.type == ALLEGRO_EVENT_MOUSE_AXES){ // Se o evento foi movimento do mouse sobre a tela
        //DETECTA CLICK DO MOUSE NOS GAMEOBJECTS
			lista_gameobjects->mouseDown_Move(event.mouse.x, event.mouse.y, 1);
		} else
    	if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){ // Se o evento foi clique do mouse
			if(lista_gameobjects->mouseDown_Move(event.mouse.x, event.mouse.y, 2) == "botao_pause"){
				finalizar=true;
			}
		} else
// CASO TENHA APERTADO A TECLA (biblioteca - teclado_key_down_up.h)
		key_down(teclas_teclado, &event, &marco->mover);

		marco->velocidade_x = 0;
		marco->velocidade_y = 0;
		marco_aux->velocidade_x = 0;
		marco_aux->velocidade_y = 0;
		if(teclas_teclado->key_S && marco->y_inferior < alturaTelaJogada){
			marco->velocidade_y += 2;
			marco_aux->velocidade_y += 2;
			marco->direcao = marco->BAIXO;
			al_play_sample(audio_passo2, 0.1, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
		}
		else if (teclas_teclado->key_W && marco->y_superior> 30){
			marco->velocidade_y -= Velocidade;
			marco_aux->velocidade_y -= Velocidade;
			marco->direcao = marco->CIMA;
			al_play_sample(audio_passo2, 0.1, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
		}
		else if(teclas_teclado->key_D && marco->x_inferior <= larguraTelaJogada){
				marco->velocidade_x += Velocidade;
				marco_aux->velocidade_x += Velocidade;
				marco->direcao = marco->DIREITA;
				al_play_sample(audio_passo2, 0.1, 0.3, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
			}

		else if(teclas_teclado->key_A && marco->x_superior>= 20){
				marco->velocidade_x -= Velocidade;
				marco_aux->velocidade_x -= Velocidade;
				marco->direcao = marco->ESQUERDA;
				al_play_sample(audio_passo2, 0.1, -0.3, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
		}

        if(teclas_teclado->key_space){
           if(!bomba->existe_bomba){bomba->Put_bomba(marco_aux->posicao_x, marco_aux->posicao_y);}
                teclas_teclado->key_space= false;
 		}
//DETECTAR COLISÃO
	switch (lista_gameobjects->DetectaColisao()){
		case SEM_COLISAO:
		    break;
			/*NAO FAZ NADA*/
		case COLISAO_MONSTRO_MARCO:
            if(mau1->conta_frames%60==0){
                marco->vida_qt -= 1;
                mau1->conta_frames = 0;
            }
            marco->conta_frames +=1;

			break;

		case COLISAO_PAREDE:

            if(marco->direcao == marco->ESQUERDA) {marco->velocidade_x -= -Velocidade; marco_aux->velocidade_x -= -Velocidade;}
            else if (marco->direcao == marco->CIMA) {marco->velocidade_y -= -Velocidade; marco_aux->velocidade_y -= -Velocidade;}
            else if (marco->direcao == marco->BAIXO) {marco->velocidade_y += -Velocidade; marco_aux->velocidade_y += -Velocidade;}
            else if (marco->direcao == marco->DIREITA) {marco->velocidade_x += -Velocidade; marco_aux->velocidade_x += -Velocidade;}
			break;

		case COLISAO_MARCO_BOMBA:
		    if(bomba->explodindo && marco->frames_decrementoDeVida == 1){
                marco->vida_qt -= 1;
                cout<<marco->vida_qt<<endl;
                marco->frames_decrementoDeVida++;
		    }
			break;
        case COLISAO_MONSTRO_BOMBA:
             if(bomba->explodindo && mau1->frames_decrementoDeVida == 1){
                mau1->vida_qt -= 1;
                cout<<mau1->vida_qt<<endl;
                mau1->frames_decrementoDeVida++;
		    }
		}
		if(!bomba->explodindo){
            marco->frames_decrementoDeVida =1;
            mau1->frames_decrementoDeVida = 1;
            lista_gameobjects->Remover("Bomba");
		}

		if(event.type == ALLEGRO_EVENT_TIMER){
			lista_gameobjects->Update();
			if(bomba->existe_bomba){
                bomba->conta_frame+=1;
                bomba->checar_explosao();
			}
		}
		if(bomba->explodir){
                bomba->explode();
                area_bomba->posicao_x = bomba->x;
                area_bomba->posicao_y = bomba->y;
                area_bomba->raio = 60;
                lista_gameobjects->Adicionar(area_bomba);
        }
// CASO TENHA SOLTADO A TECLA, (biblioteca - teclado_key_down_up.h)
        key_up (teclas_teclado, &event, &marco->mover);
        implementa_montro (mau1, mau_aux, marco->x_superior, marco->y_superior );
		bomba->Render();
		lista_gameobjects->Render();
        if(mau1->vida_qt<=0 && marco->vida_qt>0){situacao_game = VITORIA;}
        if(marco->vida_qt<=0){situacao_game = DERROTA;}
		fimDoJogo(&situacao_game, imagemFinal);
		al_flip_display();
		al_clear_to_color(al_map_rgb(255, 255, 255));

	}
	situacao_game=EMJOGO;
	finalizar = false;
}
	/* Liberando memoria */
	delete(marco);
	delete(lista_gameobjects);
	al_destroy_bitmap(set_allegro->imagem);
	al_destroy_event_queue(set_allegro->fila_eventos);
	al_destroy_timer(set_allegro->timer);
	al_destroy_display(set_allegro->display);

	return 0;
}//
