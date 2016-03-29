#include "Istos.hh"

class Elem
{
  Elem* prev;
  string wartosc;
  friend class Stos;
};

class Stos: public Istos
{
protected:
  Elem* przod;
public:
  Stos();
  Stos(string element);
  virtual bool empty();
  virtual void push(string element);
  virtual string pop();
  virtual void erase(int end);
  virtual string top();
  virtual int size();
  ~Stos();
};
