//Name: Frankie Fazlollahi
//Lab Partner: Mathew McClune
#include "dbiguint.h"

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

std::size_t dbiguint::size() const
{
  return capacity_;
}

unsigned short dbiguint::operator [](std::size_t pos) const{
  if(pos < capacity_)
   return data_[pos];
  else
    return 0;
}

std::ostream & operator << (std::ostream & out, const dbiguint & b)
{

  for(int i = b.size() -1; i >= 0; --i)
  {
    out << b[i];
  }

  return out;
}

void dbiguint::reserve(std::size_t newcapacity_)
{
  if(newcapacity_ >= capacity_)
  {
    int x = 0;
    unsigned short *p;
    p = new unsigned short[newcapacity_];
    for(size_t i = 0; i < capacity_; i++)
    {
      p[i] = data_[i];
      x++;
    }
    for(int i = x; i < newcapacity_; i++)
    {
      p[i] = 0;
    }
    delete[] data_;
    capacity_ = newcapacity_;
    data_ = p;
  }
}

void dbiguint::operator +=(const dbiguint& b)
{
  if(capacity_ < b.size())
  {
    reserve(b.size());
  }
  for(int i = 0; i < capacity_; i++)
  {
    data_[i] += b[i];
    if(data_[i] > 9)
    {
      if(i+1 < capacity_)
      {
        data_[i] -= 10;
        data_[i+1]++;
      }
      else
      {
        reserve(capacity_ + 1);
        data_[i] -= 10;
        data_[i+1]++;
        //capacity_ = capacity_+ 1;
      }
    }
  }
  while(data_[0] == 0)
  {
    unsigned short *p;
    p = new unsigned short[capacity_ -1];
    for(int i = 0; i < capacity_ -1; i++)
    {
      p[i] = data_[i+1];
    }
    delete[] data_;
    capacity_ = capacity_-1;
    data_ = p;
  }
}

dbiguint::~dbiguint()
{
  delete[] data_;
  data_ = nullptr;
  capacity_ = 0;
}

void dbiguint::clean(){
  int i;
  for(i = capacity_ - 1; i >= 0; i-- )
  {
    if(data_[i] != 0)
    {
      break;
    }
  }
  unsigned short *p;
  p = new unsigned short[i+1];
  for(int j = 0; j <= i; j++)
  {
    p[j] = data_[j];
  }
  delete[] data_;
  capacity_ = i+1;
  data_ = p;

}
/*
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
