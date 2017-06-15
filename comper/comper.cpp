#include "comper.hpp"

namespace comper  // COMmon PERsonal functions
{
  // Pythonic split()
  vector<string> split(const string& s, char delim)
  {
    std::stringstream ss;
    ss.str(s);

    string item;
    vector<string> items;

    while (std::getline(ss, item, delim))
      items.push_back(item);  // populate items
    return items;
  }

}  // end namespace comper
