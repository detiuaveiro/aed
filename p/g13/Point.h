//
// Algoritmos e Estruturas de Dados - 2023/2024
//
// J. Madeira - April/May 2022
//

#ifndef POINT_H_
#define POINT_H_

#include <iostream>

class Point {
 public:
  Point(void);
  Point(double x, double y);

  double GetX(void) const;
  void SetX(double x);
  double GetY(void) const;
  void SetY(double y);

  double DistanceTo(const Point& p) const;

  friend std::ostream& operator<<(std::ostream& os, const Point& obj);
  friend std::istream& operator>>(std::istream& is, Point& obj);

 private:
  double x_;
  double y_;
};

#endif  // POINT_H_
