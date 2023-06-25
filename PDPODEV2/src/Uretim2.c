#include "Uretim2.h"

Uretim2 Uretim2Olustur() {
	Uretim2 this;
	this = (Uretim2)malloc(sizeof(struct URETIM2));

	this->super = UretimOlustur();
	this->super->uret = &Uret;
	return this;
}
int Uret(const Uretim2 this,int a) {
	srand(time(NULL));
	return (rand() % 2 + a);
}