#include <iostream>
#include "comper/comper.hpp"
#include "chapter8/chapter8.hpp"

int main()
{
  std::ifstream infile("../chapter8/sentenceRules.csv");
  string line;
  while (std::getline(infile, line))
  {
    vector<string> items = comper::split(line, ',');
    for (auto it = items.begin(); it != items.end(); ++it)
      std::cout << *it << ' ';
    std::cout << std::endl;
  }

  vector<string> lines = comper::split("asdf,asdf,asdf,qwer,fger,vsdf", ',');

  for (auto it = lines.begin(); it != lines.end(); ++it)
    std::cout << *it << ' ';
  std::cout << std::endl;
  infile.close();
  return 0;
}
