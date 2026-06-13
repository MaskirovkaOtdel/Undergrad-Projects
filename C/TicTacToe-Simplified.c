#include <stdio.h>

#define SIZE 3

// Συνάρτηση για να εκτυπώσουμε τον πίνακα
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
int checkWin(char board[SIZE][SIZE]) {
    // Έλεγχος γραμμών, στηλών και διαγωνίων
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') return 1; // Γραμμές
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') return 1; // Στήλες
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') return 1; // Πρώτη διαγώνιος
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') return 1; // Δεύτερη διαγώνιος
    return 0;
}

// Κύριο πρόγραμμα
int main() {
    char board[SIZE][SIZE] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int row, col;
    char player = 'X';

    while (1) {
        printBoard(board);
        printf("Paiktis %c, dwse thn thesi (grammh, sthlh): ", player);
        scanf("%d %d", &row, &col);

        // Έλεγχος εγκυρότητας της θέσης
        if (row < 1 || row > SIZE || col < 1 || col > SIZE || board[row - 1][col - 1] != ' ') {
            printf("Lathos kinisi! Dokimase xana.\n");
            continue;
        }

        // Κίνηση του παίκτη
        board[row - 1][col - 1] = player;

        // Έλεγχος αν κάποιος κέρδισε
        if (checkWin(board)) {
            printBoard(board);
            printf("O Paiktis %c nikise!\n", player);
            break;
        }

        // Αλλαγή παίκτη
        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}
