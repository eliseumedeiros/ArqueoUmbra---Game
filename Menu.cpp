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
#include "GameObject.h"
#include "No.h"
#include "GameObjectList.h"
#include "Retangulo.h"
#include "Personagem.h"
#include "Menu.h"

using namespace std;

void destroi_menu(ALLEGRO_EVENT_QUEUE *fila_eventos, ALLEGRO_TIMER *timer, ALLEGRO_SAMPLE *sample_novo_jogo, ALLEGRO_SAMPLE *sample_continuar, ALLEGRO_SAMPLE *sample_instrucoes,
				  ALLEGRO_SAMPLE *sample_sair, ALLEGRO_SAMPLE *sample_tema, ALLEGRO_BITMAP *fundo_menu, ALLEGRO_BITMAP *itens_menu, ALLEGRO_BITMAP *seletor_menu,
				  GameObjectList *lista_gameobjects_menu, GameObject *novo_jogo, GameObject *continuar, GameObject *instrucoes, GameObject *sair){

    al_destroy_event_queue(fila_eventos);
	al_destroy_timer(timer);
	al_destroy_sample(sample_novo_jogo);
	al_destroy_sample(sample_continuar);
	al_destroy_sample(sample_instrucoes);
	al_destroy_sample(sample_sair);
	al_destroy_sample(sample_tema);
	al_destroy_bitmap(fundo_menu);
	al_destroy_bitmap(itens_menu);
	al_destroy_bitmap(seletor_menu);
	delete(lista_gameobjects_menu);
	delete(novo_jogo);
	delete(continuar);
	delete(instrucoes);
	delete(sair);
}

