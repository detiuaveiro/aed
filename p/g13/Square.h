//
// Algoritmos e Estruturas de Dados - 2023/2024
//
// J. Madeira - April/May 2022
//

#ifndef SQUARE_H_
#define SQUARE_H_

#include <iostream>
#include <string>

#include "Point.h"
#include "Rectangle.h"

class Square : public Rectangle {
 public:
  Square(void);
  Square(Point center, const std::string& color, double length);
  Square(double x, double y, const std::string& color, double length);

  double GetEdgeLength(void) const;
  void SetEdgeLength(double length);

  virtual std::string GetClassName(void) const;

  friend std::ostream& operator<<(std::ostream& os, const Square& obj);
  friend std::istream& operator>>(std::istream& is, Square& obj);
};

#endif  // SQUARE_H_
