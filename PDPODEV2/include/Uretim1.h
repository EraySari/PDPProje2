#ifndef URETIM1_H
#define URETIM1_H

#include "Uretim.h"

struct URETIM1 {
	Uretim super;
};
typedef struct URETIM1* Uretim1;
Uretim1 Uretim1Olustur();
int uret(const Uretim1,int);

#endif