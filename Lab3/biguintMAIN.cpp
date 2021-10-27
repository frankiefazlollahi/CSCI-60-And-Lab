#include <iostream>
#include "biguint.h"
using namespace std;

int main()
{
  biguint num1 = biguint("6");
  biguint num2 = biguint("12345");
  cout << num2[2] << endl;
  cout << num2[900]<< endl;
  cout << num2 << endl;
  num1+=num2;
  cout << num1 << endl;
  biguint sum;
  sum = num1 + num2;
  cout << sum << endl;
  return 0;
}
