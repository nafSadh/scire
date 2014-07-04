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
  * The Knuth-Morris-Pratt (KMP) algorithm for string-matching problem.
  *
  * A KMP object is initialized with a pattern to find. Each character of text
  * is then fed to the object with ReadNext() for matching.
  */
  template<typename CharType = char, typename SzType = size_t>
  class StringMatchKMP
  {
   private:
    const CharType* pattern;/**< pattern to search for */
    SzType lenght;/**< length of pattern */
    SzType* F;/**< failuire functions */
    SzType index;/**< current index of pattern matched */

   private:
    /**
    * return a safe copy of the passed string
    */
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
      memcpy(copyStr, str, slen);
      //std::copy(str, str + slen, copyStr);
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
      if (pattern == nullptr) return nullptr;
      if (len == 0) return nullptr;
      SzType* F = new SzType[len+1];
      if (F == nullptr) return nullptr;


      F[0] = F[1] = 0; // always true

      for (SzType i = 2; i <= len; i++) {
        // j is the index of the largest next partial match
        // (the largest suffix/prefix) of the string under
        // index i - 1
        SzType j = F[i - 1];
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
      return F;
    }

   public:
    /**
    * Construct KMP pattern matching object with pattern to find
    */
    StringMatchKMP(
      const CharType* pattern,/**< patther to match */
      SzType length/**< lenght of pattern */
    )
    {
      this->pattern = CopyStoreStr(pattern, length);
      this->lenght = length;
      this->F = BuildFailureFunctions(pattern, length);
      this->index;
    }

    /**
    * read next character in text stream
    * @return true if pattern matched
    */
    bool
    ReadNext(
      CharType c /**< next char in text stream */
    )
    {
      if (F == 0) return false;

      while (c != pattern[index]) {
        if (index == 0) return false; // fell all the way back, have to give up
        index = F[index]; // more positions to fall back to, keep trying
      }
      if (pattern[++index] != '\0') return false;	// partial match
      else {
        index = F[index]; // full match, but keep going
        return true;
      }
    }

    /**
    * Get the first index of text where pattern matched.
    *
    * @return index of text where pattern matched. if pattern not found then
    * last index of text (text len)
    */
    static SzType GetIndex(
      const CharType* pattern,/**< pattern to find */
      SzType patternlen, /**< length of pattern*/
      const CharType* text,/**< text to search in */
      SzType textlen /**< lenth of text */
    )
    {
      StringMatchKMP kmp(pattern, patternlen);
      SzType i = 0;
      while (i<textlen) {
        if (kmp.ReadNext(text[i]))
          return i+1-patternlen;
        i++;
      }
      return i;
    }

  };

#endif//SCIRE_StringMatchKMP_CLASS
}
#endif//SCIRE_string_knuth_morris_pratt_HPP
