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

  int nrand(int n)
  {
    if (n <= 0 || n > RAND_MAX)
      throw std::domain_error("Argument to nrand is out of range");

    const int bucket_size = RAND_MAX / n;
    int r;

    do
      r = rand() / bucket_size;
    while (r >= n);

    return r;
  }

}  // end namespace comper
