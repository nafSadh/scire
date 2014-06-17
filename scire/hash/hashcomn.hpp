// scire/hash/hashcomn

// Copyright (c) 2014, Khan 'Sadh' Mostafa (http://nafSadh.com/Khan)
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying text at http://www.boost.org/LICENSE_1_0.txt)

/**
 scire/hash/hashcomn.hpp

 hash common interface and utilities
 - IHashAlgo	  : hash algorithm interface
 - Hash         : static utility functions (disabled by NO_HASH_UTILITY)

 other required scire files:
  none

 author:
  ~nafSadh
 */
#ifndef SCIRE_hash_common_HPP
#define SCIRE_hash_common_HPP

#include <string>

namespace scire
{

#ifndef SCIRE_HashAlgo_INTFC
#define SCIRE_HashAlgo_INTFC
  template<typename SzType = size_t, /* size type, integer */
           typename Ui32t = uint32_t,/* std 32bit unsigned integer */
           typename ByteT = uint8_t,/* byte type, 8bit unsigned integer */
           typename SByteT = int8_t/* signed byte type */>
  class IHashAlgo
  {
   public:
    // -- Common  INTERFACE  for Hash Algorithms --//
    /**
    * initialization.
    */
    virtual void Init() = 0;

    /**
    * block update operation
    * @param input    an array of bytes
    * @param lenght   number of bytes in input chunk
    */
    virtual bool Update(const ByteT* input, SzType lenght) = 0;
    /** @copydoc HashAlgo::Update */
    virtual bool Update(const SByteT* input, SzType lenght) = 0;

    /**
    * final hash compute, prepare digest.
    */
    virtual void Final() = 0;

    /** fingerprint is the 128bit message-digest */
    virtual std::string Fingerprint() const = 0;

    /** String representation of Four State Words (ABCD) */
    virtual std::string StatePhrase() const = 0;

    /** string reprsentation | fingerpring on finalize, else status words */
    virtual std::string ToString() const = 0;
  };
#endif//SCIRE_HashAlgo_INTFC
}
#endif//SCIRE_hash_common_HPP
