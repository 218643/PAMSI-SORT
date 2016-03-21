#include <cstdio>
#include <unistd.h>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

#include "Stos.hh"
#include "tablica.hh"
#include "test_lista.hh"
#include "BubbleSort.hh"


//Argc - zawiera informacje o ilosci komend wpisanych do terminala.
//Argv[] - tablica, zawiera nazwy wpisacnych komend, plikow.
int main(int Argc, char* Argv[])
{
  Tablica tab(10000);
  int i=0;
  for(i=0;i<10000;i++)
    {
      tab.dopiszx2(i,rand() % 100);
    }
  tab.dotnij(i);

  //tab.wyswietl();

  BubbleSort(tab,i);

  //tab.wyswietl();


  // test_lista test;  
  //test.run(Argc,Argv);
  //test.wyswietl_wynik();
}
