#include "comper/comper.hpp"
#include "chapter8/chapter8.hpp"

// void p8_5()
//{
//  std::ifstream infile("../chapter8/sentenceRules.csv");
//  chapter8::Grammar g = chapter8::read_grammar(infile);

//  srand(time(0));  // needed to initialize RNG

//  vector<string> sentence = chapter8::gen_sentence(g);

//  copy(sentence.begin(), sentence.end(),
//       std::ostream_iterator<string>(std::cout, " "));

//  std::cout << std::endl;

//  infile.close();
//}

void p8_5()
{
  std::ifstream infile("../chapter8/sentenceRules.csv");
  chapter8::Grammar g = chapter8::read_grammar(infile);

  srand(time(0));  // needed to initialize RNG

  std::ostream_iterator<string> os(std::cout, " ");
  chapter8::gen_sentence(g, os);
  std::cout << std::endl;

  infile.close();
}

int main()
{
  p8_5();
  return 0;
}
