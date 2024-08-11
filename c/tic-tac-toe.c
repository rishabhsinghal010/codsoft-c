#include <stdio.h>

#define SIZE 3

void printBoard(char board[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) {
            for (int k = 0; k < SIZE; k++) printf("--- ");
            printf("\n");
        }
    }
    printf("\n");
}

int checkWin(char board[SIZE][SIZE], char player) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return 1;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1;
    }

    return 0;
}

int isBoardFull(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    char board[SIZE][SIZE] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int row, col;
    char currentPlayer = 'X';

    while (1) {
        printBoard(board);

        printf("Player %c, enter row and column (0, 1, or 2): ", currentPlayer);
        scanf("%d %d", &row, &col);

        // Check if the input is valid
        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != ' ') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        // Make the move
        board[row][col] = currentPlayer;

        // Check for a win
        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            printf("Player %c wins!\n", currentPlayer);
            break;
        }

        // Check for a draw
        if (isBoardFull(board)) {
            printBoard(board);
            printf("It's a draw!\n");
            break;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}