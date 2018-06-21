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

int largura = 800;
int altura = 600;

DefineAllegro::DefineAllegro(){
    this->display = NULL;
  //IMAGEM DE FUNDO
    this->imagem = NULL;
  //IMAGEM COM AS INSTRUCOES
	this->tela_instrucoes = NULL;
  //ORDENAR EVENTOS EM FILA
    this->fila_eventos = NULL;
}

int DefineAllegro::iniciar_allegro(){

  //ESTABELECER TAMANHO DA TELA
	this->display = al_create_display(largura, altura);
  //PEGANDO A IMAGEM DE PLANO DE FUNDO
    al_init_image_addon();

    this->imagem = al_load_bitmap("img/fundo_fase_game.png");
	this->tela_instrucoes = al_load_bitmap("img/instrucoes.png");
  //COLOCANDO O NOME NA BARRA DA TELA
	al_set_window_title(this->display, "PROJETO LP I - Eliseu e Wendel");
 //INICIANDO COMPONENTES
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_keyboard();
	al_install_mouse();    // Pacote para Detectar eventos do mouse
	al_install_audio();
	al_init_acodec_addon();
	al_reserve_samples(20);

    this->fila_eventos = al_create_event_queue();

	al_set_new_display_flags(ALLEGRO_WINDOWED);
/// CONDIÇÕES DE INICIALIZAÇÃO DO ALLEGRO 5

   // Inicialização do add-on para uso de fontes True Type
    if (!al_init_ttf_addon())
    {
        std::cout<<"Falha ao inicializar add-on allegro_ttf.\n";
		return -1;
    }
    if (!this->fila_eventos)
    {
		std::cout << "Erro ao tentar criar eventos" << std::endl; // Caso contrario imprime mensagem de erro
        al_destroy_display(this->display);
		return -1;
    }

	if (!this->display){                      // Iniciando o display e verificando se ocorreu tudo bem
		std::cout << "Erro ao tentar criar display" << std::endl; // Caso contrario imprime mensagem de erro
		return -1;
	}

	const  float taxa_aualizacao = 1.0/60; // Taxa de atualizacao de 60 frames por segundo que sera passada ao timer
	this->timer = al_create_timer(taxa_aualizacao); // Timer inicializado com taxa de atualizacao de 60 frames por segundo
	this->fila_eventos = al_create_event_queue(); // Fila de eventos iniciada

	al_register_event_source(this->fila_eventos, al_get_keyboard_event_source()); // Poe eventos do teclado na fila de eventos
	al_register_event_source(this->fila_eventos, al_get_timer_event_source(this->timer)); // Poe eventos ocorridos dentro do timer na fila de eventos
	al_register_event_source(this->fila_eventos, al_get_display_event_source(this->display)); // Poe na fila Eventos que procedem do ecrã
	al_register_event_source(this->fila_eventos, al_get_mouse_event_source()); // Poe na fila Eventos do mouse
	return 0;
}
