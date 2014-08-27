#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <random>
#include "../scire/sort/counting_sort.hpp"



using namespace std;
//* Definition for binary tree

int main()
{
  unsigned seed = 75545;
  std::mt19937 generator(seed);
  //int A[1000];
  vector<int> A=vector<int>(1000);
  for (int i = 0; i < 1000; i++) {
    A[i] = generator()%100;
  }
  for (int i = 0; i < 1000; i++) {
    cout << A[i] << ' ';
    if (i % 20 == 19)cout << endl;
  }
  cout << endl;
  scire::CountingSort<int>::Vector(A, 1000, 0, 99);

  for (int i = 0; i < 1000; i++) {
    cout << A[i] << ' ';
    if (i % 20 == 19)cout << endl;
  }

  int a = 1;
  int *p = &a;
  cout << p << endl;
  p = p + 1;
  cout << p << endl;

  return 0;
}