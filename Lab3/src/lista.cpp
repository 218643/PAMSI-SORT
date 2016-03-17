#include <cstdio>
#include <unistd.h>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

#include "Lista.hh"

Lista:: Lista()
{
  //przod=NULL;
  tyl=NULL;
}

//Lista:: Lista(string elem)
//{
  //  Lista* kafelek1=new Lista();
//}

bool Lista:: empty()
{
  if(przod==NULL && tyl==NULL)
    {
      cerr << "Lista pusta." << endl;
      return true;
    }
  else
    {
      cerr << "Na liscie znajduja sie elementy" << endl;
      return false;
    }
}



void Lista::push(string element,int indeks)
{
  // Lista* kafelek1=new Lista;


}
  





bool Lista:: erase(int start,int end)
  {
    return true;
  }
  
  
string Lista:: pop(int indeks)
  {
    return "A";
  }
  
string Lista:: get(int indeks)
  {
    return"A";
  }
  
  
int Lista:: size()
  {
    return 0;
  }


Lista:: ~Lista()
{


}
