#include <cstdio>
#include <unistd.h>
#include <string.h>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;


bool jestPal(string testStr)
{
  
  if(testStr.length()==0 || testStr.length()==1 )
    return true;
  else
    {
      if(testStr[0]==testStr[testStr.length()-1])
	{
	  testStr.erase(0,1);
	  testStr.pop_back();
	  jestPal(testStr);
	  return true;
	}
      else 
	return false;
    } 
}

int main()
{

}
