#include <iostream>
#include <string>
using namespace std;

template <typename T1, typename T2>
//Needs operator == to work
int count_exact(T1 a[], T2 size, T1 find)
{
  int counter = 0;
  for(T2 i = 0; i < size; i++)
  {
    if(a[i] == find)
    {
      counter++;
    }
  }
  return counter;
}
//Needs < or >  to work
template <typename T1, typename T2>
int count_range(T1 a[], T2 size, T1 low, T1 high)
{
  int counter = 0;
  for(T2 i = 0; i < size; i++)
  {
    if(a[i] < high && a[i] > low)
    {
      counter++;
    }
  }
  return counter;
}

int main()
{
  int intArray[5] = {2,4,6,2,3};
  string strArray[6] = {"aaa", "bbb", "ccc", "ddd", "aaa", "ccc"};
  string a = "aaa";
  string d = "ddd";
  cout << count_exact(intArray, 5, 2) << endl;
  cout << count_exact(strArray, 4, a) << endl;
  cout << count_range(intArray, 5, 2, 6) << endl;
  cout << count_range(strArray, 6, a, d) << endl;

  return 0;
}
