#include <cstdio>
#include <unistd.h>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;


#include"Lista.hh"

//Argc - zawiera informacje o ilosci komend wpisanych do terminala.
//Argv[] - tablica, zawiera nazwy wpisacnych komend, plikow.
int main(int Argc, char* Argv[])
{
  fstream plik; //zmienna pozwalajaca otworzyc strumien plikowy
  plik.open(Argv[1],ios::in); //otwarcie strumienia plikowego
  if(plik.good()) //jezeli udalo sie otworzyc plik

  plik.close(); //zamkniecie strumienia plikowego
}
