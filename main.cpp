// CS201R_PGM4_Games.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// NAME: Sivkan Thind
// DATE: 09/19/24
// PROGRAM: Games (4)
// Sources: Used ChatGpt for rockPaperScissors() and rockPaperScissorsSpock()
// Commented in .cpp where I used the LLM and the prompt.

#include "Games.h"
//#include "Functions.h"

int main()
{
    int netWorth = 50; // for scraps and craps.

    while (true) {

        //Give user choices and ask for them to pick.
        string userChoice;
        cout << "\nWelcome to My Games!\n";
        cout << "Games List" << endl;
        cout << "1 - Craps" << endl;
        cout << "2 - Scraps" << endl;
        cout << "3 - Rock Paper Scissors" << endl;
        cout << "4 - Rock Paper Scissors Spock" << endl;
        cout << "5 - Blackjack" << endl;
        cout << "6 - Hangman" << endl;
        cout << "7 - Quit" << endl;
        cout << "Please pick a game option (1-7): " << endl;
        cin >> userChoice;

        // Craps
        if (userChoice == "1") {
            char goAgain = *"Y";
            netWorth = 50;
            while(netWorth != 0 && goAgain != 'N') {
                craps(netWorth);
                if(netWorth <= 0) {
                    cout << "Sorry, your net worth is zero." << endl;
                    break;
                }
                cout << "\nWould you like to play again (Y/N)" << endl;
                cin >> goAgain;
                goAgain = toupper(goAgain);

            }
        }

        // Scraps
        else if (userChoice == "2") {
            char goAgain = *"Y";
            netWorth = 50;
            while(netWorth != 0 && goAgain != 'N') {
                scraps(netWorth);
                if(netWorth <= 0) {
                    cout << "Sorry, your net worth is zero." << endl;
                    break;
                }
                cout << "\nWould you like to play again (Y/N)" << endl;
                cin >> goAgain;
                goAgain = toupper(goAgain);

            }

        }

        // Rock Paper Scissors
        else if (userChoice == "3") {
            char goAgain = *"Y";
            while(goAgain != 'N') {
                rockPaperScissors();
                cout << "\nWould you like to play again (Y/N)" << endl;
                cin >> goAgain;
                goAgain = toupper(goAgain);
            }
        }

        // Rock Paper Scissors Spock
        else if (userChoice == "4") {
            char goAgain = *"Y";
            while(goAgain != 'N') {
                rockPaperScissorsSpock();
                cout << "\nWould you like to play again (Y/N)" << endl;
                cin >> goAgain;
                goAgain = toupper(goAgain);
            }
        }

        // Blackjack
        else if (userChoice == "5") {
            char goAgain = *"Y";
            while(goAgain != 'N') {
                playBlackJack();
                cout << "\nWould you like to play again (Y/N)" << endl;
                cin >> goAgain;
                goAgain = toupper(goAgain);
            }
        }

        // Hangman
        else if (userChoice == "6") {
            vector<string> words;
            playHangman(words);
        }

        // Quit
        else if (userChoice == "7") {
            break;
        }
        // Error handling if they do not enter 1-7.
        else {
            cout << "Choice not valid." << endl;
        }

    }
    cout << "Thank you for playing!" << endl;
}


