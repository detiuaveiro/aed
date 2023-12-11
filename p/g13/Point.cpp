//
// Algoritmos e Estruturas de Dados - 2023/2024
//
// J. Madeira - April/May 2022
//

#include "Point.h"

#include <cmath>
#include <iostream>

Point::Point(void) : x_(0.0), y_(0.0) {}
Point::Point(double x, double y) : x_(x), y_(y) {}

double Point::GetX(void) const { return x_; }
void Point::SetX(double x) { x_ = x; }
double Point::GetY(void) const { return y_; }
void Point::SetY(double y) { y_ = y; }

double Point::DistanceTo(const Point& p) const {
  double delta_x = p.GetX() - x_;
  double delta_y = p.GetY() - y_;

  return std::sqrt(delta_x * delta_x + delta_y * delta_y);
}

std::ostream& operator<<(std::ostream& os, const Point& obj) {
  os << "(" << obj.x_ << "," << obj.y_ << ")";
  return os;
}

std::istream& operator>>(std::istream& is, Point& obj) {
  std::cout << "x = ";
  is >> obj.x_;
  std::cout << "y = ";
  is >> obj.y_;
  return is;
}
