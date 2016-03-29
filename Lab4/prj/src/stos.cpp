#include <cstdio>
#include <unistd.h>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

#include "Stos.hh"

Stos::Stos()
{
  przod=NULL;
}

Stos::Stos(string element)
{
  Elem* Kaf=new Elem;
  Kaf->wartosc=element;
  Kaf->prev=NULL;
  przod=Kaf;
}

bool Stos::empty()
{
  if(przod==NULL)
    return true; //1
  else
    return false; //0
}

void Stos::push(string element)
{
  Elem* Kaf=new Elem;
  Kaf->wartosc=element;
  if(empty()) //pushowanie na pusty stos, jak w konstruktorze
    {
      Kaf->prev=NULL;
    }
  else //pushowanie na stos z elementami
    {
      Kaf->prev=przod;
    }  
  przod=Kaf;
}

string Stos::pop()
{
  if(empty())
    {
      cerr << "Stos pusty."<< endl;
      return "0";
    }
  else
    {
      Elem* tmp= przod;
      przod=przod->prev;
      tmp->prev=NULL;
      string wart=tmp->wartosc;
      delete tmp;
      return wart;
    }
}

void Stos::erase(int end)
{
  for(int i=0; i<end;i++)
    pop();
}

string Stos::top()
{
  if(!empty())
    return przod->wartosc;
  else
    return "0";
}

int Stos::size()
{
  Elem* buf=przod;
  int siz=0;
  while(buf!=NULL)
    {
      siz++;
      buf=buf->prev;
    }
  delete buf;
  return siz;
}

Stos::~Stos()
{
  if(!empty())
    {
      Elem* tmp;
      while(przod!=NULL)
	{
	  tmp=przod;
	  przod=przod->prev;
	  tmp->prev=NULL;
	  delete tmp;
	}
      delete przod;
    }
}
