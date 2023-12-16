//
// Created by inThe-FLesh on 08/12/2023
//

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <ostream>
#include <queue>
#include <regex>
#include <string>
#include <unordered_map>

using std::count;
using std::cout;
using std::endl;
using std::find;
using std::ifstream;
using std::queue;
using std::regex;
using std::regex_replace;
using std::string;
using std::unordered_map;

int countSemiColon(string line);

string getGame(string line, int size);

int getId(string line);

string getRound(string line, int length);

string removeGame(string line, int length);

string endRound(string line, int length);

string removeColour(string colour);

string getNextColour(string colours, int length);

int *createColourNumArray(int *numArray);

bool checkGame(int *colourNumArrSum);

int sumIDs(queue<int> acceptedIDs);
