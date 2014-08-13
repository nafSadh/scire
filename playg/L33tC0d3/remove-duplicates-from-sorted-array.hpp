/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2]. */
namespace L33tC0d3
{
  namespace remove_duplicates_from_sorted_array
  {
    class Solution
    {
     public:
      int removeDuplicates(int A[], int n)
      {
        int i, j;
        if (n<1) return 0;

        for (i = 1, j = 1; i<n; i++) {
          if (A[i] != A[j - 1]) {
            A[j] = A[i];
            j++;
          }
        }

        return j;
      }
    };
  }
}