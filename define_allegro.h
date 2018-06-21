#ifndef DEFINE_ALLEGRO_H
#define DEFINE_ALLEGRO_H

class DefineAllegro {
public:
   //TELA
	ALLEGRO_DISPLAY *display;
  //IMAGEM DE FUNDO
    ALLEGRO_BITMAP *imagem;
  //IMAGEM COM AS INSTRUCOES
	ALLEGRO_BITMAP *tela_instrucoes;
  //ORDENAR EVENTOS EM FILA
    ALLEGRO_EVENT_QUEUE *fila_eventos;

    int falha_allegro; // para receber os returns do construtor, em caso de problemas

    ALLEGRO_TIMER *timer;
    DefineAllegro();
    int iniciar_allegro();
};

#endif //DEFINE_ALLEGRO_H
