#ifndef TECLADO_DOWN_UP
#define TECLADO_DOWN_UP
void key_down(comandosTeclado *teclas_teclado, ALLEGRO_EVENT *event, bool *mover){

    if (event->type == ALLEGRO_EVENT_KEY_DOWN){ // Se o evento foi alguma tecla
			switch (event->keyboard.keycode){
			case ALLEGRO_KEY_S: // Movimento para baixo
				teclas_teclado->key_S =true;

				teclas_teclado->key_A =false; //PARA CORRIGIR O PROBLEMA DE MULTIPLAS TECLAS APERTADAS
				teclas_teclado->key_W =false;
				teclas_teclado->key_D =false;
				break;
			case ALLEGRO_KEY_W: // Movimento para cima
				teclas_teclado->key_W = true;

				teclas_teclado->key_A =false;
				teclas_teclado->key_S =false;
				teclas_teclado->key_D =false;
				break;
			case ALLEGRO_KEY_D: // Movimento direita
				teclas_teclado->key_D = true;

				teclas_teclado->key_A =false;
				teclas_teclado->key_W =false;
				teclas_teclado->key_S =false;
				break;
			case ALLEGRO_KEY_A: // Movimento para esquerda
				teclas_teclado->key_A = true;

				teclas_teclado->key_S =false;
				teclas_teclado->key_W =false;
				teclas_teclado->key_D =false;
				break;
            case ALLEGRO_KEY_SPACE:
                teclas_teclado->key_space = true;
            }
			if(event->keyboard.keycode != ALLEGRO_KEY_SPACE) { *mover = true;}
		}
}
void key_up(comandosTeclado *teclas_teclado, ALLEGRO_EVENT *event, bool *mover){
		if (event->type == ALLEGRO_EVENT_KEY_UP){ // Se o evento foi alguma tecla
			switch (event->keyboard.keycode){
			case ALLEGRO_KEY_S: // Movimento para baixo
				teclas_teclado->key_S = false;
				*mover = false;
				break;
			case ALLEGRO_KEY_W: // Movimento para cima
				teclas_teclado->key_W = false;
				*mover = false;
				break;
			case ALLEGRO_KEY_D: // Movimento direita
                teclas_teclado->key_D = false;
                *mover = false;
				break;
			case ALLEGRO_KEY_A: // Movimento para esquerda
				teclas_teclado->key_A = false;
				*mover = false;
				break;
            case ALLEGRO_KEY_SPACE:
                teclas_teclado->key_space = false;
			}

		}
}


#endif // TECLADO_DOWN_UP
