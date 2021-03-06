// scire/sort/counting_sort

// Copyright (c) 2014, Khan 'Sadh' Mostafa (http://nafSadh.com/Khan)
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying text at http://www.boost.org/LICENSE_1_0.txt)

/**
 scire/sort/counting_sort.hpp

 scire <thing> implementation:
 - CountingSort	            : very brief description

 other required scire files:
  none

 author:
  ~nafSadh
 */
#ifndef SCIRE_sort_counting_sort_HPP
#define SCIRE_sort_counting_sort_HPP


#ifndef SCIRE_DO_NOT_USE_VECTOR
#include <vector>
#endif

namespace scire
{

#ifndef SCIRE_CountingSort_CLASS
#define SCIRE_CountingSort_CLASS

  /**
  */

  template<typename InT, typename SzT = size_t>
  class CountingSort
  {
   public:
    static void Array(InT* A, SzT n, InT lower, InT upper)
    {
      //Allocate
      InT *B = new InT[n];
      SzT span = upper - lower + 1;
      InT *c = new InT[span];
      SzT i;


      //Init count array
      for (i = 0; i < span; i++) {
        c[i] = 0;
      }

      //copy array and count
      for (i = 0; i < n; i++) {
        B[i] = A[i];
        c[A[i] - lower]++;
      }

      //prefix-sum
      for (i = 1; i < span; i++) {
        c[i] = c[i] + c[i - 1];
      }

      //copy sorted
      for (SzT j = n; j >0 ; j--) {
        i = j - 1;
        SzT x = c[(B[i] - lower)]-1;
        if (x >= 0 && x<n) {
          A[x] = B[i];
          c[(B[i] - lower)]--;
        }
      }
    }

#ifndef SCIRE_DO_NOT_USE_VECTOR
    static void Vector(std::vector<InT>& A, SzT n, InT lower, InT upper)
    {
      //Allocate
      std::vector<InT> B(n);
      SzT span = upper - lower + 1;
      InT *c = new InT[span];
      SzT i;


      //Init count array
      for (i = 0; i < span; i++) {
        c[i] = 0;
      }

      //copy array and count
      for (i = 0; i < n; i++) {
        B[i] = A[i];
        c[A[i] - lower]++;
      }

      //prefix-smu
      for (i = 1; i < span; i++) {
        c[i] = c[i] + c[i - 1];
      }

      //copy sorted
      for (SzT j = n; j >0; j--) {
        i = j - 1;
        SzT x = c[(B[i] - lower)] - 1;
        if (x >= 0 && x<n) {
          A[x] = B[i];
          c[(B[i] - lower)]--;
        }
      }
    }
#endif//SCIRE_DO_NOT_USE_VECTOR
  };

#endif//SCIRE_CountingSort_CLASS
}
#endif//SCIRE_sort_counting_sort_HPP
