#include <stdio.h>
#include <string.h>

#define ROW 11
#define COL 11

void caricaCampoBattagliaNavale (char campoGiocatore [][COL]);
void VisualizzaPartita(char campoGiocatore[][COL], char campoGiocatore2[][COL]);

int main() {
    char CampoGiocatore1[ROW][COL], CampoGiocatore2[ROW][COL];
    caricaCampoBattagliaNavale(CampoGiocatore1);
    caricaCampoBattagliaNavale(CampoGiocatore2);
    VisualizzaPartita(CampoGiocatore1, CampoGiocatore2);
    return 0;
}
void caricaCampoBattagliaNavale (char campoGiocatore[][COL]) {
    int camporighe, campocolonne;
    camporighe = 65;
    campocolonne = 49;
    for(int i = 1; i < ROW; i++) {
        campoGiocatore[0][i] = camporighe;
        camporighe++;
    }
    for(int i = 1; i < COL;  i++){
        campoGiocatore[i][0] = campocolonne;
        campocolonne++;
    }
    for (int i = 1; i < ROW; ++i) {
        for (int j = 1; j < COL; j++) {
            campoGiocatore[i][j] = 219;
        }
    }
}
void VisualizzaPartita(char campoGiocatore[][COL], char campoGiocatore2[][COL]){
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            printf("%3c", campoGiocatore[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            printf("%3c", campoGiocatore2[i][j]);
        }
        printf("\n");
    }

}
