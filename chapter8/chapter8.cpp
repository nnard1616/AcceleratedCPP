#include "chapter8.hpp"

namespace chapter8
{
  Grammar read_grammar(istream& in)
  {
    Grammar ret;
    string line;

    while (getline(in, line))
    {
      vector<string> entry = comper::split(line, ',');
      if (!entry.empty())
        ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
    }
    return ret;
  }
  // Generate Sentence using output iterators
  /*-------------------------------------------------------------------------------*/
  void gen_sentence(const Grammar& g, std::ostream_iterator<string> os)
  {
    gen_aux(g, "<sentence>", os);
  }
  void gen_aux(const Grammar& g, string word, std::ostream_iterator<string> os)
  {
    try  // Key
    {
      Rule_collection rules = g.at(word);
      int ind = rand() % rules.size();
      Rule terms = rules[ind];
      for (auto it = terms.begin(); it != terms.end(); ++it)
        gen_aux(g, *it, os);
    }
    catch (const std::out_of_range& oor)  // Not a Key
    {
      *os = word;
      os++;
    }
  }
  // Generate Sentence using vectors
  /*-------------------------------------------------------------------------------*/
  vector<string> gen_sentence(const Grammar& g)
  {
    vector<string> ret;
    gen_aux(g, "<sentence>", ret);
    return ret;
  }

  vector<string> gen_aux(const Grammar& g,
                         const string& word,
                         vector<string>& ret)
  {
    try  // Key
    {
      Rule_collection rules = g.at(word);
      int ind = rand() % rules.size();
      Rule terms = rules[ind];
      for (auto it = terms.begin(); it != terms.end(); ++it)
        gen_aux(g, *it, ret);
    }
    catch (const std::out_of_range& oor)  // Not a Key
    {
      ret.push_back(word);
    }
    return ret;
  }
}
