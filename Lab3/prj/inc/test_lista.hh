#include "Lista.hh"
#include "Irunnable.hh"
#include "Istoper.hh"
#include <fstream>
#include <iostream>

#define ILOSC_OKRAZEN 10

class test_lista: public Lista, public Irunnable, public Istoper
{
protected:
  int siz; //rozmiar problemu
  clock_t sta;
  clock_t end;
  int wynik;
public:
    int ind;
    int ilosc_elementow;
    int tab[1000000];
  test_lista();
  virtual void start();
  virtual void stop();
  virtual long get_time();
  void generateINT(int gen);
  void quick_sort(int tab[], int left, int right);
  void merge ( int tab[], int start, int srodek, int koniec);
  void mergesort(int tab[], int start, int koniec);
  void wyswietl_wynik();
  string losuj_slowo();
  void szukaj(string los);
  void zapisDoTabeli();
  void zapisdoPliku(std::string const&);
  //void zapisdoPliku(std::int const&);
  virtual bool run(int Argc,char* Argv[]);

};
