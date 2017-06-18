#include "chapter10.hpp"

namespace chapter10
{
  // string_container definitions
  /*-------------------------------------------------------------------------------*/
  string_container::string_container(string in)
  {
    s = in;
    cnext = NULL;
    cprev = NULL;
  }
  void string_container::next_string(string_container* next) { cnext = next; }
  void string_container::prev_string(string_container* prev) { cprev = prev; }
  string_container* string_container::next_string() { return cnext; }
  string_container* string_container::prev_string() { return cprev; }
  string string_container::contents() { return s; }
  // string_list defintions
  /*-------------------------------------------------------------------------------*/
  string_list::string_list(std::istream& ins)
  {
    string s;
    string_container* prev;
    length = 0;
    while (std::getline(ins, s, ' '))
    {
      string_container* curr = new string_container(s);
      if (length > 0)
      {
        (*prev).next_string(curr);
        (*curr).prev_string(prev);
        end = curr;
      }
      else
        start = curr;
      prev = curr;
      ++length;
    }
  }

  unsigned int string_list::size() { return length; }
  void string_list::print_strings()
  {
    for (string_container* scp = start; scp != NULL; scp = scp->next_string())
      cout << scp->contents() << endl;
  }
  /*-------------------------------------------------------------------------------*/
  ADD::ADD(int x, int y)
  {
    gx = x;
    gy = y;
  }
  int ADD::getSum() { return gx + gy; }
}
