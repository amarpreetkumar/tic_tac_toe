#include <iostream>
#include <vector>

using namespace std;

// Function to print the Tic-Tac-Toe board
void printBoard(vector<vector<char>>& board) {
    cout << "-------------\n";
    for (int i = 0; i < 3; i++) {
       cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

// Function to check if there's a winner
bool checkWinner(vector<vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check if the board is full
bool isBoardFull(vector<vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); // Initialize the board
    char currentPlayer = 'X'; // Start with player X
    int row, col;

    while (true) {
        printBoard(board);

        // Get input from the current player
        cout << "Player " << currentPlayer << "'s turn. Enter row (0-2) and column (0-2): ";
        cin >> row >> col;

        // Validate the move
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        // Make the move
        board[row][col] = currentPlayer;

        // Check if the current player wins
        if (checkWinner(board, currentPlayer)) {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        // Check if the board is full
        if (isBoardFull(board)) {
            printBoard(board);
            cout << "It's a draw!\n";
            break;
        }

        // Switch player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
