#include "vector.hpp"

#include <cmath>
#include <cstdio>

/* write your class implementation in this file
 */
void Vector2D::initVector(double init_x, double init_y){
  x = init_x;
  y = init_y;
}
double Vector2D::getMagnitude() const{
  double ans =std::sqrt(x*x+y*y);
  return ans;
}
Vector2D Vector2D::operator+(const Vector2D & rhs) const{
  Vector2D vec;
  vec.x = x + rhs.x;
  vec.y = y + rhs.y;
  return vec;
}
Vector2D & Vector2D::operator+=(const Vector2D & rhs){
  x = x + rhs.x;
  y = y + rhs.y;
  return *this;
}
double Vector2D::dot(const Vector2D & rhs) const{
  double ans = rhs.x*x + rhs.y*y;
  return ans;
}
void Vector2D::print() const{
  std::printf("<%.2f, %.2f>", x,y);
}
