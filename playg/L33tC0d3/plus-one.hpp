#include <vector>
namespace L33tC0d3
{
  /*Given a non-negative number represented as an array of digits, plus one to the number.

  The digits are stored such that the most significant digit is at the head of the list.*/
  class PlusOne
  {
   public:
    std::vector<int> plusOne(std::vector<int> &digits)
    {
      int carry = 1;
      int i = digits.size() - 1;
      while (carry>0) {
        if (i >= 0) {
          int sum = digits[i] + carry;
          digits[i] = sum % 10;
          carry = sum / 10;
          i--;
        } else {
          digits.insert(digits.begin(), carry);
          carry = 0;
        }
      }

      return digits;
    }
  };
}