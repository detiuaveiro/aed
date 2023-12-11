//
// Algoritmos e Estruturas de Dados - 2023/2024
//
// J. Madeira - May 2022
//

#include <iostream>

#include "Point.h"

int main(void) {
  // Testing class Point
  Point p1(2, 2), p2;
  std::cout << "Insert Point:" << std::endl;
  std::cin >> p2;
  std::cout << std::endl;

  std::cout << "P1: " << p1 << std::endl << "P2: " << p2 << std::endl;
  std::cout << "Distance P1<->P2: " << p1.DistanceTo(p2) << std::endl;

  Point p3(p2);
  Point p4 = p3;
  std::cout << "P3: " << p3 << std::endl << "P4: " << p4 << std::endl;

  return 0;
}