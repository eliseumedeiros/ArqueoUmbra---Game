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

#define VOLTARMENU 1
void fimDoJogo(int *situacao_game, ALLEGRO_BITMAP *imagemFinal[2]){
enum situacao{ CARREGARIMAGEM, VITORIA, DERROTA, EMJOGO};

        if(*situacao_game==CARREGARIMAGEM){
            imagemFinal[0] = al_load_bitmap("img/vitoria0.jpg");  // Caminho da imagem 1 passado para a primeira posicao do vetor de imagens
            imagemFinal[1] = al_load_bitmap("img/derrota0.jpg");
            *situacao_game=EMJOGO;
        }
        if(*situacao_game==VITORIA){
            al_draw_bitmap(imagemFinal[0], 0, 0, 0);

        }
        else if(*situacao_game==DERROTA){
            al_draw_bitmap(imagemFinal[1], 0, 0, 0);
        }
}
