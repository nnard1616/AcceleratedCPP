#ifndef CHAPTER10_HPP
#define CHAPTER10_HPP
#include "../comper/comper.hpp"

// chapter10 namespace, for client use
namespace chapter10
{
  namespace container  // container implementation namespace, not for client use
  {
    struct string_container
    {
      string_container* cnext{nullptr};
      string_container* cprev{nullptr};
      string s{" "};  // since spaces are the delimiters for strings, will use
                      // space as end of list identifier
      string_container(string in) { s = in; }
    };

    class sc_iter  // string container iterator
    {
      string_container* current_node{nullptr};

     public:
      // Default Constructible
      sc_iter() = default;
      explicit sc_iter(string_container* node);

      // Dereferenceable
      string& operator*() const;

      // Pre- and post-incrementable
      sc_iter& operator++();
      sc_iter operator++(int);  // should this be a string_container???

      // Pre- and post-decrementable
      sc_iter& operator--();
      sc_iter operator--(int);  // should this be a string_container???

      // Equality / inequality
      bool operator==(const sc_iter& rhs);
      bool operator!=(const sc_iter& rhs);
    };
  }

  class string_list
  {
    container::string_container* first;
    container::string_container* last;
    unsigned int length;

   public:
    container::sc_iter begin() const;
    container::sc_iter end() const;

    string_list(std::istream& ins);
    unsigned int size();
    void print_strings();

    string& operator[](int x);
  };
}

#endif  // CHAPTER10_HPP
