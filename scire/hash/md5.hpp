// scire/hash/md5

// Copyright (c) 2014, Khan 'Sadh' Mostafa (http://nafSadh.com/Khan)
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying text at http://www.boost.org/LICENSE_1_0.txt)

/**
 @file: scire/hash/md5.hpp
 @author: nafSadh
 @brief:  MD5
 */
/*
 scire MD5 implementation:
 - MD5	            : a class offering MD5 functionalities

 other required scire files:
  none

 acknowledgement:
  RFC 1321, Rivest,  http://tools.ietf.org/html/rfc1321
  quantq, https://github.com/quantq/md5


  */
#ifndef SCIRE_hash_md5_HPP
#define SCIRE_hash_md5_HPP

#include <iostream>
#include <iomanip>
#include <cstdint>
#include <cstring>
#include <string>

namespace scire
{
#ifndef SCIRE_MD5_CLASS
#define SCIRE_MD5_CLASS


  template<typename SzType, typename Ui32t, typename ByteT, typename SByteT>
  class MD5;  // pre-declare the template class itself
  // pre-declare templae operator overload
  template<typename SzType, typename Ui32t, typename ByteT, typename SByteT>
  std::ostream&
  operator<< (std::ostream& out, const MD5<SzType, Ui32t, ByteT, SByteT>& md5);

  /**
  * MD5 Message-Digest Algorithm.
  * scire adaptation of the MD5 algorithm, adopted from RFC 1321.
  * http://tools.ietf.org/html/rfc1321
  *
  * This implemenation is templatic to facilitate machine portability. It takes
  * four <type> parameters:
  *   - SzType : size type, integer; default: size_t
  *   - Ui32t : unsigned 32bit integer, default: uint32_t of <cstdint>
  *   - ByteT : unsigned byte (8bit int), default: uint8_t of <cstdint>
  *   - SByteT : signed byte (8bit int), default: int8_t of <cstdint>\n
  * In most cases it will simply suffice to use MD5<>
  *
  * Example usage:
  * @code
  * MD5<> md5;
  * md5.Update(message, msglen); //call Update once or as many times necessary
  * md5.Final(); // digest is ready, any subsequent updates will be ignored
  * md5.Digest(digest); // fill 'digest' byte array with digest values
  * @endcode
  * Client should create an MD5 object. The construcor calls Init inside it, so
  * it is redundant to call Init() upor first use of the object. To compute MD5
  * checksum of a buffer, call Update() once or several times with chunks of the
  * message. A call to Final() indicated MD5 object that, message is complete.
  * Then, MD5 object computes finalized the digest. Client can receive digest
  * bytes by passing a byte array to fill digest values with it. Digest size is
  * 16 byte. After a call to Final(), all subsequent Update() calls will be
  * ignored. \n
  * MD5 object can be reused by invoking Reset() and then using it in a similar
  * fashion.
  *
  */
  template<typename SzType = size_t, /* size type, integer */
           typename Ui32t = uint32_t,/* std 32bit unsigned integer */
           typename ByteT = uint8_t,/* byte type, 8bit unsigned integer */
           typename SByteT = int8_t/* signed byte type */>
  class MD5
  {
    /* example use:
     * @code{.cpp}
     *   MD5<> md5; // ctor calls Init(), so you can start using md5 directly
     *   md5.Update(message, msglen); //once or manu times
     *   md5.Final(); // digest is ready, any subsequent updates will be ignored
     *   md5.Digest(digest); // fill 'digest' byte array with digest values
     * @encode
     */
   public:
    // -- Informative CONSTANTS --//
    enum Info {
      DigestSize_bits  = 128, /**< MD5 digest size in bits */
      DigestSize_bytes =  16, /**< MD5 digest size in bytes */
      DigestSize_words =   4, /**< MD5 digest size in words (32bit) */
      BlockSize_bits   = 512, /**< MD5 process message in chunks each of 512bit*/
      BlockSize_bytes   = 64, /**< block size in bytes */
      BlockSize_words   = 16, /**< block size in words (32bit) */
      Rounds = 4 /**< MD5 has 4 rounds */
    };
    enum Magic {
      MagicWordA = 0x01234567,
      MagicWordB = 0x89abcdef,
      MagicWordC = 0xfedcba98,
      MagicWordD = 0X76543210
    };

    /** allocate MD5 context and init */
    MD5();
    /** init MD5 object with a c-string message */
    MD5(char message[]);
    /** init MD5 object with a stl::string message */
    MD5(std::string message);

