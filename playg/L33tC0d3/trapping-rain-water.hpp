namespace L33tC0d3
{
  /* Given n non-negative integers representing an elevation map where the width
  of each bar is 1, compute how much water it is able to trap after raining.

  For example,
  Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6. */
  class TrappingRainWater
  {
   public:
    int trap(int A[], int n)
    {
      int area = 0;
      int land = 0;
      int l = 0, r = n - 1;
      int cur = 0;
      int all = 0;
      int blk = 0;

      while (l <= r) {
        int lvl = (A[l]<A[r]) ? A[l] : A[r];
        if (lvl>cur) {
          all += (lvl - cur)*(r - l + 1);
          cur = lvl;
        }
        if (A[l]<A[r]) {
          blk += A[l++];
        } else {
          blk += A[r--];
        }
      }
      return all - blk;
    }
  };
}