#include "Day6.hpp"


int Races(long int time, long int dist)
{
  long double delta = pow(time,2) -4.0*(double)dist;

  long double t1 = time/2.0 + sqrt(delta)/2.0;
  long double t2 = time/2.0 - sqrt(delta)/2.0;

  std::cout << t1 << t2 << std::endl;
  // if they are ints the floor and ceil dont do anything so add/subtract a little bit
  long double ans = floor(t1-0.0001)-ceil(t2+0.0001) + 1.0;
  return (long int)ans;
}

void Day6()
{
  // Input 1:
  int time1 = 56;
  int dist1 = 499;

  int time2 = 97;
  int dist2 = 2210;

  int time3 = 77;
  int dist3 = 1097;

  int time4 = 93;
  int dist4 = 1440;
    
  // let t be the time held down
  // let f(t) be the distance travled
  // => f'(t) is the rate of change of disance aka velocity
  // let T be the max time allowed
  // f(t) = f'(t)*(T-t)
  //f'(t) = t
  // => f(t) = t(T-t)
  // => f(t) = Tt-t^2
  // need to find when f(t) > dist
  // => dist > Tt-t^2
  // => 0 = t^2 -Tt + dist
  // can sum up the times between the values

  // quadratic formula (-b +/- sqrt(b^2 -4ac))/(2a) 
  // =>t = T/2 +/- sqrt(T^2 -4*dist)/2
  
  int ans1 = Races(time1,dist1);
  //std::cout << ans1 << std::endl;
  int ans2 = Races(time2,dist2);
  //std::cout << ans2 << std::endl;
  int ans3 = Races(time3,dist3);
  //std::cout << ans3 << std::endl;
  int ans4 = Races(time4,dist4);
  //std::cout << ans4 << std::endl;

  int ans5 = ans1*ans2*ans3*ans4;
  //std::cout << ans5 << std::endl;

  // Part 2

  long int time = 56977793;
  long int dist = 499221010971440;
  long int ans6 = Races(time,dist);
  std::cout << ans6 << std::endl;
  
}
