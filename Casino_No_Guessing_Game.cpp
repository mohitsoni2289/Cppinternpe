#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int playerBalance = 1000; // Starting balance for the player

    cout << "Welcome to the Casino Number Guessing Game!" << endl;
    cout << "You have a starting balance of $" << playerBalance << "." << endl;

    while (playerBalance > 0) {
        int chosenNumber;
        char guess;
        int bet;

        cout << "Choose a number between 1 and 100: ";
        cin >> chosenNumber;

        if (chosenNumber < 1 || chosenNumber > 100) {
            cout << "Invalid choice. Please choose a number between 1 and 100." << endl;
            continue;
        }

        cout << "Place your bet: $";
        cin >> bet;

        if (bet <= 0 || bet > playerBalance) {
            cout << "Invalid bet amount. Your current balance is $" << playerBalance << "." << endl;
            continue;
        }

        cout << "Will the rolled number be higher (H) or lower (L) than " << chosenNumber << "? ";
        cin >> guess;

        int rolledNumber = rand() % 100 + 1;
        cout << "The rolled number is: " << rolledNumber << endl;

        if ((guess == 'H' && rolledNumber > chosenNumber) || (guess == 'L' && rolledNumber < chosenNumber)) {
            cout << "Congratulations! You win $" << bet << "." << endl;
            playerBalance += bet;
        } else {
            cout << "Sorry, you lose $" << bet << "." << endl;
            playerBalance -= bet;
        }

        cout << "Your current balance: $" << playerBalance << endl;

        char playAgain;
        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;

        if (playAgain == 'N' || playAgain == 'n') {
            cout << "Thank you for playing!" << endl;
            break;
        }
    }

    if (playerBalance <= 0) {
        cout << "Oops! You've run out of money. Better luck next time!" << endl;
    }

    return 0;
}
