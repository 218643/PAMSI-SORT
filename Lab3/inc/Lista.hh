#include "Ilista.hh"
#include "Tablica.hh"

class Elem
{
  Elem* prev;
  Elem* next;
  string wartosc;
  friend class Lista;
};

class Lista: public Ilista
{
protected:
  Elem* przod;
  Elem* tyl;
public:

  //konstruktor bezparametryczny

  Lista();

  Lista(string elem);

  virtual bool empty();
  
  virtual void push(string element,int indeks);  

  //Usuwanie elementow listy od start do end, przy traceniu ich wartosci.
  virtual bool erase(int start,int end);
  
  //Usuwanie jednego elementu z wybranego miejsca,zwraca jeg wartosc.
  virtual string pop(int indeks);

  //Zwraca wartosc z podanego miejsca na liscie, nie usuwajac elementu.
  virtual string get(int indeks);
  
  //Zwraca ilosc elementow na liscie.
  virtual int size();

  ~Lista();

};
