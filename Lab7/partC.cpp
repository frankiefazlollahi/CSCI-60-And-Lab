#include <iostream>

using namespace std;
//RECURSION EXAMPLES
int salary(int n);
int factorial (int n);
void cheers(int n);
int fibonacci(int n);
int main()
{
  int s = salary(10);
  cout << "salary" << endl;
  cout << s << endl;
  int f = factorial(5);
  cout << "factorial" << endl;
  cout << f << endl;
  cheers(3);
  cout <<"Fibonacci \n";
  int fib = fibonacci(4);
  cout << fib << endl;

  return 0;
}

int salary(int n)
{
  int s = 50;
  if(n ==0)
  {
    return s;
  }
  return 1.1*salary(n-1) + 5;
}

int factorial(int n)
{
  if(n == 1)
  {
    return 1;
  }
  return n*factorial(n-1);
}
void cheers(int n){
  if(n == 1)
  {
    cout << "Hurray!\n";
  }
  else{
    cout << "Hip ";
    cheers(n-1);
  }
}
int fibonacci(int n)
{
  if(n == 0 || n == 1)
  {
    return n;
  }
  return (fibonacci(n-2) + fibonacci(n-1));

}
