#include <cstdio>
#include <unistd.h>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;


#include "test_lista.hh"

//Argc - zawiera informacje o ilosci komend wpisanych do terminala.
//Argv[] - tablica, zawiera nazwy wpisacnych komend, plikow.
int main(int Argc, char* Argv[])
{

  test_lista test;
  test.generateINT(20);
  test.run(Argc,Argv);
  test.zapisDoTabeli();
  test.quick_sort(test.tab,0,20);
  //test.mergesort(int pocz, int sr, int kon);
  test.zapisdoPliku("posortowane.txt");
  test.wyswietl_wynik();
}

