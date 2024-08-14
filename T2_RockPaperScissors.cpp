#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void printMenu() {
    cout << "Choose an option:\n";
    cout << "1. Rock\n";
    cout << "2. Paper\n";
    cout << "3. Scissors\n";
    cout << "4. Quit\n";
}

string getChoiceName(int choice) {
    switch (choice) {
        case 1: return "Rock";
        case 2: return "Paper";
        case 3: return "Scissors";
        default: return "Invalid";
    }
}

int determineWinner(int userChoice, int computerChoice) {
    if (userChoice == computerChoice) {
        return 0; // It's a tie
    } else if ((userChoice == 1 && computerChoice == 3) ||
               (userChoice == 2 && computerChoice == 1) ||
               (userChoice == 3 && computerChoice == 2)) {
        return 1; // User wins
    } else {
        return -1; // Computer wins
    }
}

int main() {
    int userChoice, computerChoice;
    char playAgain;
    
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator
    
    do {
        printMenu();
        cout << "Enter your choice: ";
        cin >> userChoice;
        
        if (userChoice == 4) {
            break;
        }
        
        if (userChoice < 1 || userChoice > 3) {
            cout << "Invalid choice. Please choose between 1 and 3.\n";
            continue;
        }
        
        computerChoice = (rand() % 3) + 1;
        
        cout << "You chose: " << getChoiceName(userChoice) << endl;
        cout << "Computer chose: " << getChoiceName(computerChoice) << endl;
        
        int result = determineWinner(userChoice, computerChoice);
        
        if (result == 0) {
            cout << "It's a tie!\n";
        } else if (result == 1) {
            cout << "You win!\n";
        } else {
            cout << "Computer wins!\n";
        }
        
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
        
    } while (playAgain == 'y' || playAgain == 'Y');
    
    cout << "Thank you for playing!\n";
    return 0;
}
