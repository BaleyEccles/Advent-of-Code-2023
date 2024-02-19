#include "Day13.hpp"

void Day13() {
  std::ifstream input;
  input.open("/home/baley/Projects/Advent-of-Code-2023-new/src/days/Day12i1.txt");
  std::vector<std::string> SpringsStr;
  std::vector<std::vector<int>> Data;

  int idx = 0;
  while(input) {
    std::string line;
    std::getline(input,line);
    std::cout << line << std::endl;

    std::istringstream iss(line);

    std::string str1;
    std::string str2;

    while (iss >> str1 >> str2) {
      SpringsStr.push_back(str1);

      //std::cout << str1 << " " << str2 << std::endl;
      Data.push_back(std::vector<int>{});
      std::stringstream ss(str2);
      std::string token;
      while(std::getline(ss, token, ',')) {
	Data[idx].push_back(std::stoi(token));
      }
      idx++;
    }

  }
}
