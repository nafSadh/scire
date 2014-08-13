/* Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3]. */
namespace L33tC0d3
{
  namespace Remove_Duplicates_from_Sorted_Array_II
  {
    class Solution
    {
     public:
      int removeDuplicates(int A[], int n)
      {
        int i, j;
        if (n < 3) return n;

        for (i = 2, j = 2; i < n; i++) {
          if (A[i] != A[j - 1] || A[i] != A[j - 2]) {
            A[j] = A[i];
            j++;
          }
        }
        return j;
      }
    };

  }
}