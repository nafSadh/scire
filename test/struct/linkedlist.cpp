#include <iostream>
#include "../../scire/struct/linkedlist.hpp"
#include <random>

using namespace std;
using namespace scire;

namespace sciretest
{
  void read(const int &a)
  {
    cout << a << " ";
  }

  int SinglyListTraverse()
  {
    //list<int> kst;
    SinglyList<int> slist;
    /* slist.Insert(100);
     slist.Insert(200);
     slist.Insert(300);
     */ slist.Traverse(read);
    cout << endl;
    for (int i = 0; i < 100; i++) {
      slist.Insert(i, i/2);
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

  int SinglyListTestMain()
  {
    SinglyList<int> slist;
    std::random_device rd;

    int sz;
    cin >> sz;
    for (int i = 0; i < sz; i++) {
      slist.Insert(rd()%101);
    }
    slist.Traverse(read);
    cout << endl;

    //cout << GetRidOfDuplicates(slist) << endl;
    //slist.Traverse(read);
    //cout << endl;
    int k;
    cin >> k;
    cout << KthToTheLast(slist,k)<<endl;


    /*int dat=0;
    while (dat>= 0) {
      cin >> dat;
      slist.Remove(dat);
      slist.Traverse(read);
      cout<<endl;
    }*/

    return 0;
  }
}

#ifdef SCIRE_TEST_LINKEDLIST
int main()
{
  return sciretest::SinglyListTestMain();
}
#endif