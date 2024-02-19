#include "Day11.hpp"

void Day11() {
  std::ifstream input;
  input.open("/home/baley/Projects/Advent-of-Code-2023-new/src/days/Day11i1.txt");
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
  // plan:
  // convert into a set of points rather than a 2d array.
  // expand the distances based on what the points say
  //.5.....
  //.##....
  //..##...
  //...##..
  //....##.
  //.....9.
  // Can be transformed into:
  //.5.....
  //.#.....
  //.#.....
  //.#.....
  //.#.....
  //.####9.
  // This works for all combinations
  // Therefore we can simply take the difference in x and y for each galaxy.
  // for the example Dx = 4 and Dy = 5


  
  struct Galaxy {
    int x,y;
    int number;
  };
  


  std::vector<Galaxy> GPoints;
  int GalaxyNum = 1;
  for(int y = 0; y < Data.size(); y++) {
    for(int x = 0; x < Data[y].size(); x++) {
      if(Data[y][x] == '#') {
	GPoints.push_back(Galaxy{x,y,GalaxyNum});
	//std::cout << GalaxyNum << std::endl;
	GalaxyNum++;
      }
    }
  }
  
  int MaxX = Data[0].size();
  int MaxY = Data.size();
  
  std::vector<bool> ExX;
  for(int i = 0; i < MaxX; i++) {
    ExX.push_back(true);
  }
  for(auto G : GPoints) {
    ExX[G.x] = false;
  }

  std::vector<bool> ExY;
  for(int i = 0; i < MaxY; i++) {
    ExY.push_back(true);
  }
  for(auto G : GPoints) {
    ExY[G.y] = false;
  }
  std::vector<int> AddY;
  std::vector<std::vector<char>> ExpandData;
  int ExtraX = 0;
  for(int y = 0; y < MaxY; y++) {
    ExpandData.push_back(std::vector<char> {});
    for(int x = 0; x < MaxX; x++) {
      bool Pdot = true;
      for(int i = 0; i < GPoints.size(); i++) {
	if(GPoints[i].x == x && GPoints[i].y == y) {
	  ExpandData[y].push_back('#');
	  std::cout << GPoints[i].number;
	  Pdot = false;
	}
      }
      if(Pdot) {
	if(ExX[x]) {
	  ExpandData[y].push_back('.');
	  std::cout << ".";
	  if(y == 0) {
	    ExtraX += 1;
	  }

	}
	ExpandData[y].push_back('.');
	std::cout << ".";
      }
    }
    if(ExY[y]) {// This is deleting the next line 
      //ExpandData.push_back(std::vector<char>(MaxX+ExtraX,'.'));
      AddY.push_back(y);
      std::cout << "" << std::endl;
      for(int i = 0; i < MaxX + ExtraX; i++) {
	//ExpandData[y+1].push_back('.');
	std::cout << ".";
      }
      //y++;
      //MaxY++;
    }
    std::cout << "" << std::endl;
  }
  for(auto e : AddY) {
    ExpandData.insert(ExpandData.begin() + e + 1, std::vector<char>(MaxX+ExtraX,'.'));
  }

  std::cout << "########" << std::endl;
  for(auto Vec : ExpandData) {
    for(auto c : Vec) {
      std::cout << c;
    }
    std::cout << "" << std::endl;
  }

  std::vector<Galaxy> EGPoints;
  int EGalaxyNum = 1;
  for(int y = 0; y < ExpandData.size(); y++) {
    for(int x = 0; x < ExpandData[y].size(); x++) {
      if(ExpandData[y][x] == '#') {
	EGPoints.push_back(Galaxy{x,y,EGalaxyNum});
	//std::cout << GalaxyNum << std::endl;
	EGalaxyNum++;
      }
    }
  }
  int EMaxX = ExpandData[0].size();
  int EMaxY = ExpandData.size();

  int ans = 0;
  for (int i = 0; i < EGPoints.size(); ++i) {
    for (int j = i + 1; j < EGPoints.size(); ++j) {
      if(EGPoints[i].number != EGPoints[j].number) {
	int Dx = abs(EGPoints[i].x-EGPoints[j].x);
	int Dy = abs(EGPoints[i].y-EGPoints[j].y);
	std::cout << "G:" << EGPoints[i].number << " P:" << EGPoints[j].number << " Dx:" << Dx<< " Dy:" << Dy << std::endl;
	ans += Dx + Dy;
	//if(G.x == P.x || G.y == P.y) {
	  //ans += 1;
	//}
      }
    }
  }
  // Im unsure why this isnt working, I assume its somthing todo with my assumtion that the differences make the shortest path, but ive tried it against all the test cases on the website and have gotten the right answer. So im going to leave it here and conclude that i tried and got close. Have an amazing day/night who ever is reading this.
  std::cout << ans << std::endl;

}
