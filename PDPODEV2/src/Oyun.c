/**
*
* @author Eray Sari eray.sari2@ogr.sakarya.edu.tr
* @since 19.05.23
* <p>
* Tüm oyun bu class icerisinde dönüyor
* </p>
*/

#include "Oyun.h"
#include "Koloni.h"


Oyun OyunOlustur() {
	Oyun this;
	this = (Oyun)malloc(sizeof(struct OYUN));
	this->basla = &basla;
	this->yokEt = &OyunYoket;
	return this;
}
void SavasSonucu(Koloni kazanan, Koloni kaybeden) {

	int fark;
	if (kazanan->getSonuc(kazanan) == kaybeden->getSonuc(kaybeden)) {
		fark = 500;
	}
	else {
		fark = kazanan->getSonuc(kazanan) - kaybeden->getSonuc(kaybeden);
	}


	int kaybedenPop = kaybeden->getPop(kaybeden);
	int oran = fark / 10;

	kaybeden->setPop(kaybeden,(kaybedenPop - (kaybedenPop * oran / 100) + 1));
	kaybeden->setStok(kaybeden,(kaybeden->getStok(kaybeden) - (kaybedenPop * oran / 100)));
	kazanan->setStok(kazanan,(kazanan->getStok(kazanan) + (kaybedenPop * oran / 100)));


	kazanan->setWin(kazanan,kazanan->getWin(kazanan) + 1);
	kaybeden->setLost(kaybeden,kaybeden->getLost(kaybeden) + 1);

}
void sonuclariYazdir(Koloni k[], int koloniSayisi, int tur) {
	printf("\n");
	printf("------------------------------------------------------------------");
	printf("\n");

	printf("Tur Sayisi: %d\n ", tur);

	printf("% s\n", "Koloni   Populasyon   YemekStogu   Kazanma   Kaybetme");

	for (int i = 0; i < koloniSayisi; i++) {

		k[i]->yazdir(k[i]);
		printf("\n");

	}
	printf("------------------------------------------------------------------");
	printf("\n");
}
void basla(const Oyun this) {

	char str[50];
	int koloniSayisi = 0;
	int girilenKoloni[15];
	int turSayisi = 0;
	int sonuclar[50];
	int uretDegerler[20];
	int randomIcin = 0;
	int elenen = 0;	

	Taktik1 taktik1 = Taktik1Olustur();
	Taktik2 taktik2 = Taktik2Olustur();
	Uretim1 uret1 = Uretim1Olustur();
	Uretim2 uret2 = Uretim2Olustur();

	printf("Populasyonlari girin: ");
	fgets(str, sizeof(str), stdin);
	char* token = strtok(str, " ");

	while (token != NULL) {	
		girilenKoloni[koloniSayisi] = atoi(token);
		koloniSayisi++;
		token = strtok(NULL, " ");
	}

	//Koloni dizisi olusturuluyor
	Koloni k[koloniSayisi];

	//koloniler olusturuluyor
	for (int i = 0; i < koloniSayisi; i++) {
		k[i] = KoloniOlustur(girilenKoloni[i], 34+i);
	}
	
	while (elenen +1< koloniSayisi) {
		sonuclariYazdir(k, koloniSayisi, turSayisi);

		for (int i = 0; i < koloniSayisi - 1; i++) {
			for (int j = i + 1; j < koloniSayisi; j++) {
				if (k[i]->getPop(k[i]) <= 0 || k[j]->getPop(k[j]) <= 0) {
					
					//elenmis koloni savasmadan atlanir
					continue;
				}

				for (int q = 0; q < 25; q++) {
					sonuclar[q] = taktik1->super->savas(taktik1, q + 1);
				}
				for (int z = 25; z < 50; z++) {
					sonuclar[z] = taktik2->super->savas(taktik2,z);
				}

				int random1;
				int random2;


				srand(time(0));
				random1 = (rand() % 4) + j + (i*2) + randomIcin;
				random2 = (rand() % 9) + (j+1)*2 + randomIcin + 1;

				//printf("\n%d %d", random1, random2);
				k[i]->setSonuc(k[i], sonuclar[random1]);
				k[j]->setSonuc(k[j], sonuclar[random2]);

				if (k[i]->getSonuc(k[i]) > k[j]->getSonuc(k[j]))	SavasSonucu(k[i], k[j]);
				else if (k[i]->getSonuc(k[i]) < k[j]->getSonuc(k[j]))	SavasSonucu(k[j], k[i]);
				else {

					if (k[i]->getPop(k[i]) > k[j]->getPop(k[j]))	SavasSonucu(k[i], k[j]);
					else if (k[i]->getPop(k[i]) < k[j]->getPop(k[j]))	SavasSonucu(k[j], k[i]);
					else {
						if((turSayisi % 2) == 0)	SavasSonucu(k[i], k[j]);
						else
						{
							SavasSonucu(k[j], k[i]);
						}
					}
				}
			}
			randomIcin++;
		}

		for (int a = 0; a < 10; a++) {
			uretDegerler[a] = uret1->super->uret(uret1,a);
		}
		for (int b = 10; b < 20; b++) {
			uretDegerler[b] = uret2->super->uret(uret2,b - 7);
		}

		//tur sonu ekleme - cikarma
		for (int c = 0; c < koloniSayisi; c++) {

			int uretDegerSec = rand() % 10 + c*(koloniSayisi/2);

			int sonStok = k[c]->getStok(k[c]);
					
			if (uretDegerSec < 20)	k[c]->setStok(k[c], (sonStok + uretDegerler[uretDegerSec]));
			else
			{
				if (uretDegerSec < 20)	k[c]->setStok(k[c], (sonStok + uretDegerler[rand() % 10 + c + 1]));
			}

			if (k[c]->getPop(k[c]) != 0 && k[c]->getStok(k[c]) != 0) {
				int populasyon = k[c]->getPop(k[c]);
				int yemekStok = k[c]->getStok(k[c]) - (populasyon * 2);
				k[c]->setPop(k[c], populasyon + (populasyon * 20 / 100));
				k[c]->setStok(k[c], yemekStok);

				if (k[c]->getPop(k[c]) <= 0 || k[c]->getStok(k[c]) <= 0)	elenen++;

			}			
			if (k[c]->getPop(k[c]) <= 0 || k[c]->getStok(k[c]) <= 0) {
				k[c]->setPop(k[c],0);
				k[c]->setStok(k[c],0);
				k[c]->setWin(k[c],0);
				k[c]->setLost(k[c],0);
				
			}
		}

		turSayisi++;

	}
	sonuclariYazdir(k, koloniSayisi, turSayisi);
}
void OyunYoket(const Oyun this) {
	
	if (this == NULL) return;
	free(this);
}
