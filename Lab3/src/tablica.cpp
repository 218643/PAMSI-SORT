#include <cstdio>
#include <unistd.h>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

#include "Tablica.hh"

Tablica::Tablica()
{
  Tab=new string [1];
  n=1; 
}

Tablica::Tablica(int k)
{
  Tab=new string [k];
  n=k; 
}

int Tablica:: size()
{
  return n;
}

void Tablica:: dopisz(int in, string x)
{
  if(in>=n)
    {
      string* Tab1=new string [n]; 
      for(int i=0; i<n;i++) //przepisuje
	{
	  Tab1[i]=Tab[i];
	}
      
      Tab= new string[n+1];  //tworze nowa powiekszona o 1
      
      for(int i=0; i<n;i++)
	{
	  Tab[i]=Tab1[i];
	}
      
      Tab[n]=x;
      delete[] Tab1;
      Tab1=NULL;
      n++;
    }
  else
    {
      Tab[in]=x;
    }
}

void Tablica:: dopiszx2(int in, string x)
{
  if(in>=n)
    {
      string* Tab1=new string [n]; 
      for(int i=0; i<n;i++) //przepisuje tablice
	{
	  Tab1[i]=Tab[i];
	}
      
      Tab= new string[n*2];  //tworze nowa powiekszona o 1
      
      for(int i=0; i<n;i++)
	{
	  Tab[i]=Tab1[i];
	}
      
      Tab[n]=x;
      delete[] Tab1;
      Tab1=NULL;
      n=n*2;
    }
  else
    {
      Tab[in]=x;
    }
}

void Tablica:: dotnij(int in) //metoda docina rozmiar tablicy do n
{
  string* Tab1=new string [in]; 
  for(int i=0; i<in;i++) //przepisuje tablice
    {
      Tab1[i]=Tab[i];
    }
  
  Tab= new string[in];  //tworze nowa powiekszona o 1
  
  for(int i=0; i<in;i++)
    {
      Tab[i]=Tab1[i];
    }
  n=in;
}


void Tablica:: wyswietl()
{
  for (int i=0;i<n;i++)
    {
      cout << Tab[i] << "  ";
    }
  cout << endl;
}

string& Tablica:: operator[](int i)
{
  return Tab[i];
}

Tablica::~Tablica()
{
  if(Tab!=NULL)
    {
      delete [] Tab;
      Tab=NULL;
    }
}
