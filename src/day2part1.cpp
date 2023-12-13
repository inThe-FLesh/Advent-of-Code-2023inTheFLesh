/* To get information, once a bag has been loaded with cubes, the Elf will reach into the bag, grab a handful of random cubes, show them to you, and then put them back in the bag. He'll do this a few times per game.

You play several games and record the information from each game (your puzzle input). Each game is listed with its ID number (like the 11 in Game 11: ...) followed by a semicolon-separated list of subsets of cubes that were revealed from the bag (like 3 red, 5 green, 4 blue).

For example, the record of a few games might look like this:

Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue
Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red
Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red
Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green

In game 1, three sets of cubes are revealed from the bag (and then put back again). The first set is 3 blue cubes and 4 red cubes; the second set is 1 red cube, 2 green cubes, and 6 blue cubes; the third set is only 2 green cubes.

The Elf would first like to know which games would have been possible if the bag contained only 12 red cubes, 13 green cubes, and 14 blue cubes?

In the example above, games 1, 2, and 5 would have been possible if the bag had been loaded with that configuration. However, game 3 would have been impossible because at one point the Elf showed you 20 red cubes at once; similarly, game 4 would also have been impossible because the Elf showed you 15 blue cubes at once. If you add up the IDs of the games that would have been possible, you get 8.

Determine which games would have been possible if the bag had been loaded with only 12 red cubes, 13 green cubes, and 14 blue cubes. What is the sum of the IDs of those games? */ 

#include "day2part1.h"
#include <regex>
#include <stdexcept>
#include <string>



int getId(string line){
  line = line.substr(0, line.find(":"));
  line = line.substr(5, 3);
  return stoi(line);
}



string getGame(string line, int length){
  // add 1 to size as there is one less semi colon than there are blocks
  return line = line.substr((line.find(":") + 2), length);
}



string getRound(string line, int length){
  string round;

  if(line.find(";")){  
    round = line.substr(0, line.find(";"));
  }else{
    round = line;
  }

  return round;
}



string endRound(string line, int length){
  // checks if the string contains a ;
  if (line.find(";") != string::npos){
    return line.substr((line.find(";") + 2), length);
  }

  return "done";
}



int *getNumbers(string round){
  string colour = round;
  int *numArray = (int*) malloc(sizeof(int) * 3);

  if (round.find(",") != string::npos){
    colour = round.substr(0, round.find(","));
  }

  if(colour.find("red")){
    colour = removeColour(colour);
    numArray[0] = stoi(colour);
  }
  
  else if (colour.find("green")) {
    colour = removeColour(colour);
    numArray[1] = stoi(colour);
  }

  else if(colour.find("blue")){
    colour = removeColour(colour);
    numArray[2] = stoi(colour);
  }

  // find a way to recurse through and add the numbers to the array

  else{
    throw std::invalid_argument("Colour not recognised");
  }
}


string removeColour(string colour){
  const regex pattern("[^0-9]");
  return regex_replace(colour, pattern, "");
}


int main(){
  int id;
  string line;
  ifstream input("day2Input.txt");

  while (getline(input, line)) {
    id = getId(line);
    string round;
    int count = 0;

    // position 0 = red, position 1 = green, position 2 = blue
    int *colourArr = (int*) malloc(sizeof(int) * 3);

    string game = getGame(line, line.length());
    
    while(line != "done"){
      string round = getRound(line, line.length());
      // function to get numbers from round
      line = endRound(line, line.length());
    }
  }

}

