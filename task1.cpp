#include <iostream>
#include <cstdlib> 
#include <ctime>   

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));
    int secretNumber = rand() % 100 + 1;
    int guess = 0;
    int numberOfTries = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have selected a number between 1 and 100." << endl;
    cout << "Can you guess what it is?" << endl;

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        numberOfTries++;

        if (guess > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Congratulations! You've guessed the correct number in " << numberOfTries << " tries." << endl;
        }
    } while (guess != secretNumber);

    return 0;
}
