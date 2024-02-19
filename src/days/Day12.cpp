#include "Day12.hpp"

void Day12() {
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
  /*
  for(auto d : SpringsStr) {
    for(auto i : d) {
      std::cout << i << " ";
    }
    std::cout << "p" << std::endl;
  }  
  for(auto d : Data) {
    for(auto i : d) {
      std::cout << i << " ";
    }
    std::cout << " #p" << std::endl;
  }

  Plan:
  calculate all the possible configs given the numbers and size
  Then removed all the configs that dont match the given data.
  
  ?###???????? 3,2,1
  We would get all the configs of size 12 that have 3,2,1
  .###.##.#...
  .###.##..#..
  .###.##...#.
  .###.##....#
  .###..##.#..
  .###..##..#.
  .###..##...#
  .###...##.#.
  .###...##..#
  .###....##.#

  ..###.##.#..
  ..###.##..#.
  ..###.##...#
  ..###..##.#.
  ..###..##..#
  ..###...##.#

  ...###.##.#.
  ...###.##..#
  ...###..##.#

  ....###.##.#
  The last three set of configs dont sattisfy the given data, so we can remove them.
  
  */
  
  enum Types {
    dot, hash, q
  };
  
  std::vector<std::vector<Types>> SpringsInt;
  for(int i = 0; i < SpringsStr.size(); i++) {
    SpringsInt.push_back(std::vector<Types>{});
    for(int j = 0; j < SpringsStr[i].size(); j++) {
      if(SpringsStr[i][j] == '.') {
	SpringsInt[i].push_back(dot);
      } else if(SpringsStr[i][j] == '#') {
	SpringsInt[i].push_back(hash);
      } else if(SpringsStr[i][j] == '?') {
	SpringsInt[i].push_back(q);
      }
    }
  }
  struct Token {
    Types LeadingType;
    int LeadingAmmount;
    Types TrailingType;
    int TrailingAmmount;
    Types Type;
  };
  std::vector<std::vector<Token>> SpringsToken;
  
  
}
