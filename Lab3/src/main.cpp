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

  Lista ll;

  ll.erase(3,3);

  ll.push_ind("test1",0);
  ll.push_ind("test2",1);
  ll.push_ind("test3",2);
  ll.push_ind("test4",3);
  ll.push_ind("test5",4);
  ll.push_ind("test6",5);
  ll.push_ind("test7",6);
  ll.push_ind("test8",7);
  ll.push_ind("test9",8);

  ll.push_ind("test333",3);

  cout << "v1:" << endl;
  ll.size();

  ll.erase(1,1);

  cout << "v2:" << endl;

  ll.push_front("test_przod");
  ll.push_back("test_tyl");
   
  ll.size();

  cout << "POPUJE" << ll.pop_front()<< endl;
  cout << "v3:" << endl;
  ll.size();
  for(int i=0;i<10;i++)
    {
      ll.pop_front();
    }
  cout << "V4" << endl;
  ll.size();
  
}
