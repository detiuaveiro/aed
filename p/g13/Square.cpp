//
// Algoritmos e Estruturas de Dados - 2023/2024
//
// J. Madeira - April/May 2022
//

#include "Square.h"

#include <cassert>
#include <iostream>
#include <string>

#include "Point.h"
#include "Rectangle.h"

Square::Square(void) : Rectangle() {}

Square::Square(Point center, const std::string& color, double length)
    : Rectangle(center, color, length, length) {}

Square::Square(double x, double y, const std::string& color, double length)
    : Rectangle(x, y, color, length, length) {}

std::string Square::GetClassName(void) const { return "Square"; }

double Square::GetEdgeLength(void) const { return GetWidth(); }
void Square::SetEdgeLength(double length) {
  assert(length > 0.0);
  SetWidth(length);
  SetHeight(length);
}

std::ostream& operator<<(std::ostream& os, const Square& obj) {
  os << "Center: " << obj.GetCenter() << std::endl;
  os << "Color: " << obj.GetColor() << std::endl;
  os << "Edge length = " << obj.GetEdgeLength() << std::endl;
  return os;
}

std::istream& operator>>(std::istream& is, Square& obj) {
  Point c;
  std::cout << "Center: ";
  is >> c;
  obj.SetCenter(c);

  std::string s;
  std::cout << "Color: ";
  is >> s;
  obj.SetColor(s);

  double d;
  std::cout << "Edge length: ";
  is >> d;
  obj.SetEdgeLength(d);

  return is;
}
