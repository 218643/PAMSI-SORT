
class Ilista
{
public:
  //Sprawdzanie, czy lista jest pusta.
  virtual bool empty()=0;  
  
  //Wrzucanie elementu na odpowiednie miejsce na liscie
  virtual void push(string element,int indeks)=0;

  //Usuwanie elementow listy od start do end, przy traceniu ich wartosci.
  virtual bool erase(int start,int end)=0;
  
  //Usuwanie jednego elementu z wybranego miejsca,zwraca jeg wartosc.
  virtual string pop(int indeks)=0;

  //Zwraca wartosc z podanego miejsca na liscie, nie usuwajac elementu.
  virtual string get(int indeks)=0;
  
  //Zwraca ilosc elementow na liscie.
  virtual int size()=0;
};
