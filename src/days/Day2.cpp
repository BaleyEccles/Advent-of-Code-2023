
#include "Day2.hpp"

void Day2(){
    Day2Pt1();
    //Day2Pt2();
}

struct game{
  int ID;
  std::vector<int> Red;
  std::vector<int> Blue;
  std::vector<int> Green;
};
void Day2Pt1()
{
  std::ifstream input;
  input.open("C:/Users/yoobl/Videos/stuff/code/AOC2023/src/days/Day2/input.txt");
  std::vector<game> GamesVec;
  while(input){
    game Game;
    std::string line;
    std::getline(input, line);
    std::vector<std::string> Data;
    for(int i = 0; i < line.size(); i++){
      if(line[i] == ':')
	{
	  std::string N{line[i-1]};
	  if(isdigit(line[i-2])){
	      std::cout << line[i-2] << std::endl;
	      N.push_back(line[i-2]);
	    }
	  if(isdigit(line[i-3])){
	    //std::cout << line[i-3] << std::endl;
	      N.push_back(line[i-3]);
	    }
	  std::string N1 = "";
	  for(int i = 0; i < N.size(); i++)
	    {
	      N1.push_back(N[N.size()-i - 1]);
	    }
  	  Game.ID = stoi(N1);
	  //std::cout << Game.ID << std::endl;
	}
      if(line[i] == ':' || line[i] == ';')
	{
	  std::string str;
	  int j = i+1;
	  while(line[j] != ';' && j != line.size()-1)
	    {
	      //std::cout << line[j];
	      str.push_back(line[j]);
	      j++;
	    }
	  //std::cout << str << std::endl;
	  Data.push_back(str);
	}
    }
    for(int i = 0; i < Data.size(); i++) {
      std::cout << Data[i] << std::endl;
      // Get Red Green Blue Numbers
      Game.Red.push_back(GetNumber("red", Data[i]));
      Game.Green.push_back(GetNumber("green", Data[i])); 
      Game.Blue.push_back(GetNumber("blue", Data[i]));
   }
    GamesVec.push_back(Game);
  }
  int IDSum = 0;
  int maxR = 12;
  int maxG = 13;
  int maxB = 14;
  for(int i = 0; i < GamesVec.size() - 1; i++)
    {
      int R = 0;
      int G = 0;
      int B = 0;
      for(int r = 0; r < GamesVec[i].Red.size(); r++)
	{
	  if(GamesVec[i].Red[r] > R)
	    {
	      R = GamesVec[i].Red[r];
	    }
	}
      for(int g = 0; g < GamesVec[i].Green.size(); g++)
	{
	  if(GamesVec[i].Green[g] > G)
	    {
	      G = GamesVec[i].Green[g];
	    }
	}
      for(int b = 0; b < GamesVec[i].Blue.size(); b++)
	{
	  if(GamesVec[i].Blue[b] > B)
	    {
	      B = GamesVec[i].Blue[b];
	    }
	}
      //std::cout << "R " << R << " G " << G << " B " << B << std::endl;
      
      if(R > 12 || G > 13 || B > 14)
	{
	  //std::cout << "Impossible: " << GamesVec[i].ID << std::endl;
	  //IDSum += GamesVec[i].ID;
	}
      else
	{
	//std::cout << GamesVec[i].ID << std::endl;
	IDSum += GamesVec[i].ID;
	}
    }
  //std::cout << IDSum << std::endl;

  //PT 2
  int PowerSum = 0;
  for(int i = 0; i < GamesVec.size(); i++)
    {
      int R = 0;
      int G = 0;
      int B = 0;
      for(int r = 0; r < GamesVec[i].Red.size(); r++)
	{
	  if(GamesVec[i].Red[r] > R)
	    {
	      R = GamesVec[i].Red[r];
	    }
	}
      for(int g = 0; g < GamesVec[i].Green.size(); g++)
	{
	  if(GamesVec[i].Green[g] > G)
	    {
	      G = GamesVec[i].Green[g];
	    }
	}
      for(int b = 0; b < GamesVec[i].Blue.size(); b++)
	{
	  if(GamesVec[i].Blue[b] > B)
	    {
	      B = GamesVec[i].Blue[b];
	    }
	}
      //P=RGB
      PowerSum += R*G*B;
    }
  std::cout << PowerSum << std::endl;
}


int GetNumber(std::string Col, std::string Str)
{
  std::string Number = "";
  for(int i = 0; i < Str.size(); i++) {
    //std::cout << "i: "  << i << " str[i]: " << Str[i] << std::endl;
    if(Str.substr(i,Col.size()) == Col){
      int j = 0;
      //std::cout << "Found Col" << std::endl;
      while(isdigit(Str[i-2-j])){
	//std::cout << "j: " << j << std::endl;
	Number.insert(0,1,Str[i-2-j]);
	j++;
      }
    }
  }
  if(Number == "")
    {
      //std::cout << "Number: 0" << std::endl;
      return 0;
    } else {
    //std::cout << "Number: " << Number << std::endl;
    return stoi(Number);
  }
}


void Day2Pt2()
{
  
}
