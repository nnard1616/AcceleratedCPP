#include "comper/comper.hpp"
#include "chapter8/chapter8.hpp"
#include "chapter10/chapter10.hpp"

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
  chapter10::string_list lis(std::cin);
  cout << lis.size() << endl;
  //  cout << lis.start->next_string()->contents() << endl;
  lis.print_strings();
  return 0;
}
