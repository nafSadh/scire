#include <iostream>
#include <string>
#include "../../scire/hash/md5.hpp"
using namespace std;
using namespace scire;

#define MSG "abc"

namespace sciretest
{
  int hash_md5_main()
  {
    unsigned char digest[16];
    //unsigned int digWord[4];
    unsigned char data[] = MSG;
    MD5<> md5;
    cout << md5 << endl;
    md5.Update(data, strlen((char*)data));
    md5.Final();
    //md5.printDigest();
    md5.Digest(digest);
    for (int i = 0; i < 16; i++) {
      printf("%02x", (unsigned int)digest[i]);
    }
    cout <<endl <<md5.StatePhrase()<<endl << md5 << endl;
    string str(MSG);
    MD5<> hash(MSG);
    hash.Digest(digest);
    /*for (int i = 0; i < 16; i++) {
      printf("%02x", (unsigned int)digest[i]);
    }*/
    cout<<hash << endl;
    return 0;
  }
}

#ifndef SCIRE_TEST_MD5
int main()
{
  return sciretest::hash_md5_main();
}
#endif
