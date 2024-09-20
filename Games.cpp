//
// Created by Sivkan Thind on 9/17/24.
// Sources: Used ChatGpt for rockPaperScissors() and rockPaperScissorsSpock()
// Commented in .cpp where I used the LLM and the prompt.
#include "Games.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

// a function to roll dice that takes in the number of sides so it can be used for multiple games.
int rollDie(int sideAmount) {
    //std::srand(static_cast<unsigned int>(std::time(0)));
    int roll = (std::rand() % sideAmount) + 1; //use srand w time
    return roll;
}

void craps(int& netWorth) {

    // welcome the user to craps and ask for a bet.
    cout << "\nWELCOME TO CRAPS\n" << endl;
    char goAgain = 'Y';

    float bet;
    cout << "Your net worth is $" << netWorth << "." << " Please enter a bet: ";
    cin >> bet;
    while(bet > netWorth) { // makes sure the bet is less than or equal to the net worth
        cout << "Please enter a bet that is less than or equal to your net worth: ";
        cin >> bet;
    }
    cout << "You bet $" << bet << "." << endl;

    // plays craps
    do{
        int roll1 = rollDie(6);
        int roll2 = rollDie(6);
        int sum = roll1 + roll2; // roll 2 dice and add the sum.
        cout << "You rolled " << roll1 << " and " << roll2 << " = " << sum << endl;
        if(sum == 7 || sum == 11){ // winning conditions
            netWorth += bet;
            cout << "YOU WIN! Your net worth is now: $" << netWorth << endl;
            return;
        }
        if(sum == 2 || sum == 3 || sum == 12){ // losing conditions
            netWorth -= bet;
            cout << "YOU LOST! Sorry! Your net worth is now: $" << netWorth << endl;
            return;
        }
        int point = sum; //point is the number to beat.
        cout << "\n     Point is " << point << endl;
        do{
            roll1 = rollDie(6);
            roll2 = rollDie(6);
            sum = roll1 + roll2;
            cout << "     You rolled " << roll1 << " and " << roll2 << " = " << sum << endl;
            if(sum == point){ // winning condition
                netWorth += bet;
                cout << "     YOU WIN! Your net worth is now: $" << netWorth << endl;
                return;
            }
            if(sum == 7){ // losing condition
                netWorth -= bet;
                cout << "     YOU LOST! Sorry! Your net worth is now: $" << netWorth << endl;
                return;
            }
        } while(true);
    } while(true);
}

// Plays scraps
void scraps(int& netWorth) {

    cout << "\nWELCOME TO SCRAPS!\n";
    int bet;
    cout << "Your net worth is $" << netWorth << "." << " Please enter a bet: ";
    cin >> bet;
    while(bet > netWorth) { // makes sure the bet is less than or equal to the net worth
        cout << "Please enter a bet that is less than or equal to your net worth: ";
        cin >> bet;
    }
    cout << "You bet " << bet << "." << endl;

    do{
        int roll1 = rollDie(8);
        int roll2 = rollDie(8);
        int roll3 = rollDie(8);
        int sum = roll1 + roll2 + roll3;
        cout << "You rolled " << roll1 << " + " << roll2 << " + " << roll3 << " = " << sum << endl;
        if(roll1 == 8 || roll2 == 8 || roll3 == 8) { // winning conditions
            netWorth += bet;
            cout << "YOU WIN! Your net worth is now: $" << netWorth << endl;
            return;
        }
        if(sum == 9 || sum == 10 || sum == 14) { // winning conditions
            netWorth += bet;
            cout << "YOU WIN! Your net worth is now: $" << netWorth << endl;
            return;
        }
        if(roll1 == 1 || roll2 == 1 || roll3 == 1) { // losing conditions
            netWorth -= bet;
            cout << "YOU LOST! Sorry! Your net worth is now: $" << netWorth << endl;
            return;
        }
        if(sum == 8 || sum == 20 || sum == 23 || sum == 24) { // losing conditions
            netWorth -= bet;
            cout << "YOU LOST! Sorry! Your net worth is now: $" << netWorth << endl;
            return;
        }
        int point = sum;
        cout << "\n     Point is: " << point << endl; // point is number to beat
        do {
            roll1 = rollDie(8);
            roll2 = rollDie(8);
            roll3 = rollDie(8);
            int sum = roll1 + roll2 + roll3;
            if(sum == point) {  // winning condition
                netWorth += bet;
                cout << "     YOU WIN! Your net worth is now: $" << netWorth << endl;
                return;
            }
            if(roll1 == 8 || roll2 == 8 || roll3 ==8 || sum == 15) { // losing conditions
                netWorth -= bet;
                cout << "     YOU LOST! Sorry! Your net worth is now: $" << netWorth << endl;
                return;
            }
        } while(true);
    } while(true);
}

