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
#include <cstring>

namespace scire
{
#ifndef SCIRE_MD5_CLASS
#define SCIRE_MD5_CLASS

  /**
  */
  template<typename SzType= size_t, typename Ui32t = uint32_t,
           typename ByteT = uint8_t, typename SByteT = int8_t>
  class MD5
  {
   public:
    // -- CONSTANTS --//
    enum {
      DigestSize_bits  = 128, DigestSize_bytes  = 16, DigsetSize_words  =  4,
      BlockSize_bits   = 512, BlockSize_bytes   = 64, BlockSize_words   = 16,
      Rounds_cnt       =   4
    };

    /** allocate MD5 context and init */
    MD5();
    /** release MD5 resources */
    ~MD5();

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
    */
    void Update(const ByteT *input, SzType lenght);
    /** @copydoc MD5::Update */
    void Update(const SByteT *input, SzType lenght);

    /**
    * MD5 finalization. Ends an MD5 message-digest operation, writing the
    * the message digest and zeroizing the context.
    */
    void Final(ByteT digest[]);

    // -- MD5 Added Interface -- //             // alias and extra functionality
    /** Reset object, similar to doing Init() */
    void Reset();

    /**  */
    const ByteT* Digest() {}
    void Digest(ByteT *digest) {}
    void Digest(Ui32t *digest) {}
    void Digest(Ui32t &A, Ui32t &B, Ui32t &C, Ui32t &D) {}
    const Ui32t* DigestWords() {}

    // -- INFORMATIVE -- //
    /*static SzType BitLen();
    static SzType ByteLen();
    static SzType DigestSize();
    static SzType BlockSize();
    static SzType Rounds();
    */

    // -- ADOPTED FROM RFC 1321 -- //

   private:
    // -- MD5 context --//
    Ui32t state[DigsetSize_words]; /** state (ABCD) */
    Ui32t count[2]; /** number of bits modulo 2^64 (lsb first) */
    ByteT buffer[BlockSize_bytes]; /** bytes that didn't fit in last 64B chunk */
    bool finalized; /** if Final called */

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

   private:
    /** the phenomenal transform function */
    void transform(ByteT block[BlockSize_bytes]);

    /** Constants for transform routine */
    enum {
      S11 =  7, S21 =  5, S31 =  4, S41 =  6,
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
    static void FF(Ui32t &a, Ui32t b, Ui32t c, Ui32t d, Ui32t x, Ui32t s, Ui32t ac)
    {
      a = rotate_left(a + F(b, c, d) + x + ac, s) + b;
    }

    static void GG(Ui32t &a, Ui32t b, Ui32t c, Ui32t d, Ui32t x, Ui32t s, Ui32t ac)
    {
      a = rotate_left(a + G(b, c, d) + x + ac, s) + b;
    }

    static void HH(Ui32t &a, Ui32t b, Ui32t c, Ui32t d, Ui32t x, Ui32t s, Ui32t ac)
    {
      a = rotate_left(a + H(b, c, d) + x + ac, s) + b;
    }

    static void II(Ui32t &a, Ui32t b, Ui32t c, Ui32t d, Ui32t x, Ui32t s, Ui32t ac)
    {
      a = rotate_left(a + I(b, c, d) + x + ac, s) + b;
    }

    /**
    * decodes input (unsigned char) into output (uint4). Assumes len is a
    * multiple of 4.
    */
    static void decode(Ui32t output[], const ByteT input[], SzType len)
    {
      for (unsigned int i = 0, j = 0; j < len; i++, j += 4)
        output[i] = ((uint4)input[j]) | (((uint4)input[j + 1]) << 8) |
                    (((uint4)input[j + 2]) << 16) | (((uint4)input[j + 3]) << 24);
    }

    /**
    * encodes input (uint4) into output (unsigned char). Assumes len is
    * a multiple of 4.
    */
    static void encode(ByteT output[], const Ui32t input[], SzType len)
    {
      for (size_type i = 0, j = 0; j < len; i++, j += 4) {
        output[j] = input[i] & 0xff;
        output[j + 1] = (input[i] >> 8) & 0xff;
        output[j + 2] = (input[i] >> 16) & 0xff;
        output[j + 3] = (input[i] >> 24) & 0xff;
      }
    }
  };

  //--------------------------//
  // -- MD5 IMPLEMENTATION -- //
  //--------------------------//

  template<typename SzType, typename Ui32t, typename ByteT, typename SByteT>
  MD5<SzType, Ui32t, ByteT, SByteT>::MD5()
    : finalized(false)
  {
    Init();
  }

  template<typename SzType, typename Ui32t,typename ByteT, typename SByteT>
  void MD5<SzType, Ui32t, ByteT, SByteT>::Init()
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
  void MD5<SzType, Ui32t, ByteT, SByteT>::Update(const SByteT input[], SzType length)
  {
    update((const unsigned char*)input, length);
  }

  template<typename SzType, typename Ui32t, typename ByteT, typename SByteT>
  void MD5<SzType, Ui32t, ByteT, SByteT>::Update(const ByteT input[], SzType inputLen)
  {
    // Compute number of bytes mod 64
    SzType index = (unsigned int)((this->count[0] >> 3) & 0x3F);


    /* Update number of bits */
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
    memcpy(&buffer[index], &input[i], length - i);
  }//end MD5::Update


  template<typename SzType, typename Ui32t, typename ByteT, typename SByteT>
  void MD5<SzType, Ui32t, ByteT, SByteT>::Final()
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
      update(padding, padLen);

      // Append length (before padding)
      update(bits, 8);

      // Store state in digest
      encode(digest, state, 16);

      // Zeroize sensitive information.
      memset(buffer, 0, sizeof buffer);
      memset(count, 0, sizeof count);

      finalized = true;
    }
  }


  template<typename SzType, typename Ui32t, typename ByteT, typename SByteT>
  void MD5<SzType, Ui32t, ByteT, SByteT>::transform(const ByteT block[blocksize])
  {
    uint4 a = state[0], b = state[1], c = state[2], d = state[3], x[16];
    decode(x, block, blocksize);

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
