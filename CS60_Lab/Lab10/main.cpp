#include <iostream>
#include "partA.cpp"
using namespace std;

int main()
{
  bag<int> bag1;
  for(int i = 0; i < 5; i++)
  {
    bag1.insert(i);
  }
  for (auto e : bag1) cout << e*e << endl;
  cout << endl;
  bag<int> bag2;
  for(int i = 5; i < 10; i++)
  {
    bag2.insert(i);
  }
  for(bag<int>::iterator it = bag2.begin(); it != bag2.end(); it++)
  {
    cout << *it << endl;
  }

  return 0;
}
