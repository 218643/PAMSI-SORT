#include <cstdio>
#include <unistd.h>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

#include "Kolejka.hh"

bool Kolejka:: empty()
{
  return true;
}  
  
void Kolejka:: push(string element)
{
  
}
  
string Kolejka:: pop()
{
  return "A";
}

string Kolejka:: front()
{
  return "x";
}

string Kolejka:: end()
{
  return"x";
}

int Kolejka:: size()
{
  return 3;
}
