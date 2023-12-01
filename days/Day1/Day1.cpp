#include "Day1.hpp"


/*
1abc2
pqr3stu8vwx
a1b2c3d4e5f
treb7uchet
*/
void Day1(){
    //Pt1();
    Pt2();
}

void Pt1()
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
    std::cout << ans << std::endl;
}

void Pt2()
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
    std::cout << ans << std::endl;

}