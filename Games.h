//
// Created by Sivkan Thind on 9/17/24.
//

#ifndef GAMES_H
#define GAMES_H
#include <string>
#include <fstream>
#include <algorithm>
#include <random>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Pre: Takes in "netWorth" (pass by reference).
// Post: Plays a round of craps.
void craps(int& netWorth);

// Pre: Takes in "netWorth" (pass by reference).
// Post: Plays a round of scraps.
void scraps(int& netWorth);

// Pre: none.
// Post: Plays a round of rock paper scissors.
//       Asks player to pick rock, paper, or scissors, then computer picks, then output winner.
void rockPaperScissors();

// Pre: none.
// Post: Plays a round of rock paper scissors spock.
//       Asks player to pick rock, paper, scissors, or spock, then computer picks, then output winner.
void rockPaperScissorsSpock();

// Pre: none
// Post: Plays a round of black jack.
//       creates a deck, hands out two cards to both person and computer, asks the player
//       if they want to keep drawing, then computer plays. Outputs winner.
void playBlackJack();

void playHangman(vector<string> &wordList);


// Sources: Used ChatGpt for rockPaperScissors() and rockPaperScissorsSpock()
// Commented in .cpp where I used the LLM and the prompt.

#endif //GAMES_H
