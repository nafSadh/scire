#include <iostream>
#include "../../../scire/struct/linkedlist.hpp"
#include <list>

using namespace std;
using namespace scire;

void read(int a)
{
  cout << a << " ";
}

int llkmain()
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
  cout << "all inserted:" << slist.Size() << endl;
  cin >> a;
  cout << "--\n";
  for (int i = 0; i < 10; i++) {
    cout << slist.Peek() << endl;
    slist.Deduce();
    //slist.Traverse(read);
    //cout << endl;
  }
  cin >> a;

  return 0;
}

int linkedListMain()
{
  llkmain();
  cout << "exit\n";
  int a;
  cin >> a;

  return 0;
}
