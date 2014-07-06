#include <iostream>
#include "../../scire/struct/linkedlist.hpp"
#include <list>

using namespace std;
using namespace scire;

namespace sciretest
{
  void read(const int &a)
  {
    cout << a << " ";
  }

  int SinglyListMain()
  {
    //list<int> kst;
    SinglyList<int> slist;
    /* slist.Insert(100);
     slist.Insert(200);
     slist.Insert(300);
     */ slist.Traverse(read);
    cout << endl;
    for (int i = 0; i < 100; i++) {
      slist.Insert(i, 0);
      //slist.Traverse(read);
      //cout << endl;
    }
    int a;
    cout << "all inserted:" << slist.Size() << endl;
    slist.Traverse(read);
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
}

#ifndef SCIRE_TEST_LINKEDLIST
int main()
{
  sciretest::SinglyListMain();
  cout << "exit\n";
  int a;
  cin >> a;

  return 0;
}
#endif