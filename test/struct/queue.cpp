#include <iostream>
#include "../../scire/struct/queue.hpp"
#include <queue>

using namespace std;
using namespace scire;

namespace sciretest
{
  int struct_queue_main()
  {
    Queue<int> *que = new Queue<int>();

    for (int c = 0; c <= 100000; c++) {
      que->Enque(c);
    }

    int a;
    cin >> a;
    delete que;
    //while (que.Size() > 0) {
    //  //cout << que.Size() << que.Front() << endl;
    //  que.Deque();
    //}

    cin >> a;

    return 0;
  }
}

#ifndef SCIRE_TEST_QUEUE
int main()
{
  return sciretest::struct_queue_main();
}
#endif