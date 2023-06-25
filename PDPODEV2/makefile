hepsi: derle calistir

derle:

	gcc -I ./include/ -o ./lib/Taktik.o -c ./src/Taktik.c
	gcc -I ./include/ -o ./lib/Taktik1.o -c ./src/Taktik1.c
	gcc -I ./include/ -o ./lib/Taktik2.o -c ./src/Taktik2.c
	gcc -I ./include/ -o ./lib/Uretim.o -c ./src/Uretim.c
	gcc -I ./include/ -o ./lib/Uretim1.o -c ./src/Uretim1.c
	gcc -I ./include/ -o ./lib/Uretim2.o -c ./src/Uretim2.c
	gcc -I ./include/ -o ./lib/Koloni.o -c ./src/Koloni.c
	gcc -I ./include/ -o ./lib/Oyun.o -c ./src/Oyun.c

	gcc -I ./include/ -o ./bin/Test ./lib/Taktik.o ./lib/Taktik1.o ./lib/Taktik2.o ./lib/Uretim.o ./lib/Uretim1.o ./lib/Uretim2.o ./lib/Koloni.o ./lib/Oyun.o ./src/Test.c
	
calistir:
	./bin/Test