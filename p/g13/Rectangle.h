//
// Algoritmos e Estruturas de Dados - 2023/2024
//
// J. Madeira - April/May 2022
//

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include <iostream>
#include <string>

#include "Figure.h"
#include "Point.h"

class Rectangle : public Figure {
 public:
  Rectangle(void);
  Rectangle(Point center, const std::string& color, double width,
            double height);
  Rectangle(double x, double y, const std::string& color, double width,
            double height);

  double GetHeight(void) const;
  void SetHeight(double height);
  double GetWidth(void) const;
  void SetWidth(double width);

  std::string GetClassName(void) const;
  double Area(void) const;
  double Perimeter(void) const;

  friend std::ostream& operator<<(std::ostream& os, const Rectangle& obj);
  friend std::istream& operator>>(std::istream& is, Rectangle& obj);

 private:
  double height_;
  double width_;
};

#endif  // RECTANGLE_H_
