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

int main()
{
  string a;
  cout << "Podaj slowo: "  << endl;
  cin >> a;

  if(jestPal(a))
    cout << "To jest palindrom!"<< endl;
  else
    cout << "To nie jest palindrom!"<<endl;
  return 0;
}
