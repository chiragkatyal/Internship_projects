#include <iostream>

using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE];

void initializeBoard() {
    int counter = 1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '0' + counter++;
        }
    }
}

void printBoard() {
    cout << "\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << " " << board[i][j];
            if (j < SIZE - 1) cout << " |";
        }
        cout << "\n";
        if (i < SIZE - 1) cout << "---|---|---\n";
    }
    cout << "\n";
}

bool checkWin(char mark) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) ||
            (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) ||
        (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark)) {
        return true;
    }
    return false;
}

bool isBoardFull() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

void playerMove(char mark) {
    int move;
    bool validMove = false;

    while (!validMove) {
        cout << "Player " << mark << ", enter your move (1-9): ";
        cin >> move;
        
        if (move < 1 || move > 9) {
            cout << "Invalid move. Please enter a number between 1 and 9.\n";
        } else {
            int row = (move - 1) / SIZE;
            int col = (move - 1) % SIZE;
            
            if (board[row][col] != 'X' && board[row][col] != 'O') {
                board[row][col] = mark;
                validMove = true;
            } else {
                cout << "This spot is already taken. Try again.\n";
            }
        }
    }
}

int main() {
    char playAgain;
    do {
        initializeBoard();
        char currentPlayer = 'X';
        bool gameWon = false;
        bool draw = false;

        while (!gameWon && !draw) {
            printBoard();
            playerMove(currentPlayer);
            gameWon = checkWin(currentPlayer);
            draw = isBoardFull();

            if (gameWon) {
                printBoard();
                cout << "Player " << currentPlayer << " wins!\n";
            } else if (draw) {
                printBoard();
                cout << "It's a draw!\n";
            } else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thank you for playing!\n";
    return 0;
}
