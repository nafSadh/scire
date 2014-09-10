#include <string>
#include <stack>
using namespace std;
namespace L33tC0d3
{
  /** Given a string containing just the characters
    '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
    The brackets must close in the correct order, "()" and "()[]{}" are all
    valid but "(]" and "([)]" are not.*/
  class ValidParentheses
  {
   public:
    bool isValid(string s)
    {
      int len = s.length();
      stack<char> stk;
      int i = 0;
      while (i < len) {
        switch (s[i]) {
        case '(':
        case '{':
        case '[':
          stk.push(s[i]);
          break;

        case ')':
          if (stk.empty() || stk.top() != '(') return false;
          stk.pop();
          break;
        case '}':
          if (stk.empty() || stk.top() != '{') return false;
          stk.pop();
          break;
        case ']':
          if (stk.empty() || stk.top() != '[') return false;
          stk.pop();
          break;
        }
        i++;
      }
      return (stk.size() == 0);
    }
  };
}