#include <cstdio>
#include <unistd.h>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;


#include"Lista.hh"


int main()
{
  Tablica tab;
  Lista ll;

  ll.empty();

  int i;

  for(i=0;i<10;i++)
    {
      tab.dopiszx2(i,"Ala");
    }
  tab.dotnij(i);
  tab.wyswietl();

}
