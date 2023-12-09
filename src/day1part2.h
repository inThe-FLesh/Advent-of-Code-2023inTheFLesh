//
// Created by inThe-FLesh on 08/12/2023
//

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <ostream>
#include <regex>
#include <string>
#include <algorithm>
#include <string>
#include <unordered_map>

using std::ifstream; 
using std::cout;
using std::endl;
using std::string;
using std::find;
using std::unordered_map;
using std::regex;
using std::regex_replace;

int getCalibrationValue(string line, int size);

string stripLetters(string line);

string parseNumFromString(string line);

class day1{};


