#ifndef TAKTIK2_H
#define TAKTIK2_H

#include "Taktik.h"

struct TAKTIK2 {
	Taktik super;

};
typedef struct TAKTIK2* Taktik2;
Taktik2 Taktik2Olustur();
int savas(const Taktik2,int);


#endif