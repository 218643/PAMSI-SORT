#include <cstdio>
#include <unistd.h>
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>

int Potega(int x, int p)
{
  if (p==0)
    return 1;
  else
    {
      return x*Potega(x,p-1);
    }
}

int Silnia(int x)
{
  if(x==0)
    return 1;
  else 
    return x*Silnia(x-1);
}

using namespace std;

int main()
{
  int x;
  
  x=Potega(3,3);
  cout << x << endl;

  x=Silnia(4);
  cout << x << endl;
  
  return 0;
}
