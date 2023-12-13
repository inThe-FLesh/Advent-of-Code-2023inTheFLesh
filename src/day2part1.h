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
using std::count;

int countSemiColon(string line);

string getGame(string line, int size);

int getId(string line);

string getRound(string line, int length);

string endRound(string line, int length);

string removeColour(string colour);