    /** release MD5 resources */
    //~MD5();

    // -- MD5 INTERFACE --//                        // adopted from Rivest's RFC
    /**
    * MD5 initialization.
    * Begins an MD5 operation, writing a new context (i.e. init class object).
    */
    void Init();

    /**
    * MD5 block update operation. Continues an MD5 message-digest
    * operation, processing another message block, and updating the
    * context.
    * @param input    an array of bytes
    * @param lenght   number of bytes in input chunk
    */
    bool Update(const ByteT *input, SzType lenght);
    /** @copydoc MD5::Update */
    bool Update(const SByteT *input, SzType lenght);

    /**
    * MD5 finalization. Ends an MD5 message-digest operation, writing the
    * the message digest and zeroizing the context.
    */
    void Final();

    /**
    * get digest bytes in
    * @return false if Final has yet not been called
    * @param digest   a 16 byte array to read digest values in
    */
    bool Digest(ByteT digest[DigestSize_bytes]);

    /** output digest to ostream */
    friend std::ostream& operator<< <>(std::ostream& out, const MD5<SzType, Ui32t, ByteT, SByteT>& md5);

    // -- ADOPTED FROM RFC 1321 -- //
   private:
    // -- MD5 context --//
    /** state (ABCD) */
    Ui32t state[DigestSize_words];
    /** number of bits modulo 2^64 (lsb first) */
    Ui32t count[2];
    /** bytes that didn't fit in last 64B chunk */
    ByteT buffer[BlockSize_bytes];
    /** if Final called */
    bool finalized;
    ByteT digest[DigestSize_bytes];

   public:
    // -- MD5 Added Interface -- //             // alias and extra functionality
    /** Reset object, similar to doing Init() */
    void Reset()
    {
      Init();
    }

    /** return  */
    //void Digest(ByteT *digest) {}
    //void Digest(Ui32t *digest) {}
    //void Digest(Ui32t &A, Ui32t &B, Ui32t &C, Ui32t &D) {}

// -- Basic MD5 Functions -- //
   protected:
    /**
    * F(X,Y,Z) = XY v not(X) Z
    *
    * from RFC 1321:\n
    * In each bit position F acts as a conditional: if X then Y else Z.
    * The function F could have been defined using + instead of v since XY
    * and not(X)Z will never have 1's in the same bit position.) It is
    * interesting to note that if the bits of X, Y, and Z are independent
    * and unbiased, the each bit of F(X,Y,Z) will be independent and
    * unbiased.
    */
    static Ui32t F(Ui32t x, Ui32t y, Ui32t z)
    {
      return (x&y) | ((~x)&z);
    }
    /**
    * G(X,Y,Z) = XZ v Y not(Z)
    *
    * from RFC 1321:\n
    * The functions G, H, and I are similar to the function F, in that they
    * act in "bitwise parallel" to produce their output from the bits of X,
    * Y, and Z, in such a manner that if the corresponding bits of X, Y,
    * and Z are independent and unbiased, then each bit of G(X,Y,Z),
    * H(X,Y,Z), and I(X,Y,Z) will be independent and unbiased. Note that
    * the function H is the bit-wise "xor" or "parity" function of its
    * inputs.
    * @see MD5::F
    */
    static Ui32t G(Ui32t x, Ui32t y, Ui32t z)
    {
      return (x&z) | (y&(~z));
    }
    /** H(X,Y,Z) = X xor Y xor Z  @see MD5::G */
    static Ui32t H(Ui32t x, Ui32t y, Ui32t z)
    {
      return x ^ y ^ z;
    }
    /** I(X,Y,Z) = Y xor (X v not(Z)) @see MD5::G */
    static Ui32t I(Ui32t x, Ui32t y, Ui32t z)
    {
      return y ^ (x | (~z));
    }

    /** the phenomenal transform function */
    void transform(const ByteT block[BlockSize_bytes]);

   private:
    /** constants for MD5 algorithm */
    enum {
      /** status indices */
      A = 0, B = 1, C = 2, D = 3,
      /** Constants for transform routine */
      S11 = 7, S21 = 5, S31 = 4, S41 = 6,
      S12 = 12, S22 =  9, S32 = 11, S42 = 10,
      S13 = 17, S23 = 14, S33 = 16, S43 = 15,
      S14 = 22, S24 = 20, S34 = 23, S44 = 21,
    };

    // -- MD5 UTILITY FUNCTIONS -- //

