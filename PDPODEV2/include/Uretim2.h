#ifndef URETIM2_H
#define URETIM2_H

#include "Uretim.h"

struct URETIM2 {
	Uretim super;
};
typedef struct URETIM2* Uretim2;
Uretim2 Uretim2Olustur();
int Uret(const Uretim2,int);

#endif