//
// Algoritmos e Estruturas de Dados - 2023/2024
//
// J. Madeira - May 2022
//

#include <iomanip>
#include <iostream>

#include "Circle.h"
#include "Point.h"

int main(void) {
  Circle circle_1;
  std::cout << circle_1 << std::endl;

  Circle circle_2(0.0, 0.0, "yellow", 2.0);
  std::cout << circle_2 << std::endl;

  std::cout << "The yellow circle intersects the black circle?" << std::endl;
  std::cout << std::boolalpha << circle_1.Intersects(circle_2) << std::endl;
  std::cout << std::endl;

  Circle circle_3(1.0, 0.0, "red", 1.0);
  std::cout << circle_3 << std::endl;

  std::cout << "The red circle intersects the black circle?" << std::endl;
  std::cout << std::boolalpha << circle_1.Intersects(circle_3) << std::endl;
  std::cout << std::endl;

  Point p1(2, 2);
  Circle circle_4(p1, "blue", 4), circle_5;
  std::cout << "Insert Circle Info:" << std::endl;
  std::cin >> circle_5;
  std::cout << std::endl;

  std::cout << "circle_4: " << circle_4 << std::endl
            << "circle_5: " << circle_5 << std::endl;
  std::cout << "Area: circle_4 = " << circle_4.Area()
            << "; circle_5 = " << circle_5.Area() << std::endl;
  std::cout << "Perimeter: circle_4 = " << circle_4.Perimeter()
            << "; circle_5 = " << circle_5.Perimeter() << std::endl;
  std::cout << "circle_4 intersects circle_5: " << std::boolalpha
            << circle_4.Intersects(circle_5) << std::endl;
  std::cout << std::endl;

  Circle circle_6(circle_2);
  Circle circle_7 = circle_6;
  std::cout << "circle_6: " << circle_6 << std::endl
            << "circle_7: " << circle_7 << std::endl;

  return 0;
}