    /** rotates x left n bits.*/
    static Ui32t rotateleft(Ui32t x, SzType n)
    {
      return (x << n) | (x >> (32 - n));
    }

    /* FF, GG, HH, and II transformations for rounds 1, 2, 3, and 4.
    Rotation is separate from addition to prevent recomputation.
    */
    static void FF(Ui32t &a, Ui32t b, Ui32t c, Ui32t d,
                   Ui32t x, Ui32t s, Ui32t ac)
    {
      a = rotateleft(a + F(b, c, d) + x + ac, s) + b;
    }

    static void GG(Ui32t &a, Ui32t b, Ui32t c, Ui32t d,
                   Ui32t x, Ui32t s, Ui32t ac)
    {
      a = rotateleft(a + G(b, c, d) + x + ac, s) + b;
    }

    static void HH(Ui32t &a, Ui32t b, Ui32t c, Ui32t d,
                   Ui32t x, Ui32t s, Ui32t ac)
    {
      a = rotateleft(a + H(b, c, d) + x + ac, s) + b;
    }

    static void II(Ui32t &a, Ui32t b, Ui32t c, Ui32t d,
                   Ui32t x, Ui32t s, Ui32t ac)
    {
      a = rotateleft(a + I(b, c, d) + x + ac, s) + b;
    }

    /**
    * decodes input (unsigned char) into output (Ui32t). Assumes len is a
    * multiple of 4.
    */
    static void decode(Ui32t out[], const ByteT input[], SzType len)
    {
      for (unsigned int i = 0, j = 0; j < len; i++, j += 4)
        out[i] = ((Ui32t)input[j]) | (((Ui32t)input[j + 1]) << 8) |
                 (((Ui32t)input[j + 2]) << 16) | (((Ui32t)input[j + 3]) << 24);
    }

    /**
    * encodes input (Ui32t) into output (unsigned char). Assumes len is
    * a multiple of 4.
    */
    static void encode(ByteT out[], const Ui32t input[], SzType len)
    {
      for (SzType i = 0, j = 0; j < len; i++, j += 4) {
        out[j] = input[i] & 0xff;
        out[j + 1] = (input[i] >> 8) & 0xff;
        out[j + 2] = (input[i] >> 16) & 0xff;
        out[j + 3] = (input[i] >> 24) & 0xff;
      }
    }
  };

//------------------//
// -- MD5 CTORS -- //
//----------------//

  template<typename SzType, typename Ui32t, typename ByteT, typename SByteT>
  MD5<SzType, Ui32t, ByteT, SByteT>::
  MD5()
    : finalized(false)
  {
    Init();
  }


  template<typename SzType, typename Ui32t, typename ByteT, typename SByteT>
  MD5<SzType, Ui32t, ByteT, SByteT>::
  MD5(char msg[])
    : finalized(false)
  {
    Init();
    Update(reinterpret_cast<const ByteT*>(msg), strlen(msg));
    Final();
  }

  template<typename SzType, typename Ui32t, typename ByteT, typename SByteT>
  MD5<SzType, Ui32t, ByteT, SByteT>::
  MD5(std::string msg)
    : finalized(false)
  {
    Init();
    Update(reinterpret_cast<const ByteT*>(msg.c_str()), msg.length());
    Final();
  }

  template<typename SzType, typename Ui32t, typename ByteT, typename SByteT>
  std::ostream&
  operator<<(std::ostream& out, const MD5<SzType, Ui32t, ByteT, SByteT>& md5)
  {
    for (SzType i = 0; i < 16; i++) {
      out << setfill('0') << setw(2) << hex << (int)md5.digest[i];
    }
    return out;
  }

  //---------------------------//
  // -- MD5 IMPLEMENTATION -- //
  //-------------------------//

  template<typename SzType, typename Ui32t, typename ByteT, typename SByteT>
  void MD5<SzType, Ui32t, ByteT, SByteT>::
  Init()
  {
    // init consumed bitlen to zero
    this->count[0] = this->count[1] = 0;
    // init with magic numbers
    this->state[0] = 0x67452301;
    this->state[1] = 0xefcdab89;
    this->state[2] = 0x98badcfe;
    this->state[3] = 0x10325476;

    this->finalized = false;
  }


  template<typename SzType, typename Ui32t, typename ByteT, typename SByteT>
  bool MD5<SzType, Ui32t, ByteT, SByteT>::
  Digest(ByteT digest_[DigestSize_bytes])
  {
    if (!finalized) return false;

    for (int i = 0; i < DigestSize_bytes; i++) {
      digest_[i] = this->digest[i];
    }

    return true;
  }