// Plays rock paper scissors
void rockPaperScissors() {
    /*
    Here I asked the LLM to create a code to validate user inputs for rock, paper, and scissors.
    "make this so that the user has to enter either rock, paper, or scissors"
    I went in and edited the code to be simpler and make sense myself.
    */
    std::string choices[] = {"rock", "paper", "scissors"};
    std::string userChoice;

    std::cout << "Enter your choice (rock, paper, or scissors): ";
    cin >> userChoice;

    // Validate user input
    while (userChoice != "rock" && userChoice != "paper" && userChoice != "scissors") {
        std::cout << "Invalid choice! Please enter rock, paper, or scissors." << std::endl;
        cin >> userChoice;
    }

    /*
    Here I asked the LLM to create a code that picks a winner for a basic game of
    rock, paper, scissors after the computer generates its own random choice.
    I went in and edited the code to make proper sense myself.
    */
    //Random numbers for computer choice.
    std::srand(std::time(0));
    int computerChoiceIndex = std::rand() % 3;
    std::string computerChoice = choices[computerChoiceIndex];

    std::cout << "You chose: " << userChoice << std::endl;
    std::cout << "Computer chose: " << computerChoice << std::endl;


    if (userChoice == computerChoice) { // tie condition
        std::cout << "It's a tie!" << std::endl;
    } else if ((userChoice == "rock" && computerChoice == "scissors") ||
               (userChoice == "paper" && computerChoice == "rock") ||
               (userChoice == "scissors" && computerChoice == "paper")) {
        std::cout << "You win!" << std::endl; // winning conditions for player.
               } else {
                   std::cout << "You lose!" << std::endl; // if player does not win, they lose.
               }
}

// Plays rock paper scissors spock.
void rockPaperScissorsSpock() {
    cout << "\n WELCOME TO ROCK PAPER SCISSORS SPOCK\n";

    /* for this function I used the one above created by the LLM and just
      added the spock to it. For the second part I asked the LLM to recode the
      winners by providing it with the new rules.
      I edited the first part to include spock myself.
    */
    std::string choices[] = {"rock", "paper", "scissors", "spock"};
    std::string userChoice;

    std::cout << "Enter your choice (rock, paper, scissors, or spock): ";
    std::cin >> userChoice;

    // Validate user input
    while (userChoice != "rock" && userChoice != "paper" && userChoice != "scissors" && userChoice != "spock") {
        std::cout << "Invalid choice! Please enter rock, paper, scissors, or spock." << std::endl;
        cin >> userChoice;
    }

    // random computer choice generated.
    std::srand(std::time(0));
    int computerChoiceIndex = std::rand() % 4;
    std::string computerChoice = choices[computerChoiceIndex];

    std::cout << "You chose: " << userChoice << std::endl;
    std::cout << "Computer chose: " << computerChoice << std::endl;


    if (userChoice == computerChoice) {
        std::cout << "It's a tie!" << std::endl; // Tie condition
    } else if ((userChoice == "rock" && (computerChoice == "scissors" || computerChoice == "spock")) ||
               (userChoice == "paper" && (computerChoice == "rock" || computerChoice == "spock")) ||
               (userChoice == "scissors" && (computerChoice == "paper" || computerChoice == "spock")) ||
               (userChoice == "spock" && (computerChoice == "scissors" || computerChoice == "rock"))) {
        std::cout << "You win!" << std::endl; // the winning conditions for the player.
               } else {
                   std::cout << "You lose!" << std::endl; // if player does not win, they lose.
               }
}

// For Blackjack
//adds the suits to the deck.
void addSuitsToDeck(string suit, vector<string>& deck) {
    for(int i = 1; i <= 13; i++) {
        std::string card = suit;
        if (i == 11) {
            card += "J";
        }
        else if(i == 12) {
            card += "Q";
        }
        else if(i == 13) {
            card += "K";
        }
        else if(i == 1) {
            card += "A";
        }
        else if(i == 10) {
            card += "T";
        }
        else {
            card += std::to_string(i);
        }
        deck.push_back(card);
    }
}

// Prints the current cards with correct colors and suit with number/ character.
void printCards(const vector<string>& hand) {
    for (auto card : hand) {
        if (card[0] == 'S') {
            cout << "♠";
        }
        else if (card[0] == 'H') {
            cout << "\u001b[31m♥";
        }
        else if (card[0] == 'D') {
            cout << "\u001b[31m♦";
        }
        else if (card[0] == 'C') {
            cout << "♣";
        }
        if (card[1] == 'T') {
            cout << "   10\u001b[0m" << endl;
        }
        else {
            cout << "   " << card[1] << "\u001b[0m" << endl;
        }
    }
}

