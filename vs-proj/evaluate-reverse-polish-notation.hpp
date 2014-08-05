/* Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:

  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/
#include <vector>
#include <stack>
using namespace std;
namespace L33tC0d3
{
  namespace binary_tree_preorder_traversal
  {

    class Solution
    {
     public:
      int evalRPN(vector<string> &tokens)
      {
        int len = tokens.size();
        int val = 0;
        stack<int> stk;
        int a, b, c;
        for (int i = 0; i<len; i++) {
          char op = (tokens[i])[0];
          if (tokens[i].length() == 1) {
            switch (op) {
            case '+':
              b = (stk.top());
              stk.pop();
              a = (stk.top());
              stk.pop();
              c = a + b;
              stk.push(c);
              break;
            case '-':
              b = (stk.top());
              stk.pop();
              a = (stk.top());
              stk.pop();
              c = a - b;
              stk.push(c);
              break;
            case '*':
              b = (stk.top());
              stk.pop();
              a = (stk.top());
              stk.pop();
              c = a*b;
              stk.push(c);
              break;
            case '/':
              b = (stk.top());
              stk.pop();
              a = (stk.top());
              stk.pop();
              c = a / b;
              stk.push(c);
              break;
            default:
              stk.push(atoi(tokens[i].c_str()));
            }
          } else {
            stk.push(atoi(tokens[i].c_str()));
          }
        }

        return stk.top();
      }
    };
  }
}