#include "Taktik.h"

Taktik TaktikOlustur() {
	Taktik this;
	this = (Taktik)malloc(sizeof(struct TAKTIK));
	return this;
}
