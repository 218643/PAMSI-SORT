#include <cstdio>
#include <unistd.h>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

#include "Lista.hh"

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
  przod=kafelek;     //wskaznik przod klasy Lista wsakazuje na nowy kafelek
  tyl=kafelek;      //tyl rowniez
}

//Metoda zwraca true, gdy lista pusta, false, gdy cos na niej jest
bool Lista:: empty()
{
  if(przod==NULL && tyl==NULL)
    {
      cerr << "Lista pusta." << endl;
      return true;
    }
  else
    {
      cerr << "Na liscie znajduja sie elementy" << endl;
      return false;
    }
}



void Lista::push(string element,int indeks)
{
  if(empty()) //jezeli pusta - to samo co w konstruktorze param.
    {
      Kaf* kafelek=new Kaf();
      kafelek->next=NULL; 
      kafelek->prev=NULL; 
      przod=kafelek;     
      tyl=kafelek;  
    }
  else
    {
      Kaf* kafelek2=new Kaf();
      kafelek2->prev=przod; //prev wskazuje na pierwszy element na liscie
      kafelek2->next=NULL;  //next to NULL
      kafelek2->wartosc=element;
      przod->next=kafelek2;
      przod=kafelek2;
      
      
    }
}
  





bool Lista:: erase(int start,int end)
  {
    return true;
  }
  
  
string Lista:: pop(int indeks)
  {
    return "A";
  }
  
string Lista:: get(int indeks)
  {
    return"A";
  }
  
  
int Lista:: size()
  {
    return 0;
  }


Lista:: ~Lista()
{


}
