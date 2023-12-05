#include "Day1.hpp"
/*
1abc2
pqr3stu8vwx
a1b2c3d4e5f
treb7uchet
*/
void Day1(){
    //Day1Pt1();
    Day1Pt2();
}

void Day1Pt1()
{
    std::ifstream Input;
    Input.open("days/Day1/input.txt");
    
    std::vector<char> Values = {};
    
    while ( Input ) {
        std::string Line;
        std::getline(Input, Line);
        std::cout << Line << std::endl;

        std::vector<char> ValTemp = {};
        for(int i = 0; i < Line.size(); i++)
        {
            if(isdigit(Line[i]))
            {
                //std::cout << Line[i] << std::endl;
                ValTemp.push_back(Line[i]);
            }
        }
        if(ValTemp.size() > 0)
        {
            //std::cout << ValTemp.size() << std::endl;
            Values.push_back(ValTemp[0]);
            Values.push_back(ValTemp[ValTemp.size()-1]);
        }
    }
    Input.close();
    int ans = 0;
    for(int i = 0; i < Values.size()/2; i++)
    {
        std::string c = "";
        char a = Values[2*i];
        char b = Values[2*i + 1];
        c.push_back(a);
        c.push_back(b);
        ans += std::stoi(c); 
    }
}

void Day1Pt2()
{
    std::ifstream Input;
    Input.open("days/Day1/input.txt");
    
    std::vector<char> Values = {};
    
    while ( Input ) {
        std::string Line;
        std::getline(Input, Line);
        std::cout << Line << std::endl;

        std::vector<char> ValTemp = {};
        for(int i = 0; i < Line.size(); i++)
        {
            if(isdigit(Line[i]))
            {
                //std::cout << Line[i] << std::endl;
                ValTemp.push_back(Line[i]);
            } else {
                if(Line.size() - i >= 3)
                {
                    if(Line[i] == 'o' && Line[i + 1] == 'n' && Line[i + 2] == 'e')
                    {
                        ValTemp.push_back('1');
                    }
                    if(Line[i] == 't' && Line[i + 1] == 'w' && Line[i + 2] == 'o')
                    {
                        ValTemp.push_back('2');
                    }
                    if(Line[i] == 's' && Line[i + 1] == 'i' && Line[i + 2] == 'x')
                    {
                        ValTemp.push_back('6');
                    }
                }
                if(Line.size() - i >= 4)
                {
                    if(Line[i] == 'f' && Line[i + 1] == 'o' && Line[i + 2] == 'u' && Line[i + 3] == 'r')
                    {
                        ValTemp.push_back('4');
                    }
                    if(Line[i] == 'f' && Line[i + 1] == 'i' && Line[i + 2] == 'v' && Line[i + 3] == 'e')
                    {
                        ValTemp.push_back('5');
                    }
                    if(Line[i] == 'n' && Line[i + 1] == 'i' && Line[i + 2] == 'n' && Line[i + 3] == 'e')
                    {
                        ValTemp.push_back('9');
                    }
                }
                if(Line.size() - i >= 5)
                {
                    if(Line[i] == 't' && Line[i + 1] == 'h' && Line[i + 2] == 'r' && Line[i + 3] == 'e' && Line[i + 4] == 'e')
                    {
                        ValTemp.push_back('3');
                    }
                    if(Line[i] == 's' && Line[i + 1] == 'e' && Line[i + 2] == 'v' && Line[i + 3] == 'e' && Line[i + 4] == 'n')
                    {
                        ValTemp.push_back('7');
                    }
                    if(Line[i] == 'e' && Line[i + 1] == 'i' && Line[i + 2] == 'g' && Line[i + 3] == 'h' && Line[i + 4] == 't')
                    {
                        ValTemp.push_back('8');
                    }
                }
            }
        }
        if(ValTemp.size() > 0)
        {
            //std::cout << ValTemp.size() << std::endl;
            //std::cout << ValTemp[0] << std::endl;
            //std::cout << ValTemp[ValTemp.size() - 1] << std::endl;
            Values.push_back(ValTemp[0]);
            Values.push_back(ValTemp[ValTemp.size()-1]);
        }
    }
    Input.close();
    int ans = 0;

    for(int i = 0; i < Values.size()/2; i++)
    {
        std::string c = "";
        char a = Values[2*i];
        char b = Values[2*i + 1];
        c.push_back(a);
        c.push_back(b);
        ans += std::stoi(c); 
    }
    std::cout << ans << std::endl;
}
