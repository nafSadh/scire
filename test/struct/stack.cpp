#include <iostream>
#include "../../scire/struct/stack.hpp"
#include <stack>

using namespace std;
using namespace scire;

namespace sciretest
{
  int struc_stack_main()
  {
    StackCrate<char> stk(40);

    for (char c = 'a'; c <= 'z'; c++) {
      stk.Push(c);
      cout << stk.Size() << stk.Top() << endl;
    }

    while (stk.Size() > 0) {
      cout << stk.Top() << " ";
      stk.Pop();
    }
    cout << endl;

    return 0;
  }
}

#ifdef SCIRE_TEST_STACK
int main()
{
  return sciretest::struc_stack_main();
}
#endif