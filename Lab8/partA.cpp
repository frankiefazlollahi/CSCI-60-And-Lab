#include <iostream>

using namespace std;

double water(int n)
{
  if(n == 0)
  {
    return 10;
  }
  else
  {
    return (water(n-1))/2 +1;
  }

}
bool isSorted(int a[], int n)
{
  if(n == 2)
  {
    return (a[n-2] <= a[n-1]);
  }
  else
  {
    return isSorted(a, (n-1)) && (a[n-1] <= a[n]) ;
  }
}

int main()
{

  int array[5] = {1,2,3,5,4};
  cout << isSorted(array, 5) << endl;
  cout<< water(2);
  return 0;
}
