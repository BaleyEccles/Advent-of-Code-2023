#include "Day9.hpp"
#define Part2
void CalcDerivatives(std::vector<std::vector<int>> &Vec)
{
  bool GoAgain = false;

  Vec.push_back(std::vector<int>{});
  for(int i = 0; i < Vec[Vec.size()-2].size()-1; i++) {
    int val = Vec[Vec.size()-2][i+1] - Vec[Vec.size()-2][i];
    Vec[Vec.size()-1].push_back(val);
    if(val != 0) { GoAgain = true; }
  }
  if(GoAgain){
    CalcDerivatives(Vec);
  }
}

void Day9() {
  // I have seen this exact math concept in a Mathologer video: https://www.youtube.com/watch?v=4AuV93LOPcEy
  // I am not going to rewatch it and try to derive everything my self.

  // The basic concept is predicting the following data using their rate of change. Even though this is using discrete data we can extend it to continuous data. This will allow us to use calculus easier.
  // Given all the data colapses to 0 with enough itterations we can model this using a polynomial of degree n, where n is the number of times we have to itterate to get 0.
  /*
    0   3   6   9  12  15
      3   3   3   3   3
        0   0   0   0
  */
  // This can be interpated as points at (0,0),(1,3),(2,6),(3,9),(4,12) and (5,15). Given the second derivative is all zeros then we know that the function will be a linear one of the form f(x)=ax+c. We can see the second derivative is all threes => f(x)=3x+c, it passes through (0,0) therefore c = 0 => f(x)=3x and f(6)=3*6=18
  // We can generalize this by saying
  /*                        x-1  x   x+1
    f(x)=1   3   6  10  15  21   28 36
       f'(x)=2   3   4   5   6   7  8
          f''(x)=1   1   1   1   1  1
             f'''(x)=0   0   0   0  0
  =>
    f'''(x+1)=0
    f''(x+1) =f'''(x+1)+f''(x)
    f'(x+1)  =f''(x+1)+f'(x)
    f(x+1)   =f'(x+1)+f(x)
  =>
    f(x+1)=f''(x+1)+f'(x)+f(x)
    =>f(x+1)=f'''(x+1)+f''(x)+f'(x)+f(x)
    =>f(x+1)=f''(x)+f'(x)+f(x)
    therefore in general
    f(x+1)= sum(0,N)(f(N)(x)), where N is the number of derivatives required to get 0
  */
  std::ifstream input;
  input.open("/home/baley/Projects/Advent-of-Code-2023-new/src/days/Day9i2.txt");
  std::vector<std::vector<int>> Data;

  int idx = 0;  
  while(input) {
    std::string line;
    std::getline(input,line);
    //std::cout << line << std::endl;

    std::istringstream iss(line);
    Data.push_back(std::vector<int>{});
    int i;
    while (iss >> i) {
      Data[idx].push_back(i);
      //std::cout << i << std::endl;
    }
    idx += 1;
  }
  Data.pop_back();
  // for(auto vec : Data) {
  //   for(auto i : vec) {
  //     std::cout << i << " ";
  //   }
  //   std::cout << "" << std::endl;
  // }

  //Calculate derivatives
  //std::cout << Data.size() << std::endl;
  std::vector<std::vector<std::vector<int>>> DataAndDerivatives;
  for(auto vec : Data) {
    std::vector<std::vector<int>> DirVec;
    DirVec.push_back(vec);
    CalcDerivatives(DirVec);
    DataAndDerivatives.push_back(DirVec);
  }
#ifdef Part2
  //
  /*      x-1  x  x+1
      f(x)=5  10  13  16  21  30  45
     f'(x)=5   3   3   5   9  15
   f''(x)=-2   0   2   4   6
   f'''(x)=2   2   2   2
           0   0   0
  =>
    f''''(x-1)=0
    f'''(x-1)=f'''(x)-f''''(x-1)
    f''(x-1)=f''(x)-f'''(x-1)
    f'(x-1)=f'(x)-f''(x-1)
    f(x-1)=f(x)-f'(x-1)
    => f(x-1)=f(x)-f'(x)+f''(x-1)
    => f(x-1)=f(x)-f'(x)+f''(x)-f'''(x)+0
    In general f(x-1) = sum(0,N)f(N)(x)(-1)^N
    So basically we need to add/subtract the last element rather then add the last.
  */
  int ans = 0;
  for(auto I : DataAndDerivatives) {
    int next = 0;
    int N = 0;
    for(auto J : I) {
      next += pow(-1,N)*J[0];
      N++;
    }
    ans += next;
  }
  std::cout << ans << std::endl;
#else
  // Sum the last elements to get the next value
  int ans = 0;
  for(auto I : DataAndDerivatives) {
    int next = 0;
    for(auto J : I) {
      next += J[J.size()-1];
    }
    ans += next;
  }
  std::cout << ans << std::endl;
#endif

  //Now that I have finnished I am going to re watch the video.
  
}
