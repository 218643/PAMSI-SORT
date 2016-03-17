FLAGS=-g -Iinc -pedantic -Wall -std=c++0x

Lab3: obj obj/main.o obj/tablica.o obj/lista.o
	g++ -pedantic -Wall -std=c++0x -o Lab3 obj/main.o obj/tablica.o obj/lista.o

obj:
	mkdir obj

obj/main.o: src/main.cpp src/tablica.cpp inc/Lista.hh inc/Tablica.hh
	g++ -c ${FLAGS} -o obj/main.o src/main.cpp

obj/lista.o: src/lista.cpp inc/Lista.hh inc/Ilista.hh
	g++ -c ${FLAGS} -o obj/lista.o src/lista.cpp

obj/tablica.o: src/tablica.cpp inc/Tablica.hh inc/Itablica.hh
	g++ -c ${FLAGS} -o obj/tablica.o src/tablica.cpp

make clear:
	rm -r obj/*
