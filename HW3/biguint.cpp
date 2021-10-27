//Name: Frankie Fazlollahi
//Lab Partner: Matthew McClune
#include "biguint.h"

biguint::biguint()
{
  for(size_t i = 0; i < CAPACITY; i++)
  {
    data_[i] = 0;
  }
}

biguint::biguint(const std::string& num)
{
  int index = 0;
  char zero = '0';
  for(size_t i = num.size() - 1; i > 0; i--)
  {
    data_[index] = num[i] - zero;
    index++;
  }
  data_[index] = num[0] - zero;
  index++;
  for(size_t j = index; j < CAPACITY; j++)
  {
    data_[j] = 0;
  }
}

unsigned short biguint::operator [](std::size_t pos) const
{
  if(pos < CAPACITY)
  {
   return data_[pos];
  }
   //if the pos is over the capacity, it returns 0
  else
  {
    return 0;
  }
}

std::ostream& operator <<(std::ostream& out, const biguint& b)
{
  for(int i = biguint::CAPACITY-1; i >= 0; --i)
  {
    out << b[i];
  }
  return out;
}

void biguint::operator += (const biguint & b)
{
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

biguint operator +(const biguint& lhs, const biguint& rhs)
{
  biguint sum;
  sum += lhs;
  sum += rhs;
  return sum;
}

int biguint::compare(const biguint& b) const
{
  int result = 0;
  //if lhs > rhs return 1
  for(int i = CAPACITY-1; i >= 0; i--)
  {
    if(data_[i] > b[i])
    {
      result = 1;
    }
  }
  //if lhs < rhs return 2
  for(int i = CAPACITY-1; i >= 0; i--)
  {
    if(data_[i] < b[i])
    {
      result = 2;
    }
  }
  //if lhs is neither > or < rhs then they are equal
  //returns 0 if they are equal
  return result;
}

bool operator < (const biguint& lhs, const biguint& rhs)
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
bool operator <= (const biguint& lhs, const biguint& rhs)
{
  if(lhs.compare(rhs) == 2 || lhs.compare(rhs) == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}
bool operator != (const biguint& lhs, const biguint& rhs)
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
bool operator == (const biguint& lhs, const biguint& rhs)
{
  if(lhs.compare(rhs) == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}
bool operator >= (const biguint& lhs, const biguint& rhs)
{
  if(lhs.compare(rhs) == 1 || lhs.compare(rhs) == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}
bool operator > (const biguint& lhs, const biguint& rhs)
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

void biguint::operator -= (const biguint & b)
{
  int temp;
  for(int i = 0; i < CAPACITY; i++)
  {
    temp = data_[i];
    if(temp -= b[i] < 0)
    {
      data_[i] += 10;
      data_[i] -= b[i];
      data_[i]--;
    }
    else
    {
      data_[i] -= b[i];
    }
  }
}

biguint operator -(const biguint& lhs, const biguint& rhs)
{
  biguint difference;
  difference += lhs;
  difference -= rhs;
  return difference;
}

std::string biguint::toString() const
{
  //CAPACITY + 1 to include null value
  char cString[CAPACITY+1];
  int x = 0;
  for(int i = CAPACITY-1; i >= 0; --i)
  {
    cString[x] = '0' + data_[i];
    x++;
  }
  return cString;
}
