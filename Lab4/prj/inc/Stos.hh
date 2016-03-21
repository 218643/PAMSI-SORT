#include "Istos.hh"

class Elem
{
  Elem* stos;
  string wartosc;
};

class Stos: public Istos
{
protected:
  Elem* przod;
public:
  Stos();
  Stos(int rozm);
  virtual bool empty();
  virtual bool push(string element);
  virtual string pop();
  virtual bool erase(int end);
  virtual string top();
  virtual int size();
};
