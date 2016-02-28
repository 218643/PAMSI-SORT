#include <cstdio>
#include <cstdlib> //zawiera funkcje do gen pseudolosowych liczb wykmw
#include <time.h>
#include <unistd.h>
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>

class Tab_Dyn
{
private:
  int n=0;
  int m=0;
  int *Tab1D=NULL;
  int **Tab2D=NULL;
  
public:
  /*Metoda ma na celu pobranie wymiarow tablicy*/
    void setnm(int x) 
  {
    n=x;
  }

  void setnm(int x,int y) 
  {
    n=x;
    m=y;
  }
  
  /*Metoda ma na celu implementacje tablicy1D/2D, zwraca tablice wypelniona 0*/
  void impl_tab()
  {
    if(n!=0 && m==0)
      {
	Tab1D=new int [n];
      }

    if(n!=0 && m!=0)
      {
	Tab2D= new int*[n];
	for(int i=0; i<n;i++)
	  {
	    Tab2D[i]=new int[m];
	  }
      }
  }
 /*Metoda wypelnia tablice 1D lub 2D wartosciami od 0 do x(dowolny int)*/  
  void wypelnij_tab(int x)
  {
    srand (time(NULL));   //ustawienie zarodka, by przy kazdym uruchom prog
                          //losowalo inne liczby
    if(Tab1D!=NULL) 
      {
	for(int i=0; i<n; i++)
	  {
	   Tab1D[i]= rand() % (x+1); // a przyjmuje wartosc od 1 do x
	  }
      }

    if(Tab2D!=NULL)
      {
	for(int i=0;i<n;i++)
	  {
	    for(int j=0;j<m;j++)
	      Tab2D[i][j]= rand() % (x+1);
	  }      
      }
  }

  /*Metoda ma na celu usuniecie tablicy*/
  void usun_tab()
  {
    if(Tab1D!=NULL) // Jezeli tablica 1D zaimplementowana
      {
	delete [] Tab1D;
	Tab1D=NULL;
      }

    if(Tab2D!=NULL) // Jezeli tablica 2D zaimplementowana
      {
	for (int i=0;i<n;i++)
	  {
	    delete [] Tab2D[i];
	  }
	delete [] Tab2D;
	Tab2D=NULL;
      }
    n=0;
    m=0;
  } 

  /*Metoda znajduje wartosc maksymalna w tablicy*/
  int wartmax_tab()
  {
    int a=0;
    if(Tab1D!=NULL)
      {
	for(int i=0; i<n; i++)
	  {
	    if(a < Tab1D[i])
	      {
		a = Tab1D[i];
	      }
	  }
      }

    if(Tab2D!=NULL)
      {
	for(int i=0; i<n; i++)
	  {
	    for(int j=0; j<m;j++)
	      {
		if(a < Tab2D[i][j])
		  {
		    a = Tab2D[i][j];
		  }
	      }
	  }
      }
    return a;
  }

  /*Metoda wyswietla tablice*/
  void wyswietl_tab()
  {
    if(Tab1D!=NULL) // Jezeli tablica 1D zaimplementowana
      {
	for(int i=0;i<n;i++)
	  {
	    std::cout << Tab1D[i];
	    std::cout << "  ";
	  } 
	std::cout<< std::endl;

      }

    if(Tab2D!=NULL) // Jezeli tablica 2D zaimplementowana
      {
	for (int i=0;i<n;i++)
	  {
	    for(int j=0;j<m;j++)
	      {
	      std::cout << Tab2D[i][j];
	      std::cout << "  ";	      
	      }
	    std::cout << std::endl;
	  }
      }

  }
  
};

using namespace std;

void menu()
{
  cout << "Witaj w programie do tworzenia tablic dynamicznychbymw"<<endl;
  cout << "1 - Stworz tablice dynamiczna 1D"<<endl;
  cout << "2 - Stworz tablice dynamiczna 2D"<<endl;
  cout << "3 - Wyjdz z proramu"<<endl;
}


int main()
{
  int a,b,c,d;	
  Tab_Dyn tab1;
 
  while(c!=3)
    {
      menu();
      cin >> c;
      switch(c)
	{
	case 1:
	  cout << "Podaj x"<< endl;
	  cin >> a;
	  tab1.setnm(a);
	  tab1.impl_tab();
	  cout << "Wypelnij tablice wartosciami od 0 do x. x= ";
	  cin >> d;
	  tab1.wypelnij_tab(d);
	  tab1.wyswietl_tab();
	  cout << "Wartosc maksymalna z tej tab, to : " << tab1.wartmax_tab();
	  cout << endl;
	  tab1.usun_tab();
	  break;
	case 2 :
	  cout << "Podaj x"<< endl;
	  cin >> a;
	  cout << "Podaj y"<< endl;
	  cin >> b;
	  tab1.setnm(a,b);
	  tab1.impl_tab();
	  cout << "Wypelnij tablice wartosciami od 0 do x. x= ";
	  cin >> d;
	  tab1.wypelnij_tab(d);
	  tab1.wyswietl_tab();
	  cout << "Wartosc maksymalna z tej tab, to : " << tab1.wartmax_tab();
	  cout << endl;
	  tab1.usun_tab();
	  break;
	case 3 :
	  cout << "Do widzenia!" << endl;
	  break;
	}
    }
 
  return 0;
}
