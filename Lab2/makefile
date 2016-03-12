FLAGS=-g -Iinc -pedantic -Wall -std=c++0x

Lab2: obj obj/main.o obj/tablica.o obj/test_tab.o
	g++ -pedantic -Wall -std=c++0x -o Lab2 obj/main.o obj/tablica.o obj/test_tab.o

obj:
	mkdir obj

obj/main.o: src/main.cpp inc/tablica.hh inc/test_tab.hh
	g++ -c ${FLAGS} -o obj/main.o src/main.cpp

obj/tablica.o: src/tablica.cpp inc/tablica.hh inc/Itablica.hh
	g++ -c ${FLAGS} -o obj/tablica.o src/tablica.cpp

obj/test_tab.o: src/test_tab.cpp inc/test_tab.hh inc/Irunnable.hh inc/Istoper.hh inc/tablica.hh
	g++ -c ${FLAGS} -o obj/test_tab.o src/test_tab.cpp

make clear:
	rm -r obj/*
