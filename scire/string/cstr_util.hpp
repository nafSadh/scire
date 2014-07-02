// scire/string/cstr_util

// Copyright (c) 2014, Khan 'Sadh' Mostafa (http://nafSadh.com/Khan)
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying text at http://www.boost.org/LICENSE_1_0.txt)

/**
scire/string/cstr_util.hpp

scire <thing> implementation:
- CharStringUtil	            : very brief description

other required scire files:
none

author:
~nafSadh
*/
#ifndef SCIRE_string_cstr_util_HPP
#define SCIRE_string_cstr_util_HPP

#include <cstring>

namespace scire
{

#ifndef SCIRE_CharStringUtil_FUNCS
#define SCIRE_CharStringUtil_FUNCS

  /**
  */
  class CharStringUtil
  {
   public:
    /**
    * check if all characater in a string is unique
    * @return false if at least one char appear more than once in the string
    */
    static bool IsAllCharUnique(const char str[]/**< string to check */)
    {
      size_t len = strlen(str);
      if (len > 128) return false;

      bool chrmap[128] = {false};
      size_t i = 0;
      while (i < len) {
        if (chrmap[str[i]] == true)
          return false;
        chrmap[str[i]] = true;
        i++;
      }

      return true;
    }

    /** reverse the passed string */
    static void Reverse(char str[] /**<string to reverse */)
    {
      size_t len = strlen(str);
      size_t mid = len / 2;
      size_t end = len - 1;

      for (size_t i = 0; i < mid; i++) {
        char temp = str[i];
        str[i] = str[end - i];
        str[end - i] = temp;
      }
    }

    template <size_t N>
    static bool IsPermutation(const char a[], const char b[])
    {
      size_t len = strlen(a);

      if (len != strlen(b)) {
        return false;
      }

      int map[N] = {0};

      size_t i = 0;

      while (i < len) {
        map[a[i]]++;
        map[b[i]]--;
        i++;
      }

      for (i = 0; i < N; i++) {
        if (map[i] != 0) return false;
      }

      return true;
    }
  };

#endif SCIRE_CharStringUtil_FUNCS
}
#endif SCIRE_string_cstr_util_HPP
