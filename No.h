#ifndef _NO_H_
#define _NO_H_

class No : public GameObject{
public:
	GameObject *valor_gobj;
	No *prox_gobj; // APONTA PARA O PROX GAMEOBJECT DA LISTA
	No();
	~No();
};

#endif
