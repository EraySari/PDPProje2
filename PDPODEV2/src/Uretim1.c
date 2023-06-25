#include "Uretim1.h"


Uretim1 Uretim1Olustur() {
	Uretim1 this;
	this = (Uretim1)malloc(sizeof(struct URETIM1));

	this->super = UretimOlustur();
	this->super->uret = &uret;
	return this;
}
int uret(const Uretim1 this,int a) {
	time_t t;
	srand((unsigned)time(&t));
	return (rand() % 2 + a);
}