#include <iostream>
#include "../../scire/string/cstr_util.hpp"


using namespace std;
using namespace scire;

namespace sciretest
{
  int cstr_util_main()
  {
    char str[500];
    cin >> str;
    cout << endl << CharStringUtil::IsAllCharUnique(str);
    return 0;
  }
}

#ifndef SCIRE_TEST_CSTR_UTIL
int main()
{
  return sciretest::cstr_util_main();
}
#endif