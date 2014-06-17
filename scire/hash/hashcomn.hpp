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

#ifndef NO_HASH_UTILITY
#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
#include <cstdint>
#endif
#include <string>

namespace scire
{

#ifndef SCIRE_HashAlgo_INTFC
#define SCIRE_HashAlgo_INTFC
  /**
  * Common interface for Hash Algorithms
  */
  template<typename SzType = size_t, /* size type, integer */
           typename Ui32t = uint32_t,/* std 32bit unsigned integer */
           typename ByteT = uint8_t,/* byte type, 8bit unsigned integer */
           typename SByteT = int8_t/* signed byte type */>
  class IHashAlgo
  {
   public:
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

#ifndef  NO_HASH_UTILITY
  /** static utility routines for hash algorithms */
  class Hash
  {
   public:
    /**
    * Compute hash of msg using passed algo. Digest is to be stored in hash
    * object. This routine inits hash object and then invokes Update and Final
    */
    template<typename SzT, typename U32, typename B8, typename SB8>
    static void Compute(
      IHashAlgo<SzT, U32, B8, SB8>& iHA,/**< algo to compute with */
      std::string msg/**< message string to compute hash for */
    )
    {
      iHA.Init();
      iHA.Update(reinterpret_cast<const B8*>(msg.c_str()), msg.length());
      iHA.Final();
    }

    enum { BlockSz = 2048 };

    /**
    * Compute hash of file using passed algo. Digest is to be stored in hash
    * object. This routine inits hash object and then invokes Update and Final
    */
    template<typename SzT, typename U32, typename B8, typename SB8>
    static bool Compute(
      IHashAlgo<SzT, U32, B8, SB8>& iHA,/**< algo to compute with */
      std::ifstream& ifs/**< std::ifstream object to compute hash for */
    )
    {
      iHA.Init();
      if (!ifs) return false;

      // get length of file:
      ifs.seekg(0, ifs.end);
      std::streamsize filesize = ifs.tellg();
      ifs.seekg(0, ifs.beg);

      //compute
      std::streamsize processed = 0;
      char * buffer = new char[BlockSz];
      bool finished = false;

      while (!finished && (processed < filesize)) {
        // decide read size
        std::streamsize readq = (filesize - processed < BlockSz)
                                ? (filesize - processed) : BlockSz;
        // request read from file
        ifs.read(buffer, readq);

        // read results
        std::streamsize readc = ifs.gcount();
        if (readc < 0 || !ifs) {
          finished = true;
        } else {
          iHA.Update(reinterpret_cast<const B8*>(buffer), readc);
          processed += readc;
        }
      }
      iHA.Final();
      return true;
    }

    /**
    * Compute hash of file using passed algo. Digest is to be stored in hash
    * object. This routine inits hash object and then invokes Update and Final
    */
    template<typename SzT, typename U32, typename B8, typename SB8>
    static bool ComputeFile(
      IHashAlgo<SzT, U32, B8, SB8>& iHA,/**< algo to compute with */
      std::string filepath/**< path to file to compute hash for */
    )
    {
      std::ifstream ifs(filepath, std::ifstream::binary);
      if (!ifs) return false;
      bool result = Compute(iHA, ifs);
      ifs.close();
      return result;
    }
    /** @copydoc Hash::ComputeFilre */
    template<typename SzT, typename U32, typename B8, typename SB8>
    static bool ComputeFile(
      IHashAlgo<SzT, U32, B8, SB8>& iHA,/**< algo to compute with */
      char* filepath/**< path to file to compute hash for */
    )
    {
      return ComputeFile(iHA, std::string(filepath));
    }

  };
#endif//YES_HASH_UTILITY
}//scire namespace
#endif//SCIRE_hash_common_HPP
