#include <stdio.h>

#define ROW 10
#define COL 10

void caricaCampoBattagliaNavale (char campoGiocatore [][COL]);
void VisualizzaPartita(char campoGiocatore[][COL]);

int main() {
    char CampoGiocatore1, CampoGiocatore2;
    caricaCampoBattagliaNavale(CampoGiocatore1);
    VisualizzaPartita(CampoGiocatore1);
    return 0;
}
void caricaCampoBattaliaNavale (char campoGiocatore[][COL]) {
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; j++) {
            campoGiocatore[i][j] = 'O';
        }
    }
}
void VisualizzaPartita(char campoGiocatore[][COL]){
        for(int i = 0; i < ROW; i++){
            for(int j = 0; j < COL; j++){
                printf("%c\t", campoGiocatore[i][j]);
            }
            printf("\n");
        }
    }

