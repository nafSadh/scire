#include <iostream>
#include "..\..\..\scire\struct\stack.hpp"
#include <stack>

using namespace std;
using namespace scire;

int main()
{
  stack<int> lst;
  Stack<char> stk;

  for (char c = 'a'; c <= 'z'; c++) {
    stk.Push(c);
    cout << stk.Size() << stk.Top() << endl;
  }

  while (stk.Size() > 0) {
    cout << stk.Top()<< " ";
    stk.Pop();
  }
  cout << endl;

  return 0;
}