// ALG0401LPI
//  knapsack problem

// coded by :
// Khan Muhammad Nafee Mostafa Sadh
// 0507007 Undergraduate student,
// Dept of Computer Science and Engineering,
// Khulna University of Engineering and Technology.

// on 15 Nov 2007
//

////|//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//|////
/*	|	  	this program demonstrates                           |	*
*	|		implementation of                                   |	*
*	|                                                           |	*
*	|		solution to KNAPSACK Problem using GREEDY METHOD    |	*
*	|                                                           |	*
*///|//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//|////
#include<iostream>
using namespace std;
////////////////////////////////////////////////////////////////////////
template<class swapType>
bool Swap(swapType &a, swapType &b)
{
  swapType temp;
  temp = a;
  a = b;
  b = temp;
  return true;
}

template<class heapType, class indexType>
bool inHeap(heapType ary[], heapType item, indexType index)
{
  if (index<0)return false;
  if (!index) return true;

  indexType par = ((index + 1) / 2) - 1;
  if ((ary[par]) >= (ary[index]))return true;
  Swap(ary[index], ary[par]);
  inHeap(ary, ary[par], par);
  return true;
}

template<class heapifyT, class indexT>
bool heapify(heapifyT ary[], indexT first, indexT last)
{
  for (indexT i = first; i <= last; i++)
    inHeap(ary, ary[i], i);
  return true;
}

template<class heapAryT, class sizeT>
bool heapSort(heapAryT ary[], sizeT size)
{
  sizeT zero = 0;
  for (sizeT i = size - 1; i>0; i--) {
    heapify(ary, zero, i);
    Swap(ary[0], ary[i]);
  }
  return true;
}
////////////////////////////////////////////////////////////////////
class Object
{
  double p;//profit from total of object
  double w;
  double r;//available weight of ith object
 public:
  Object() {}
  Object(double pr, double wr)
  {
    p = pr;
    w = wr;
    r = p / w;
  }

  double ratio()
  {
    return r;
  }

  bool operator>=(Object o)
  {
    return (ratio() >= o.ratio());
  }

  double profit()
  {
    return p;
  }

  double weight()
  {
    return w;
  }
};

class KnapSack
{
  int n;//number of objects;
  Object *obj;//array of objects
  double *x;//solution vector
  double capacity;

 public:
  KnapSack(int numberOfObjects, double profitArray[], double weightArray[])
  {
    n = numberOfObjects;
    obj = new Object[n];
    x = new double[n];
    for (int i = 0; i<n; i++) {
      obj[i] = Object(profitArray[i], weightArray[i]);
    }
    heapSort(obj, n);
  }

  void setCapacity(double capacityOfKnapSack)
  {
    capacity = capacityOfKnapSack;
  }
  double getCapacity()
  {
    return capacity;
  }
  void print()
  {
    cout << "\nweight,profit,ratio\n";
    for (int i = n - 1; i >= 0; i--)
      cout << obj[i].weight() << "," << obj[i].profit() << "," << obj[i].ratio() << endl;
  }

  void greedy()
  {
    int i;

    for (i = 0; i<n; i++)x[i] = 0.0;

    double U = capacity;//space ramaining

    for (i = n - 1; i >= 0; i--) {
      if (obj[i].weight() >U)break;
      x[i] = 1.0;
      U -= obj[i].weight();
    }
    if (i >= 0)x[i] = U / obj[i].weight();


  }

  void greedyKnapSack(double capacityOfKnapSack)
  {
    setCapacity(capacityOfKnapSack);
    greedy();
    double myProfit = 0;
    int i;
    cout << "\nfor a knapsack that can carry " << capacity
         << ", the solution matrix is : \n\n"
         << "weight,profit,fraction\n";
    for (i = n - 1; i >= 0; i--) {
      cout << obj[i].weight() << "," << obj[i].profit() << "," << x[i] << endl;
      myProfit += x[i] * obj[i].profit();
    }
    cout << "\nfor total profit " << myProfit;
    cout << endl;
  }

};


int GreedyKnapsackOLD_main()
{

  double *p;//[]={1,9,3};
  double *w;//[]={1,1,1};
  int i;
  int n;
  double m;

  cout << "enter number of objects ";
  cin >> n;
  p = new double[n];
  w = new double[n];

  cout << endl << "enter profits ";
  for (i = 0; i<n; i++)cin >> p[i];

  cout << endl << "enter available weight";
  for (i = 0; i<n; i++)cin >> w[i];
  KnapSack q(n, p, w);
  cout << "after sorting we get : \n";
  q.print();
  int d = 1;
  while (d) {
    cout << "what is the capacity of knapsack ";
    cin >> m;
    q.greedyKnapSack(m);
    cout << "\n\nenter 1 to recheck for new bag ;0 otherwise\n";
    cin >> d;
  }
  return 0;
}