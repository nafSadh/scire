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
  /*
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
   */
  for(int i=0 ; i<5 ; printf("%llx\n",pow(8,i)) , i++);
  cout << endl;
  printf("%llx\n", -1.0);
  int j = 0;
  while (j < 5) {
    cout<<pow(10, j)<<" ";
    cout << j << endl;
    j++;
  }

  cout << "---------\n\n";

  for (int i = 0; i < 5; i++) {

    int k = (int)pow(10, i);

    printf(" %d\n", k);
  }


  return 0;
}