#include <cstdio>
#include <unistd.h>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;


#include"test_lista.hh"

//Argc - zawiera informacje o ilosci komend wpisanych do terminala.
//Argv[] - tablica, zawiera nazwy wpisacnych komend, plikow.
int main(int Argc, char* Argv[])
{
  test_lista test;  
  test.run(Argc,Argv);
  test.wyswietl_wynik();
}
