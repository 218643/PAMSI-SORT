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
  int nr=0; //element dodany po to, by dac liscie swiadomosc swojego rozmiaru
public:

  //konstruktor bezparametryczny

  Lista();

  Lista(string elem);

    //Sprawdzanie, czy lista jest pusta.
  virtual bool empty();  

  //Zwraca wartosc z podanego miejsca na liscie, nie usuwajac elementu.
  virtual string get(int indeks);

  //Zwraca ilosc elementow na liscie.
  virtual int size();
  
  //Wrzucanie elementu na poczatek listy
  virtual void push_front(string element);

  //Wrzucanie elementu na koniec listy
  virtual void push_back(string element);

  //Wrzucanie elementu na odpowiednie miejsce na liscie
  virtual void push_ind(string element,int indeks);

  //Usuwanie jednego elementu z przodu listy,zwraca jeg wartosc.
  virtual string pop_front();

  //Usuwanie jednego elementu z tylu listy,zwraca jeg wartosc.
  virtual string pop_back();

  //Usuwanie elementow listy od start do end, przy traceniu ich wartosci.
  virtual void erase(int start,int end);


  ~Lista();

};
