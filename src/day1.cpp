//
// Created by inThe-FLesh on 08/12/2023
//

#include "day1.h"

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

    for(char c : line){
        int castChar = (int) c;    
        // checks if character is a number
        if (castChar < 58 && castChar > 47){
            nums += c;
        }
    }

    return nums;
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
