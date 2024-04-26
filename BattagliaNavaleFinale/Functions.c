#include "Functions.h"
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
void caricaNaviCasuale(char campoGiocatore[][COL]){
    int i, j;
    char car[] = {'i', 'j'};

    srand(time(NULL));

    i = 0;
    j = 0;

    if(car[rand()& 2] == 'i'){
        j = rand()%(10 - 1 + 1) + 1;
        do{
            i = rand()%(10 - 1 + 1) + 1;
        } while(i + 5 > 10);

        for(int nav = 0;  nav < 5; nav++){
            campoGiocatore[i][j] = 'N';
            i++;
        }
    } else {
        i = rand()%(10 - 1 + 1) + 1;
        do{
            j = rand()%(10 - 1 + 1) + 1;
        } while(j + 5 > 10);
        for(int nav = 0;  nav < 5; nav++){
            campoGiocatore[i][j] = 'N';
            j++;
        }
    }
    for(int nav = 0; nav < 2; nav++) {
        if (car[rand() & 2] == 'i') {
            j = rand() % (10 - 1 + 1) + 1;
            do {
                i = rand() % (10 - 1 + 1) + 1;
            } while (i + 4 > 10);
            for (int nav = 0; nav < 4; nav++) {
                campoGiocatore[i][j] = 'N';
                i++;
            }
        } else {
            i = rand() % (10 - 1 + 1) + 1;
            do {
                j = rand() % (10 - 1 + 1) + 1;
            } while (j + 4 > 10);
            for (int nav = 0; nav < 4; nav++) {
                campoGiocatore[i][j] = 'N';
                j++;
            }
        }
    }
    for(int nav = 0; nav < 2; nav++) {
        if (car[rand() & 2] == 'i') {
            j = rand() % (10 - 1 + 1) + 1;
            do {
                i = rand() % (10 - 1 + 1) + 1;
            } while (i + 3 > 10);
            for (int nav = 0; nav < 3; nav++) {
                campoGiocatore[i][j] = 'N';
                i++;
            }
        } else {
            i = rand() % (10 - 1 + 1) + 1;
            do {
                j = rand() % (10 - 1 + 1) + 1;
            } while (j + 3 > 10);
            for (int nav = 0; nav < 3; nav++) {
                campoGiocatore[i][j] = 'N';
                j++;
            }
        }
    }
    for(int nav = 0; nav < 2; nav++) {
        if (car[rand() & 2] == 'i') {
            j = rand() % (10 - 1 + 1) + 1;
            do {
                i = rand() % (10 - 1 + 1) + 1;
            } while (i + 2 > 10);
            for (int nav = 0; nav < 2; nav++) {
                campoGiocatore[i][j] = 'N';
                i++;
            }
        } else {
            i = rand() % (10 - 1 + 1) + 1;
            do {
                j = rand() % (10 - 1 + 1) + 1;
            } while (j + 2 > 10);
            for (int nav = 0; nav < 2; nav++) {
                campoGiocatore[i][j] = 'N';
                j++;
            }
        }
    }

    if (car[rand() & 2] == 'i') {
        j = rand() % (10 - 1 + 1) + 1;
        do {
            i = rand() % (10 - 1 + 1) + 1;
        } while (i + 1 > 10);
        for (int nav = 0; nav < 1; nav++) {
            campoGiocatore[i][j] = 'N';
            i++;
        }
    } else {
        i = rand() % (10 - 1 + 1) + 1;
        do {
            j = rand() % (10 - 1 + 1) + 1;
        } while (j + 1 > 10);
        for (int nav = 0; nav < 1; nav++) {
            campoGiocatore[i][j] = 'N';
            j++;
        }
    }

}
void caricaNaviManuale(char campoGiocatore[][COL]) {
    int navi[] = {5, 4, 3, 3, 2};  // dimensione delle navi
    int numNavi = sizeof(navi) / sizeof(navi[0]);
    char direction, colonna;
    int riga;
    int dimensioneNave;
    int valido;
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            printf("%3c", campoGiocatore[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < numNavi; i++) {
        dimensioneNave = navi[i];
        valido = 0;

        while (!valido) {
            valido = 1;

            printf("\nInserisci la riga per la nave di dimensione %d (1-10): ", dimensioneNave);
            scanf("%d", &riga);

            printf("\nInserisci la colonna per la nave di dimensione %d (1-10): ", dimensioneNave);
            scanf("%c", &colonna);

            printf("\nScegli la direzione (h per orizzontale, v per verticale): ");
            scanf(" %c", &direction);

            if ((riga < 1 || riga > 10) || (colonna < 'A' || colonna > 'J')) {
                printf("Riga o colonna fuori dai limiti. Riprova.\n");
                valido = 0;
                continue;
            }
            switch(colonna){
                case 'A':
                    colonna = 1;
                    break;
                case 'B':
                    colonna = 2;
                    break;
                case 'C':
                    colonna = 3;
                    break;
                case 'D':
                    colonna = 4;
                    break;
                case 'E':
                    colonna = 5;
                    break;
                case 'F':
                    colonna = 6;
                    break;
                case 'G':
                    colonna = 7;
                    break;
                case 'H':
                    colonna = 8;
                    break;
                case 'I':
                    colonna = 9;
                    break;
                case 'J':
                    colonna = 10;
                    break;
            }
            // verifica se va oltre i bordi della griglia
            if ((direction == 'h' && colonna + dimensioneNave - 1 > 10) ||
                (direction == 'v' && riga + dimensioneNave - 1 > 10)) {
                printf("La nave va oltre il bordo della griglia. Riprova.\n");
                valido = 0;
            }

            // verifica delle sovrapposizioni
            if (valido && direction == 'h') {
                for (int j = 0; j < dimensioneNave; j++) {
                    if (campoGiocatore[riga][colonna + j] != 219) {
                        printf("La nave si sovrappone ad un'altra nave. Riprova.\n");
                        valido = 0;
                        break;
                    }
                }
            } else if (valido && direction == 'v') {
                for (int j = 0; j < dimensioneNave; j++) {
                    if (campoGiocatore[riga + j][colonna] != 219) {
                        printf("La nave si sovrappone ad un'altra nave. Riprova.\n");
                        valido = 0;
                        break;
                    }
                }
            }

            if (valido) {
                if (direction == 'h') {
                    for (int j = 0; j < dimensioneNave; j++) {
                        campoGiocatore[riga][colonna + j] = 'S';  // 'S' per nave
                    }
                } else if (direction == 'v') {
                    for (int j = 0; j < dimensioneNave; j++) {
                        campoGiocatore[riga + j][colonna] = 'S';  // 'S' per nave
                    }
                }
            }
        }
    }
}


void M_PlvsPl(char campoGiocatore1[][COL], char campoGiocatore2[][COL]){
    while(1) {
        printf("Turno del Giocatore 1:");
        printf("\n");
        VisualizzaPartita(campoGiocatore2);
        AttaccoGiocatore(campoGiocatore2);
        VisualizzaPartita(campoGiocatore2);
        system("PAUSE");
        if(NumeroNavi(campoGiocatore2) == 0){
            break;
        }
        printf("Turno del Giocatore 2:");
        printf("\n");
        VisualizzaPartita(campoGiocatore1);
        AttaccoGiocatore(campoGiocatore1);
        VisualizzaPartita(campoGiocatore1);
        system("PAUSE");
        if(NumeroNavi(campoGiocatore1) == 0){
            break;
        }
    }
    if(NumeroNavi(campoGiocatore2) == 0){
        printf("\nIl Giocatore Uno ha Vinto!");
        printf("\nForza Catania");
    } else {
        printf("\nIl Giocatore Due ha Vinto!");
        printf("\nSchifo Palermo");
    }
}

void M_PlvsBot(char campoGiocatore1[][COL], char campoGiocatore2[][COL]){


    while(1) {
        printf("Turno del Giocatore 1:");
        printf("\n");
        VisualizzaPartita(campoGiocatore2);
        AttaccoGiocatore(campoGiocatore2);
        VisualizzaPartita(campoGiocatore2);
        system("PAUSE");
        if(NumeroNavi(campoGiocatore2) == 0){
            break;
        }
        printf("Turno del Bot:");
        printf("\n");
        VisualizzaPartita(campoGiocatore1);
        AttaccoGiocatoreAutomatico(campoGiocatore1);
        VisualizzaPartita(campoGiocatore1);
        system("PAUSE");
        if(NumeroNavi(campoGiocatore1) == 0){
            break;
        }
    }
    if(NumeroNavi(campoGiocatore2) == 0){
        printf("\nIl Giocatore Uno ha Vinto!");
        printf("\nForza Catania");
    } else {
        printf("\nIl Bot ha Vinto!");
        printf("\nSchifo Palermo");
    }
}

void M_BotvsBot(char campoGiocatore1[][COL], char campoGiocatore2[][COL]){
    while(1) {
        printf("Turno del Bot 1:");
        printf("\n");
        VisualizzaPartita(campoGiocatore2);
        AttaccoGiocatoreAutomatico(campoGiocatore2);
        VisualizzaPartita(campoGiocatore2);
        system("PAUSE");
        if(NumeroNavi(campoGiocatore2) == 0){
            break;
        }
        printf("Turno del Bot 2:");
        printf("\n");
        VisualizzaPartita(campoGiocatore1);
        AttaccoGiocatoreAutomatico(campoGiocatore1);
        VisualizzaPartita(campoGiocatore1);
        system("PAUSE");
        if(NumeroNavi(campoGiocatore1) == 0){
            break;
        }
    }
    if(NumeroNavi(campoGiocatore2) == 0){
        printf("\nIl Giocatore Bot Uno ha Vinto!");
        printf("\nForza Catania");
    } else {
        printf("\nIl Bot Due ha Vinto!");
        printf("\nSchifo Palermo");
    }
}

int NumeroNavi(char campoGiocatore[][COL]){
    int nnav;
    nnav = 0;
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            if(campoGiocatore[i][j] == 'N'){
                nnav++;
            }
        }
    }
    return nnav;
}
void AttaccoGiocatore(char campoGiocatore[][COL]){
    int cr;
    char cc;
    do {

        do {
            getchar();
            printf("Inserire la colonna (in maiuscolo) in cui si vuole eseguire l'attacco: ");
            scanf("%c", &cc);
        } while (cc < 'A' || cc > 'J');

        switch (cc) {
            case 'A':
                cc = 1;
                break;
            case 'B':
                cc = 2;
                break;
            case 'C':
                cc = 3;
                break;
            case 'D':
                cc = 4;
                break;
            case 'E':
                cc = 5;
                break;
            case 'F':
                cc = 6;
                break;
            case 'G':
                cc = 7;
                break;
            case 'H':
                cc = 8;
                break;
            case 'I':
                cc = 9;
                break;
            case 'J':
                cc = 10;
                break;
        }

        do {
            getchar();
            printf("Inserire la riga in cui si vuole eseguire l'attacco: ");
            scanf("%d", &cr);
        } while (cr < 1 || cr > 10);
    }while(campoGiocatore[cr][cc] == 'X' || campoGiocatore[cr][cc] == 'O' );

    if (campoGiocatore[cr][cc] == 'N') {
        printf("\nHai preso una nave!\n");
        campoGiocatore[cr][cc] = 'X';
    } else {
        printf("\nHai preso l'oceano!\n");
        campoGiocatore[cr][cc] = 'O';
    }

}
void AttaccoGiocatoreAutomatico(char campoGiocatore[][COL]){
    int cr;
    char cc;
    do {
        cr = rand() % (10 - 1 + 1) + 1;
        cc = rand() % (10 - 1 + 1) + 1;
    } while(campoGiocatore[cr][cc] == 'X' || campoGiocatore[cr][cc] == 'O' );
    if(campoGiocatore[cr][cc] == 'N'){
        printf("\nHai preso una nave!\n");
        campoGiocatore[cr][cc] = 'X';
    } else {
        printf("\nHai preso l'oceano!\n");
        campoGiocatore[cr][cc] = 'O';
    }
}