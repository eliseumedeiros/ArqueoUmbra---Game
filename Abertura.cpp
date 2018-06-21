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
#include "Abertura.h"


using namespace std;

bool Abertura(){
	bool fim_abertura = false;
	int conta_frames = 1;
	ALLEGRO_EVENT event;
    const  float taxa_aualizacao = 1.0/60; // Taxa de atualizacao de 60 frames por segundo que sera passada ao timer
    ALLEGRO_TIMER *timer = al_create_timer(taxa_aualizacao); // Timer inicializado com taxa de atualizacao de 60 frames por segundo

    ALLEGRO_EVENT_QUEUE *fila_eventos=NULL;

    fila_eventos = al_create_event_queue(); // Fila de eventos iniciada
    al_register_event_source(fila_eventos, al_get_timer_event_source(timer)); // Poe eventos ocorridos dentro do timer na fila de eventos

	ALLEGRO_SAMPLE *sample_titulo = al_load_sample("audio/titulo.wav");
    ALLEGRO_SAMPLE *sample_impacto = al_load_sample("audio/impacto_leve.wav");

	ALLEGRO_BITMAP *fundo_abertura = al_load_bitmap("img/fundo_menu_abertura.png");
	ALLEGRO_BITMAP *titulo_abertura = al_load_bitmap("img/titulo_abertura.png");
	ALLEGRO_BITMAP *pedras_abertura = al_load_bitmap("img/pedras_abertura.png");

	if(fundo_abertura == NULL || titulo_abertura == NULL || pedras_abertura == NULL)
		al_show_native_message_box(NULL, "Imagem nao carregada", "Erro em Menu.cpp  Verifique caminho da imagem", ".", NULL, ALLEGRO_MESSAGEBOX_ERROR);

	al_draw_bitmap(fundo_abertura, 0, 0, 0);
	al_flip_display();
	al_play_sample(sample_titulo, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);

	al_start_timer(timer);

	while (!fim_abertura){
		conta_frames++;
		al_flip_display();
		al_wait_for_event(fila_eventos, &event);

		if (event.type == ALLEGRO_EVENT_TIMER){	
		if(conta_frames == 300){
			al_play_sample(sample_impacto, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
			al_draw_bitmap(titulo_abertura, -2.5, -100.0, 0);
		}
		if(conta_frames == 400){
			al_play_sample(sample_impacto, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
			al_draw_bitmap(pedras_abertura, -2.5, -100.0, 0);
		}
		if(conta_frames > 600){
			al_destroy_bitmap(fundo_abertura);
			al_destroy_bitmap(pedras_abertura);
			al_destroy_bitmap(titulo_abertura);
			al_destroy_sample(sample_titulo);
			al_destroy_sample(sample_impacto);
			al_destroy_event_queue(fila_eventos);
			al_destroy_timer(timer);
			return true;
		}
	    }
	}
	return false;
}
