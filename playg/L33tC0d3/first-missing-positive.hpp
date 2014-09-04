namespace L33tC0d3
{
  /* Given an unsorted integer array, find the first missing positive integer.

  For example,
  Given [1,2,0] return 3,
  and [3,4,-1,1] return 2.

  Your algorithm should run in O(n) time and uses constant space. */
  class FirstMissingPositive
  {
   public:
    int firstMissingPositive(int A[], int n)
    {
      if (n == 0) return 1;
      for (int i = 0; i < n; i++) {
        if (A[i] <= n && A[i] > 0 && A[i] != i + 1) {
          if (A[A[i] - 1] != A[i]) { //line 9
            int tmp = A[A[i] - 1];
            A[A[i] - 1] = A[i];
            A[i] = tmp;
            i--; //line 13
          }
        }
      }
      for (int i = 0; i < n; i++) {
        if (A[i] != i + 1) return i + 1;
      }
      return n + 1;
    }
  };
}