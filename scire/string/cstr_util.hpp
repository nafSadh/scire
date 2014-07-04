// scire/string/cstr_util

// Copyright (c) 2014, Khan 'Sadh' Mostafa (http://nafSadh.com/Khan)
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying text at http://www.boost.org/LICENSE_1_0.txt)

/**
scire/string/cstr_util.hpp

scire <thing> implementation:
- CharStringUtil	            : very brief description

other required scire files:
  knuth_morris_pratt.hpp

author:
~nafSadh
*/
#ifndef SCIRE_string_cstr_util_HPP
#define SCIRE_string_cstr_util_HPP

#include <cstring>
#include "knuth_morris_pratt.hpp"

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

    /** check if a string passed is a permutation of the other */
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

    /** replace all occurrences of a character with some string */
    static size_t Replace(const char subject[],/**<string to operate on */
                          char result[],/**<result string*/
                          char search,/**<character to replace*/
                          char replace[]/**<string to replace with*/)
    {
      size_t len = 0;

      size_t rep = strlen(replace);

      size_t i = 0;
      while (subject[i] != '\0') {
        if (subject[i] == search) {
          for (size_t j = 0; j < rep; j++) {
            result[len++] = replace[j];
          }
        } else {
          result[len++] = subject[i];
        }
        i++;
      }
      result[len] = '\0';
      return len;
    }

    template <typename Type>
    static size_t NumToDecimalString(Type num, char str[])
    {
      size_t base = 10;
      size_t len;

      //estimate place count
      len = 0;
      Type copy = num;
      while (copy > 0) {
        len++;
        copy /= base;
      }

      for (int i = len - 1; i >= 0; i--) {
        str[i] = (num % base) + '0';
        num /= base;
      }
      str[len] = '\0';

      return len;
    }

    /** encode a string such that every repeated character is encoded as the
    character followed by count. e.g. aabcccaaaa -> a2b1c3a4
    @return lenght of encoded string */
    static size_t CharCountEncoding(const char subject[],/**<string to encode*/
                                    char encstr[]/**<encoded string*/)
    {
      size_t len = 0;

      size_t i = 0;
      char curc = subject[i];
      size_t count = 1;
      while (subject[i] != '\0') {
        if (subject[i+1] == curc) {
          count++;
        } else { //update encoded string
          encstr[len++] = curc;
          //encstr[len++] = count + '0';
          char nstr[32];
          size_t nlen = NumToDecimalString(count, nstr);
          for (size_t j = 0; j < nlen; j++) {
            encstr[len++] = nstr[j];
          }
          //reset
          curc = subject[i + 1];
          count = 1;
        }
        i++;
      }
      encstr[len] = '\0';

      return len;
    }

    /** compress a string such that every repeated character is encoded as the
    character followed by count. e.g. aabcccaaaa -> a2b1c3a4. If encoded string
    is not smaller then return original string.
    @return lenght of encoded string */
    static size_t CharCountCompress(const char subject[],/**<string to encode*/
                                    char compstr[]/**<encoded string*/)
    {
      size_t enclen = CharCountEncoding(subject, compstr);
      if (enclen < strlen(subject))
        return enclen;
      else {
        size_t i = 0;
        while (subject[i] != '\0') {
          compstr[i] = subject[i];
          i++;
        }
        compstr[i] = '\0';
        return i;
      }
    }
  };
#endif//SCIRE_CharStringUtil_FUNCS
}
#endif//SCIRE_string_cstr_util_HPP
