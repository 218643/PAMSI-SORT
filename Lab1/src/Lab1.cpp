#include <cstdio>
#include <unistd.h>
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;


class Tablica
{
private:
  int *Tab=NULL;
  int n=0;
public:
  
  Tablica(int a)
  {
    n=a;
    Tab=new int [a];
    for(int i=0; i<a; i++)
      {
	Tab[i]=0;
      }
  }

    void usun()
    {
      if(Tab!=NULL)
	{
	  delete [] Tab;
	  Tab=NULL;
	}
    }


  void dopisz(int in, int x)
  {
    if(in>n)
      {
	int* Tab1=new int [n]; 
	for(int i=0; i<n;i++) //przepisuje tablice
	  {
	    Tab1[i]=Tab[i];
	  }
	Tab= new int[n+1];  //tworze nowa powiekszona o 1
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

    void wyswietl()
  {
    for (int i=0;i<n;i++)
      {
	cout << Tab[i] << "  ";
      }
    cout << endl;
  }
  
};


int main()
{
  int b=0;
  cout << "Jaka wartoscia zainicjowac?"<< endl;
  cin >> b;
  Tablica dyn(b);
  dyn.wyswietl();
  
  cout << "Do jakiego rozmiaru powiekszyc?" << endl;
  cin >> b;
  
  for (int i=0;i<b;i++)
    {
      dyn.dopisz(i,i);
    }

  dyn.wyswietl();

  dyn.usun();

  return 0;
}
