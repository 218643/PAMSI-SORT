
class Istots
{
public:
  //Sprawdzanie, czy kolejka jest pusta.
  virtual bool empty()=0;  
  
  //Wrzucanie elementu na koniec kolejki
  virtual bool push(string element)=0;
  
  //Sciaganie elementu z poczatku kolejki.
  virtual string pop()=0;

  //Zwraca wartosc ze szczytu stosu, bez jej usuwania.
  virtual string front()=0;

  //Zwraca wartosc statniego elemetu kolejki, bez jej usuwania.
  virtual strin end()=0;
  
  //Zwraca ilosc elementow na stoosie.
  virtual int size()=0;
};
