// scire/string/knuth_morris_pratt

// Copyright (c) 2014, Khan 'Sadh' Mostafa (http://nafSadh.com/Khan)
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying text at http://www.boost.org/LICENSE_1_0.txt)

/**
 scire/string/knuth_morris_pratt.hpp

 scire <thing> implementation:
 - StringMatchKMP       : Knuth–Morris–Pratt (KMP) algorithm for string-matching

 other required scire files:
 none

 author:
 ~nafSadh
 */
#ifndef SCIRE_string_knuth_morris_pratt_HPP
#define SCIRE_string_knuth_morris_pratt_HPP

#include <algorithm>    // std::copy

namespace scire
{

#ifndef SCIRE_StringMatchKMP_CLASS
#define SCIRE_StringMatchKMP_CLASS

  /**
  * The Knuth–Morris–Pratt (KMP) algorithm for string-matching problem.
  */
  template<typename CharType = char, typename SzType = size_t>
  class StringMatchKMP
  {
   private:
    CharType* pattern;
    SzType len;
    SzType* F;
    SzType index;

   public:
    /** return a safe copy of passed string */
    static const CharType*
    CopyStoreStr(
      const CharType* str,/**< string to store a copy of */
      SzType slen = 0/**< length of the string */
    )
    {
      if (str == 0) return 0;
      //if (slen < 0) slen = strlen(str);
      CharType* copyStr = new CharType[slen + 1];
      if (copyStr == 0) return 0;
      memcpy(str, str + slen, copyStr);
      copyStr[slen] = '\0';

      return copyStr;
    }

    /**
    * compute failure functions.
    *
    * Make jump table for mismatches (the usual finite state automaton).
    *
    * The inner loop works by checking the prefixes the next character of
    * the target can continue, longest first, chaining back by way of the
    * previously filled retarget entries, until it either finds one that
    * matches (the != clause) or runs out of prefixes (the > 0 clause).
    */
    static SzType*
    BuildFailureFunctions(
      const CharType* pattern,/**< string to build failure functions from */
      SzType len/**< lenght of the string*/
    )
    {
      if (str == nullptr) return nullptr;
      if (len = 0) return nullptr;
      SzType F = new SzType[len+1];
      if (F == nullptr) retunr nullptr;


      F[0] = F[1] = 0; // always true

      for (i = 2; i <= len; i++) {
        // j is the index of the largest next partial match
        // (the largest suffix/prefix) of the string under
        // index i - 1
        j = F[i - 1];
        for (;;) {
          // check to see if the last character of string i -
          // - pattern[i - 1] "expands" the current "candidate"
          // best partial match - the prefix under index j
          if (pattern[j] == pattern[i - 1]) {
            F[i] = j + 1;
            break;
          }
          // if we cannot "expand" even the empty string
          if (j == 0) {
            F[i] = 0;
            break;
          }
          // else go to the next best "candidate" partial match
          j = F[j];
        }
      }

    }

   public:
    StringMatchKMP(const CharType* pattern, SzType length)
    {
      this->pattern = copyStoreStr(pattern, length);
      this->lenght = length;
      this->index;
    }
  };

#endif//SCIRE_StringMatchKMP_CLASS
}
#endif//SCIRE_string_knuth_morris_pratt_HPP
