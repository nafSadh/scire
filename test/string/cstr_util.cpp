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

    //while (true) {
    //  cin >> a >> b;
    //  cout << CharStringUtil::IsPermutation<128>(a, b)<<endl;
    //}

    //while (true) {
    //  cin >> str;
    //  CharStringUtil::Replace(str, a, '_', "%20");
    //  cout << a << endl;
    //}

    //while (true) {
    //  int x;
    //  cin >> x;
    //  CharStringUtil::NumToDecimalString<int>(x, str);
    //  cout << str << endl;
    //}

    /*while (true) {
      cin >> str;
      cout << strlen(str) << "->" << CharStringUtil::CharCountCompress(str, a) << ": ";
      cout << a << endl;
    }*/

    while (true) {
      char text[500], key[50];
      cin >> text >> key;
      //cout << StringMatchKMP<>::GetIndex(text, strlen(text), key, strlen(key)) << endl;
      cout << CharStringUtil::isRotation(text, key) << endl;
    }

    return 0;
  }
}

#ifdef SCIRE_TEST_CSTR_UTIL
int main()
{
  return sciretest::cstr_util_main();
}
#endif