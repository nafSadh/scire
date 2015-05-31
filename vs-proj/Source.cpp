#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <random>
#include "../scire/stat/quickselect.hpp"



using namespace std;
//* Definition for binary tree

int enmain()
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

class Solution
{
  int inline sqr(int n)
  {
    return n*n;
  }
  int sumOfSquareOfDigits(int n)
  {
    int sum = 0;
    while (n>0) {
      sum += sqr(n % 10);
      n /= 10;
    }
    return sum;
  }
  bool isHappy(int n, vector<int> &v)
  {
    int sum = sumOfSquareOfDigits(n);
    if (sum == 1) return true;
    for (int i = 0; i < v.size(); i++) {
      if (v[i] == sum) return false;
    }
    v.push_back(sum);
    return isHappy(sum, v);
  }
 public:
  bool isHappy(int n)
  {
    vector<int> v;
    v.push_back(n);
    return isHappy(n, v);
  }
};

int main()
{
  Solution s;
  int n;
  cin >> n;
  cout<<endl<<s.isHappy(n)<<endl;
  return 0;
}