#ifndef CHAPTER10_HPP
#define CHAPTER10_HPP
#include "../comper/comper.hpp"
namespace chapter10
{
  class string_container
  {
    string s;
    string_container* cnext;
    string_container* cprev;

   public:
    string_container(string in);
    void next_string(string_container* next);
    void prev_string(string_container* prev);
    string_container* next_string();
    string_container* prev_string();
    string contents();
  };

  class string_list
  {
    string_container* start;
    string_container* end;
    unsigned int length;

   public:
    string_list(std::istream& ins);
    unsigned int size();
    void print_strings();
  };

  /*-------------------------------------------------------------------------------*/
  class ADD
  {
    int gx;
    int gy;

   public:
    ADD(int x, int y);
    int getSum();
  };
}
#endif  // CHAPTER10_HPP
