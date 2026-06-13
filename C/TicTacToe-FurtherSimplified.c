#include <stdio.h>

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}; 
    int row, col;
    char player = 'X';

    while (1) {
        // Print the board
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                printf(" %c ", board[i][j]);
                if (j < 2) printf("|");
            }
            printf("\n");
            if (i < 2) printf("-----------\n");
        }

        printf("Paiktis %c, dwse thesh (grammh, sthlh): ", player);
        scanf("%d %d", &row, &col);

        // Input validation
        if (row < 1 || row > 3 || col < 1 || col > 3) {
            printf("Lathos: H thesi einai ektos twn oriwn tou pinaka. Dokimase xana.\n");
            continue;
        }
        if (board[row-1][col-1] != ' ') {
            printf("Lathos: H thesh einai hdh kathlhmenh. Dokimase xana.\n");
            continue;
        }

        // Make the move
        board[row-1][col-1] = player;

        // Check for a win only after each move
        int winner_found = 0;

        // Check rows and columns
        for (int i = 0; i < 3; i++) {
            if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') || 
                (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')) { 
                winner_found = 1;
                break;
            }
        }

        // Check diagonals
        if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||  
            (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')) {  
            winner_found = 1;
        }

        if (winner_found) {
            // Print final board
            printf("\n");
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    printf(" %c ", board[i][j]);
                    if (j < 2) printf("|");
                }
                printf("\n");
                if (i < 2) printf("-----------\n");
            }
            printf("Paiktis %c nikhse!\n", player);
            return 0;
        }

        // Switch player
        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}
