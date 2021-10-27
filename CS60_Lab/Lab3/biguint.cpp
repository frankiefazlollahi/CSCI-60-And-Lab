//Name: Frankie Fazlollahi
//Lab Partner: Mathew McClune
#include "ddbiguint.h"

dbiguint::dbiguint(){
  capacity_ = 1;
  data_ = new unsigned short[1];
  data_[0] = 0;
}

dbiguint::dbiguint(const std::string& num)
{
  capacity_ = num.size();
  data_ = new unsigned short[capacity_];
  int x = 0;
  char zero = '0';
  for(size_t i = capacity_ - 1; i > 0; i--)
  {
    data_[x] = num[i] - zero;
    x++;
  }
  data_[x] = num[0] - zero;
  x++;
}
/*
unsigned short dbiguint::operator [](std::size_t pos) const{
  if(pos < CAPACITY)
   return data_[pos];
  else
    return 0;
}

std::ostream& operator <<(std::ostream& out, const dbiguint& b)
{

  for(int i = dbiguint::CAPACITY-1; i >= 0; --i)
  {
    out << b[i];
  }

  return out;
}

void dbiguint::operator += (const dbiguint & b){
    for(int i = 0; i < CAPACITY; i++)
    {
      data_[i] += b[i];
      if(data_[i] > 9)
      {
        data_[i] -= 10;
        data_[i+1]++;
      }
    }
}

dbiguint operator +(const dbiguint& lhs, const dbiguint& rhs)
{
  dbiguint sum;
  sum += lhs;
  sum+= rhs;
  return sum;
}

int dbiguint::compare(const dbiguint& b) const{
  //if lhs > rhs return 1
    for(int i = CAPACITY-1; i >= 0; --i)
    {
      if(data_[i] > b[i])
      {
        return 1;
      }
    }
    //if lhs < rhs return 2
    for(int i = CAPACITY-1; i >= 0; --i)
    {
      if(data_[i] < b[i])
      {
        return 2;
      }
    }
    //if lhs is neither > or < rhs then they are equal
    //returns 3 if they are equal
    return 3;
}

bool operator < (const dbiguint& lhs, const dbiguint& rhs)
{
  if(lhs.compare(rhs) == 2)
  {
    return true;
  }
  else
  {
    return false;
  }
}
bool operator <= (const dbiguint& lhs, const dbiguint& rhs)
{
  if(lhs.compare(rhs) == 2 || lhs.compare(rhs) == 4)
  {
    return true;
  }
  else
  {
    return false;
  }
}
bool operator != (const dbiguint& lhs, const dbiguint& rhs)
{
  if(lhs.compare(rhs) == 1 || lhs.compare(rhs) == 2)
  {
    return true;
  }
  else
  {
    return false;
  }
}
bool operator == (const dbiguint& lhs, const dbiguint& rhs)
{
  if(lhs.compare(rhs) == 3)
  {
    return true;
  }
  else
  {
    return false;
  }
}
bool operator >= (const dbiguint& lhs, const dbiguint& rhs)
{
  if(lhs.compare(rhs) == 1 || lhs.compare(rhs) == 3)
  {
    return true;
  }
  else
  {
    return false;
  }
}
bool operator > (const dbiguint& lhs, const dbiguint& rhs)
{
  if(lhs.compare(rhs) == 1)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void dbiguint::operator -= (const dbiguint & b)
{
  for(int i = 0; i < CAPACITY; i++)
  {
    int temp = data_[i];
    if(temp -= b[i] < 0)
    {
      data_[i]+= 10;
      data_[i+1]--;
      data_[i] -= b[i];
    }
    else
    {
      data_[i] -= b[i];
    }
  }
}

std::string dbiguint::toString() const
{
  char cString[CAPACITY + 1];
  int x = 0;
  for(int i = CAPACITY-1; i >= 0; --i)
  {
    cString[x] = (char)data_[i];
  }
  std::string newString = (string)cString;
  return newString;
}
*/
