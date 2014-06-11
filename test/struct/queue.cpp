#include <iostream>
#include "../../scire/struct/queue.hpp"
#include <queue>

using namespace std;
using namespace scire;

namespace sciretest
{
  int struct_queue_main()
  {
    queue<int> q;
    Queue<int> *que = new Queue<int>();

    cout<<"enqueue items # ";
    int n;
    cin >> n;
    for (int c = 0; c <= n; c++) {
      que->Enque(c);
    }

    cout<<"dequeue until # ";
    cin>>n;
    //delete que;
    while (que->Size() > n) {
      cout << que->Size() <<" "<< que->Front() << endl;
      que->Deque();
    }

    cout<<"done";
    return 0;
  }
}

#ifndef SCIRE_TEST_QUEUE
int main()
{
  return sciretest::struct_queue_main();
}
#endif
