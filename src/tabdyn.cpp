#include <cstdio>
#include <math.h>
#include <unistd.h>
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
  int x=0,y=0;

  cout << "Jaki rozmiar ma miec tablica?" << endl;
  cout << "Rozmiar x:";
  cin >> x; 
  cout << endl << "Rozmiar y:";
  cin >> y;
  cout << endl;
 
  /*Implementacja tablicy dynamicznej*/

  int **Tab_Dyn=new int *[x];

  for(int i=0;i<x; i++)
    {
      Tab_Dyn[i]=new int[y];
    }

  /*Zwolnienei pamieci*/

  for (int i=0; i<x; i++)
    {
      delete Tab_Dyn[i];
    }

  delete Tab_Dyn;

  return 0;
}