// plays blackjack
void playBlackJack() {
    std::vector<std::string> deck;
    std::vector<std::string> handOne;
    std::vector<std::string> handTwo;
    addSuitsToDeck("S",deck);
    addSuitsToDeck("C",deck);
    addSuitsToDeck("H",deck);
    addSuitsToDeck("D",deck); //  create the deck

    auto rd = std::random_device {};

    auto rng = std::default_random_engine {rd()};
    ranges::shuffle(deck, rng); // shuffle the deck

    //initial deal
    for (int i = 0; i < 2; i++) {
        string card = deck.back();
        deck.pop_back();
        handOne.push_back(card); // give player card
        card = deck.back();
        deck.pop_back();
        handTwo.push_back(card); // give computer card
    }

    int playerTotal = 0;
    int compTotal = 0;

    //player turn
    while (true) {
        playerTotal = 0;
        cout << "Player has the following cards: " << endl;
        printCards(handOne); // print out hand
        for (auto card: handOne) { // calculate total
            if (card[1] == 'T'|| card[1] == 'K' || card[1] == 'Q' || card [1] == 'J') {
                playerTotal += 10;
            }
            else if(card[1] == 'A'){
                if(playerTotal + 11 > 21) {
                    playerTotal += 1;
                }
                else {
                    playerTotal += 11;
                }
            }
            else {
                playerTotal += (card[1] - 48);
            }
        }
        cout << "     Total is " << playerTotal << endl;
        if(playerTotal > 21) { // losing condition
            cout << "Oops, you lose!" << endl;
            return;
        }
        string userChoice;
        cout << "Would you like to draw again? (Y/N): " << endl; // ask if they want to play again
        cin >> userChoice;

        // check for validity
        while(userChoice != "Y" && userChoice != "y" && userChoice != "N" && userChoice != "n") {
            cout << "Please enter a valid choice (Y/N): " << endl;
            cin >> userChoice;
        }
        // play again
        if(userChoice == "Y" || userChoice == "y") {
            string card = deck.back();
            deck.pop_back();
            handOne.push_back(card);
        }
        else {
            break;
        }
    }
    while(true) { // same thing as above, but automated for computer
        compTotal = 0;
        cout << "Computer has the following cards: " << endl;
        printCards(handTwo);
        for (auto card: handTwo) {
            if (card[1] == 'T'|| card[1] == 'K' || card[1] == 'Q' || card [1] == 'J') {
                compTotal += 10;
            }
            else if(card[1] == 'A'){
                if(compTotal + 11 > 21) {
                    compTotal += 1;
                }
                else {
                    compTotal += 11;
                }
            }
            else {
                compTotal += (card[1] - 48);
            }
        }
        cout << "     Total is " << compTotal << endl;
        if(compTotal > 21) {
            cout << "Computer loses, you win!!" << endl;
            return;
        }

        if(compTotal <= 17) { // stops if total goes above 17
            string card = deck.back();
            deck.pop_back();
            handTwo.push_back(card);
        }
        else {
            break;
        }
    }

    // winning, losing, and tying conditions and output.
    if(compTotal > playerTotal) {
        cout << "Computer Wins." << endl;
    }
    else if(compTotal == playerTotal) {
        cout << "You tied with computer." << endl;
    }
    else {
        cout << "You win!" << endl;
    }
}

// reads a file in for hangman.
void readFile(vector<string> &wordTxt) {
    ifstream inFile;
    inFile.open("words.txt");
    if (!inFile.is_open()) {
        cout << "Could not open the file\n";
        return;
    }
    string tempWord;
    getline(inFile, tempWord);
    while (inFile.good()) {
        wordTxt.push_back(tempWord);
        getline(inFile, tempWord);
    }
    inFile.close();
}

//Plays hangman
void playHangman(vector<string> &wordList) {
    readFile(wordList);
    int inx, triesLeft = 6; // number of tries
    string randWord, guessWord;
    char guessLetter;

    srand(time(0)); // picks a random word
    inx = rand() % wordList.size();
    randWord = wordList[inx];

    for (int i = 0; i < randWord.size(); i++) {
        guessWord += '?';
    }
    cout << "HANGMAN - your word is: " << guessWord << endl;

    while (randWord != guessWord && triesLeft > 0) { // plays while they have guesses left
        cout << "\nEnter your guess: ";
        cin >> guessLetter;
        if (randWord.find(guessLetter) != string::npos) {
            for (int i = 0; i < randWord.size(); i++) {
                if (randWord[i] == guessLetter)
                    guessWord[i] = guessLetter;
            }
            if (guessWord == randWord) {
                cout << "Nice Guess! You Win!! The word was " << randWord << endl; // winner
                break;
            }
            cout << "Nice Guess! You have " << triesLeft << " guesses left. Your current word: " << guessWord << endl;// good guess
        } else {
            triesLeft -= 1;
            cout << "Sorry! Guess is not valid or correct. You have " << triesLeft << " guesses left. Your current word: " << guessWord << endl;
            if (triesLeft == 0) {
                cout << "\nYou Lose. The word was: " << randWord << endl; // loser
            }
        }
    }
}
