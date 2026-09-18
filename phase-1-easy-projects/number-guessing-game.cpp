#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits>
using namespace std;

int getValidInt() {

    int value;
    while (!(cin >> value)) {
        cout << "Invalid input. Please enter a valid number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return value;
}

void selectDifficultyLevel(int &randNum, int &maxNum) {

    cout << "Choose a difficulty level: " << endl;
    cout << "1. Easy (1-50)" << endl;
    cout << "2. Medium (1-100)" << endl;
    cout << "3. Hard (1-200)" << endl;
    cout << "Enter your choice: ";

    int difficulty = getValidInt();

    while (difficulty < 1 || difficulty > 3) { // Edge case: if the difficulty level is not between 1 and 3
        cout << "Invalid difficulty level. Please choose between 1 and 3." << endl;
        difficulty = getValidInt();
    }

    if (difficulty == 1) {
        maxNum = 50;
    } else if (difficulty == 2) {
        maxNum = 100;
    } else if (difficulty == 3) {
        maxNum = 200;
    }

    randNum = rand() % maxNum + 1; // Generate a random number between 1 and maxNum

}

void playGuessingGame(int guessNum, int randNum, int &attempts, int maxNum) {

    while (true) {
        cout << "Guess a Number: ";
        guessNum = getValidInt();

        // You can validate and skip without counting an attempt
        if (guessNum < 1 || guessNum > maxNum) {
            cout << "Invalid guess. Please guess a number between 1 and " << maxNum << "." << endl;
            continue;
        }

        attempts++;

        // The exit condition: leave the loop only when correct
        if (guessNum == randNum) {
            cout << "Congratulations! You guessed the correct number." << endl;
            break; // Stops the while(true) loop here
        }
        else if (guessNum > randNum) { // Otherwise, give hints and let the loop repeat
            cout << "Too high!" << endl;
        }
        else {
            cout << "Too low!" << endl;
        }
    }
    cout << "Attempts = " << attempts << endl;
}

int calculateScore(int attempts) {

    if (attempts <= 3) {
       return 100;
    }
    else if (attempts <= 6) {
        return 70;
    }
    else if (attempts <= 10) {
        return 50;
    }
    else {
        return 0;
    }
}

int main() {

    srand(time(0)); // Seed the random number generator using the current time
    char playAgain;

    do {
        // Difficulty levels
       
        int randNum = 0, maxNum = 0;
        selectDifficultyLevel(randNum, maxNum);

        int guessNum, attempts = 0;
        playGuessingGame(guessNum, randNum, attempts, maxNum);

        int scoreValue = calculateScore(attempts);

        cout << "Score = " << scoreValue << endl;

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
        // Discard any extra characters in the input stream (e.g. if user typed "yes")
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thank you for playing!" << endl;

    return 0;
}
