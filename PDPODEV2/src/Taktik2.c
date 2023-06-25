#include "Taktik2.h"

Taktik2 Taktik2Olustur() {
	Taktik2 this;
	this = (Taktik2)malloc(sizeof(struct TAKTIK2));
	
	this->super = TaktikOlustur();
	this->super->savas = &savas;
	return this;
}
int savas(const Taktik2 this,int b) {
	time_t t;
	srand((unsigned)time(&t));
	int r = rand() % 600;
	return (r + b*b - b*2);
}