#include <stdio.h>


    char filo;
    int varos;
int main() {

    // Ζητάμε από τον χρήστη να εισάγει το φύλο και το βάρος
    printf("Dwste fylo (A gia andra kai G gia gynaika): ");
    scanf(" %s", &filo);  // Το κενό πριν από το %c αποτρέπει την ανάγνωση του προηγούμενου χαρακτήρα νέας γραμμής.
    
    printf("Dwste to varos: ");
    scanf("%d", &varos);  // Διαβάζουμε το βάρος ως ακέραιο αριθμό

    // Έλεγχος με βάση το φύλο και το βάρος
    if (filo == 'A') {
        if (varos < 60) {
            printf("Adynatos\n");
        } else {
            printf("Kanonikos\n");
        }
    } else if (filo == 'G') {
        if (varos < 75) {
            printf("Adynath\n");
        } else {
            printf("Kanonikh\n");
        }
    } else {
        printf("Agnwsto\n");
    }

    return 0;
}
