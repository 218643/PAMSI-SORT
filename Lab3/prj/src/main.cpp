#include <cstdio>
#include <unistd.h>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;


#include "test_lista.hh"
#include "Stoper.hh"

//Argc - zawiera informacje o ilosci komend wpisanych do terminala.
//Argv[] - tablica, zawiera nazwy wpisacnych komend, plikow.
int main(int Argc, char* Argv[])
{
  int iloscelem = 10;
  test_lista test;
  Stoper stoper;
  test.ilosc_elementow = iloscelem;
  test.generateINT(iloscelem);
  stoper.Start(); //wystartowanie zegara
  test.run(Argc,Argv);
  test.zapisDoTabeli();
  test.quick_sort(test.tab,0,iloscelem);
  //test.mergesort(test.tab,0,iloscelem);
  test.zapisdoPliku("posortowane.txt");
  stoper.Stop();
  std::cout <<"Czas sortowania:"<< stoper.getElapsedTime() << std::endl;
  //test.wyswietl_wynik();

}

