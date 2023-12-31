#include "Day3.hpp"


void Day3(){
  Day3Pt1();
  

}

void Day3Pt1()
{

  std::ifstream input;
  input.open("/home/baley/Projects/Advent-of-Code-2023/src/days/Day3input.txt");
  if(!input.good()){
    std::cout << "could not open file" << std::endl;
  }
  std::vector<std::vector<char>> Data;
  int y = 0;
  while(input)
    {
      Data.push_back(std::vector<char>{});
      std::string line;
      std::getline(input, line);
      //std::cout << line << std::endl;
      for(int x = 0; x < line.size(); x++)
	{
	  Data[y].push_back(line[x]);
	}
      y++;
    }
  int YSize = Data[0].size();
  int XSize = Data.size();
  
  std::vector<std::vector<int>> DataNum(XSize, std::vector<int>(YSize, -1));

  // Format Data
  for(int x = 0; x < Data.size(); x++)
    {
      for(int y = 0; y < Data[x].size(); y++)
	{
	  if(isdigit(Data[x][y]))
	    {
	      DataNum[x][y] = Data[x][y] - '0';
	    }
	  else {
	    if(Data[x][y] != '.')
	      {
		DataNum[x][y] = -2;
	      }
	  }
	  std::cout << DataNum[x][y];
	}
      DataNum[x].push_back(-1);
      DataNum[x].insert(DataNum[x].begin(), -1);
      std::cout << "" << std::endl;
    }
  DataNum.push_back(std::vector<int>(XSize + 1, -1));
  DataNum.insert(DataNum.begin(), std::vector<int>(XSize + 1, -1));

  for(int x = 0; x < DataNum.size(); x++)
    {
      for(int y = 0; y < DataNum[x].size(); y++)
	{
	  if(DataNum[x][y] == -1)
	    {
	      std::cout << "#";
	    }
	  else if(DataNum[x][y] == -2)
	    {
	      std::cout << "0";
	    }
	  else
	    {
	      std::cout << DataNum[x][y];
	    }
	}
      std::cout << "" << std::endl;
    }
  
  int ans = 0;
  //std::cout << "B" << std::endl;
  for(int x = 0; x < DataNum.size(); x++)
    {
      for(int y = 0; y < DataNum[x].size(); y++)
	{
	  //std::cout << y << std::endl;
	  if(DataNum[x][y] == -2)
	    {
	      //std::cout << "X: " << x << " Y: " << y << std::endl;
   	      ans += AddPartNum(x,y,DataNum);
	    }
	}
    }
  std::cout << "ans: " << ans << std::endl;
}

int AddPartNum(int x, int y, std::vector<std::vector<int>> Data)
{
  int sum = 0;
  std::vector<int> Num;
  std::vector<int> CheckedPlaces;


  if(Data[x+1][y+1] > -1 && Data[x][y+1] > -1)
    {
        GetNum(y,x,-1,-1,Data,CheckedPlaces);//Top Left
    }
  else {
      GetNum(y,x,-1,-1,Data,CheckedPlaces);//Top Left
      GetNum(y,x,-1,+1,Data,CheckedPlaces);//Top Right
  }
  
  if(Data[x+1][y-1] > -1 && Data[x][y-1] > -1)
    {
      GetNum(y,x,+1,-1,Data,CheckedPlaces);//Bottom Left
    }
  else {
      GetNum(y,x,+1,-1,Data,CheckedPlaces);//Bottom Left
      GetNum(y,x,+1,+1,Data,CheckedPlaces);//Bottom Right
  }
  //  if (Data[x+1][y+1]


  GetNum(y,x,-1,+0,Data,CheckedPlaces);//Up

  GetNum(y,x,+1,+0,Data,CheckedPlaces);//Down




  
  GetNum(y,x,+0,-1,Data,CheckedPlaces);//Left
  GetNum(y,x,+0,+1,Data,CheckedPlaces);//Right
    
  //the code removes ALL duplicates, this is bad as there may be intenional dupes.
  std::sort(CheckedPlaces.begin(), CheckedPlaces.end());
  auto last = std::unique(CheckedPlaces.begin(), CheckedPlaces.end());
  CheckedPlaces.erase(last, CheckedPlaces.end());
  for(int i = 0; i < CheckedPlaces.size(); i++)
    {
      std::cout << CheckedPlaces[i] << std::endl;;
      sum += CheckedPlaces[i];
    }
  std::cout << "S " << sum << std::endl;
  CheckedPlaces.clear();
  return sum;
}

int GetNum(int x, int y, int p1, int p2, std::vector<std::vector<int>> Data, std::vector<int>& CheckedPlaces)
{
  std::vector<int> Num;
  int p = 0;
  for(int xx = 0; xx <Data.size(); xx++)
    {
      for(int yy = 0; yy<Data[xx].size(); yy++)
	{
	  // std::cout << Data[xx][yy];
	}
      //std::cout << "" << std::endl;
    }
  if(Data[y+p1][x+p2] < 0)
    {
      return 0;
    }

  //std::cout << "x: " << x << " y: " << y << " p1: " << p1 << " p2: " << p2  << std::endl;
  while(Data[y + p1][x + p2+p] > -1){
    //std::cout << Data[y + p1][x + p2+p] << std::endl;
    //std::cout << Data[y][x] << std::endl;
    p -= 1;
    //std::cout << "p: " << p << std::endl;
  }
  //std::cout << "p: " << p << std::endl;
  int j = 0;
  //std::cout << "C" << std::endl;
  while(Data[y+ p1][x + p2+p+j+1] > -1){// some wwhere ehere
    //std::cout << "enter " << std::endl;
    //    if(std::find(CheckedPlaces.begin(), CheckedPlaces.end(), y+p+p1+j+1) == CheckedPlaces.end())
      {
	//std::cout << "D: " << Data[y+ p1][x + p2+p+j+1] << std::endl;
	Num.push_back(Data[y+ p1][x + p2+p+j+1]);
	//CheckedPlaces.push_back(x+p+p1+j+1);
      }
    //std::cout << j << std::endl;
    j++;
  }
  std::reverse(Num.begin(), Num.end());
  int N = 0;

  //std::cout << "A" <<std::endl;
  for(int i = 0; i < Num.size(); i++)
    {
      //std::cout << Num[i];
      N += Num[i]*pow(10,i);
    }
  //std::cout << N << std::endl;
  CheckedPlaces.push_back(N);
  //std::cout << N << std::endl;
  return N;
}
