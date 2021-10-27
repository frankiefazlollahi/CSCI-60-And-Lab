#include "dynamicset.h"
#include <iostream>
#include <cstdlib>

using namespace std;
//prints set using overloaded <<
void printSet(const DynamicSet& s);
//if the set contains target, prints that it does
//if it does not, it prints an error saying that the set does not have that target value
void testContains(const DynamicSet& s, int target);
//shows the set before anything is done to it, and after it has had a number inserted to it
//only makes change if the target does not already exist in the set
void testInsert(DynamicSet& s, int target);
//shows the set before anything is done to it, and after a number from it was removed
void testRemove(DynamicSet& s, int target);


int main()
{
  DynamicSet a;
  for(int i = 1; i <= 5; i++)
  {
    a.insert(i);
  }
  cout << "Set A: ";
  printSet(a);
  cout << endl;
  testContains(a, 4);
  cout << endl;
  testContains(a, 6);
  cout << endl;
  cout << "Inserting 6" << endl;
  testInsert(a, 6);
  cout << endl;
  cout<< "Trying to insert 2 when the set already contains a 2" << endl;
  testInsert(a,2);
  cout << endl;
  cout << "Removing 1" << endl;
  testRemove(a, 1);
  cout << endl;
  cout << "Removing 9" << endl;
  testRemove(a,9);

  DynamicSet b;
  for(int i = 7; i <= 9; i++)
  {
    b.insert(i);
  }

  //Testing += Operator
  cout << endl;
  cout << "Set A: ";
  printSet(a);
  cout << endl;
  cout << "Set B: ";
  printSet(b);
  cout << endl;
  cout << "SetA += SetB" << endl;
  a+=b;
  cout << "SetA: ";
  printSet(a);
  cout << endl;
  cout << endl;

  //Testing *= Operator
  DynamicSet c;
  c = a;
  cout << "Set C: ";
  printSet(c);
  cout << endl;
  cout << "Set B: ";
  printSet(b);
  cout << endl;
  cout << "SetC *= SetB" << endl;
  c*=b;
  cout << "SetC: ";
  printSet(c);
  cout << endl;
  cout << endl;

  //Testing -= Operator
  DynamicSet d;
  d = a;
  cout << "Set D: ";
  printSet(d);
  cout << endl;
  cout << "Set B: ";
  printSet(b);
  cout << endl;
  cout << "SetD -= SetB" << endl;
  d-=b;
  cout << "SetD: ";
  printSet(d);
  cout << endl;
  cout << endl;



  //Testing + Operator
  DynamicSet e;
  for(int i = 1; i <= 3; i++)
  {
    e.insert(i);
  }
  DynamicSet f;
  for(int i = 4; i <= 6; i++)
  {
    f.insert(i);
  }
  DynamicSet g = e + f;
  cout <<"SetE: ";
  printSet(e);
  cout << endl;
  cout << "SetF: ";
  printSet(f);
  cout << endl;
  cout << "SetG = SetE + SetF" << endl;
  cout <<"SetG: ";
  printSet(g);
  cout << endl;
  cout << endl;

  //Testing * Operator
  DynamicSet h;
  for(int i = 1; i <= 9; i++)
  {
    h.insert(i);
  }
  DynamicSet i;
  i.insert(2);
  i.insert(7);
  i.insert(5);
  DynamicSet j = h * i;
  cout <<"SetH: ";
  printSet(h);
  cout << endl;
  cout << "SetI: ";
  printSet(i);
  cout << endl;
  cout << "SetJ = SetH * SetI" << endl;
  cout << "SetJ: ";
  printSet(j);
  cout << endl;
  cout << endl;

  DynamicSet k;
  for(int i = 1; i <= 9; i++)
  {
    k.insert(i);
  }
  DynamicSet l;
  for(int i = 2; i <= 9; i+=2)
  {
    l.insert(i);
  }
  //Testing - Operator
  DynamicSet m = k - l;
  cout <<"SetK: ";
  printSet(k);
  cout << endl;
  cout << "SetL: ";
  printSet(l);
  cout << endl;
  cout << "SetM = SetK - SetL" << endl;
  cout << "SetM: ";
  printSet(m);
  cout << endl;
  cout << endl;


  return 0;
}
void printSet(const DynamicSet& s)
{
  cout << s;
}
void testContains(const DynamicSet& s, int target)
{
  if(s.contains(target) == true)
  {
    cout << "The set contains " << target << endl;
  }
  else
  {
    cout << "ERROR: The set does not contain " << target << endl;
  }

}

void testInsert(DynamicSet& s, int target)
{
  cout << "Before Insert: ";
  printSet(s);
  cout << endl;
  s.insert(target);
  cout << "After Insert: ";
  printSet(s);
  cout << endl;
}

void testRemove(DynamicSet& s, int target)
{
  cout << "Before Remove: ";
  printSet(s);
  cout << endl;
  if(s.remove(target) == true)
  {
    cout << "After Remove: ";
    printSet(s);
    cout << endl;
  }
  else
  {
    cout <<"ERROR: The set does not contain " << target << endl;
  }
}
