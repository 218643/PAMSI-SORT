#include <cstdio>
#include <unistd.h>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

class Istoper
{
protected:
  clock_t sta;
  clock_t end;
  int ilosc_okr;
public:
  virtual void start()
  {
     sta=clock();
  }

  virtual void stop()
  {
    end=clock();
  }

  virtual long get_time()
  {
    return 1000./CLOCKS_PER_SEC*(end-sta);
  }
};

class Irunnable
{
protected:
  int size;
  int sygnal_startu=0;
public:

  virtual bool przygotuj()
  {
    sygnal_startu=1;
    return true;
  }

  virtual void reset()
  {
    sygnal_startu=0;
  }

  virtual bool run()
  {
    if(sygnal_startu==1)
      return true;
    else
      return false;
  }


};

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
	for(int i=0; i<n;i++) //przepisuje
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

void dopiszx2(int in, int x)
  {
    if(in>=n)
      {
	int* Tab1=new int [n]; 
	for(int i=0; i<n;i++) //przepisuje tablice
	  {
	    Tab1[i]=Tab[i];
	  }
	
	Tab= new int[n*2];  //tworze nowa powiekszona o 1
	
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

  void dotnij(int in) //metoda docina rozmiar tablicy do n
  {
    int* Tab1=new int [in]; 
    for(int i=0; i<in;i++) //przepisuje tablice
      {
	Tab1[i]=Tab[i];
      }
	
    Tab= new int[in];  //tworze nowa powiekszona o 1
    
    for(int i=0; i<in;i++)
      {
	Tab[i]=Tab1[i];
      }
    n=in;
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

class test_tablica
{
protected:
  int in=0;

};

int main()
{
 int b=0;

  cout << "Jaka wartoscia zainicjowac?"<< endl;
  cin >> b;
  Tablica dyn(b);
  // dyn.wyswietl();
  
  cout << "Do jakiego rozmiaru powiekszyc?" << endl;
  cin >> b;

  int i;  

  for (i=0;i<b;i++)
    {
      dyn.dopiszx2(i,i+1);
    }
  dyn.dotnij(i);


  cout <<"Czas wykonania algorytmu, to: "; 

  //dyn.wyswietl();
  dyn.usun();

  return 0;
}
