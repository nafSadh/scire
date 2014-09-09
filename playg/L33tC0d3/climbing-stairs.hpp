namespace L33tC0d3
{
  /** You are climbing a stair case. It takes n steps to reach to the top.
  Each time you can either climb 1 or 2 steps. In how many distinct ways can you
  climb to the top? */
  class ClimbingStairs
  {
   public:
    int climbStairs(int n)
    {
      int a = 1, b = 0;
      int c;
      for (int i = 0; i < n; i++) {
        c = a + b;
        b = a;
        a = c;
      }
      return c;
    }
  };
}