  template<typename SzType, typename Ui32t, typename ByteT, typename SByteT>
  bool MD5<SzType, Ui32t, ByteT, SByteT>::
  Update(const SByteT * input, SzType length)
  {
    Update((const unsigned char*)input, length);
  }


  template<typename SzType, typename Ui32t, typename ByteT, typename SByteT>
  bool MD5<SzType, Ui32t, ByteT, SByteT>::
  Update(const ByteT * input, SzType inputLen)
  {
    if (finalized) return false; // ignore all Update() after Final() is called

    // Compute number of bytes mod 64
    SzType index = (unsigned int)((this->count[0] >> 3) & 0x3F);

    // Update number of bits
    if ((this->count[0] += ((Ui32t)inputLen << 3)) < ((Ui32t)inputLen << 3)) {
      this->count[1]++;
    }//eventually
    this->count[1] += ((Ui32t)inputLen >> 29);

    SzType partLen = 64 - index;
    SzType i;
    // Transform as many times as possible
    if (inputLen >= partLen) {
      std::memcpy(&buffer[index], input, partLen);
      transform(buffer);

      // transform each chunk of blocksize (64B)
      for (i = partLen; i + 63 < inputLen; i += 64)
        transform(&input[i]);
      index = 0;
    } else {
      i = 0;
    }

    //buffer remaining input for padding shall occur
    memcpy(&buffer[index], &input[i], inputLen - i);

    return true;
  }//end MD5::Update


  template<typename SzType, typename Ui32t, typename ByteT, typename SByteT>
  void MD5<SzType, Ui32t, ByteT, SByteT>::
  Final()
  {
    static ByteT padding[64] = {
      0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };

    if (!finalized) {
      // Save number of bits
      ByteT  bits[8];
      encode(bits, count, 8);

      // pad out to 56 mod 64.
      SzType index = (Ui32t)((this->count[0] >> 3) & 0x3f);
      SzType padLen = (index < 56) ? (56 - index) : (120 - index);
      Update(padding, padLen);

      // Append length (before padding)
      Update(bits, 8);

      // Store state in digest
      encode(digest, state, 16);

      // Zeroize sensitive information.
      memset(buffer, 0, sizeof buffer);
      memset(count, 0, sizeof count);

      finalized = true;
    }
  }


