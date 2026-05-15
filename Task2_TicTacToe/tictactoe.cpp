#include <iostream>
#include <algorithm>

char board[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
char player = 'X', ai = 'O';

void displayBoard() {
    std::cout << "\n  " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << std::endl;
    std::cout << " ---+---+---" << std::endl;
    std::cout << "  " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << std::endl;
    std::cout << " ---+---+---" << std::endl;
    std::cout << "  " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n" << std::endl;
}

int checkWinner() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return (board[i][0] == ai) ? 10 : -10;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return (board[0][i] == ai) ? 10 : -10;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return (board[0][0] == ai) ? 10 : -10;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return (board[0][2] == ai) ? 10 : -10;
    return 0;
}

bool isMovesLeft() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O') return true;
    return false;
}

int minimax(int depth, bool isMax) {
    int score = checkWinner();
    if (score == 10 || score == -10) return score;
    if (!isMovesLeft()) return 0;

    if (isMax) {
        int best = -1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] != 'X' && board[i][j] != 'O') {
                    char temp = board[i][j];
                    board[i][j] = ai;
                    best = std::max(best, minimax(depth + 1, false));
                    board[i][j] = temp;
                }
            }
        }
        return best;
    } else {
        int best = 1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] != 'X' && board[i][j] != 'O') {
                    char temp = board[i][j];
                    board[i][j] = player;
                    best = std::min(best, minimax(depth + 1, true));
                    board[i][j] = temp;
                }
            }
        }
        return best;
    }
}

void aiMove() {
    int bestVal = -1000, row = -1, col = -1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                char temp = board[i][j];
                board[i][j] = ai;
                int moveVal = minimax(0, false);
                board[i][j] = temp;
                if (moveVal > bestVal) { row = i; col = j; bestVal = moveVal; }
            }
        }
    }
    board[row][col] = ai;
}

int main() {
    std::cout << "TIC-TAC-TOE AI" << std::endl;
    while (isMovesLeft()) {
        displayBoard();
        int choice;
        std::cout << "Your move (1-9): ";
        std::cin >> choice;
        int r = (choice - 1) / 3, c = (choice - 1) % 3;

        if (choice < 1 || choice > 9 || board[r][c] == 'X' || board[r][c] == 'O') {
            std::cout << "Invalid move! Try again." << std::endl;
            continue;
        }

        board[r][c] = player;
        if (checkWinner() == -10) { displayBoard(); std::cout << "Congrats! You won!"; return 0; }
        if (!isMovesLeft()) break;

        aiMove();
        if (checkWinner() == 10) { displayBoard(); std::cout << "AI wins! Better luck next time."; return 0; }
    }
    displayBoard();
    std::cout << "It's a draw!" << std::endl;
    return 0;
}
