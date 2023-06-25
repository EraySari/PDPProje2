#ifndef KOLONI_H
#define KOLONI_H

#include "Taktik1.h"
#include "Taktik2.h"
#include "Math.h"

struct KOLONI {
	char symbol;
	int pop;
	int stok;
	int win;
	int lost;
	int sonuc;

	void (*yazdir)(struct KOLONI*);
	int (*getPop)(struct KOLONI*);
	void (*setPop)(struct KOLONI*,int);
	int (*getStok)(struct KOLONI*);
	void (*setStok)(struct KOLONI*, int);
	int (*getWin)(struct KOLONI*);
	void (*setWin)(struct KOLONI*, int);
	int (*getLost)(struct KOLONI*);
	void (*setLost)(struct KOLONI*, int);
	int (*getSonuc)(struct KOLONI*);
	void (*setSonuc)(struct KOLONI*, int);
	void (*yoket)(struct KOLONI*);
};
typedef struct KOLONI* Koloni;

Koloni KoloniOlustur(int,char);
void toString(const Koloni);

int getPop(const Koloni);
void setPop(const Koloni,int);

int getStok(const Koloni);
void setStok(const Koloni,int);

int getWin(const Koloni);
void setWin(const Koloni, int);

int getLost(const Koloni);
void setLost(const Koloni, int);

int getSonuc(const Koloni);
void setSonuc(const Koloni, int);

void yazdir(const Koloni);

void KoloniYoket(const Koloni);

#endif