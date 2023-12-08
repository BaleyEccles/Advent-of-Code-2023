#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <math.h>

void Day3();

void Day3Pt1();
int AddPartNum(int x, int y, std::vector<std::vector<int>> Data);
int GetNum(int x, int y, int p1, int p2, std::vector<std::vector<int>> Data, std::vector<int>& CheckedPlaces);

void Day3Pt2();
