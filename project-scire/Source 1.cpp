#include <iostream>
#include "..\scire\struct\linkedlist.hpp"
#include <list>

using namespace std;
using namespace scire;

void read(int a)
{
    cout << a << " ";
}

int main()
{
    SinglyList<int> slist;
    slist.Insert(100);
    slist.Insert(200);
    slist.Insert(300);
    slist.Traverse(read);
    cout << endl;
    for (int i = 0; i < 10; i++) {
        slist.Insert(i, i);
        slist.Traverse(read);
        cout << endl;
    }
    cout << "--\n";
    for (int i = 0; i < 10; i++) {
        cout<<slist.Pop()<<endl;
        slist.Traverse(read);
        cout << endl;
    }

}