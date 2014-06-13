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

#include <cstdint>

namespace scire
{
#ifndef SCIRE_MD5_CLASS
#define SCIRE_MD5_CLASS

  /**
  */
  template<typename SzType= size_t, typename WordType = uint32_t,
           typename ByteType = uint8_t, typename SignedByteType = int8_t>
  class MD5
  {
   public:
    MD5();
    void Reset();

    void Update(const ByteType *buf, SzType lenght);
    void Update(const SignedByteType *buf, SzType lenght);

    const WordType* DigestWords();
    const ByteType* DigestBytes();
    void Digest(ByteType *digest);
    void Digest(WordType *digest);
    void Digest(WordType &A, WordType &B, WordType &C, WordType &D);

    static SzType BitLen();
    static SzType ByteLen();
    static SzType DigestSize();
  };

#endif SCIRE_MD5_CLASS
}
#endif SCIRE_hash_md5_HPP
