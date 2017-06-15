#ifndef COMPER_HPP
#define COMPER_HPP
#include <vector>
#include <string>
#include <sstream>

using std::vector;
using std::string;

namespace comper  // COMmon PERsonal functions
{
  // pythonic split() function
  vector<string> split(const string& s, char delim);
}
#endif  // COMPER_HPP
