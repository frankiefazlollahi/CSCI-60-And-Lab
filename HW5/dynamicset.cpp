// HW5 Q1 starter implementation file for DynamicSet
// Frankie Fazlollahi

#include "dynamicset.h"

DynamicSet::DynamicSet() : DynamicBag(){}

DynamicSet::DynamicSet(const DynamicBag& b) : DynamicBag(b){}

bool DynamicSet::contains(int target) const
{
  if(DynamicBag::count(target) > 0)
  {
    return true;
  }
  return false;
}

void DynamicSet::remove(int target)
{
  DynamicBag::erase_one(target);
}

void DynamicSet::insert(int target)
{
  if(!contains(target))
  {
    DynamicBag::insert(target);
  }
}
