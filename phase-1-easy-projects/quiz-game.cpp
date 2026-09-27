#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <limits>
using namespace std;

int getPositiveIntegerInput()
{
    int input;
    while (true)
    {
        cin >> input;
        if (cin.fail() || input <= 0)
        {
            cin.clear();                                         // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input. Please enter a positive integer: ";
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard any extra input
            return input;
        }
    }
}

void displayCategories(const vector<string> &categories)
{
    for (size_t i = 0; i < categories.size(); ++i)
    {
        cout << (i + 1) << ". " << categories[i] << endl;
    }
}

void selectCategory(int &categoryChoice, const vector<string> &categories)
{

    cout << "Enter the number of your choice (1-" << categories.size() << "): ";
    categoryChoice = getPositiveIntegerInput();

    // Validate category choice
    while (categoryChoice < 1 || categoryChoice > categories.size())
    {
        cout << "Invalid choice. Please select a valid category number: ";
        categoryChoice = getPositiveIntegerInput();
    }
}

void inputUserAnswer(char &userAnswer)
{
    cout << "Enter your answer (A, B, C, D): ";
    cin >> userAnswer;
    userAnswer = toupper(userAnswer);

    while (userAnswer != 'A' && userAnswer != 'B' &&
           userAnswer != 'C' && userAnswer != 'D')
    {
        cout << "Invalid choice. Please enter A, B, C, or D: ";
        cin >> userAnswer;
        userAnswer = toupper(userAnswer);
    }
}

void askToPlayAgain(char& playAgain)
{
    cout << "Do you want to play again? (Y/N): ";
    cin >> playAgain;

    while (playAgain != 'Y' && playAgain != 'y' && playAgain != 'N' && playAgain != 'n')
    {
        cout << "Invalid input. Please enter Y or N: ";
        cin >> playAgain;
    }

    if (playAgain == 'Y' || playAgain == 'y')
    {
        cout << "Starting a new game...." << endl;
    }
    else
    {
        cout << "Exiting from game...." << endl;
    }
}

void line() {
    cout << "-----------------" << endl;
}

int main()
{

    /*Quiz Game
    • Multiple questions with four options.
    • Track correct/wrong answers and final score .
    • Support multiple categories.
    • Concepts: arrays/vectors, strings, loops, functions*/

    char playAgain;
    // Step 1: Questions

    vector<vector<string>> questions = {
        {"Which language is mainly used for web page structure?",
         "Which data structure follows FIFO?",
         "What does CPU stand for?"},
        {"Which planet is known as the Red Planet?",
         "What gas do humans need to breathe?",
         "What is the boiling point of water at sea level in Celsius?"},
        {"What is the capital city of Pakistan?",
         "How many days are there in a week?",
         "Which is the largest ocean on Earth?"}};

    // Step 2: 4 Options

    vector<vector<vector<string>>> options = {
        {{"A. HTML", "B. CSS", "C. C++", "D. Python"},
         {"A. Stack", "B. Queue", "C. Tree", "D. Graph"},
         {"A. Central Processing Unit", "B. Computer Personal Unit",
          "C. Central Program Utility", "D. Control Processing Unit"}},
        {{"A. Venus", "B. Mars", "C. Jupiter", "D. Mercury"},
         {"A. Nitrogen", "B. Carbon Dioxide", "C. Oxygen", "D. Hydrogen"},
         {"A. 50 degree C", "B. 75 degree C", "C. 100 degree C", "D. 150 degree C"}},
        {{"A. Lahore", "B. Karachi", "C. Islamabad", "D. Peshawar"},
         {"A. 5", "B. 6", "C. 7", "D. 8"},
         {"A. Atlantic Ocean", "B. Indian Ocean", "C. Arctic Ocean", "D. Pacific Ocean"}}};

    // Step 3: Correct Answers

    vector<vector<char>> answers = {
        {'A', 'B', 'A'},
        {'B', 'C', 'C'},
        {'C', 'C', 'D'}};

    // Step 4: Categories

    vector<string> categories = {
        "Computer Science",
        "Science",
        "General Knowledge"};

    // Step 5: Display and select Categories

    do
    {
        int score = 0, wrong = 0;

        cout << "Welcome to the Quiz Game!" << endl;
        cout << "Please select a category:" << endl;

        // Display categories
        displayCategories(categories);

        // Select category
        int categoryChoice;
        selectCategory(categoryChoice, categories);
        line();

        // Step 6: Display questions and options for the selected category

        for (int i = 0; i < questions[categoryChoice - 1].size(); i++)
        {
            cout << "Question " << (i + 1) << ": " << endl;
            cout << questions[categoryChoice - 1][i] << endl;

            // Display options
            for (const auto &option : options[categoryChoice - 1][i])
            {
                cout << option << endl;
            }

            // Input user answer
            char userAnswer;
            inputUserAnswer(userAnswer);

            // Check if the answer is correct
            if (userAnswer == answers[categoryChoice - 1][i])
            {
                cout << "Correct! " << endl;
                score++;
            }
            else
            {
                cout << "Wrong! The correct answer is: " << answers[categoryChoice - 1][i] << endl;
                wrong++;
            }
            line();
        }

        cout << "Your final score is: " << score << "/" << questions[categoryChoice - 1].size() << endl;
        cout << "Wrong answers: " << wrong << endl;
        line();

        // Ask if the user wants to play again
        askToPlayAgain(playAgain);
        line();

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "Thanks for playing Quiz Game!" << endl;
    line();

    return 0;
}
