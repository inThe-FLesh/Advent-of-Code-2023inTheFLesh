//
// Created by inThe-FLesh on 08/12/2023
//

#include "day1part2.h"

// Gets the first and last number in each string
int getCalibrationValue(string line, int size){
  
  string first = "";
  string last = "";

  first = line[0];
  last = line[size - 1];

  string firstAndLast = first + last;

  return std::stoi(firstAndLast);

}

// Function that removes the letters from the string leaving only numbers
string stripLetters(string line){
  
  string nums = "";

  line = parseNumFromString(line);

  for(char c : line){
    
    int castChar = (int) c;    
    
    if (castChar < 58 && castChar > 47){
          nums += c;
    }
  }
  
  return nums;
}

string parseNumFromString(string line){
  
  string numStrings[] = {"one", "two", "three", 
                        "four", "five", "six", 
                        "seven", "eight", "nine"};

  // have to replace the first and last characters as they can make up another 
  // number e.g. twone, nineight
  unordered_map<string, string> numMap = 
  {{"one", "o1e"}, {"two", "t2o"},  {"three", "t3e"}, 
  {"four", "f4r"}, {"five", "f5e"}, {"six", "s6x"}, 
  {"seven", "s7n"}, {"eight", "e8t"}, {"nine", "n9e"}
  };
  
  for (string num : numStrings){
    regex match(num);
    line = regex_replace(line, match, numMap.at(num));
  }

  return line;
}

int main(){

  int count = 0;
  string line;
  ifstream input("input.txt");

  while (getline(input, line)) {
    
    string stripped = stripLetters(line);
    
    int num = getCalibrationValue(stripped, stripped.length());
    
    count += num;
  }

  cout << count << endl;
}
