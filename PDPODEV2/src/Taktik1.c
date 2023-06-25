#include "Taktik1.h"

Taktik1 Taktik1Olustur() {
	Taktik1 this;
	this = (Taktik1)malloc(sizeof(struct TAKTIK1));
	
	this->super = TaktikOlustur();
	this->super->savas = &Savas;
	return this;
}
int Savas(const Taktik1 this,int a) {
    srand(time(NULL));
	int b = rand() % 500;
    return (b + a*a);
}
