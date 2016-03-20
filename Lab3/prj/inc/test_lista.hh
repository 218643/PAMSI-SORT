#include "Lista.hh"
#include "Irunnable.hh"
#include "Istoper.hh"

#define ILOSC_OKRAZEN 10

class test_lista: public Lista, public Irunnable, public Istoper 
{
protected:
  int siz; //rozmiar problemu
  clock_t sta;
  clock_t end;
  int wynik;
public:
  
  test_lista();
  virtual void start();
  virtual void stop();
  virtual long get_time();  
  void wyswietl_wynik(); 
  string losuj_slowo();
  void szukaj(string los);
  virtual bool run(int Argc,char* Argv[]); 
};
