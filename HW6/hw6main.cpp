// HW6 starter file
// Frankie Fazlollahi

#include <iostream>
#include <vector>

using namespace std;

/* Part 1 */
template<typename T>
ostream& operator <<(ostream& out, const vector<T>& n)
{
  for(vector<int>::size_type i=0; i<n.size(); i++)
  {
    out << n[i];
    if(i != n.size() - 1)
      out << ", ";
  }
  return out;
}


/* Part 2 */
template<typename T1, typename T2>
class Pair{
public:
  Pair(): x(T1()), y(T2()) {}
  Pair(T1 x, T2 y) : x(x), y(y) {}
  T1 getX() const {return x;}
  T2 getY() const {return y;}
  Pair<T1,T2> operator +(const Pair<T1,T2>& rhs)
  {
    T1 xSum = x + rhs.getX();
    T2 ySum = y + rhs.getY();
    Pair sum = Pair(xSum, ySum);
    return sum;
  }

private:
  T1 x;
  T2 y;
};

template<typename T1, typename T2>
ostream& operator <<(ostream& out, const Pair<T1,T2>& p)
{
  out << "(" << p.getX() << "," << p.getY() << ")";
  return out;
}


/* Part 3 */
class Rational {
public:
  Rational(int n, int d) : n(n), d(d) { reduce(); } // sets up n/d, reduced
  Rational(int n) : n(n), d(1) {}; // sets up n/1
  Rational() : n(0), d(1) {} // sets up 0/1
  int getN() const { return n; }
  int getD() const { return d; }
  double getVal() const { return 1.0*n/d; } // returns the double value
  void set(int n, int d) { this->n = n; this->d = d; reduce(); } // sets values
  void reduce(); // TODO: implement this out-of-line below
  Rational operator +(const Rational& rhs) const; // TODO: implement this too!
private:
  int n, d;
};

// TODO: implement this
ostream& operator <<(ostream& out, const Rational& r)
{
  out << r.getN();
  if(r.getD() != 1)
  {
    out << "/" << r.getD();
  }
  return out;
}
void Rational::reduce()
{
  if(n%d == 0)
  {
    n/=d;
    d=1;
  }
  if(n < 0 && d < 0)
  {
    n*=-1;
    d*=-1;
  }
  if(n > 0 && d < 0)
  {
    n*=-1;
    d*=-1;
  }
  int gcf;
  if(n > d)
  {
    gcf = n;
  }
  else
  {
    gcf = d;
  }
  for(int i = gcf; i > 1; i--)
  {
    if((n%i == 0) && (d%i == 0))
    {
      n/=i;
      d/=i;
    }
  }
}

Rational Rational::operator +(const Rational& rhs) const
{
  int num = (n*rhs.getD()) + (rhs.getN() * d);
  int den = d * rhs.getD();
  return Rational(num,den);
}


/* Part 4 */
int main() {
  vector<int> intVec;
  intVec.push_back(2);
  intVec.push_back(4);
  intVec.push_back(4);
  intVec.push_back(-1);
  cout << intVec << endl;
  cout << endl;

  Pair<int,double> pair1 = Pair<int,double>(1,0.6);
  Pair<int,double> pair2 = Pair<int,double>(4,0.8);
  Pair<int,double> pair3;
  pair3 = pair1 + pair2;
  cout << pair3 << endl;
  cout << endl;

  Rational r1 = Rational(18,66);
  cout << r1 << endl;
  Rational r2 = Rational(3,-6);
  cout << r2 << endl;
  Rational r3 = Rational(-8,-4);
  cout << r3 << endl;
  cout << endl;

  Pair<double, Rational> pair4 = Pair<double,Rational>(2.7, Rational(3,4));
  cout << pair4 << endl;
  Pair<double, Rational> pair5 = Pair<double,Rational>(8.4, r1);
  cout << pair5 << endl;
  vector<Pair<double,Rational>> v;
  v.push_back(pair4);
  v.push_back(pair5);
  cout << v;

  return 0;
}
