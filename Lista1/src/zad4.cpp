#include <cstdio>
#include <unistd.h>
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

int IleZnakow(string Tab) //funkcja zwraca ilosc znakow stringa
{
int i=0;
 while(Tab[i]!='\0')
   {
     i++;
   }
return i;
}

bool jestPal(string testStr)
{
  int i=0;
  int j=IleZnakow(testStr)-1;

  if(IleZnakow(testStr) % 2 == 1 ) //czy ilosc znakow nieparzysta?
      {
      while(i!=j)
	{
	  if(testStr[i]==testStr[j]) 
	    {
	      i++;
	      j--;
	    }
	  else
	    {
	      return false;
	    }
	}
      }
  else   //gdy napis ma parzysta ilosc znakow
    {
      while(i!=IleZnakow(testStr)/2+1)
	{
	  if(testStr[i]==testStr[j]) 
	    {
	      i++;
	      j--;
	    }
	  else
	    {
	      return false;
	    }
	}
    }
  return true;
}

int main()
{
  string a;
  cout << "Podaj stringa do sprawdzenia."<< endl;
  cin >> a;
  cout << jestPal(a)<<endl;
  return 0;
}
