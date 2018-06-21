#ifndef _FASE_1_H_
#define _FASE_1_H_

void colocar_barreiras( GameObjectList *lista_gameobjects){
//(std::string nome, float posicao_x, float posicao_y,  float altura, float largura, std::string diretorio, std::string nome_img, std::string extensao_img, int qt_img)
    int y = 15;
    int x = 0;;
    int alt = 50;
    int larg = 50;
    Barreira *barreira1 = new   Barreira("barreira1", 100+x, 100+y,  alt, larg, "img/", "barreira", ".png", 1);
    Barreira *barreira2 = new   Barreira("barreira2", 200+x, 100+y,  alt, larg, "img/", "barreira", ".png", 1);
    Barreira *barreira3 = new   Barreira("barreira3", 300+x, 100+y,  alt, larg, "img/", "barreira", ".png", 1);
    Barreira *barreira4 = new   Barreira("barreira4", 400+x, 100+y,  alt, larg, "img/", "barreira", ".png", 1);
    Barreira *barreira5 = new   Barreira("barreira5", 500+x, 100+y,  alt, larg, "img/", "barreira", ".png", 1);
    Barreira *barreira6 = new   Barreira("barreira6", 600+x, 100+y,  alt, larg, "img/", "barreira", ".png", 1);
    Barreira *barreira7 = new   Barreira("barreira7", 700+x, 100+y,  alt, larg, "img/", "barreira", ".png", 1);
    Barreira *barreira8 = new   Barreira("barreira8", 100+x, 200+y,  alt, larg, "img/", "barreira", ".png", 1);
    Barreira *barreira9 = new   Barreira("barreira9", 200+x, 200+y,  alt, larg, "img/", "barreira", ".png", 1);
    Barreira *barreira10 = new  Barreira("barreira10", 300+x, 200+y,  alt, larg, "img/", "barreira", ".png", 1);
    Barreira *barreira11 = new  Barreira("barreira11", 400+x, 200+y,  alt, larg, "img/", "barreira", ".png", 1);
    Barreira *barreira12 = new  Barreira("barreira12", 500+x, 200+y,  alt, larg, "img/", "barreira", ".png", 1);
    Barreira *barreira13 = new   Barreira("barreira13", 600+x, 200+y, alt, larg, "img/", "barreira", ".png", 1);
    Barreira *barreira14 = new   Barreira("barreira14", 700+x, 200+y, alt, larg, "img/", "barreira", ".png", 1);
    Barreira *barreira15 = new   Barreira("barreira15", 100+x, 300+y, alt, larg, "img/", "barreira", ".png", 1);
    Barreira *barreira16 = new   Barreira("barreira16", 200+x, 300+y, alt, larg, "img/", "barreira", ".png", 1);
    Barreira *barreira17 = new   Barreira("barreira17", 300+x, 300+y, alt, larg, "img/", "barreira", ".png", 1);
    Barreira *barreira18 = new   Barreira("barreira18", 400+x, 300+y, alt, larg, "img/", "barreira", ".png", 1);
    Barreira *barreira19 = new   Barreira("barreira19", 500+x, 300+y, alt, larg, "img/", "barreira", ".png", 1);
    Barreira *barreira20 = new   Barreira("barreira20", 600+x, 300+y, alt, larg, "img/", "barreira", ".png", 1);
    Barreira *barreira21 = new   Barreira("barreira21", 700+x, 300+y, alt, larg, "img/", "barreira", ".png", 1);
    Barreira *barreira22 = new  Barreira("barreira22", 100+x, 400+y,  alt, larg, "img/", "barreira", ".png", 1);
    Barreira *barreira23 = new  Barreira("barreira23", 200+x, 400+y,  alt, larg, "img/", "barreira", ".png", 1);
    Barreira *barreira24 = new  Barreira("barreira24", 300+x, 400+y,  alt, larg, "img/", "barreira", ".png", 1);
    Barreira *barreira25 = new   Barreira("barreira25", 400+x, 400+y, alt, larg, "img/", "barreira", ".png", 1);
    Barreira *barreira26 = new   Barreira("barreira26", 500+x, 400+y, alt, larg, "img/", "barreira", ".png", 1);
    Barreira *barreira27 = new   Barreira("barreira27", 600+x, 400+y, alt, larg, "img/", "barreira", ".png", 1);
    Barreira *barreira28 = new   Barreira("barreira28", 700+x, 400+y, alt, larg, "img/", "barreira", ".png", 1);
    Barreira *barreira29 = new   Barreira("barreira29", 100+x, 500+y,  alt, larg, "img/", "barreira", ".png", 1);
    Barreira *barreira30 = new   Barreira("barreira30", 200+x, 500+y,  alt, larg, "img/", "barreira", ".png", 1);
    Barreira *barreira31 = new   Barreira("barreira31", 300+x, 500+y,  alt, larg, "img/", "barreira", ".png", 1);
    Barreira *barreira32 = new  Barreira("barreira32", 400+x, 500+y,  alt, larg, "img/", "barreira", ".png", 1);
    Barreira *barreira33 = new  Barreira("barreira33", 500+x, 500+y,  alt, larg, "img/", "barreira", ".png", 1);
    Barreira *barreira34 = new  Barreira("barreira34", 600+x, 500+y,  alt, larg, "img/", "barreira", ".png", 1);
    Barreira *barreira35 = new  Barreira("barreira35", 700+x, 500+y,  alt, larg, "img/", "barreira", ".png", 1);


    lista_gameobjects->Adicionar(barreira1);
    lista_gameobjects->Adicionar(barreira2);
    lista_gameobjects->Adicionar(barreira3);
    lista_gameobjects->Adicionar(barreira4);
    lista_gameobjects->Adicionar(barreira5);
    lista_gameobjects->Adicionar(barreira6);
    lista_gameobjects->Adicionar(barreira7);
    lista_gameobjects->Adicionar(barreira8);
    lista_gameobjects->Adicionar(barreira9);
    lista_gameobjects->Adicionar(barreira10);
    lista_gameobjects->Adicionar(barreira11);
    lista_gameobjects->Adicionar(barreira12);
    lista_gameobjects->Adicionar(barreira13);
    lista_gameobjects->Adicionar(barreira14);
    lista_gameobjects->Adicionar(barreira15);
    lista_gameobjects->Adicionar(barreira16);
    lista_gameobjects->Adicionar(barreira17);
    lista_gameobjects->Adicionar(barreira18);
    lista_gameobjects->Adicionar(barreira19);
    lista_gameobjects->Adicionar(barreira20);
    lista_gameobjects->Adicionar(barreira21);
    lista_gameobjects->Adicionar(barreira22);
    lista_gameobjects->Adicionar(barreira23);
    lista_gameobjects->Adicionar(barreira24);
    lista_gameobjects->Adicionar(barreira25);
    lista_gameobjects->Adicionar(barreira26);
    lista_gameobjects->Adicionar(barreira27);
    lista_gameobjects->Adicionar(barreira28);
    lista_gameobjects->Adicionar(barreira29);
    lista_gameobjects->Adicionar(barreira30);
    lista_gameobjects->Adicionar(barreira31);
    lista_gameobjects->Adicionar(barreira32);
    lista_gameobjects->Adicionar(barreira33);
    lista_gameobjects->Adicionar(barreira34);
    lista_gameobjects->Adicionar(barreira35);


}

void fase_1(GameObjectList *lista_gameobjects){
   colocar_barreiras(lista_gameobjects);
   return;
}

#endif // _FASE_1_H_
