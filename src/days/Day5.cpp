#include "Day5.hpp"

struct Conversion {
  int DestStart;
  int SrcStart;
  int Range;
  std::vector<int> Dest;
  std::vector<int> Src;
};


std::vector<int> GetNumbers(std::string Line)
{

  std::vector<int> numbers;

  // Process the string without using streams
  size_t pos = 0;
  while (pos < Line.size()) {
    size_t spacePos = Line.find(' ', pos);
    if (spacePos == std::string::npos) {
      spacePos = Line.size();
    }
    
    std::string numStr = Line.substr(pos, spacePos - pos);
    int num = std::stoi(numStr);
    numbers.push_back(num);
    
    pos = spacePos + 1;
  }
  
  // Print the vector
  std::cout << "Vector of numbers: ";
  for (int n : numbers) {
    std::cout << n << " ";
  }
  std::cout << std::endl;
  return numbers;
}

void GetConversion(std::vector<int> &conversion, std::vector<std::vector<int>> &data)
{
  std::vector<int> tempConv = conversion;
  for(int i = 0; i < data.size(); i++)
    {
      for(int j = 0; j < tempConv.size(); j++) {
	int num = data[i][0];
	int pos = data[i][1];
	int dist = data[i][2];
	if(tempConv[j] == pos)
	  {
	    std::cout <<"pos: " <<  pos << "  num: " << num << " dist: " << dist << "  j: " << j << std::endl;
	    for(int x = 0; x < dist; x++)
	      {
		
		conversion[j + x] = num + x;// Not the index rather the location of the 'pos' number i think :)
		std::cout << "conv: " << conversion[j + x] << "  idx: " << j+x << std::endl;
	      }
	  }
      }
    }
  for(int i = 0; i < conversion.size(); i++)
    {
      
      //std::cout << "Conv: " << conversion[i+1] << " size: " << conversion.size() << std::endl; 
    }
  
}


void Day5()
{
  std::ifstream input;
  input.open("/home/baley/Projects/Advent-of-Code-2023/src/days/Day5i1.txt");
  std::vector<int> Seeds;
  std::vector<std::vector<int>> Soils;
  std::vector<std::vector<int>> Fertz;
  std::vector<std::vector<int>> Waters;
  std::vector<std::vector<int>> Lights;
  std::vector<std::vector<int>> Temps;
  std::vector<std::vector<int>> Humidities;
  std::vector<std::vector<int>> Locations;

  
  while(input)
    {
      std::string line;
      std::getline(input,line);
      //std::cout << line << std::endl;
      if(line == "seeds:")
	{
	  std::string Seedline;
	  std::getline(input, Seedline);
	  //std::cout << Seedline << std::endl;
	  while(isdigit(Seedline[0]))
	    {
	      Seeds = GetNumbers(Seedline);
	      Seedline.clear();
	      std::getline(input, Seedline);
	    }
	    
	}
      if(line == "seed-to-soil map:")
	{
	  std::string Seedline;
	  std::getline(input, Seedline);
	  //std::cout << Seedline << std::endl;
	  while(isdigit(Seedline[0]))
	    {
	      Soils.push_back(GetNumbers(Seedline));
	      Seedline.clear();
	      std::getline(input, Seedline);
	    }
	    
	}
      if(line == "soil-to-fertilizer map:")
	{
	  std::string Seedline;
	  std::getline(input, Seedline);
	  //std::cout << Seedline << std::endl;
	  while(isdigit(Seedline[0]))
	    {
	      Fertz.push_back(GetNumbers(Seedline));
	      Seedline.clear();
	      std::getline(input, Seedline);
	    }
	    
	}
      if(line == "fertilizer-to-water map:")
	{
	  std::string Seedline;
	  std::getline(input, Seedline);
	  //std::cout << Seedline << std::endl;
	  while(isdigit(Seedline[0]))
	    {
	      Waters.push_back(GetNumbers(Seedline));
	      Seedline.clear();
	      std::getline(input, Seedline);
	    }
	    
	}
      if(line == "water-to-light map:")
	{
	  std::string Seedline;
	  std::getline(input, Seedline);
	  //std::cout << Seedline << std::endl;
	  while(isdigit(Seedline[0]))
	    {
	      Lights.push_back(GetNumbers(Seedline));
	      Seedline.clear();
	      std::getline(input, Seedline);
	    }
	    
	}
      if(line == "light-to-temperature map:")
	{
	  std::string Seedline;
	  std::getline(input, Seedline);
	  //std::cout << Seedline << std::endl;
	  while(isdigit(Seedline[0]))
	    {
	      Temps.push_back(GetNumbers(Seedline));
	      Seedline.clear();
	      std::getline(input, Seedline);
	    }
	    
	}
      if(line == "temperature-to-humidity map:")
	{
	  std::string Seedline;
	  std::getline(input, Seedline);
	  //std::cout << Seedline << std::endl;
	  while(isdigit(Seedline[0]))
	    {
	      Humidities.push_back(GetNumbers(Seedline));
	      Seedline.clear();
	      std::getline(input, Seedline);
	    }
	}
      if(line == "humidity-to-location map:")
	{
	  std::string Seedline;
	  std::getline(input, Seedline);
	  //std::cout << Seedline << std::endl;
	  while(isdigit(Seedline[0]))
	    {
	      Locations.push_back(GetNumbers(Seedline));
	      Seedline.clear();
	      std::getline(input, Seedline);
	    }
	    
	}
    }
  /*
  for(int i = 0; i < Soils.size(); i++)
    {
      for(int j = 0; j < Soils[i].size(); j++)
	{
	  std::cout << Soils[i][j] << std::endl;
	}
    }
  */
  /*

  std::vector<std::vector<int>> Soils;
  std::vector<std::vector<int>> Fertz;
  std::vector<std::vector<int>> Waters;
  std::vector<std::vector<int>> Lights;
  std::vector<std::vector<int>> Temps;
  std::vector<std::vector<int>> Humidities;
  std::vector<std::vector<int>> Locations;
  */
  std::vector<int> Conv1;

  for (int i = 0; i < 100; ++i) {
    Conv1.push_back(i);
  }
  GetConversion(Conv1, Soils);
  std::vector<int> Conv2 = Conv1;
  GetConversion(Conv2, Fertz);

  std::vector<int> Conv3 = Conv2;
  GetConversion(Conv3, Waters);
  std::cout << "123213123123123123123123123123123123" << std::endl;
  std::vector<int> Conv4 = Conv3;
  GetConversion(Conv4, Lights);

  std::vector<int> Conv5 = Conv4;
  GetConversion(Conv5, Temps);

  std::vector<int> Conv6 = Conv5;
  GetConversion(Conv6, Humidities);

  std::vector<int> Conv7 = Conv6;
  GetConversion(Conv7, Locations);
  for(int i = 0; i < Conv2.size(); i++){
    std::cout << Conv2[i] << " ";
    std::cout << Conv3[i] << " ";
    std::cout << Conv4[i] << " ";
    std::cout << Conv5[i] << " ";
    std::cout << Conv6[i] << " ";
    std::cout << Conv7[i] << " " << std::endl;;

  }


  int t = Conv7[79];
  std::cout <<"S: " <<t << std::endl;
}



