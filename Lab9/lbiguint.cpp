#include "lbiguint.h"

#include <cassert>
#include "node.h"
#include <sstream>

 lbiguint::lbiguint(){

     head = tail = new node (0, nullptr);
 }
 lbiguint::lbiguint (const std::string & s)
 {

     if (s.size() == 0)
         return;



     head = new node (s[0] - '0', nullptr);
     tail = head;
     for (int i = 1; i < s.size(); i++)
     {
         assert(isdigit(s[i]));
         head = new node(s[i] - '0', head);

     }
 }
//how to delete all stuff from a linked list
  lbiguint::~lbiguint()
 {
   if(head != nullptr)
   {
     node *p = head;
     while (p!=nullptr)
     {
       node* temp = p;
       p = p->link();
       delete temp;
     }
     head = nullptr;
     tail = nullptr;
   }
 }


 std::size_t lbiguint::operator [](std::size_t pos) const
 {
   std::size_t counter = 0;
    for(node * p = head; p != nullptr; p = p->link())
    {
      if(counter == pos)
      {
        return p->data();
      }
      counter ++;
    }
    return 0;
 }


/*
 int lbiguint::compare(const lbiguint & b) const{
     for(std::size_t i =CAPACITY-1; i>=0; --i){
         if(_data[i]>b._data[i])
             return 1;
         else if (_data[i]<b._data[i])
             return -1;

     }
     return 0;
 }



 void lbiguint::operator += (const lbiguint & b){
     int carry = 0;
     int next = 0;
     for(std::size_t i=0; i<CAPACITY; ++i){
         next = carry+_data[i]+b._data[i];
         _data[i]=next%10;
        carry=next/10;
     }
 }
 std::string lbiguint::toStdString() const
 {
     std::stringstream ss;
     ss << *this;
     return ss.str();
 }//We haven't talked about stringstreams; just ignore this, I was being lazy.
 */
 std::ostream & operator << (std::ostream & os, const lbiguint & b)
 {

     for (std::size_t i = b.size(); i  > 0; i--)
         os << b[i];
    os<<b[0];
     return os;
 }

 std::size_t lbiguint::size() const
 {
   std::size_t counter = 0;
    for(node * p = head; p != nullptr; p = p->link())
    {

      counter ++;
    }
    return counter;
 }
/*
 std::istream & operator >> (std::istream & is, lbiguint & b)
 {
     std::string s;
     is >> s;
     b = lbiguint(s);
     return is;


 }

 bool operator <(const lbiguint& a, const lbiguint& b){
     return (a.compare(b)==-1);
 }

 bool operator <= (const lbiguint & b1, const lbiguint & b2)
 {
     return (b1.compare(b2) <= 0);
 }

 bool operator == (const lbiguint & b1, const lbiguint & b2)
 {
     return (b1.compare(b2) == 0);
 }

 bool operator != (const lbiguint & b1, const lbiguint & b2)
 {
     return (b1.compare(b2) != 0);
 }
*/
//You do > and >=
