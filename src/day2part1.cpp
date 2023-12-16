/* To get information, once a bag has been loaded with cubes, the Elf will reach
into the bag, grab a handful of random cubes, show them to you, and then put
them back in the bag. He'll do this a few times per game.

You play several games and record the information from each game (your puzzle
input). Each game is listed with its ID number (like the 11 in Game 11: ...)
followed by a semicolon-separated list of subsets of cubes that were revealed
from the bag (like 3 red, 5 green, 4 blue).

For example, the record of a few games might look like this:

Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue
Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red
Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red
Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green

In game 1, three sets of cubes are revealed from the bag (and then put back
again). The first set is 3 blue cubes and 4 red cubes; the second set is 1 red
cube, 2 green cubes, and 6 blue cubes; the third set is only 2 green cubes.

The Elf would first like to know which games would have been possible if the bag
contained only 12 red cubes, 13 green cubes, and 14 blue cubes?

In the example above, games 1, 2, and 5 would have been possible if the bag had
been loaded with that configuration. However, game 3 would have been impossible
because at one point the Elf showed you 20 red cubes at once; similarly, game 4
would also have been impossible because the Elf showed you 15 blue cubes at
once. If you add up the IDs of the games that would have been possible, you
get 8.

Determine which games would have been possible if the bag had been loaded with
only 12 red cubes, 13 green cubes, and 14 blue cubes. What is the sum of the IDs
of those games? */

#include "day2part1.h"
#include <cstdlib>
#include <stdexcept>
#include <string>

int getId(string line) {
  line = line.substr(0, line.find(":"));
  line = line.substr(5, 3);
  return stoi(line);
}

string getRound(string line, int length) {
  string round;

  if (line.find(";") != string::npos) {
    round = line.substr(0, line.find(";"));
  } else {
    round = line;
  }

  if (round.find(":") != string::npos) {
    round = removeGame(round, length);
  }
  return round;
}

string removeGame(string line, int length) {
  return line.substr(line.find(":") + 2, length);
}

string endRound(string line, int length) {
  // checks if the string contains a ;
  if (line.find(";") != string::npos) {
    return line.substr((line.find(";") + 2), length);
  }

  return "done";
}

int *getNumbers(string round, int roundLength) {
  int *numArray = (int *)malloc(sizeof(int) * 3);
  bool finished = false;
  string colour = round.substr(0, round.find(","));

  numArray[0] = 0;
  numArray[1] = 0;
  numArray[2] = 0;

  while (!finished) {

    if (colour.find("red") != string::npos) {
      numArray[0] = std::stoi(removeColour(colour));
    }

    else if (colour.find("green") != string::npos) {
      numArray[1] = std::stoi(removeColour(colour));
    }

    else if (colour.find("blue") != string::npos) {
      numArray[2] = std::stoi(removeColour(colour));
    }

    else {
      throw(std::invalid_argument("Unknown colour"));
    }

    if (round.find(",") != string::npos) {
      round = getNextColour(round, roundLength);
      colour = round.substr(0, round.find(","));
    } else {
      finished = true;
    }
  }

  return numArray;
}

string removeColour(string colour) {
  const regex pattern("[^0-9]");
  return regex_replace(colour, pattern, "");
}

string getNextColour(string colours, int length) {
  return colours.substr(colours.find(",") + 2, length);
}

bool checkGame(int *colourNumArrSum) {

  if (colourNumArrSum[0] > 12) {
    return false;
  }

  if (colourNumArrSum[1] > 13) {
    return false;
  }

  if (colourNumArrSum[2] > 14) {
    return false;
  }

  return true;
}

int sumIDs(queue<int> acceptedIDs) {
  int total = 0;

  return total;
}

bool maxCheck(int *colourNumArr) {

  if (colourNumArr[0] > 12) {
    return false;
  }

  if (colourNumArr[1] > 13) {
    return false;
  }

  if (colourNumArr[2] > 14) {
    return false;
  }

  return true;
}

int main() {
  int id;
  int sum = 0;
  string line;
  ifstream input("day2Input.txt");
  queue<int> acceptedIDs;

  while (getline(input, line)) {
    id = getId(line);
    string round;
    int count = 0;
    bool check = false;

    int *colourNumArr = (int *)malloc(sizeof(int) * 3);

    for (int i = 0; i < 3; i++) {
      colourNumArr[i] = 0;
    }

    while (line != "done") {
      // position 0 = red, position 1 = green, position 2 = blue
      string round = getRound(line, line.length());

      // function to get numbers from round
      line = endRound(line, line.length());

      colourNumArr = getNumbers(round, round.length());

      check = maxCheck(colourNumArr);

      if (check == false) {
        line = "done";
      }
    }

    if (check) {
      acceptedIDs.push(id);
    }

    free(colourNumArr);
  }

  while (!acceptedIDs.empty()) {
    int currentID = acceptedIDs.front();
    sum += currentID;
    acceptedIDs.pop();
  }

  cout << sum << endl;
}
