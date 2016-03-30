#include "Ikolejka.hh"

class Ele
{
  Ele* prev;
  Ele* next;
  string wartosc;
  friend class Kolejka;
};

class Kolejka: public Ikolejka
{
protected:
  Ele* przod;
  Ele* tyl;
public:
  Kolejka();
  Kolejka(string elem);
  virtual bool empty();  
  virtual void push(string element);
  virtual string pop();
  virtual string front();
  virtual string end();
  virtual int size();
  ~Kolejka();
};
