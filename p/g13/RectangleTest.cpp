//
// Algoritmos e Estruturas de Dados - 2023/2024
//
// J. Madeira - May 2022
//

#include <iostream>

#include "Point.h"
#include "Rectangle.h"

int main(void) {
  Rectangle r1;
  std::cout << r1 << std::endl;

  Rectangle r2(0.0, 0.0, "yellow", 2, 5);
  std::cout << r2 << std::endl;

  Rectangle r3(1.0, 0.0, "red", 10, 50);
  std::cout << r3 << std::endl;

  Point p1(2, 2);
  Rectangle r4(p1, "blue", 4, 10), r5;
  std::cout << "Insert Rectangle Info:" << std::endl;
  std::cin >> r5;
  std::cout << std::endl;

  std::cout << "r4: " << r4 << std::endl << "r5: " << r5 << std::endl;
  std::cout << "Area: r4 = " << r4.Area() << "; r5 = " << r5.Area()
            << std::endl;
  std::cout << "Perimeter: r4 = " << r4.Perimeter()
            << "; r5 = " << r5.Perimeter() << std::endl;
  std::cout << std::endl;

  Rectangle r6(r2);
  Rectangle r7 = r6;
  std::cout << "r6: " << r6 << std::endl << "r7: " << r7 << std::endl;

  return 0;
}