int Menu(){
	enum Opcoes{ NOVO_JOGO, CONTINUAR, INSTRUCOES, SAIR, NEUTRO} opcao;
	opcao = NEUTRO;
	bool fim_menu = false;
	int conta_frames = 1;
	bool itens_menu_exibidos = false;

	std::string opc = "";
	const  float taxa_aualizacao = 1.0/60; // Taxa de atualizacao de 60 frames por segundo que sera passada ao timer

	ALLEGRO_EVENT_QUEUE *fila_eventos=NULL;
	fila_eventos = al_create_event_queue();

	ALLEGRO_TIMER *timer = al_create_timer(taxa_aualizacao); // Timer inicializado com taxa de atualizacao de 60 frames por segundo
	fila_eventos = al_create_event_queue(); // Fila de eventos iniciada
    al_install_mouse();    // Pacote para Detectar eventos do mouse
	al_register_event_source(fila_eventos, al_get_timer_event_source(timer)); // Poe eventos ocorridos dentro do timer na fila de eventos
	al_register_event_source(fila_eventos, al_get_mouse_event_source()); // Poe na fila Eventos do mouse

    ALLEGRO_SAMPLE *sample_novo_jogo = al_load_sample("audio/novo_jogo.wav");
	ALLEGRO_SAMPLE *sample_continuar = al_load_sample("audio/continuar.wav");
	ALLEGRO_SAMPLE *sample_instrucoes = al_load_sample("audio/instrucoes.wav");
	ALLEGRO_SAMPLE *sample_sair = al_load_sample("audio/sair.wav");
	ALLEGRO_SAMPLE *sample_tema = al_load_sample("audio/tema.wav");

	ALLEGRO_BITMAP *fundo_menu = al_load_bitmap("img/fundo_menu_abertura.png");
	ALLEGRO_BITMAP *itens_menu = al_load_bitmap("img/itens_menu.png");
	ALLEGRO_BITMAP *seletor_menu = al_load_bitmap("img/seletor_menu.png");
	ALLEGRO_BITMAP *instrucoes0 = al_load_bitmap("img/instrucoes.png");

	if(fundo_menu == NULL || itens_menu == NULL || fundo_menu == NULL || seletor_menu == NULL)
		al_show_native_message_box(NULL, "Imagem nao carregada", "Erro em Menu.cpp  Verifique caminho da imagem", ".", NULL, ALLEGRO_MESSAGEBOX_ERROR);

	al_play_sample(sample_tema, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
	al_draw_bitmap(fundo_menu, 0, 0, 0);
	al_draw_bitmap(itens_menu, 200, 120, 0);
	al_flip_display();

	GameObjectList *lista_gameobjects_menu = new GameObjectList();
	GameObject *novo_jogo = new Retangulo("novo_jogo", 390.0, 180.0, 5, 5, 0.1, 0.0, /*#*/116, /*#*/89, /*#*/255, 50, 300);
	GameObject *continuar = new Retangulo("continuar", 390.0, 250.0, 5, 5, 0.1, 0.0, /*#*/116, /*#*/89, /*#*/255, 50, 300);
	GameObject *instrucoes = new Retangulo("instrucoes", 390.0, 320.0, 5, 5, 0.1, 0.0, /*#*/116, /*#*/89, /*#*/255, 70, 300);
	GameObject *sair = new Retangulo("sair", 390.0, 400.0, 5, 5, 0.1, 0.0, /*#*/255, /*#*/255, /*#*/255, 50, 300);

	lista_gameobjects_menu->Adicionar(novo_jogo);
	lista_gameobjects_menu->Adicionar(continuar);
	lista_gameobjects_menu->Adicionar(instrucoes);
	lista_gameobjects_menu->Adicionar(sair);


	al_start_timer(timer);

	while (!fim_menu){
		al_flip_display();
		ALLEGRO_EVENT event;    // Armazaena todos os eventos que acontecem, no caso do menu, recebera eventos do teclado ou mouse
		al_wait_for_event(fila_eventos, &event);  // Esperando possiveis eventos*/

		if(event.type == ALLEGRO_EVENT_MOUSE_AXES){ // Se o evento foi movimento do mouse sobre a tela
			al_clear_to_color(al_map_rgb(0, 0, 0));
			al_draw_bitmap(fundo_menu, 0, 0, 0);
			al_draw_bitmap(itens_menu, 200, 120, 0);
			if(lista_gameobjects_menu->mouseDown_Move(event.mouse.x, event.mouse.y, 1) == "novo_jogo"){
				al_draw_bitmap(seletor_menu, 180, 140, 0);
			    al_play_sample(sample_novo_jogo, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
			}
			else
			if(lista_gameobjects_menu->mouseDown_Move(event.mouse.x, event.mouse.y, 1) == "continuar"){
				al_draw_bitmap(seletor_menu, 180, 210, 0);
			    al_play_sample(sample_continuar, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
			}
			else
			if(lista_gameobjects_menu->mouseDown_Move(event.mouse.x, event.mouse.y, 1) == "instrucoes"){
				al_draw_bitmap(seletor_menu, 180, 280, 0);
			    al_play_sample(sample_instrucoes, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
			}
			else
			if(lista_gameobjects_menu->mouseDown_Move(event.mouse.x, event.mouse.y, 1) == "sair"){
				al_draw_bitmap(seletor_menu, 180, 350, 0);
			    al_play_sample(sample_sair, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
			}
		}


		if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){ // Se o evento foi clique do mouse
			if(lista_gameobjects_menu->mouseDown_Move(event.mouse.x, event.mouse.y, 2) == "novo_jogo"){
				fim_menu = true;
				destroi_menu(fila_eventos, timer, sample_novo_jogo, sample_continuar, sample_instrucoes, sample_sair, sample_tema,
								fundo_menu, itens_menu, seletor_menu, lista_gameobjects_menu, novo_jogo, continuar, instrucoes, sair);
				return NOVO_JOGO;
			} else
				if(lista_gameobjects_menu->mouseDown_Move(event.mouse.x, event.mouse.y, 2) == "continuar"){
				    fim_menu = true;
					destroi_menu(fila_eventos, timer, sample_novo_jogo, sample_continuar, sample_instrucoes, sample_sair, sample_tema,
								fundo_menu, itens_menu, seletor_menu, lista_gameobjects_menu, novo_jogo, continuar, instrucoes, sair);
					return CONTINUAR;
				}
				else
					if(lista_gameobjects_menu->mouseDown_Move(event.mouse.x, event.mouse.y, 2) == "instrucoes"){
                        al_draw_bitmap(instrucoes0,0, 0, 0);

					}
					else
						if(lista_gameobjects_menu->mouseDown_Move(event.mouse.x, event.mouse.y, 2) == "sair"){
							fim_menu = true;
							destroi_menu(fila_eventos, timer, sample_novo_jogo, sample_continuar, sample_instrucoes, sample_sair, sample_tema,
								fundo_menu, itens_menu, seletor_menu, lista_gameobjects_menu, novo_jogo, continuar, instrucoes, sair);
							return SAIR;
			           }
	    }

	}

	destroi_menu(fila_eventos, timer, sample_novo_jogo, sample_continuar, sample_instrucoes, sample_sair, sample_tema,
				fundo_menu, itens_menu, seletor_menu, lista_gameobjects_menu, novo_jogo, continuar, instrucoes, sair);
	return 0;
}
