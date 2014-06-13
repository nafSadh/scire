// scire/hash/md5

// Copyright (c) 2014, Khan 'Sadh' Mostafa (http://nafSadh.com/Khan)
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying text at http://www.boost.org/LICENSE_1_0.txt)

/**
 scire/hash/md5.hpp

 scire MD5 implementation:
 - MD5	            : a class offering MD5 functionalities

 other required scire files:
  none

 author:
  ~nafSadh
 */
#ifndef SCIRE_hash_md5_HPP
#define SCIRE_hash_md5_HPP

namespace scire
{
#ifndef SCIRE_MD5_CLASS
#define SCIRE_MD5_CLASS

  /**
  */
  template<typename SzType = size_t>
  class MD5
  {
   public:
    void Reset();
    SzType BitLen();
    SzType ByteLen();
    SzType DigestSize();
    SzType
  };

#endif SCIRE_MD5_CLASS
}
#endif SCIRE_hash_md5_HPP
