#include "chapter10.hpp"

namespace chapter10
{
  namespace container
  {
    sc_iter::sc_iter(string_container* node)
    {
      current_node = node;  // current_node is a pointer to a string_container
    }

    string& sc_iter::operator*() const { return current_node->s; }
    sc_iter& sc_iter::operator++()
    {
      current_node = current_node->cnext;
      return *this;
    }

    sc_iter sc_iter::operator++(int)
    {
      sc_iter tmp = *this;
      current_node = current_node->cnext;
      return tmp;
    }

    sc_iter& sc_iter::operator--()
    {
      current_node = current_node->cprev;
      return *this;
    }

    sc_iter sc_iter::operator--(int)
    {
      sc_iter tmp = *this;
      current_node = current_node->cprev;
      return tmp;
    }

    bool sc_iter::operator==(const sc_iter& rhs)
    {
      return this->current_node == rhs.current_node;
    }
    bool sc_iter::operator!=(const sc_iter& rhs)
    {
      return this->current_node != rhs.current_node;
    }
  }

  /*-------------------------------------------------------------------------------*/
  string_list::string_list(std::istream& ins)
  {
    string s;
    container::string_container* prev;
    length = 0;
    while (std::getline(ins, s, ' '))
    {
      container::string_container* curr = new container::string_container(s);
      if (length > 0)  // list is already being made
      {
        prev->cnext = curr;
        curr->cprev = prev;
        last = curr;
      }
      else  // just now starting to create the list
        first = curr;
      prev = curr;
      ++length;
    }

    // the following make a string_container with " " as contents, who is after
    // last container, and before the first container, making string_list a
    // circular list
    container::string_container* curr = new container::string_container(" ");
    prev->cnext = curr;
    curr->cprev = prev;
    curr->cnext = first;
    first->cprev = curr;
  }

  container::sc_iter string_list::begin() const
  {
    return container::sc_iter(first);
  }

  container::sc_iter string_list::end() const
  {
    return ++(container::sc_iter(last));
  }
  unsigned int string_list::size() { return length; }
  void string_list::print_strings()
  {
    for (container::string_container* scp = first; scp != nullptr;
         scp = scp->cnext)
      cout << scp->s << endl;
  }

  string& string_list::operator[](int x)
  {
    container::sc_iter start = this->begin();
    while (x > 0)
    {
      start++;
      --x;
    }
    return *start;
  }
}
