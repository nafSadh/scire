#include <iostream>
#include "../../scire/string/cstr_util.hpp"


using namespace std;
using namespace scire;

namespace sciretest
{
  int cstr_util_main()
  {
    char str[500], a[500],b[500];
    //cin >> str;
    //cout << CharStringUtil::IsAllCharUnique(str)<<endl;
    //CharStringUtil::Reverse(str);
    //cout << str << endl;

    while (true) {
      cin >> a >> b;
      cout << CharStringUtil::IsPermutation<128>(a, b)<<endl;
    }
    return 0;
  }
}

#ifndef SCIRE_TEST_CSTR_UTIL
int main()
{
  return sciretest::cstr_util_main();
}
#endif