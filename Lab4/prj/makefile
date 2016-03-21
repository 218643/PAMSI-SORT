FLAGS=-g -Iinc -pedantic -Wall -std=c++0x

Lab4: obj obj/main.o obj/lista.o obj/test_lista.o obj/stos.o obj/tablica.o
	g++ -pedantic -Wall -std=c++0x -o Lab4 obj/main.o obj/lista.o obj/test_lista.o obj/stos.o obj/tablica.o

obj:
	mkdir obj

obj/main.o: src/main.cpp inc/Lista.hh inc/Stos.hh inc/tablica.hh inc/BubbleSort.hh
	g++ -c ${FLAGS} -o obj/main.o src/main.cpp

obj/lista.o: src/lista.cpp inc/Lista.hh inc/Ilista.hh
	g++ -c ${FLAGS} -o obj/lista.o src/lista.cpp

obj/test_lista.o: src/test_lista.cpp inc/test_lista.hh inc/Irunnable.hh inc/Istoper.hh
	g++ -c ${FLAGS} -o obj/test_lista.o src/test_lista.cpp

obj/stos.o: src/stos.cpp inc/Stos.hh inc/Istos.hh
	g++ -c ${FLAGS} -o obj/stos.o src/stos.cpp

obj/tablica.o: src/tablica.cpp inc/tablica.hh inc/Itablica.hh
	g++ -c ${FLAGS} -o obj/tablica.o src/tablica.cpp

make clear:
	rm -r obj/*
	rm Lab4
