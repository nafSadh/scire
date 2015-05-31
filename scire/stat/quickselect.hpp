#include <stdexcept>

template<typename Type, typename SzT = size_t>
class QuickSelect
{

  static void swap(Type *a, Type *b)
  {
    int temp = *a;
    *a = *b;
    *b = temp;
  }

  // Standard partition process of QuickSort().  It considers the last
  // element as pivot and moves all smaller element to left of it
  // and greater elements to right
  static SzT partition(Type A[], SzT l, SzT r)
  {
    Type x = A[r];
    SzT i = l;
    for (SzT j = l; j < r; j++) {
      if (A[j] <= x) {
        swap(&A[i], &A[j]);
        i++;
      }
    }
    swap(&A[i], &A[r]);
    return i;
  }

 public:
  static Type Array(Type A[], SzT k, SzT right, SzT left = 0)
  {
    if ((k < 0) || (k >(right - left + 1))) throw std::invalid_argument("k is out of bound");
    SzT pos = partition(A, left, right);

    return (pos - left == k - 1) ? A[pos] :
           (pos - left > k - 1) ?
           Array(A, k, pos - 1, left) :
           Array(A, k - pos + left - 1, right, pos + 1);
  }
};