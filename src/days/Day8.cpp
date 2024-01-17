#include "Day8.hpp"
#define Part2

// Function to calculate the greatest common divisor (GCD) using Euclidean algorithm
long long unsigned int gcd(long long unsigned int a, long long unsigned int b) {
  while (b != 0) {
    long long unsigned int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

// Function to calculate the Lowest Common Multiple (LCM) of a vector of numbers
long long unsigned int lcm(const std::vector<int>& numbers) {
    if (numbers.empty()) {
        return 1; // LCM of an empty set is 1
    }

    long long unsigned int result = numbers[0];
    for (size_t i = 1; i < numbers.size(); ++i) {
        result = (result * numbers[i]) / gcd(result, numbers[i]);
    }

    return result;
}

bool IsLastZ(std::vector<std::string> Starts) {
  for(auto str : Starts) {
    if(str[2] != 'Z') {
      //std::cout << str << std::endl;
      return false;
    }
  }
  return true;
}

void Day8()
{
  std::ifstream input;
  input.open("/home/baley/Projects/Advent-of-Code-2023-new/src/days/Day8i2.txt");

  std::vector<std::tuple<std::string, std::string, std::string>> Data;
  std::string Direction = "NULL";
    int idx = 0;  
  while(input) {
    std::string line;
    std::getline(input,line);
    //std::cout << line << std::endl;


    std::istringstream iss1(line);
    std::string Dir;
    while (iss1 >> Dir) {
      if( Direction == "NULL") {
	Direction = Dir;
	std::cout << Direction << std::endl;
      }
    }

    std::istringstream iss2(line);

    std::string i, j, k;
    while (iss2 >> i >> j >> k) {

      Data.push_back(std::tuple<std::string, std::string, std::string>{i, j, k});
      //std::cout << "i: " << std::get<0>(Data[idx]) << ", j: " << std::get<1>(Data[idx]) << ", k: " << std::get<2>(Data[idx]) << std::endl;
      idx += 1;
    }
  }
  int Steps = 0;
#ifdef Part2
  // Get all places that have a A in the last slot
  std::vector<std::string> Starts;
  for(auto tup : Data) {
    if(std::get<0>(tup)[2] == 'A') {
      Starts.push_back(std::get<0>(tup));
      std::cout << std::get<0>(tup) << std::endl;
    }
  }
  // New idea that isnt brute force:
  // There appears to be a cylce for each set, we only need to find the cycle for each pattern once and then using some maths we can calculate when they line up. There may be cases where it lands on two or more ones that end in z, if this is the case we may have to do more things, but lets assume that it isnt the case for now.
  // Example: one has a cycle of 10 and another has a cycle of 15. The lowest ammount of cycles is 30, as 3*10 = 30 = 2*15. This is the lowest common multiple.
  // Im unsure what im doing wrong im getting 142098619635685513248 from wolframalpha and 3748039082863876128 from my code, both are wrong and idk why.
  // 3748039082863876128
  // 142098619635685513248
  std::vector<int> StepsForStarts;
  for(int i = 0; i < Starts.size(); i++) {
    Steps = 0;
    idx = 0;
    std::string Location = Starts[i];
    
    while(Location[2] != 'Z') {
      idx++;
      Steps++;

      //std::cout << Location << std::endl; 
      if(idx == Direction.size()) {
	//std::cout << "Loop" << std::endl;
	idx = 0;
      }
      //std::cout << Direction[idx] << std::endl;
      if(Direction[idx] == 'R') {
	for(auto tup : Data) {
	  if(std::get<0>(tup) == Location) {
	    //std::cout << "R: " <<  std::get<2>(tup) << std::endl;
	    Location = std::get<2>(tup);
	    goto EXIT;
	  }
	}
      } else {
	for(auto tup : Data) {
	  if(std::get<0>(tup) == Location) {
	    //std::cout << "L: " <<  std::get<1>(tup) << std::endl;
	    Location = std::get<1>(tup);
	    goto EXIT;
	  }
	}
      }
    EXIT:  
    }
    StepsForStarts.push_back(Steps);
  }
  for(auto s : StepsForStarts) {
    std::cout << s << std::endl;
  }
  std::cout << lcm(StepsForStarts) << std::endl;
  
  /* bad and old code
  
  idx = -1;
  while(!IsLastZ(Starts)) { //Check if all the places have Z in their last slot
    idx++;
    Steps++;
    if(idx == Direction.size()) {
      //std::cout << "Loop" << std::endl;
      idx = 0;
    }
    // itterate through all the places once
    for(int i = 0; i < Starts.size(); i++) {
      //std::cout << Location << std::endl; 
      //std::cout << Direction[idx] << std::endl;
      if(Direction[idx] == 'R') {
	for(auto tup : Data) {
	  if(std::get<0>(tup) == Starts[i]) {
	    //std::cout << "R: " <<  std::get<2>(tup) << std::endl;
	    Starts[i]= std::get<2>(tup);
	    goto EXIT;
	  }
	}

      } else {
	for(auto tup : Data) {
	  if(std::get<0>(tup) == Starts[i]) {
	    //std::cout << "L: " <<  std::get<1>(tup) << std::endl;
	    Starts[i] = std::get<1>(tup);
	    goto EXIT;
	  }
	}
      }
    EXIT:
    }
    if(Steps % 50000 == 0) {
      std::cout << Steps << std::endl;
    }
  }
  */
#else
  std::string Location = "AAA";

  idx = -1;
  while(Location != "ZZZ") {
    idx++;
    Steps++;

    //std::cout << Location << std::endl; 
    if(idx == Direction.size()) {
      //std::cout << "Loop" << std::endl;
      idx = 0;
    }
    //std::cout << Direction[idx] << std::endl;
    if(Direction[idx] == 'R') {
      for(auto tup : Data) {
	if(std::get<0>(tup) == Location) {
	  //std::cout << "R: " <<  std::get<2>(tup) << std::endl;
	  Location = std::get<2>(tup);
	  goto EXIT;
	}
      }
    } else if(Direction[idx] == 'L') {
      for(auto tup : Data) {
	if(std::get<0>(tup) == Location) {
	  //std::cout << "L: " <<  std::get<1>(tup) << std::endl;
	  Location = std::get<1>(tup);
	  goto EXIT;
	}
      }
    }
  EXIT:  
  }
  std::cout << Steps << std::endl;
#endif

}


