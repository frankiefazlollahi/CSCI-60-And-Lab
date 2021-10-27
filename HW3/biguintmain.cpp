#include <iostream>
#include "biguint.h"
using namespace std;

int main()
{
  biguint num1 = biguint("10");
  biguint num2 = biguint("4");
  //cout << num2[2] << endl;
  //cout << num2[900]<< endl;
  cout << num1 << endl;
  cout << num2 << endl;
//  num1+=num2;
  //cout << num1 << endl;
//  biguint sum;
  //sum = num1 + num2;
  //cout << sum << endl;
  //num1-=num2;
  //cout << num1-num2 << endl;
  cout << num1.toString() << endl;
  cout << (num1 > num2);
  return 0;
}
