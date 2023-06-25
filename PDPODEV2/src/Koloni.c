/**
*
* @author Eray Sari eray.sari2@ogr.sakarya.edu.tr
* @since 19.05.23
* <p>
* Koloninin get set fonksiyonlarinin fonksiyon göstericileri ayarlaniyor
* </p>
*/
#include "Koloni.h"


Koloni KoloniOlustur(int pop,char symbol) {
	Koloni this;
	this = (Koloni)malloc(sizeof(struct KOLONI));

	this->symbol = symbol;
	this->pop = pop;
	this->stok = pop * pop;
	this->win = 0;
	this->lost = 0;
	this->sonuc = 0;
	this->yazdir = &yazdir;
	this->getStok = &getStok;	
	this->getPop = &getPop;
	this->setPop = &setPop;
	this->setStok = &setStok;
	this->getLost = &getLost;
	this->setLost = &setLost;	
	this->getWin = &getWin;
	this->setWin = &setWin;
	this->getSonuc = &getSonuc;
	this->setSonuc = &setSonuc;
	this->yoket = &KoloniYoket;

	return this;
}
void yazdir(const Koloni this) {

	if (this->getPop(this) == 0 || this->getStok(this) == 0) {
		printf(" %c", this->symbol);
		printf("\t   %s", "--");
		printf(" \t\t  %s", "--");
		printf("\t  \t%s", "--");
		printf("  \t%s", "--");
	}
	else {
	printf(" %c", this->symbol);
	printf("\t   %d",this->pop);
	printf(" \t\t  %d", this->stok);
	printf("\t  \t%d", this->win);
	printf("  \t%d", this->lost);
	}

}

int getPop(const Koloni this) {
	return this->pop;
}
void setPop(const Koloni this, int pop) {
	this->pop = pop;
}

int getStok(const Koloni this) {
	return this->stok;
}
void setStok(const Koloni this, int stok) {
	this->stok = stok;
}

int getWin(const Koloni this) {
	return this->win;
}
void setWin(const Koloni this, int win) {
	this->win = win;
}

int getLost(const Koloni this) {
	return this->lost;
}
void setLost(const Koloni this, int lost) {
	this->lost = lost;
}

int getSonuc(const Koloni this) {
	return this->sonuc;
}
void setSonuc(const Koloni this, int sonuc) {
	this->sonuc = sonuc;
}

void KoloniYoket(const Koloni this) {
	free(this);
}