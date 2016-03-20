#include <cstdio>
#include <unistd.h>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

#include "Lista.hh"

/*!
 *\file
 *\brief Definicje funkcji oraz metod klasy Lista.
 * Plik ten zawierqa definicje funkcji oraz metod
 * dla obiektow klasy Lista. Sa one umieszczone tutaj
 * a nie w pliku naglowkowym aby zwiekszyc przejrzystosc 
 * kodu.
 */

/*!
 *\brief Konstruktor bezparametryczny dla obiektow klasy Lista.
 */
Lista:: Lista()
{
  przod=NULL;
  tyl=NULL;
}

//Konstruktor parametryczny, twrzy kafelek i sprawia, ze oba wskazniki klasy
//Lista wskazuja na niego
Lista:: Lista(string elem)
{
  Kaf* kafelek=new Kaf(); //tworze nowy kafelek
  kafelek->next=NULL; //nastepny element to NULL
  kafelek->prev=NULL; //poprzedni element to NULL
  kafelek->wartosc=elem; //nadanie wartsci kafelka
  przod=kafelek;     //wskaznik przod klasy Lista wsakazuje na nowy kafelek
  tyl=kafelek;      //tyl rowniez
  nr++;
}

//Metoda zwraca true, gdy lista pusta, false, gdy cos na niej jest
bool Lista:: empty()
{
  if(przod==NULL && tyl==NULL)
    {
      //cerr << "Lista pusta." << endl;
      return true;
    }
  else
    {
      //cerr << "Na liscie znajduja sie elementy" << endl;
      return false;
    }
}

string Lista:: get()
  {
    if(!empty())
      return przod->wartosc;
    else
      return "/n";
  }


//Zwraca rozmiar listy 
int Lista:: size()
{
  int n=0;
  Kaf* bufo=przod;
  if(!empty())
    {
      while(bufo!=NULL)
	{
	  bufo=bufo->prev;
	  n++;
	}
    }
  delete bufo;
  return n;
}


void Lista::push_front(string element)
{
  Kaf* kafelek2=new Kaf();
  kafelek2->next=NULL;
  if(empty()) //jezeli pusta - to samo co w konstruktorze param.
    { 
      kafelek2->prev=NULL; 
      kafelek2->wartosc=element;
      przod=kafelek2;     
      tyl=kafelek2;
    }
  else
    {
      kafelek2->prev=przod;
      przod->next=kafelek2;
      przod=kafelek2;
      kafelek2->wartosc=element;
    }
  nr++;  
}


void Lista::push_back(string element)
{
  Kaf* kafelek2=new Kaf();
  kafelek2->prev=NULL; 
  if(empty()) //jezeli pusta - to samo co w konstruktorze param.
    {
      kafelek2->next=NULL; 
      kafelek2->wartosc=element;
      przod=kafelek2;     
      tyl=kafelek2;
      nr++;  
    }
  else
    {
      kafelek2->next=tyl;
      tyl->prev=kafelek2;
      tyl=kafelek2;
      kafelek2->wartosc=element;
    }
  nr++;
}


void Lista::push_ind(string element,int indeks)
{
  Kaf* kafelek2=new Kaf();
  if(empty()) //jezeli pusta - to samo co w konstruktorze param.
    {
      kafelek2->next=NULL; 
      kafelek2->prev=NULL; 
      kafelek2->wartosc=element;
      przod=kafelek2;     
      tyl=kafelek2;
      nr++;  
    }
  else
    {
      if(indeks >= nr)
      {
	przod->next=kafelek2;
	kafelek2->prev=przod;
	cout<<"Nr:  " <<nr<<endl;
	przod=kafelek2; 
	kafelek2->wartosc=element;
	nr++;
      }
      else //zmieniam wartosc zadanego kafelka
	{
	  if(nr==1)
	    przod->wartosc=element;
	  else
	    {
	      Kaf* tyl_tmp=tyl; //wsk na tylni element
	      for(int i=0; i<indeks;i++)
		{
		  tyl=tyl->next;
		}
	      tyl->wartosc=element; 
	      tyl=tyl_tmp;
	    }
	}
    }
}

//Sciaganie elementu z gory listy
string Lista:: pop_front()
{
  if(empty()) // Jezeli lista pusta
    {
      cerr <<"Nie ma czego usuwac." << endl;
      return "Nie ma czego usuwac.";
    }
  else
    {
      Kaf* tmp= przod; //zmienna pomocnicza
      string a=tmp->wartosc; //pobranie wartosci
      if(przod->prev==NULL) //Jezeli jeden element na liscie
	{
	  przod=NULL;
	  tyl=NULL;
	  tmp->next=NULL; 
	  tmp->prev=NULL;
	  delete tmp;
	}
      else
	{
	  przod=przod->prev; //cofniecie wskaznika z pierwszego kaf na drugi kaf
	  przod->next=NULL; //"odciecie" polaczenia z popowanym kafelkiem
	  tmp->next=NULL; 
	  tmp->prev=NULL;
	  delete tmp; //zwolnienie pamieci
	  nr--; //zmniejszenie rozmiaru listy 
	}
      return a;
    }
}

  
  
string Lista:: pop_back()
{
  if(empty()) // Jezeli lista pusta
    {
      cerr << "Nie ma czego usuwac" <<endl;
      return "Nie ma czego usuwac.";
    }
  else
    {
      Kaf* tmp=tyl;
      string a=tmp->wartosc;
      if(tyl->next==NULL)//jezeli jeden element na tablicy
	{
	  tyl=NULL;
	  przod=NULL;
	  tmp->next=NULL; 
	  tmp->prev=NULL;
	  delete tmp;
	  cerr << "Usunieto ostatni element" << endl;
	}
      else //jezeli wiecej elementow na tablicy
	{
	  tyl=tyl->next;
	  tyl->prev=NULL;
	  tmp->next=NULL;
	  tmp->prev=NULL;
	  delete tmp;
	  nr--;
	}
      return a;
    }
}


void Lista:: erase(int start,int end)
{
    if(empty()) // Jezeli lista pusta
      {
	cerr <<"Nie ma czego usuwac." << endl;
      }
    else
      {
	Kaf* tmp=tyl;
	if(start==end) //usuwanie jednego elementu
	  {
	    if(end==nr) //sytuacja skrajna, usuwanie elementu z konca tablicy
	      {
		
	      }
	    else if(end==0) //usuwanie elem z 
	      {

	      }
	    else
	      {
		for(int i = 0; i < end ;i++)
		  {
		    tyl=tyl->next;
		  }
		tyl->prev->next=tyl->next;
		tyl->next->prev=tyl->prev;
		delete tyl;
		tyl=tmp;
		nr--;
	      }
	  }
      }
}
    


Lista:: ~Lista()
{
  if(!empty())
    {
      while(przod!=tyl) //dopoki wskazniki nie wskazuja na to samo(jeden el na liscie)
	{
	  Kaf* tmp=przod;
	  przod=przod->prev;
	  przod->next=NULL;
	  tmp->next=NULL; 
	  tmp->prev=NULL;
	  delete tmp; //zwolnienie pamieci
	  nr--; //zmniejszenie rozmiaru listy 
	}
      Kaf* tmp=przod;
      tyl=NULL;
      przod=NULL;
      tmp->next=NULL; 
      tmp->prev=NULL;
      delete tmp;
      delete przod;
      delete tyl;
      nr=0;
    }
}
