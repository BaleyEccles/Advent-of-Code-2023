#include "days/Day1.hpp"
#include "days/Day2.hpp"
#include "days/Day3.hpp"
#include "days/Day4.hpp"
#include "days/Day5.hpp"
#include "days/Day6.hpp"
#include "days/Day7.hpp"
#include "days/Day8.hpp"
#include "days/Day9.hpp"
#include "days/Day10.hpp"
#include "days/Day11.hpp"
#include "days/Day12.hpp"
#include "days/Day13.hpp"


#include <ostream>
#include <iostream>

int main()
{
  std::ifstream File;
  File.open("/home/baley/Projects/OpenGL/OpenGL2/Shaders/VertexShader.txt");

  while(File) {
    std::string line;
    std::getline(File,line);
    std::cout << line << std::endl;
  }
   
  File.close();

  
  //Day12();
  std::cout << "Done" << std::endl;
  //while(true){};
}
