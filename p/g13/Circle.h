//
// Algoritmos e Estruturas de Dados - 2023/2024
//
// J. Madeira - April/May 2022
//

#ifndef CIRCLE_H_
#define CIRCLE_H_

#include <string>

#include "Figure.h"
#include "Point.h"

class Circle : public Figure {
 public:
  Circle(void);
  Circle(Point center, const std::string& color, double radius);
  Circle(double x, double y, const std::string& color, double radius);

  double GetRadius(void) const;
  void SetRadius(double radius);

  std::string GetClassName(void) const;
  double Area(void) const;
  double Perimeter(void) const;

  bool Intersects(const Circle& c) const;

  friend std::ostream& operator<<(std::ostream& os, const Circle& obj);
  friend std::istream& operator>>(std::istream& is, Circle& obj);

 private:
  double radius_;
};

#endif  // CIRCLE_H_
