#include "Lista.hh"
#include "Irunnable.hh"
#include "Istoper.hh"
#include <fstream>

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
    int tab[10000];
  test_lista();
  virtual void start();
  virtual void stop();
  virtual long get_time();
  void generateINT(int gen);
  void quick_sort(int tab[], int left, int right);
  void wyswietl_wynik();
  string losuj_slowo();
  void szukaj(string los);
  void zapisDoTabeli();
  void zapisdoPliku(std::string const&);
  virtual bool run(int Argc,char* Argv[]);
};
