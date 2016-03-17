#include "Ilista.hh"

class Kaf // Komorka twrzaca liste
{
  Kaf* prev;
  Kaf* next;
  string wartosc;
  friend class Lista;
};

class Lista: public Ilista
{
protected:
  Kaf* przod;
  Kaf* tyl;
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
