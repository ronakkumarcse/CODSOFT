#include <iostream>
#include <cstdlib> 
#include <ctime>  
using namespace std;
int main() {
    int number, guess, attempts = 0;
    srand(time(0));
    number = rand() % 100 + 1;

    cout << " Welcome to the Number Guessing Game!" << endl;
    cout << "I have chosen a number between 1 and 50." << endl;
    cout << "Can you guess it?" << endl;
    do {
        cout << "\nEnter your guess: ";
        cin >> guess;
        attempts++;
        if (guess > number) {
            cout << "Too big! Try again.";
        } else if (guess < number) {
            cout << "Too small! Try again.";
        } else {
            cout << " Congratulations! You guessed the number in " 
                 << attempts << " attempts." << endl;
        }
    } while (guess != number);
    return 0;
}
