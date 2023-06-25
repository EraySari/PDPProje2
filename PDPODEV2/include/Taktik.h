#ifndef TAKTIK_H
#define TAKTIK_H


#include "stdio.h"
#include "stdlib.h"
#include "time.h"

struct TAKTIK
{
	int (*savas)();
};

typedef struct TAKTIK* Taktik;

Taktik TaktikOlustur(); 
#endif
