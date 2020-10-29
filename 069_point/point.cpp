#include "point.hpp"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include <cmath>
#include <cstdio>

void Point::move(double dx, double dy){
  x = x + dx;
  y = y + dy;
}
double Point::distanceFrom(const Point & p){
  double res;
  double x_dis = p.x - x;
  double y_dis = p.y - y;
  res = std::sqrt(x_dis*x_dis + y_dis*y_dis);
  return res;
}
