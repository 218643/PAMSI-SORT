#include <cstdio>
#include <unistd.h>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

#include "Kolejka.hh"

Kolejka:: Kolejka()
{
  przod=NULL;
  tyl=NULL;
}

Kolejka::Kolejka(string elem)
{
  Ele* Kaf= new Ele;
  Kaf->wartosc=elem;
  Kaf->prev=NULL;
  Kaf->next=NULL;
  przod=Kaf;
  tyl=Kaf;
}

bool Kolejka:: empty()
{
  if(przod==NULL && tyl==NULL)
    return true;
  else
    return false;
}  
  
void Kolejka:: push(string element)
{
  Ele* Kaf= new Ele;
  Kaf->wartosc=element;
  if(empty())
    {
      Kaf->prev=NULL;
      Kaf->next=NULL;
      przod=Kaf;
    }
  else
    {
      tyl->prev=Kaf;
      Kaf->next=tyl;
      Kaf->prev=NULL;
    }
  tyl=Kaf;
}
  
string Kolejka:: pop()
{
  Ele* tmp;
  string wart="0";
  if(empty())
    {
      cerr <<"Nie ma czego usuwac" << endl;
      return wart;
    }
  else if(przod->next==NULL && przod->prev==NULL) // jezeli jeden element w kolejce
    {
      tmp=przod;
      przod=NULL;
      tyl=NULL;
      wart=tmp->wartosc;
      delete tmp;
      return wart;
    }
  else
    {
      tmp=przod;
      przod=przod->prev;
      przod->next->prev=NULL;
      przod->next=NULL;
      wart=tmp->wartosc;
      delete tmp;
      return wart;
    }
}

string Kolejka:: front()
{
  if(!empty())
    return przod->wartosc;
  else
    return "0";
}

string Kolejka:: end()
{
  if(!empty())
    return tyl->wartosc;
  else
    return "0";
}

int Kolejka:: size()
{
  Ele* buf;
  int n=0;
  buf=przod;
  while(buf!=NULL)
    {
      n++;
      buf=buf->prev;
    }
  delete buf;
  return n;
}

Kolejka::~Kolejka()
{
  if(!empty())
    {
      Ele* tmp;
      while(przod!=tyl)
	{
	  tmp=przod;
	  przod=przod->prev;
	  tmp->next=NULL;
	  tmp->prev=NULL;
	  delete tmp;
	}
      tmp=przod;
      przod=NULL;
      tyl=NULL;
      delete tmp;
    }
}
