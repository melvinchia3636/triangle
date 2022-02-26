#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void printTriangle(std::vector<std::vector<char> > triangle) {
  for (int i = 0; i < triangle.size(); i++) {
    for (int j = 0; j < triangle[i].size(); j++) {
      std::cout << triangle[i][j];
    }
    std::cout << std::endl;
  }
}

std::vector<std::vector<char> > singleCharTriangle(int level, int direction) {
  /**
   * Single Character Traingle
   *
   * Returns a triangle formed by the hash (*) character.
   * The triangle can be either equiliteral or right-angled
   * depending on the direction argument
   * 
   * @param level number of levels of the result triangle
   * @param direction 0 for right-angled triangle, 1 for equiliteral triangle and 2 for reversed right-angled triangle
   * @return a vector containing the triangle character
  */

  std::vector<std::vector<char> > triangle;
  for (int i = 0; i < level; i++) {
    std::vector<char> currentLevel;
    if (direction != 1) {
      for (int j = 0; j < i+1; j++) {
        currentLevel.push_back('*');
      }
      for (int j = 0; j < level - i+1; j++) {
        currentLevel.push_back(' ');
      }
      if (direction == 2) std::reverse(currentLevel.begin(), currentLevel.end());
      triangle.push_back(currentLevel);
    } else {
      for (int j = 0; j < level - i; j++) {
        currentLevel.push_back(' ');
      }
      for (int j = 0; j < i * 2 + 1; j++) {
        currentLevel.push_back('*');
      }
      for (int j = 0; j < level - i; j++) {
        currentLevel.push_back(' ');
      }
      triangle.push_back(currentLevel);
    }
  }
  return triangle;
}

int main() {
  std::vector<std::vector<char> > rightAngledTriangle = singleCharTriangle(10, 0);
  std::vector<std::vector<char> > equiliteralTriangle = singleCharTriangle(10, 1);
  std::vector<std::vector<char> > reversedRightAngledTriangle = singleCharTriangle(10, 2);

  std::cout << "Right angled triangle:" << std::endl;
  printTriangle(rightAngledTriangle);

  std::cout << std::endl;

  std::cout << "Equiliteral triangle:" << std::endl;
  printTriangle(equiliteralTriangle);
  
  std::cout << std::endl;

  std::cout << "Reversed right angled triangle:" << std::endl;
  printTriangle(reversedRightAngledTriangle);

  return 0;
}