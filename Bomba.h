#ifndef _BOMBA_H
#define _BOMBA_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
const int TEMPO_EXPLOSAO = 3;

class Bomba{
    public:
    ALLEGRO_BITMAP *imagens[2];
    bool existe_bomba;
    bool explodir;
    bool explodindo;
    int conta_frame;
    int x;
    int y;

    Bomba();
    void Put_bomba(int x, int y);
    void checar_explosao ();
    void explode();
    void update();
    void Render();
  };



#endif // _BOMBA_H
