#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 11
#define COL 11

void caricaCampoBattagliaNavale (char campoGiocatore [][COL]);
void VisualizzaPartita(char campoGiocatore[][COL]);
void caricaNavi(char campoGiocatore[][COL]);

int main() {
    char CampoGiocatore1[ROW][COL], CampoGiocatore2[ROW][COL];
    srand(time(NULL));
    caricaCampoBattagliaNavale(CampoGiocatore1);
    caricaCampoBattagliaNavale(CampoGiocatore2);
    caricaNavi(CampoGiocatore1);
    VisualizzaPartita(CampoGiocatore1);
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
void VisualizzaPartita(char campoGiocatore[][COL]){
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            printf("%3c", campoGiocatore[i][j]);
        }
        printf("\n");
    }

}
void caricaNavi(char campoGiocatore[][COL]){
    int i, j;
    char car[] = {'i', 'j'};

    i = 0;
    j = 0;

    if(car[rand()& 2] == 'i'){
        j = rand()%(10 - 1 + 1) + 1;
        do{
            i = rand()%(10 - 1 + 1) + 1;
        } while(i + 5 > 10);

        for(int nav = 0;  nav < 5; nav++){
            campoGiocatore[i][j] = 53;
            i++;
        }
    } else {
        i = rand()%(10 - 1 + 1) + 1;
        do{
            j = rand()%(10 - 1 + 1) + 1;
        } while(j + 5 > 10);
        for(int nav = 0;  nav < 5; nav++){
            campoGiocatore[i][j] = 53;
            j++;
        }
    }

    if(car[rand()& 2] == 'i'){
        j = rand()%(10 - 1 + 1) + 1;
        do{
            i = rand()%(10 - 1 + 1) + 1;
        } while(i + 4 > 10);
        for(int nav = 0;  nav < 4; nav++){
            campoGiocatore[i][j] = 52;
            i++;
        }
    } else {
        i = rand()%(10 - 1 + 1) + 1;
        do{
            j = rand()%(10 - 1 + 1) + 1;
        } while(j + 4 > 10);
        for(int nav = 0;  nav < 4; nav++){
            campoGiocatore[i][j] = 52;
            j++;
        }
    }
}
