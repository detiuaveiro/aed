//
// Algoritmos e Estruturas de Dados - 2023/2024
//
// J. Madeira - April/May 2022
//

#include <iomanip>
#include <iostream>
#include <vector>

#include "Circle.h"
#include "Figure.h"
#include "Rectangle.h"
#include "Square.h"

int main(void) {
  Square square_1;
  std::cout << square_1;
  std::cout << std::endl;

  Rectangle rect_1;
  std::cout << rect_1;
  std::cout << std::endl;

  Circle circle_1;
  std::cout << circle_1;
  std::cout << std::endl;

  Circle circle_2(0.0, 0.0, "yellow", 2.0);
  std::cout << circle_2;
  std::cout << std::endl;

  std::cout << "The yellow circle intersects the black circle?" << std::endl;
  std::cout << std::boolalpha << circle_1.Intersects(circle_2) << std::endl;
  std::cout << std::endl;

  Circle circle_3(1.0, 0.0, "red", 1.0);
  std::cout << circle_3;
  std::cout << std::endl;

  std::cout << "The red circle intersects the black circle?" << std::endl;
  std::cout << std::boolalpha << circle_1.Intersects(circle_3) << std::endl;

  std::vector<Figure*> figures;
  figures.push_back(&square_1);
  figures.push_back(&rect_1);
  figures.push_back(&circle_1);
  figures.push_back(&circle_2);
  figures.push_back(&circle_3);

  std::cout << std::endl;
  for (auto ptr : figures) {
    std::cout << ptr->GetClassName() << " - Area = " << ptr->Area()
              << " - Perimeter = " << ptr->Perimeter() << std::endl;
  }

  return 0;
}