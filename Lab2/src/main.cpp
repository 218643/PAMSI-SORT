#include <cstdio>
#include <unistd.h>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

#include "test_tab.hh"

int main()
{
  test_tab Testuj;

  Testuj.run(10000,10);
  Testuj.wyswietl_wynik();
  return 0;
}
