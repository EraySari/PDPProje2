#ifndef URETIM_H
#define URETIM_H


#include "stdio.h"
#include "stdlib.h"
#include "time.h"

struct URETIM
{
	int (*uret)();
};

typedef struct URETIM* Uretim;

Uretim UretimOlustur();
#endif
