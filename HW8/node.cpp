// Implementation file for HW8
// Frankie Fazlollahi

#include "node.h"

// 2-arg node constructor
node::node(const value_type& data, node * link) : data_(data), link_(link) {}

// overloaded << for debugging
std::ostream& operator <<(std::ostream& out, const node * head) {
  for (const node* p=head; p!=nullptr; p=p->link()) {
    out << p->data() << " ";
  }
  return out;
}

// TODO: your implementations go here!

int sequence(int n)
{
  if(n <= 1)
  {
    return 1;
  }
  return (sequence(n-2) + n - 1);
 }

void list_clear(node * & head_ptr, node * & tail_ptr)
{
  if(head_ptr != nullptr)
  {
    if(head_ptr->link() == nullptr && tail_ptr->link() == nullptr)
    {
      head_ptr = nullptr;
      tail_ptr = nullptr;
      return;
    }
    node* temp = head_ptr->link();
    delete head_ptr;
    head_ptr = temp;
    list_clear(head_ptr,tail_ptr);
  }
}

void reverse(int a[], int start, int end)
{
  if(start >= end)
  {
    return;
  }
  int temp = a[start];
  a[start] = a[end];
  a[end] = temp;
  reverse(a,start + 1, end - 1);
}

void list_reverse(node*& head, node*& tail)
{
  node *previous = nullptr;
  node *next = nullptr;
  node *current = head;
  while (current->link() != nullptr)
  {
    next = current->link();
    current->set_link(previous);
    previous = current;
    current = next;
  }
  head = tail;
  head->set_link(previous);
  tail = previous->link();
}
