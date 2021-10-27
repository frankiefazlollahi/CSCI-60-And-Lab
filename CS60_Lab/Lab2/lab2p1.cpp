#include <iostream>
using namespace std;

class ModInt{
public:
  int getNum(){return num;}
  int getMod(){return mod;}
  ModInt();
  ModInt(int n, int m);
  void operator +=(ModInt rhs);

private:
  int num;
  int mod;
};
bool operator ==(ModInt lhs, ModInt rhs){
  if(lhs.getNum() == rhs.getNum() && lhs.getMod() == rhs.getMod())
  {
    return true;
  }
  else
    return false;
}

ModInt operator +(ModInt lhs, ModInt rhs)
{
  if(lhs.getMod() == rhs.getMod())
  {
    return ModInt((lhs.getNum() + rhs.getNum()) % lhs.getMod(), lhs.getMod());
  }
  else
  {
    return ModInt();
  }
}

int main()
{
  ModInt test(3,10);
  ModInt test2 (9,10);
  ModInt newModInt = test + test2;
  cout << (test == test2) << endl;
  test += test2;
  cout << test.getNum() << " " << test.getMod() << endl;
  cout << newModInt.getNum() << " " << newModInt.getMod();

  return 0;
}

ModInt:: ModInt()
  {
    num = 0;
    mod = 1;
  }
ModInt::ModInt(int n, int m){
    num = n;
    mod = m;
  }
void ModInt :: operator +=(ModInt rhs){
    if(mod == rhs.getMod())
    {
      num += rhs.getNum();
      num = num % mod;
    }
    else{
      num = -1;
      mod = -1;
    }
  }
