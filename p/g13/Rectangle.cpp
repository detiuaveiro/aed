//
// Algoritmos e Estruturas de Dados - 2023/2024
//
// J. Madeira - April/May 2022
//

#include "Rectangle.h"

#include <cassert>
#include <iostream>
#include <string>

#include "Point.h"

Rectangle::Rectangle(void)
    : Figure(Point(0.0, 0.0), "black"), height_(1.0), width_(1.0) {}

Rectangle::Rectangle(Point center, const std::string& color, double width,
                     double height)
    : Figure(center, color), height_(height), width_(width) {
  assert(width_ > 0.0 && height_ > 0.0);
}

Rectangle::Rectangle(double x, double y, const std::string& color, double width,
                     double height)
    : Figure(x, y, color), height_(height), width_(width) {
  assert(width_ > 0.0 && height_ > 0.0);
}

double Rectangle::GetHeight(void) const { return height_; }
void Rectangle::SetHeight(double length) {
  assert(length > 0.0);
  height_ = length;
}

double Rectangle::GetWidth(void) const { return width_; }
void Rectangle::SetWidth(double length) {
  assert(length > 0.0);
  width_ = length;
}

std::string Rectangle::GetClassName(void) const { return "Rectangle"; }
double Rectangle::Area(void) const { return width_ * height_; }
double Rectangle::Perimeter(void) const { return 2.0 * width_ + 2.0 * height_; }

std::ostream& operator<<(std::ostream& os, const Rectangle& obj) {
  os << "Center: " << obj.GetCenter() << std::endl;
  os << "Color: " << obj.GetColor() << std::endl;
  os << "Width = " << obj.width_ << std::endl;
  os << "Height = " << obj.height_ << std::endl;
  return os;
}

std::istream& operator>>(std::istream& is, Rectangle& obj) {
  Point c;
  std::cout << "Center: ";
  is >> c;
  obj.SetCenter(c);

  std::string s;
  std::cout << "Color: ";
  is >> s;
  obj.SetColor(s);

  std::cout << "Width: ";
  is >> obj.width_;

  std::cout << "Height: ";
  is >> obj.height_;

  return is;
}
