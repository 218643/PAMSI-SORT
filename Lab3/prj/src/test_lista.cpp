#include <cstdio>
#include <unistd.h>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

#include "test_lista.hh"



test_lista::test_lista()
{
  siz=0;
  sta=0;
  end=0;
}

void test_lista:: start()
{
  sta=clock();
}

void test_lista:: stop()
{
  end=clock();
}

long test_lista:: get_time()
{
  return 1000./CLOCKS_PER_SEC*(end-sta);
}

void test_lista::wyswietl_wynik()
{
  cout << get_time() << endl;
}

string test_lista:: losuj_slowo()
{
  srand (time(NULL));   //ustawienie zarodka, by przy kazdym uruchom prog       
                        //losowalo inne liczby
  Kaf* tmp=this->przod;
  int rn= rand() % (siz+1); //Losowanie elementu, ktory ma zostac wyszukany
  for(int i=0;i<(rn-1);i++) //rn-1,bo indeksuje od 0
    {
      tmp=tmp->prev;
    }
  string slowo=tmp->wartosc;
  cout <<"Los:  "<< slowo << endl;
  //delete tmp;
  return slowo;
}

void test_lista::szukaj(string los)
{
  start();
  while(get()!=los)
    {
      pop_front();
    }
  stop();
}

bool test_lista:: run(int Argc,char* Argv[])
{
  if(Argc!=2)
    {
      cerr << "Niewlasciwa ilosc plikow na wejsciu."<< endl;
      return false;
    }
  else
    {
      //***************Obsluga pliku***************//
      string elem;
      fstream plik; //zmienna pozwalajaca otworzyc strumien plikowy
      plik.open(Argv[1],ios::in); //otwarcie strumienia plikowego
      if(plik.good()) //jezeli udalo sie otworzyc plik
	{
	  while(!plik.eof())
	    {
	      plik >> elem;
	      push_front(elem);
	    }
	  pop_front();
	}
      plik.close(); //zamkniecie strumienia plikowego
    
      siz=size(); //ustawienie rozmiaru problemu  
      
      szukaj(losuj_slowo());
	  
    }
  return true;
  //*********************************//
}

