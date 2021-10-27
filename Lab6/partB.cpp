#include <iostream>
using namespace std;

template<typename T>
class Point
{
public:
  Point();
  Point(int dim);
  Point(T array[], int dim);
  T getItem(int pos) {return arr[pos];}
  int getSize() {return dimension;}
  void operator =(const Point& p);
private:
  T arr[10];
  int dimension;
};

template<typename T>
Point<T>::Point()
{
  for(int i = 0; i < 10; i++)
  {
    arr[i] = T();
  }
  dimension = 0;
}
template<typename T>
Point<T>::Point(int dim)
{
  dimension = dim;
  for(int i = 0; i < dim; i++)
  {
    arr[i] = T();
  }
}
template<typename T>
Point<T>::Point(T array[], int dim)
{
  for(int i = 0; i < dim; i++)
  {
    arr[i] = array[i];
  }

  dimension = dim;
}
template<typename T>
void Point<T>::operator =(const Point<T>& p)
{
  dimension = p.dimension;
  for(int i = 0; i < dimension; i++)
  {
    arr[i] = p.arr[i];
  }
}

int main()
{
  Point<int> p;
  Point<int> p2(4);
  string arr[6] = {"aa", "bb", "cc", "dd", "ee", "ff"};
  Point<string> p3(arr, 6);
  cout << p2.getItem(3) << endl;
  cout << p3.getItem(2) << endl;

  for(int i = 0; i < 6; i++)
  {
    cout << p3.getItem(i) << " ";
  }
  cout << endl;
  Point<string> p4;
  p4 = p3;
  for(int i = 0; i < 6; i++)
  {
    cout << p4.getItem(i) << " ";
  }

  return 0;
}
