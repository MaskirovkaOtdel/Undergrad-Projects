#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

// Συνάρτηση για να εκτυπώσουμε τον πίνακα της τρίλιζας
void printBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---|---|---\n");
    }
}

// Συνάρτηση για να ελέγξουμε αν υπάρχει νικητής
int checkWin(char board[SIZE][SIZE], char player) {
    // Έλεγχος γραμμών και στηλών
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return 1;  // Γραμμή
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return 1;  // Στήλη
    }
    // Έλεγχος διαγωνίων
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return 1;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return 1;
    
    return 0;
}

// Συνάρτηση για να ελέγξουμε αν ο πίνακας είναι γεμάτος
int isBoardFull(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ')  // Αν υπάρχει κενό στοιχείο
                return 0;
        }
    }
    return 1;  // Αν δεν υπάρχουν κενά
}

int main() {
    char board[SIZE][SIZE] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int row, col, moves = 0;
    char player = 'X';
    
    while (1) {
        printf("\nPiniakos: \n");
        printBoard(board);

        printf("\nPaiktis %c, dwse thn thesi (grammh, sthlh) gia thn kinisi sou: ", player);
        scanf("%d %d", &row, &col);

        // Έλεγχος εγκυρότητας θέσης
        if (row < 1 || row > SIZE || col < 1 || col > SIZE || board[row - 1][col - 1] != ' ') {
            printf("Lathos kinisi, dokimase xana.\n");
            continue;
        }

        // Κάνουμε την κίνηση
        board[row - 1][col - 1] = player;
        moves++;

        // Έλεγχος νικητή
        if (checkWin(board, player)) {
            printf("\nPiniakos: \n");
            printBoard(board);
            printf("O Paiktis %c nikhse! \n", player);
            break;
        }

        // Έλεγχος αν είναι γεμάτος ο πίνακας (ισόπαλο παιχνίδι)
        if (isBoardFull(board)) {
            printf("\nPiniakos: \n");
            printBoard(board);
            printf("To paixnidi einai isopalo.\n");
            break;
        }

        // Αλλάζουμε παίκτη
        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}
