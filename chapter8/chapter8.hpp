#ifndef CHAPTER8_HPP
#define CHAPTER8_HPP
#include <map>
#include <istream>
#include <fstream>
#include "../comper/comper.hpp"

using std::map;
using std::istream;

namespace chapter8
{
  typedef vector<string> Rule;
  typedef vector<Rule> Rule_collection;
  typedef map<string, Rule_collection> Grammar;

  template <typename Out>
  void gen_sentence(const Grammar& g);
  Grammar read_grammar(istream& in);

  void xref(void);
}
#endif  // CHAPTER8_HPP
