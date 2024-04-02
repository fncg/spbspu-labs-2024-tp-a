#include "DataStruct.hpp"
#include <bitset>
#include <algorithm>
#include "Delimiter.hpp"
#include "ScopeGuard.hpp"

std::string getBinNumber(unsigned long long value)
{
  std::string bin;

  do
  {
    bin.push_back('0' + (value & 1));
  }
  while (value >>= 1);

  std::reverse(bin.begin(), bin.end());
  return bin;
}

bool artemev::DataStruct::operator<(const DataStruct& other) const
{
  if (key1 != other.key1)
  {
    return key1 < other.key1;
  }

  else if (key2 != other.key2)
  {
    return key2 < other.key2;
  }

  return (key3.length() <= other.key3.length());
}

std::istream& artemev::operator>>(std::istream& in, DataStruct& value)
{
  std::istream::sentry sentry(in);
  if (!sentry)
  {
    return in;
  }

  ScopeGuard scopeGuard(in);

  using delChar = DelimiterCharI;
  using delString = DelimiterStringI;

  const size_t KEY_NUMBER = 3;
  size_t keyI = 0;

  in >> delChar{ '(' };

  for (size_t i = 0; i < KEY_NUMBER; ++i)
  {
    in >> delString{ ":key" } >> keyI;
    switch (keyI)
    {
      case 1:
      {
        in >> value.key1 >> delChar{ 'd' };
        break;
      }
      case 2:
      {
        std::bitset< 64 > bin;
        in >> delString{ "0b" } >> bin;
        if (in)
        {
          value.key2 = bin.to_ullong();
        }
        break;
      }
      case 3:
      {
        in >> delChar{ '"' };
        std::getline(in, value.key3, '"');
        break;
      }
      default:
      {
        in.setstate(std::ios::failbit);
      }
    }
  }

  in >> delString{ ":)" };
  return in;
}
