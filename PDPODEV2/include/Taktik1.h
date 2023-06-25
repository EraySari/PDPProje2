#ifndef TAKTIK1_H
#define TAKTIK1_H

#include "Taktik.h"
#include "unistd.h"

struct TAKTIK1 {
	Taktik super;
};
typedef struct TAKTIK1* Taktik1;
Taktik1 Taktik1Olustur();
int Savas(const Taktik1,int);


#endif