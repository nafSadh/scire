#include <iostream>
#include "../../scire/search/union_find.hpp"


using namespace std;
using namespace scire;

namespace sciretest
{
  int union_find_main()
  {
    int n;
    cin >> n;
    UnionFind<> uf(n);

    int op = 1, a, b;
    while (true) {
      cin >> op >> a >> b;
      switch (op) {
      case 1:
        cout<<uf.IsConnected(a, b)<<endl;
        break;
      case 2:
        uf.Unite(a, b);
        break;
      default:
        break;
      }
    }

    return 0;
  }
}

#ifndef SCIRE_TEST_UNION_FIND
int main()
{
  return sciretest::union_find_main();
}
#endif