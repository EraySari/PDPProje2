/**
*
* @author Eray Sari eray.sari2@ogr.sakarya.edu.tr
* @since 19.05.23
* <p>
* Oyunun baslatildigi main sinifi
* </p>
*/
#include "Taktik1.h"
#include "Taktik2.h"
#include "Uretim1.h"
#include "Uretim2.h"
#include "Math.h"
#include "Koloni.h"
#include "Oyun.h"

int main() {
		
	Oyun oyun = OyunOlustur();
	oyun->basla(oyun);
	oyun->yokEt(oyun);

	return 0;
}
