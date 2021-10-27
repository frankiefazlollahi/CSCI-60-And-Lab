#include "dynamicset.h"

DynamicSet::DynamicSet(){
  data_ = nullptr;
  capacity_ = 0;
  used_ = 0;
}

DynamicSet::DynamicSet(const DynamicSet& s)
{
  if (s.capacity_>0)
  {
    data_ = new int[s.capacity_];
    for (size_t i=0; i<s.used_; i++)
    {
      data_[i] = s.data_[i];
    }
  }
  else
  {
    data_ = nullptr;
  }
  capacity_ = s.capacity_;
  used_ = s.used_;
}

DynamicSet::~DynamicSet()
{
  delete [] data_;
  data_ = nullptr;
}

bool DynamicSet::contains(int target) const
{
  for(int i = 0; i < used_; i++)
  {
    if(data_[i] == target)
    {
      return true;
    }
  }
  return false;
}

void DynamicSet::insert(int target)
{
  if(contains(target) == false)
  {
    if(capacity_ == 0)
    {
      capacity_ = 1;
      data_ = new int[capacity_];
    }
    else if(capacity_ == used_)
    {
      capacity_ = capacity_ * 2;
      int *temp = new int[capacity_];
      for(int i = 0; i < used_; i++)
      {
        temp[i] = data_[i];
      }
      delete [] data_;
      data_ = temp;
    }
    data_[used_] = target;
    used_++;
  }
}

bool DynamicSet::remove(int target)
{
  size_t i = 0;
  while(i < used_ && data_[i] != target)
  {
    i++;
  }
  if(i == used_)
  {
    return false;
  }
  for(i++; i < used_; i++)
  {
    data_[i-1] = data_[i];
  }
  used_--;
  return true;
}

void DynamicSet::operator =(const DynamicSet & s2)
{
  used_ = s2.used_;
  if(capacity_ != s2.capacity_)
  {
    capacity_ = s2.capacity_;
    delete [] data_;
    data_ = new int[capacity_];
  }
  for(int i = 0; i < used_; i++)
  {
    data_[i] = s2.data_[i];
  }
}

void DynamicSet::operator +=(const DynamicSet & s2)
{
  for(int i = 0; i < s2.used_;i++)
  {
    insert(s2[i]);
  }
}

void DynamicSet::operator *=(const DynamicSet & s2)
{
  for(int i = 0; i < used_; i++)
  {
    if(s2.contains(data_[i]) == false)
    {
      remove(data_[i]);
      i--;
    }
  }
}

void DynamicSet::operator -=(const DynamicSet & s2)
{
  for(int i = 0; i < s2.used_; i++)
  {
    if(contains(s2.data_[i]) == true)
    {
      remove(s2.data_[i]);
      i--;
    }
  }
}

DynamicSet operator +(const DynamicSet & s1, const DynamicSet & s2)
{
  DynamicSet sum;
  sum = s1;
  sum += s2;
  return sum;
}

DynamicSet operator *(const DynamicSet & s1, const DynamicSet & s2)
{
  DynamicSet intersect;
  intersect = s1;
  intersect *= s2;
  return intersect;
}

DynamicSet operator -(const DynamicSet & ls, const DynamicSet & s2)
{
  DynamicSet difference;
  difference = ls;
  difference -= s2;
  return difference;
}

std::ostream& operator <<(std::ostream& out, const DynamicSet & s)
{
  for(int i = 0; i < s.size(); i++)
  {
    out << s[i];
  }
  return out;
}
