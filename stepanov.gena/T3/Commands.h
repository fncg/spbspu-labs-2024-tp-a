#ifndef COMMANDS_H
#define COMMANDS_H

#include <vector>
#include <ostream>
#include "DataStruct.h"


namespace stepanov
{
  void getAreaEven(const std::vector< Polygon >& polygons, std::ostream& out);
  void getAreaOdd(const std::vector< Polygon >& polygons, std::ostream& out);
  void getAreaMean(const std::vector< Polygon >& polygons, std::ostream& out);
}

#endif
