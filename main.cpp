#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <limits>

using namespace std;

bool numberGuessingGame() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;
    int attempts = 0;
    int guess;
    
    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I'm thinking of a number between 1 and 100." << endl;
    
    while (true) {
        cout << "Enter your guess: ";
        cin >> guess;
        
        // Check for invalid input
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid number." << endl;
            continue;
        }
        
        attempts++;
        
        if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else if (guess > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You've guessed the number " << secretNumber << " correctly!" << endl;
            cout << "It took you " << attempts << " attempts." << endl;
            break;
        }
    }
    
    string playAgain;
    cout << "Do you want to play again? (yes/no): ";
    cin >> playAgain;
    
    return (playAgain == "yes" || playAgain == "Yes" || playAgain == "YES");
}

int main() {
    while (numberGuessingGame()) {
        // Continue playing
    }
    
    cout << "Thanks for playing! Goodbye!" << endl;
    return 0;
}