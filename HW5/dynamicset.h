// HW5 Q1 starter header file for DynamicSet, which should inherit DynamicBag
// Frankie Fazlollahi

#ifndef DYNAMICSET_H
#define DYNAMICSET_H

#include "dynamicbag.h"

using std::size_t;

class DynamicSet : public DynamicBag
{
public:
  DynamicSet();
  DynamicSet(const DynamicBag& b);
  
  bool contains(int target) const;
  void remove(int target);
  void insert(int target);
};

#endif
