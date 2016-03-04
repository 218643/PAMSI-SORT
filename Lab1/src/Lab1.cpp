#include <cstdio>
#include <unistd.h>
#include <string>
#include <ctime>
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
    Tab=new int [a];
    for(int i=0; i<a; i++)
      {
	Tab[i]=0;
      }
    n=a; 
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
    if(in>=n)
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
  clock_t start,stop;

  cout << "Jaka wartoscia zainicjowac?"<< endl;
  cin >> b;
  Tablica dyn(b);
  // dyn.wyswietl();
  
  cout << "Do jakiego rozmiaru powiekszyc?" << endl;
  cin >> b;
  
  start=clock();
  for (int i=0;i<b;i++)
    {
      dyn.dopisz(i,i+1);
    }
  stop=clock();

  cout <<"Czas wykonania algorytmu, to: ";
  cout << 1000./CLOCKS_PER_SEC*(stop-start) << "ms" << endl; 

  //dyn.wyswietl();
  dyn.usun();

  return 0;
}
