#include "Day7.hpp"
#define Part2
enum type {
  High = 0,
  One = 1,
  Two = 2,
  Three = 3,
  Full = 4,
  Four = 5,
  Five = 6
};


void Day7()
{
  std::ifstream input;
  input.open("/home/baley/Projects/Advent-of-Code-2023-new/src/days/Day7i2.txt");

  std::vector<std::string> Cards;
  std::vector<int> Bet;
  while(input)
    {
      std::string line;
      std::getline(input,line);
      //std::cout << line << std::endl;

      std::istringstream iss(line);
      std::string code;
      int number;

      while (iss >> code >> number) {
	//std::cout << "Cards: " << code << ", Bet: " << number << std::endl;
	Cards.push_back(code);
	Bet.push_back(number);
      }
    }
  
  //Convert cards to vector of ints
  // 2->0, 3->1, 4->2 ... 9->7 ... A->12
  std::vector<std::vector<int>> CardNum;
  for(int i = 0; i < Cards.size(); i++) {
    CardNum.push_back(std::vector<int> {});
    for(int s = 0; s < Cards[i].size(); s++) {
      if(isdigit(Cards[i][s])) {
	CardNum[i].push_back(Cards[i][s] - 2 - '0');
	}
	else {
	  if(Cards[i][s] == 'T') {
	    CardNum[i].push_back(8 + 0);
	  } else if(Cards[i][s] == 'J') {
#ifdef Part2
	    CardNum[i].push_back(-1);
#else
	    CardNum[i].push_back(8 + 1);
#endif
	  } else if(Cards[i][s] == 'Q') {
	    CardNum[i].push_back(8 + 2);
	  } else if(Cards[i][s] == 'K') {
	    CardNum[i].push_back(8 + 3);
	  } else if(Cards[i][s] == 'A') {
	    CardNum[i].push_back(8 + 4);
	  }
	}
    }
  }
  auto CardUnsorted = CardNum;
  for(int i = 0; i < CardNum.size(); i++) {
    std::sort(CardNum[i].begin(), CardNum[i].end());
    for(int j = 0; j < CardNum[i].size(); j++) {

      //std::cout << CardNum[i][j] << " ";
    }
    //std::cout << " " << std::endl;
  }
#ifdef Part2
  // Clasify the hands
  std::vector<std::vector<int>> CardClass;
  std::vector<std::vector<int>> CardAmount;

  int CardClassi = 0;
  for(auto hand : CardNum) {
    CardClass.push_back(std::vector<int> {});
    CardAmount.push_back(std::vector<int> {});
    for (auto it = hand.begin(); it != hand.end(); ++it) {
      auto duplicateEnd = std::upper_bound(it, hand.end(), *it);
      int count = std::distance(it, duplicateEnd);
      //std::cout << *it << " appears " << count << " times." << std::endl;
      CardClass[CardClassi].push_back(count);
      int Am = *it;
      CardAmount[CardClassi].push_back(Am);
      it = duplicateEnd - 1;
    }
    //std::cout << "" << std::endl;
    CardClassi++;
  }
  std::vector<std::vector<std::pair<int,int>>> CardClassAmount;
  for(int i = 0; i < CardClass.size(); i++) {
    CardClassAmount.push_back(std::vector<std::pair<int,int>>{});
    for(int j = 0; j < CardClass[i].size(); j++) {
      //std::cout << "Num: " << CardClass[i][j] << " Ammount: " << CardAmount[i][j] << std::endl;
      CardClassAmount[i].push_back(std::pair<int,int>{CardClass[i][j],CardAmount[i][j]});
    }
    //std::cout << "&&&&&&&&" << std::endl;
  }

  for(int i = 0; i < CardClassAmount.size(); i++) {
    std::sort(CardClassAmount[i].begin(), CardClassAmount[i].end());
    
    for(int j = 0; j < CardClassAmount[i].size(); j++) {
      if(CardClassAmount[i][j].second == -1) {
	if(CardClassAmount[i][CardClassAmount[i].size()-1].second == -1) {
	  std::cout <<"HI " << std::endl;
	  CardClassAmount[i][CardClassAmount[i].size()-1].first += 10;
	} else {
	  CardClassAmount[i][CardClassAmount[i].size()-1].first += CardClassAmount[i][j].first;
	  CardClassAmount[i].erase(CardClassAmount[i].begin() + j);
	}
      }
      std::cout << "Card: " << CardClassAmount[i][j].second << " Ammount: " << CardClassAmount[i][j].first << std::endl;
    }
    std::cout << "&&&&&&&&" << std::endl;
    
  }
  std::vector<std::vector<int>> CardClass2;
  
  for(int i = 0; i < CardClassAmount.size(); i++) {
    CardClass2.push_back(std::vector<int>{});
    for(int j = 0; j < CardClassAmount[i].size(); j++) {
      CardClass2[i].push_back(CardClassAmount[i][j].first);
    }
  }

  /*
    High = 0,
    One, Two, Three, Full, Four, Five  */
  int i = 0;
  std::vector<int> Types;
  for(auto vec : CardClass2) {
    std::sort(vec.begin(), vec.end());

    if(vec[0] == 5) {
      Types.push_back(Five);
    } else if(vec[vec.size()-1] == 4) {
      Types.push_back(Four);
    } else if(vec[vec.size()-1] == 3 && vec[0] == 2) {
      Types.push_back(Full);
    } else if(vec[vec.size()-1] == 3 && vec[0] == 1) {
      Types.push_back(Three);
    } else if(vec[vec.size()-1] == 2 && vec[vec.size()-2] == 2) {
      Types.push_back(Two);
    } else if(vec[vec.size()-1] == 2 && vec[vec.size()-2] == 1) {
      Types.push_back(One);
    } else if(vec[vec.size()-1] == 1) {
      Types.push_back(High);
    } else {
      for(auto V : vec) {
	std::cout << V << " ";
      }
      std::cout << "" << std::endl;
      std::cout << i << std::endl;
      std::cout << "UNREACHABLE" << std::endl;
    }
    i++;
  }
  
#else
  // Clasify the hands
  std::vector<std::vector<int>> CardClass;
  int CardClassi = 0;
  for(auto hand : CardNum) {
    CardClass.push_back(std::vector<int> {});
    for (auto it = hand.begin(); it != hand.end(); ++it) {
      auto duplicateEnd = std::upper_bound(it, hand.end(), *it);
      int count = std::distance(it, duplicateEnd);
      //std::cout << *it << " appears " << count << " times." << std::endl;
      CardClass[CardClassi].push_back(count);
      it = duplicateEnd - 1;
    }
    //d::cout << "" << std::endl;
    CardClassi++;
  }

  /*
  High = 0,
  One, Two, Three, Full, Four, Five  */
  
  std::vector<int> Types;
  for(auto vec : CardClass) {
    std::sort(vec.begin(), vec.end());

    if(vec[0] == 5) {
      Types.push_back(Five);
    } else if(vec[vec.size()-1] == 4) {
      Types.push_back(Four);
    } else if(vec[vec.size()-1] == 3 && vec[0] == 2) {
      Types.push_back(Full);
    } else if(vec[vec.size()-1] == 3 && vec[0] == 1) {
      Types.push_back(Three);
    } else if(vec[vec.size()-1] == 2 && vec[vec.size()-2] == 2) {
      Types.push_back(Two);
    } else if(vec[vec.size()-1] == 2 && vec[vec.size()-2] == 1) {
      Types.push_back(One);
    } else if(vec[vec.size()-1] == 1) {
      Types.push_back(High);
    } else {
      std::cout << "UNREACHABLE" << std::endl;
    }	
  }
#endif
  std::cout << "*****" << std::endl;

  for(auto T : Types) {
    //std::cout << T << std::endl;
  }
  std::vector<std::tuple<int, std::vector<int>, int>> ClassCardsBet;

  for(int i = 0; i < Types.size(); i++) {
    ClassCardsBet.push_back(std::tuple<int, std::vector<int>, int>{Types[i], CardUnsorted[i], Bet[i]});
  }
  std::cout << "%%%%%%%%%%%%" << std::endl;
  std::sort(ClassCardsBet.begin(),ClassCardsBet.end());
  std::vector<std::vector<std::tuple<int, std::vector<int>, int>>> Cards2;
  for(int i = 0; i < 1000; i++) { // ammount of data dependedt 
    Cards2.push_back(std::vector<std::tuple<int, std::vector<int>, int>>{});
  }
  std::cout << "%%%%%%%%%%%%" << std::endl;
  for(int i = 0; i < ClassCardsBet.size(); i++) {
    //std::cout << std::get<0>(ClassCardsBet[i]) << std::endl;
    Cards2[i].push_back(ClassCardsBet[i]);
  }
    std::cout << "%%%%%%%%%%%%" << std::endl;
  int ans = 0;
  int rank = 1;
  
  for(auto &i : Cards2) {
    //std::sort(i.begin(), i.end(), [](const auto& a, const auto& b) { return std::get<1>(a) < std::get<1>(b); });

    std::sort(i.begin(), i.end(), [](const auto& a, const auto& b) { return std::get<1>(a) < std::get<1>(b); });
    for(int j = 0; j < i.size(); j++) {
      for(auto k : std::get<1>(i[j])) {
	//std::cout << k << " ";
      }
      //std::cout << "| " << std::get<0>(i[j]) << " | " << std::get<2>(i[j]);
      //std::cout << "" << std::endl;
      //std::cout << "Rank: " << rank << " Bet: " << std::get<2>(i[j]) << std::endl;
      ans += rank * std::get<2>(i[j]);
      rank++;
    }

  }
  std::cout << ans << std::endl;
}
