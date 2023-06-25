#ifndef OYUN_H
#define OYUN_H


#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "Taktik1.h"
#include "Taktik2.h"
#include "Uretim1.h"
#include "Uretim2.h"


struct OYUN
{
	void (*basla)(struct OYUN*);
	void (*yokEt)(struct OYUN*);
};

typedef struct OYUN* Oyun;

Oyun OyunOlustur();
void basla(const Oyun);
void OyunYoket(const Oyun);
#endif
