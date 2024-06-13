#include "commands.hpp"

#include <algorithm>
#include <numeric>
#include <iterator>
#include <limits>
#include <cmath>

#include "baseForCommands.hpp"

void rebdev::areaEven(const polyVec & p, std::ostream & out)
{
  double area = rebdev_private::areaIf(p,
    [](const Polygon & polygon)
    {
      return ((polygon.points.size() % 2) != 0);
    });

  out << "AREA EVEN\n";
  out << area << '\n';
}
void rebdev::areaOdd(const polyVec & p, std::ostream & out)
{
  double area = rebdev_private::areaIf(p,
    [](const Polygon & polygon)
    {
      return ((polygon.points.size() % 2) == 0);
    });

  out << "AREA ODD\n";
  out << area << '\n';
}
void rebdev::areaMean(const polyVec & p, std::ostream & out)
{
  double area = 0;
  area = std::accumulate(p.begin(), p.end(), area, rebdev_private::getArea);

  out << "AREA MEAN\n";
  out << (area / p.size()) << '\n';
}
void rebdev::areaNum(size_t s, const polyVec & p, std::ostream & out)
{
  double area = rebdev_private::areaIf(p,
    [&](const Polygon & polygon)
    {
      return (polygon.points.size() != s);
    });

  out << "AREA " << s << '\n';
  out << area << '\n';
}
void rebdev::maxArea(const polyVec & p, std::ostream & out)
{
  std::vector< double > areaVec(p.size());
  rebdev_private::fillAreaVec(p, areaVec);
  out << "MAX AREA\n";
  out << *std::max_element(areaVec.begin(), areaVec.end()) << '\n';
}
void rebdev::maxVertexes(const polyVec & p, std::ostream & out)
{
  std::vector< size_t > vertVec(p.size());
  rebdev_private::fillVertVec(p, vertVec);
  out << "MAX VERTEXES\n";
  out <<  *std::max_element(vertVec.begin(), vertVec.end()) << '\n';
}
void rebdev::minArea(const polyVec & p, std::ostream & out)
{
  std::vector< double > areaVec(p.size());
  rebdev_private::fillAreaVec(p, areaVec);
  out << "MIN AREA\n";
  out << *std::min_element(areaVec.begin(), areaVec.end()) << '\n';
}
void rebdev::minVertexes(const polyVec & p, std::ostream & out)
{
  std::vector< size_t > vertVec(p.size());
  rebdev_private::fillVertVec(p, vertVec);
  out << "MIN VERTEXES\n";
  out << *std::min_element(vertVec.begin(), vertVec.end()) << '\n';
}
void rebdev::countEven(const polyVec & p, std::ostream & out)
{
  size_t NumOfCountEven = std::count_if(p.begin(), p.end(),
    [](const Polygon & polygon)
    {
      return ((polygon.points.size() % 2) == 0);
    });
  out << "COUNT EVEN\n";
  out << NumOfCountEven << '\n';
}
void rebdev::countOdd(const polyVec & p, std::ostream & out)
{
  size_t NumOfCountOdd = std::count_if(p.begin(), p.end(),
    [](const Polygon & polygon)
    {
      return ((polygon.points.size() % 2) != 0);
    });
  out << "COUNT ODD\n";
  out << NumOfCountOdd << '\n';
}
void rebdev::countNum(size_t s, const polyVec & p, std::ostream & out)
{
  size_t NumOfCountNum = std::count_if(p.begin(), p.end(),
    [&](const Polygon & polygon)
    {
      return (polygon.points.size() == s);
    });

  out << "COUNT " << s << '\n';
  out << NumOfCountNum << '\n';
}
void rebdev::rects(const polyVec & p, std::ostream & out)
{
  size_t rectsNum = std::count_if(p.begin(), p.end(),
    [&](const Polygon & polygon)
    {
      if (polygon.points.size() != 4)
      {
        return false;
      }
      double firstDiagonal = rebdev_private::distanceBetweenPoints(polygon.points[0], polygon.points[2]);
      double secondDiagonal = rebdev_private::distanceBetweenPoints(polygon.points[1], polygon.points[3]);
      return (firstDiagonal == secondDiagonal);
    });

  out << "RECTS \n";
  out << rectsNum << '\n';
}
void rebdev::inframe(const polyVec & p, std::istream & in, std::ostream & out)
{
}
