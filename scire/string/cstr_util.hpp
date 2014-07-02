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
    static bool IsAllCharUnique(const char str[])
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
  };

#endif SCIRE_CharStringUtil_FUNCS
}
#endif SCIRE_string_cstr_util_HPP
