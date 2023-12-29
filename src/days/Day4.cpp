#include "Day4.hpp"
#if 0
#define WinNumSize 10
#define CNumSize 25
#else
#define WinNumSize 5
#define CNumSize 8
#endif
void Day4(){
  Day4Pt1();
}

struct Cards {
  int GameNum;
  std::vector<int> WinNum;
  std::vector<int> PlyNum;
};

void Day4Pt1(){
  std::ifstream input;
  input.open("/home/baley/Projects/Advent-of-Code-2023/src/days/Day4input.txt");
  std::vector<Cards> CardVec;
  while(input)
    {
      std::string line;
      std::getline(input, line);
      std::cout << line << std::endl;
      if(line.size() > 0)
	{
	  //format line
	  line.push_back('C');
	  auto it = std::find(line.begin(),line.end(), ':');
	  int dist = std::distance(line.begin(), it);
	  for(int i = 0; i < dist; i++)
	    {
	      line[i] = 'C';
	    }
	    
	  std::vector<int> IntVec;
	  for(int i = 0; i < line.size(); i++)
	    {
	      if(line[i] != 'C')
		{
		  if(isdigit(line[i]) && isdigit(line[i+1]))
		    {
		      //converts the current and next char to num and add to vec
		      std::string str;
		      str.push_back(line[i]);
		      str.push_back(line[i+1]);
		      IntVec.push_back(std::stoi(str));
		    }
		  else if(isdigit(line[i]) && line[i-1] == ' ' && (line[i+1] == ' ' || line[i+1] == 'C'))
		    {
		      std::string str;
		      str.push_back(line[i]);
		      IntVec.push_back(std::stoi(str));
		    }
		}
	    }
	  Cards C;
	  for(int i = 0; i < WinNumSize; i++)
	    {
	      std::cout << "W: " << IntVec[i] << std::endl;
	      C.WinNum.push_back(IntVec[i]);
	    }
	  for(int i = WinNumSize; i < WinNumSize + CNumSize; i++)
	    {
	      std::cout << "P: " << IntVec[i] << std::endl;
	      C.PlyNum.push_back(IntVec[i]);
	    }
	  CardVec.push_back(C);
	}
    }
  /*Part 1
  int points = 0;
  for(int i = 0; i < CardVec.size(); i++)
    {
      std::sort(CardVec[i].WinNum.begin(), CardVec[i].WinNum.end());
      std::sort(CardVec[i].PlyNum.begin(), CardVec[i].PlyNum.end());

      std::vector<int> Overlap;

      for(int num : CardVec[i].WinNum)
	{
	if (std::binary_search(CardVec[i].PlyNum.begin(), CardVec[i].PlyNum.end(), num))
	    {
	      Overlap.push_back(num);
	      std::cout << "Point: " << num << std::endl;
	    }
	}
      if(Overlap.size() > 0)
	{
	  points += pow(2,Overlap.size()-1);
	  std::cout << points<< "  " << Overlap.size()  << std::endl;
	}
    }
  */
  //Set game nums
  for(int i = 0; i < CardVec.size(); i++)
    {
      CardVec[i].GameNum = i + 1;
    }
  std::vector<std::vector<int>> CardIndexAdd;
  for(int i = 0; i < CardVec.size(); i++)
    {
      std::sort(CardVec[i].WinNum.begin(), CardVec[i].WinNum.end());
      std::sort(CardVec[i].PlyNum.begin(), CardVec[i].PlyNum.end());

      std::vector<int> Overlap;
      int k = 0;
      for(int j = 0; j < CardVec[i].WinNum.size(); j++)
	{
	if (std::binary_search(CardVec[i].PlyNum.begin(), CardVec[i].PlyNum.end(), CardVec[i].WinNum[j]))
	    {
	      k++;
	      Overlap.push_back(CardVec[i].GameNum + k);// vector that contains the index of the extra card to add
	      //std::cout << "Point: " << num << std::endl;
	    }
	}
      CardIndexAdd.push_back(Overlap);
      Overlap.clear();
      std::cout << Overlap.size() <<std::endl;
      std::cout << "Card " << CardVec[i].GameNum;
      for(int p = 0; p < CardVec[i].WinNum.size(); p++)
	{
	  std::cout << " " << CardVec[i].WinNum[p];
	}
      std::cout << " |";
      for(int p = 0; p < CardVec[i].PlyNum.size(); p++)
	{
	  std::cout << " " << CardVec[i].PlyNum[p];
	}
      std::cout << "" << std::endl;
    }

  std::vector<int> EncIndexes(CardIndexAdd.size(),1);
  for(int i = 0; i < CardIndexAdd.size(); i++)
    {
      for(int j = 0; j < CardIndexAdd[CardIndexAdd.size() - i - 1].size(); j++)
	{
	  EncIndexes[i] += EncIndexes[CardIndexAdd[CardIndexAdd.size()-i - 1][j]];
	  std::cout << EncIndexes[CardIndexAdd[CardIndexAdd.size() - i -1][j]] << " ";

	}
      std::cout << "" << std::endl;
    }
  int ans = 0;
  for(int i = 0; i < EncIndexes.size(); i++)
    {
      std::cout << "I: " << EncIndexes[i] << std::endl;
      ans += EncIndexes[i];
    }
  std::cout << "ans: " << ans << std::endl;
  /*
  for(int i = 0; i < CardVec.size(); i++)
    {
      std::cout << "Card " << CardVec[i].GameNum;
      for(int p = 0; p < CardVec[i].WinNum.size(); p++)
	{
	  std::cout << " " << CardVec[i].WinNum[p];
	}
      std::cout << " |";
      for(int p = 0; p < CardVec[i].PlyNum.size(); p++)
	{
	  std::cout << " " << CardVec[i].PlyNum[p];
	}
      std::cout << "" << std::endl;
    }
  */
  std::cout << "Cards: " << CardVec.size() << std::endl;
}
