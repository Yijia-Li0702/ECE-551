#include "circle.hpp"
//#include "point.hpp"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <cstdio>

void Circle::move(double dx, double dy){
  center.move(dx,dy);
}
double Circle::intersectionArea(const Circle & otherCircle){
  double dis = center.distanceFrom(otherCircle.center);
  double r1 = radius;
  double r2 = otherCircle.radius;
  if(dis > r1+r2){
    return 0;
  }
  double a = abs(r1-r2);
  if(dis <= a){
    double r_m;
    if(r1>r2){
      r_m = r2;
    }else{
      r_m = r1;
    }
    double res = M_PI * r_m*r_m;
    return res;
  }
  double angle1 = acos((r1*r1-r2*r2+dis*dis)/(2*dis*r1));
  double angle2 = acos((r2*r2-r1*r1+dis*dis)/(2*dis*r2));
  double s = angle1*r1*r1+angle2*r2*r2-dis*r1*sin(angle1);
  return s;
}

