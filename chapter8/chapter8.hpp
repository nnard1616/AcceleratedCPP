#ifndef CHAPTER8_HPP
#define CHAPTER8_HPP
#include <map>
#include <iostream>
#include <istream>
#include <fstream>
#include <iterator>
#include "../comper/comper.hpp"

using std::map;
using std::istream;

namespace chapter8
{
  typedef vector<string> Rule;
  typedef vector<Rule> Rule_collection;
  typedef map<string, Rule_collection> Grammar;

  Grammar read_grammar(istream& in);

  void gen_sentence(const Grammar& g, std::ostream_iterator<string> os);

  void gen_aux(const Grammar& g, string word, std::ostream_iterator<string> os);

  vector<string> gen_sentence(const Grammar& g);
  vector<string> gen_aux(const Grammar& g,
                         const string& word,
                         vector<string>& ret);
  void xref(void);
}
#endif  // CHAPTER8_HPP
