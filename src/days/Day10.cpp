#include "Day10.hpp"

void Day10() {
  std::ifstream input;
  input.open("/home/baley/Projects/Advent-of-Code-2023-new/src/days/Day10i3.txt");
  

  std::vector<std::vector<char>> Data;

  int idx = 0;

  while(input) {
    std::string line;
    std::getline(input,line);
    std::cout << line << std::endl;

    Data.push_back(std::vector<char>{});
    for(auto c : line) {
      Data[idx].push_back(c);
    }
    idx++;
  }
  std::pair<int,int> Start;
  for(int i = 0; i < Data.size(); i++) {
    for(int j = 0; j < Data[i].size(); j++) {
      std::cout << Data[i][j];
      if(Data[i][j] == 'S') {
	Start = std::pair<int,int>{i,j};
      }
    }
    std::cout << "" << std::endl;
  }
  enum Direction {
    up,down,left,right
  };

  std::vector<std::tuple<int,int,char>> PipeLocations;
  Direction D;
  std::pair<int,int> Location = Start;
  int Steps = 0;
  do {
    char PipeType = Data[Location.first][Location.second];
    PipeLocations.push_back(std::tuple<int,int,char>{Location.second,Data.size()-Location.first,PipeType});
    //std::cout << "x: " << Location.second << " y: " << Data.size()-Location.first << std::endl;
    switch (PipeType) {
    case 'S':
      {
	char LEFT = '.';
	char RIGHT = '.';
	char UP = '.';
	char DOWN = '.';
	// Replace S with the required piece

	if (Location.second > 0) {
	  LEFT = Data[Location.first][Location.second - 1];
	}

	if (Location.second + 1 < Data[0].size()-1) {
	  RIGHT = Data[Location.first][Location.second + 1];
	}

	if (Location.first > 0) {
	  UP = Data[Location.first - 1][Location.second];
	}

	if (Location.first + 1 < Data[0].size()-1) {
	  DOWN = Data[Location.first + 1][Location.second];
	}
	std::cout << LEFT << std::endl;
	std::cout << DOWN << std::endl;
	std::cout << UP << std::endl;
	std::cout << RIGHT << std::endl; 
	//std::cout <<  Data[Location.first][Location.second-1] << std::endl;
	// std::cout <<  Data[Location.first][Location.second+1] << std::endl;
	// std::cout <<  Data[Location.first-1][Location.second] << std::endl;
	// std::cout <<  Data[Location.first+1][Location.second] << std::endl;
	
	
	// |
	if(UP == '|' || UP == 'F' || UP == '7' ){
	  if(DOWN == '|' || DOWN == 'J' || DOWN == 'L') {
	    Location.first += 1;
	    D = down;
	  }
	}
	// -
	if(LEFT == '-' || LEFT == 'F' || LEFT == 'L' ){
	  if(RIGHT == '-' || RIGHT == 'J' || RIGHT == '7') {
	    Location.second += 1;
	    D = right;
	  }
	}
	// J
	if(LEFT == '-' || LEFT == 'F' || LEFT == 'L' ){
	  if(UP == '|' || UP == 'F' || UP == '7') {
	    Location.first -= 1;
	    D = up;
	  }
	}
	// L
	if(RIGHT == '-' || RIGHT == 'J' || RIGHT  == '7' ){
	  if(UP == '|' || UP == 'F' || UP == '7') {
	    Location.second += 1;
	    D = right;
	  }
	}
	// 7
	if(LEFT == '-' || LEFT == 'F' || LEFT == 'L' ){
	  if(DOWN == '|' || DOWN == 'J' || DOWN == 'L') {
	    Location.first += 1;
	    D = down;
	  }
	}
	// F
	if(RIGHT == '-' || RIGHT == 'J' || RIGHT == '7' ) {
	  if(DOWN == '|' || DOWN == 'J' || DOWN == 'L') {
	    Location.second += 1;
	    D = right;
	  }
	}
	goto EXIT1;
      }
    case '|':
      {
	if(D == down) {
	  Location.first += 1;
	} else if(D == up ) {
	  Location.first -= 1;
	}
	goto EXIT1;
      }
    case '-':
      {
	if(D == right) {
	  Location.second += 1;
	} else if(D == left) {
	  Location.second -= 1;
	}
	goto EXIT1;
      }
    case 'F':
      {
	if(D == left) {
	  Location.first += 1;
	  D = down;
	} else if(D == up) {
	  Location.second += 1;
	  D = right;
	}
	goto EXIT1;
      }
    case '7':
      {
	if(D == right) {
	  Location.first += 1;
	  D = down;
	} else if(D == up) {
	  Location.second -= 1;
	  D = left;
	}
	goto EXIT1;
      }
    case 'J':
      {
	if(D == right) {
	  Location.first -= 1;
	  D = up;
	} else if(D == down) {
	  Location.second -= 1;
	  D = left;
	}
	goto EXIT1;
      }
    case 'L':
      {
	if(D == left) {
	  Location.first -= 1;
	  D = up;
	} else if(D == down) {
	  Location.second += 1;
	  D = right;
	}
	goto EXIT1;
      }
    default:
      {
	std::cout << PipeType << std::endl;    
	std::cout << "UNREACHABLE 2" << std::endl;
	Location = Start;      
      }
    }
  EXIT1:

    // if(Steps > 1000) {
    //   std::cout << "REACHED LIMIT" << std::endl;
    //   Location = Start;
    // }

    Steps++;
    
  } while(Location != Start);
  std::cout<< Steps/2 << std::endl;  
  //Part 2
  //each time we cross a pipe we enter/exit the centre. Example
  // Here is a line of some loop:
  // ...|000|....|00|....
  //    I   O    I  O    | I = in , O = out 
  // if there are three in a row, we cannot do this and must add some edge case.
  // .L-J...
  //  IOI   | Here the ... would be counted as in      
  // To counteract this problem we will condense all the pipes into one:
  // .I... | this will work with any ammount of pipes and we dont have to worry about it disconntecting above and bellow, beacause we dont need to.
  std::vector<std::vector<char>> Map;
  int maxX = Data[0].size()+1;
  int maxY = Data.size()+1;

  std::cout << maxX << " " << maxY << std::endl;
  for(int y = 0; y < maxY; y++) {
    Map.push_back(std::vector<char> {});
    for(int x = 0; x < maxX; x++) {
      Map[y].push_back('.');
      for(auto p : PipeLocations) {
	if(std::get<0>(p) == x && std::get<1>(p) == y) {
	  Map[y][x] = std::get<2>(p);
	}
      }
    }
  }
  std::cout << "" << std::endl;
  for(int i = 0; i < maxY; i++) {
    for(int x = 0; x < maxX; x++) {
      int y = maxY-i-1;
      std::cout << Map[y][x];
    }
    std::cout << "" << std::endl;
  }
  
  
  /*
    std::vector<std::vector<int>> Map;
  int maxX = 0;
  int maxY = 0;
  for(int i = 0; i < PipeLocations.size(); i++) {
    if(maxX < PipeLocations[i].first) {
      maxX = PipeLocations[i].first;
    }
    if(maxY < PipeLocations[i].second) {
      maxY = PipeLocations[i].second;
    }
  }
  maxX += 20;
  maxY += 20;
  for(int x = 0; x < maxX; x++) {
    Map.push_back(std::vector<int> {});
    for(int y = 0; y < maxY; y++) {
      Map[x].push_back(0);
    }
  }

  for(auto l : PipeLocations) {
    Map[l.second-1][l.first-1] = 1;
  }

  int InsideAns = 0;
  bool Inside = false;
  std::vector<std::string> MapString;
  for(auto vec : Map) {  
    std::string str;
    for (int num : vec) {
        str += std::to_string(num);
    }
    MapString.push_back(str);
  }
  std::cout << InsideAns << std::endl;
  for(auto str : MapString) {
    std::cout << str << std::endl;
    
    std::stringstream ss(str);
    std::string token;
    
    int L = 0;
    while(std::getline(ss, token, '1')) {
      if(token[0] == '0') {
	std::cout << token << "   L: " << L + 1 << std::endl;
	L++;
      }
      if(L % 2 == 0) {
	InsideAns += token.size();
      }
    }
  }
  
  std::cout << "Ans: " << InsideAns << std::endl;
*/
  
}