  template<typename SzType, typename Ui32t, typename ByteT, typename SByteT>
  void MD5<SzType, Ui32t, ByteT, SByteT>::
  transform(const ByteT block[BlockSize_bytes])
  {
    // copy current status
    Ui32t a = state[A], b = state[B], c = state[C], d = state[D];

    // convert input to 32bit uints
    Ui32t x[BlockSize_words];
    decode(x, block, BlockSize_bytes);

    /* Round 1 */
    FF(a, b, c, d, x[ 0], S11, 0xd76aa478); /* 1 */
    FF(d, a, b, c, x[ 1], S12, 0xe8c7b756); /* 2 */
    FF(c, d, a, b, x[ 2], S13, 0x242070db); /* 3 */
    FF(b, c, d, a, x[ 3], S14, 0xc1bdceee); /* 4 */
    FF(a, b, c, d, x[ 4], S11, 0xf57c0faf); /* 5 */
    FF(d, a, b, c, x[ 5], S12, 0x4787c62a); /* 6 */
    FF(c, d, a, b, x[ 6], S13, 0xa8304613); /* 7 */
    FF(b, c, d, a, x[ 7], S14, 0xfd469501); /* 8 */
    FF(a, b, c, d, x[ 8], S11, 0x698098d8); /* 9 */
    FF(d, a, b, c, x[ 9], S12, 0x8b44f7af); /* 10 */
    FF(c, d, a, b, x[10], S13, 0xffff5bb1); /* 11 */
    FF(b, c, d, a, x[11], S14, 0x895cd7be); /* 12 */
    FF(a, b, c, d, x[12], S11, 0x6b901122); /* 13 */
    FF(d, a, b, c, x[13], S12, 0xfd987193); /* 14 */
    FF(c, d, a, b, x[14], S13, 0xa679438e); /* 15 */
    FF(b, c, d, a, x[15], S14, 0x49b40821); /* 16 */

    /* Round 2 */
    GG(a, b, c, d, x[ 1], S21, 0xf61e2562); /* 17 */
    GG(d, a, b, c, x[ 6], S22, 0xc040b340); /* 18 */
    GG(c, d, a, b, x[11], S23, 0x265e5a51); /* 19 */
    GG(b, c, d, a, x[ 0], S24, 0xe9b6c7aa); /* 20 */
    GG(a, b, c, d, x[ 5], S21, 0xd62f105d); /* 21 */
    GG(d, a, b, c, x[10], S22, 0x2441453); /* 22 */
    GG(c, d, a, b, x[15], S23, 0xd8a1e681); /* 23 */
    GG(b, c, d, a, x[ 4], S24, 0xe7d3fbc8); /* 24 */
    GG(a, b, c, d, x[ 9], S21, 0x21e1cde6); /* 25 */
    GG(d, a, b, c, x[14], S22, 0xc33707d6); /* 26 */
    GG(c, d, a, b, x[ 3], S23, 0xf4d50d87); /* 27 */
    GG(b, c, d, a, x[ 8], S24, 0x455a14ed); /* 28 */
    GG(a, b, c, d, x[13], S21, 0xa9e3e905); /* 29 */
    GG(d, a, b, c, x[ 2], S22, 0xfcefa3f8); /* 30 */
    GG(c, d, a, b, x[ 7], S23, 0x676f02d9); /* 31 */
    GG(b, c, d, a, x[12], S24, 0x8d2a4c8a); /* 32 */

    /* Round 3 */
    HH(a, b, c, d, x[ 5], S31, 0xfffa3942); /* 33 */
    HH(d, a, b, c, x[ 8], S32, 0x8771f681); /* 34 */
    HH(c, d, a, b, x[11], S33, 0x6d9d6122); /* 35 */
    HH(b, c, d, a, x[14], S34, 0xfde5380c); /* 36 */
    HH(a, b, c, d, x[ 1], S31, 0xa4beea44); /* 37 */
    HH(d, a, b, c, x[ 4], S32, 0x4bdecfa9); /* 38 */
    HH(c, d, a, b, x[ 7], S33, 0xf6bb4b60); /* 39 */
    HH(b, c, d, a, x[10], S34, 0xbebfbc70); /* 40 */
    HH(a, b, c, d, x[13], S31, 0x289b7ec6); /* 41 */
    HH(d, a, b, c, x[ 0], S32, 0xeaa127fa); /* 42 */
    HH(c, d, a, b, x[ 3], S33, 0xd4ef3085); /* 43 */
    HH(b, c, d, a, x[ 6], S34, 0x4881d05); /* 44 */
    HH(a, b, c, d, x[ 9], S31, 0xd9d4d039); /* 45 */
    HH(d, a, b, c, x[12], S32, 0xe6db99e5); /* 46 */
    HH(c, d, a, b, x[15], S33, 0x1fa27cf8); /* 47 */
    HH(b, c, d, a, x[ 2], S34, 0xc4ac5665); /* 48 */

    /* Round 4 */
    II(a, b, c, d, x[ 0], S41, 0xf4292244); /* 49 */
    II(d, a, b, c, x[ 7], S42, 0x432aff97); /* 50 */
    II(c, d, a, b, x[14], S43, 0xab9423a7); /* 51 */
    II(b, c, d, a, x[ 5], S44, 0xfc93a039); /* 52 */
    II(a, b, c, d, x[12], S41, 0x655b59c3); /* 53 */
    II(d, a, b, c, x[ 3], S42, 0x8f0ccc92); /* 54 */
    II(c, d, a, b, x[10], S43, 0xffeff47d); /* 55 */
    II(b, c, d, a, x[ 1], S44, 0x85845dd1); /* 56 */
    II(a, b, c, d, x[ 8], S41, 0x6fa87e4f); /* 57 */
    II(d, a, b, c, x[15], S42, 0xfe2ce6e0); /* 58 */
    II(c, d, a, b, x[ 6], S43, 0xa3014314); /* 59 */
    II(b, c, d, a, x[13], S44, 0x4e0811a1); /* 60 */
    II(a, b, c, d, x[ 4], S41, 0xf7537e82); /* 61 */
    II(d, a, b, c, x[11], S42, 0xbd3af235); /* 62 */
    II(c, d, a, b, x[ 2], S43, 0x2ad7d2bb); /* 63 */
    II(b, c, d, a, x[ 9], S44, 0xeb86d391); /* 64 */

    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;

    // Zeroize sensitive information.
    memset(x, 0, sizeof x);
  }
#endif SCIRE_MD5_CLASS
}
#endif SCIRE_hash_md5_HPP
