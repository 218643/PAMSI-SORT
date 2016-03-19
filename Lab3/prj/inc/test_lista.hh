#include "Lista.hh"
#include "Irunnable.hh"
#include "Istoper.hh"

class test_lista: public Lista, public Irunnable, public Istoper 
{
protected:
  int size; //rozmiar problemu
  clock_t sta;
  clock_t end;
public:
  
  test_lista();

  /**Irunnable**/
  //Gdy dobiegnie zwraca true
  virtual bool run(int Argc,char *argv[]);

  /**Istoper**/
  virtual void start();

  virtual void stop();

  virtual long get_time();
  
  void wyswietl_wynik();
};
