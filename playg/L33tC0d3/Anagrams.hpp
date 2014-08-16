
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

namespace scire
{
  namespace wordplay
  {
    class Anagrams
    {

      static int anagramcomp(const string& s1, const string& s2)
      {
        try {
          int len1 = s1.length();
          int len2 = s2.length();
          if (len1 != len2) return (len1 - len2);
          if (len1 == 0) return 0;

          char * str1 = new char[len1 + 1];
          std::strcpy(str1, s1.c_str());
          sort(str1, str1 + len1);
          char * str2 = new char[len2 + 1];
          std::strcpy(str2, s2.c_str());
          sort(str2, str2 + len2);

          return strcmp(str1, str2);
        } catch (int e) {
          return -1;
        }
      }

      static bool anacomp(string s1, string s2)
      {
        return (anagramcomp(s1, s2)<0);
      }
      static int anacompv(const void *s1, const void *s2)
      {
        string a = *((string*)s1);
        string b = *((string*)s2);
        return anagramcomp(a, b);
      }

     public:
      vector<string> anagrams(vector<string> &strs)
      {
        vector<string> angs;
        int n = strs.size();
        sort(strs.begin(), strs.end(), anacomp);
        for (int i = 0; i<n; i++) {
          int preveq = -1, nexteq = +1;
          if (i>0) preveq = (anagramcomp(strs[i], strs[i - 1]));
          if (i<(n - 1)) nexteq = (anagramcomp(strs[i], strs[i + 1]));
          if ((preveq == 0) || (nexteq == 0)) {
            angs.push_back(strs[i]);
          }
        }
        return angs;
      }
    };
  }
}

/*
int main()
{
  vector<string> list;

  ifstream in_stream;

  string line;

  in_stream.open("S:\\wordlist.txt");

  while (!in_stream.eof()) {
    in_stream >> line;
    list.push_back(line);
  }
  in_stream.close();

  scire::wordplay::Anagrams ag;

  vector<string> aglist = ag.anagrams(list);

  ofstream outf;
  outf.open("anagrams.txt");

  for (string str : aglist) {
    outf << str << endl;
  }
  outf.close();

  return 0;
}
*/