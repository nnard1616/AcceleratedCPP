#ifndef COMPER_HPP
#define COMPER_HPP
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <iostream>
#include <istream>
#include <fstream>
#include <iterator>

using std::vector;
using std::string;
using std::cout;
using std::endl;

namespace comper  // COMmon PERsonal functions
{
  // pythonic split() function
  vector<string> split(const string& s, char delim);
  int nrand(int n);
}
#endif  // COMPER_HPP
