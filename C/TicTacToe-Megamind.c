#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define COMPUTER 1
#define HUMAN 2
#define SIDE 3
#define COMPUTERMOVE 'O'
#define HUMANMOVE 'X'

struct Move {
    int row, col;
};

char player = 'X', opponent = 'O';

// Δηλώσεις για τις συναρτήσεις που ελέγχουν τις γραμμές, στήλες και διαγωνίους
int rowCrossed(char board[3][3]);
int columnCrossed(char board[3][3]);
int diagonalCrossed(char board[3][3]);

// Εξέταση κινήσεων και έλεγχος αν υπάρχουν ελεύθερα κελιά
bool isMovesLeft(char board[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == '_')
                return true;
    return false;
}

// Αξιολόγηση του πίνακα (Win: +10, Loss: -10, Tie: 0)
int evaluate(char b[3][3]) {
    for (int row = 0; row < 3; row++) {
        if (b[row][0] == b[row][1] && b[row][1] == b[row][2]) {
            if (b[row][0] == player)
                return +10;
            else if (b[row][0] == opponent)
                return -10;
        }
    }

    for (int col = 0; col < 3; col++) {
        if (b[0][col] == b[1][col] && b[1][col] == b[2][col]) {
            if (b[0][col] == player)
                return +10;
            else if (b[0][col] == opponent)
                return -10;
        }
    }

    if (b[0][0] == b[1][1] && b[1][1] == b[2][2]) {
        if (b[0][0] == player)
            return +10;
        else if (b[0][0] == opponent)
            return -10;
    }
    if (b[0][2] == b[1][1] && b[1][1] == b[2][0]) {
        if (b[0][2] == player)
            return +10;
        else if (b[0][2] == opponent)
            return -10;
    }

    return 0;
}

// Αλγόριθμος Minimax με Alpha-Beta Pruning
int minimax(char board[3][3], int depth, bool isMax, int alpha, int beta, int difficulty) {
    int score = evaluate(board);

    if (score == 10) return score;
    if (score == -10) return score;
    if (isMovesLeft(board) == false) return 0;

    if (isMax) {
        int best = -1000;

        if (difficulty == 1 && depth > 3) return 0; // Εύκολο επίπεδο
        if (difficulty == 2 && depth > 4) return 0; // Μέτριο επίπεδο

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == '_') {
                    board[i][j] = player;
                    best = (best > minimax(board, depth + 1, !isMax, alpha, beta, difficulty)) ? best : minimax(board, depth + 1, !isMax, alpha, beta, difficulty);
                    board[i][j] = '_';
                    alpha = (alpha > best) ? alpha : best;
                    if (beta <= alpha) return best;
                }
            }
        }
        return best;
    } else {
        int best = 1000;

        if (difficulty == 1 && depth > 3) return 0;
        if (difficulty == 2 && depth > 4) return 0;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == '_') {
                    board[i][j] = opponent;
                    best = (best < minimax(board, depth + 1, !isMax, alpha, beta, difficulty)) ? best : minimax(board, depth + 1, !isMax, alpha, beta, difficulty);
                    board[i][j] = '_';
                    beta = (beta < best) ? beta : best;
                    if (beta <= alpha) return best;
                }
            }
        }
        return best;
    }
}

// Βρίσκουμε την καλύτερη κίνηση για τον υπολογιστή
struct Move findBestMove(char board[3][3], int difficulty) {
    struct Move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;

    if (difficulty == 1) {
        int availableMoves[9];
        int count = 0;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == '_') {
                    availableMoves[count++] = i * 3 + j;
                }
            }
        }

        if (count > 0) {
            int randomIndex = rand() % count;
            bestMove.row = availableMoves[randomIndex] / 3;
            bestMove.col = availableMoves[randomIndex] % 3;
        }
    } else {
        int bestVal = -1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == '_') {
                    board[i][j] = player;
                    int moveVal = minimax(board, 0, false, -1000, 1000, difficulty);
                    board[i][j] = '_';
                    if (moveVal > bestVal) {
                        bestMove.row = i;
                        bestMove.col = j;
                        bestVal = moveVal;
                    }
                }
            }
        }
    }
    return bestMove;
}

// Προβολή του πίνακα
void showBoard(char board[3][3]) {
    printf("\n\n");
    printf("\t\t\t %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("\t\t\t--------------\n");
    printf("\t\t\t %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("\t\t\t--------------\n");
    printf("\t\t\t %c | %c | %c \n\n", board[2][0], board[2][1], board[2][2]);
}

// Δήλωση του νικητή
void declareWinner(int whoseTurn) {
    if (whoseTurn == COMPUTER)
        printf("COMPUTER has won\n");
    else
        printf("HUMAN has won\n");
}

// Ελέγχει αν το παιχνίδι έχει τελειώσει
int gameOver(char board[3][3]) {
    return (rowCrossed(board) || columnCrossed(board) || diagonalCrossed(board));
}

// Έλεγχος αν υπάρχει νίκη σε κάποια γραμμή
int rowCrossed(char board[3][3]) {
    for (int i = 0; i < SIDE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') return 1;
    }
    return 0;
}

// Έλεγχος αν υπάρχει νίκη σε κάποια στήλη
int columnCrossed(char board[3][3]) {
    for (int i = 0; i < SIDE; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') return 1;
    }
    return 0;
}

// Έλεγχος αν υπάρχει νίκη σε κάποια διαγώνιο
int diagonalCrossed(char board[3][3]) {
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        || (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' '))
        return 1;
    return 0;
}

// Αρχικοποίηση του παιχνιδιού
void initialise(char board[3][3], int moves[]) {
    srand(time(NULL));
    for (int i = 0; i < SIDE; i++) {
        for (int j = 0; j < SIDE; j++)
            board[i][j] = '_';
    }
    for (int i = 0; i < SIDE * SIDE; i++) {
        moves[i] = i;
    }
}

// Παίξτε το Tic-Tac-Toe με επίπεδο δυσκολίας
void playTicTacToe(int whoseTurn, int difficulty) {
    char board[SIDE][SIDE];
    int moves[SIDE * SIDE];
    int moveIndex = 0;
    initialise(board, moves);
    showBoard(board);

    while (!gameOver(board) && moveIndex < SIDE * SIDE) {
        int row, col;

        // Αν είναι η σειρά του υπολογιστή
        if (whoseTurn == COMPUTER) {
            struct Move bestMove = findBestMove(board, difficulty);
            row = bestMove.row;
            col = bestMove.col;
            board[row][col] = COMPUTERMOVE;
            moveIndex++;
            showBoard(board);
            if (gameOver(board)) {
                declareWinner(COMPUTER);
                return;
            }
            whoseTurn = HUMAN;
        } else { // Αν είναι η σειρά του παίκτη
            printf("Your move (1-9): ");
            int choice;
            scanf("%d", &choice);
            choice--;
            row = choice / 3;
            col = choice % 3;
            if (board[row][col] != '_') {
                printf("Cell already taken. Try again.\n");
            } else {
                board[row][col] = HUMANMOVE;
                moveIndex++;
                showBoard(board);
                if (gameOver(board)) {
                    declareWinner(HUMAN);
                    return;
                }
                whoseTurn = COMPUTER;
            }
        }
    }

    if (moveIndex == SIDE * SIDE) {
        printf("Game Draw\n");
    }
}
