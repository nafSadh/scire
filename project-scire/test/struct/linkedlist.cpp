#include <iostream>
#include "..\..\..\scire\struct\linkedlist.hpp"
#include <list>

using namespace std;
using namespace scire;

void read(int a)
{
  cout << a << " ";
}

int kmain()
{
  //list<int> kst;
  SinglyList<int> slist;
  /* slist.Insert(100);
   slist.Insert(200);
   slist.Insert(300);
  */ slist.Traverse(read);
  cout << endl;
  for (int i = 0; i < 10000000; i++) {
    slist.Insert(i, 0);
    //slist.Traverse(read);
    //cout << endl;
  }
  int a;
  cout << "all inserted:"<<slist.Count()<<endl;
  cin >> a;
  cout << "--\n";
  for (int i = 0; i < 10; i++) {
    cout << slist.Pop() << endl;
    //slist.Traverse(read);
    //cout << endl;
  }
  cin >> a;

  return 0;
}

int main()
{
  kmain();
  cout << "exit\n";
  int a;
  cin >> a;
}