#include "day2part2.h"
#include <cstdlib>
#include <stdexcept>
#include <string>

int getId(string line) {
  line = line.substr(0, line.find(":"));
  line = line.substr(5, 3);
  return stoi(line);
}

string getGame(string line, int length) {
  // add 1 to size as there is one less semi colon than there are blocks
  return line = line.substr((line.find(":") + 2), length);
}

string getRound(string line, int length) {
  string round;

  if (line.find(";") != string::npos) {
    round = line.substr(0, line.find(";"));
  } else {
    round = line;
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

// returns an array of minimum values for each colour in a given round
int *getNumbers(string round, int roundLength, int *numArray) {
  bool finished = false;
  string colour = round.substr(0, round.find(","));

  while (!finished) {

    if (colour.find("red") != string::npos) {
      int numColour = std::stoi(removeColour(colour));
      if (numArray[0] > numColour)
        numArray[0] = numColour;
    }

    else if (colour.find("green") != string::npos) {
      int numColour = std::stoi(removeColour(colour));
      if (numArray[1] > numColour)
        numArray[1] = numColour;
    }

    else if (colour.find("blue") != string::npos) {
      int numColour = std::stoi(removeColour(colour));
      if (numArray[2] > numColour)
        numArray[2] = numColour;
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

int findPower(int *numArray) {

  int power = 1;

  for (int i = 0; i < 3; i++) {
    power *= numArray[i];
  }

  return power;
}

int powerSum(queue<int> powers) {
  int total = 0;

  while (!powers.empty()) {
    total += powers.front();
    powers.pop();
  }

  return total;
}

int main() {
  int id;
  int totalPowers = 0;
  string line;
  ifstream input("day2Input.txt");
  queue<int> powers;

  while (getline(input, line)) {
    id = getId(line);
    string round;

    int *colourNumArr = (int *)malloc(sizeof(int) * 3);

    for (int i = 0; i < 3; i++) {
      colourNumArr[i] = numeric_limits<int>::max();
    }

    string game = getGame(line, line.length());

    while (line != "done") {
      // position 0 = red, position 1 = green, position 2 = blue
      string round = getRound(line, line.length());

      // function to get numbers from round
      line = endRound(line, line.length());

      colourNumArr = getNumbers(round, round.length(), colourNumArr);
    }

    // use a queue
    powers.push(findPower(colourNumArr));

    free(colourNumArr);
  }

  totalPowers = powerSum(powers);

  cout << "Total Powers: " << totalPowers << endl;
}
