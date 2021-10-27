#include "node.h"

node::node(const value_type & init_data, node * init_link)
{

    _data = init_data;
    _link = init_link;
}

node::value_type node::data() const
{
    return _data;
}

node * node::link()
{
    return _link;
}

void node::set_data(const value_type & new_data)
{
    _data = new_data;
}

void node::set_link(node * new_link)
{
    _link = new_link;
}



std::size_t list_index(node *head_ptr, std::size_t target)
{
  int counter = 0;
  //const before type means u cant modify the value of the pointer
  //const after the star means u cant modify the address ur pointing to
  for(const node *p = head_ptr; p!= nullptr; p = p->link())
  {
    if(p->data() == target)
    {
      return counter;
    }
    counter++;
  }
  return -1;
}

node* list_at(node *head_ptr, std::size_t n)
{
  int counter = 0;
  for(const node *p = head_ptr; p!= nullptr; p = p->link())
  {
    if(counter == n)
    {
      return p;
    }
    counter++;
  }
  return nullptr;
}




/*
 *
const node * node::link() const
{
    return _link;
}
*/
