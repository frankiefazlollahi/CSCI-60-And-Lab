#include <iostream>
#include "dbiguint.h"
using namespace std;

int main()
{
  dbiguint num1;
  dbiguint num2("12345");
  dbiguint num3("90000");
//  cout << num2.size() << endl;
  cout << num2 << endl;
  cout << num3 << endl;
//num2.reserve(10);
//  cout << num2.size() << endl;
//  cout << num2 << endl;
  num2 += num3;
  cout << num2 << endl;

  dbiguint num ("0000000000000489642");
  cout << num << endl;
  num.clean();
  cout << num << endl;

  return 0;
}
