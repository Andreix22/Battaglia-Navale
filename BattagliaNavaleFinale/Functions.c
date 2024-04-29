#include "Functions.h"
void caricaCampoBattagliaNavale (char campoGiocatore[][COL]) {
    int camporighe, campocolonne;
    camporighe = 65;
    campocolonne = 49;
    for(int i = 1; i < ROW; i++) { //Riservo la prima colonna per la creazione delle coordinate y
        campoGiocatore[0][i] = camporighe;
        camporighe++;
    }
    for(int i = 1; i < COL;  i++){
        campoGiocatore[i][0] = campocolonne; //Riservo la prima riga per la creazione delle coordinate x
        campocolonne++;
    }
    for (int i = 1; i < ROW; ++i) {
        for (int j = 1; j < COL; j++) { // Genera l'interno nel campo
            campoGiocatore[i][j] = 219;
        }
    }
}
void visualizzaPartita(char campoGiocatore[][COL]){
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            printf("%3c", campoGiocatore[i][j]);
        }
        printf("\n");
    }

}
void generaIndici(char campoGiocatore [][COL], char *carat, int *i, int *j, int dimn, int tp){
    int controllo;

    char car[] = {'i', 'j'};


    do {
        *carat = car[rand() % 2];
        controllo = 0;

        srand(time(NULL));

        *i = rand() % (10 - 1 + 1) + 1; // Genero casualmente la posizione della nave
        *j = rand() % (10 - 1 + 1) + 1;


        if (*carat == 'i') { //Distinguo i controlli in base a se la nave è disposta in orizzontale o verticale

            if (*i + dimn > 10) { // Controllo che la nave non esca dai bordi del campo
                controllo = 1;
            }
            for(int k = 0; k < dimn ; k++){
                if(campoGiocatore[*i + k][*j] == 'N'){ // Controllo che le navi non si sovrappongono tra di loro
                    controllo = 1;
                }
            }

            if(tp == 2) { // Nel caso l'utente abbia scelto di generare le navi con contorni

                if (campoGiocatore[*i - 1][*j] == 'N' || campoGiocatore[*i + dimn][*j] == 'N') { // Controllo che ci sia un blocco in alto e in basso di mare di distanza tra un nave e l'altra
                    controllo = 1;
                }


                for (int k = 0; k < dimn; k++) {
                    if (campoGiocatore[*i + k][*j + 1] == 'N' || campoGiocatore[*i + k][*j - 1] == 'N') { // Controllo che ci sia uno spazio a destra e a sinistra di distanza tra un nave e l'altra
                        controllo = 1;
                    }
                }
            }
        } else { //Distinguo i controlli in base a se la nave è disposta in orizzontale o verticale

            if (*j + dimn > 10) { // Controllo che la nave non esca dai bordi del campo
                controllo = 1;
            }
            for (int k = 0; k < dimn; k++) {
                if (campoGiocatore[*i][*j + k] == 'N') { // Controllo che le navi non si sovrappongono tra di loro
                    controllo = 1;
                }
            }

            if(tp == 2) { // Nel caso l'utente abbia scelto di generare le navi con contorni

                if (campoGiocatore[*i][*j - 1] == 'N' || campoGiocatore[*i][*j + dimn] == 'N') { // Controllo che ci sia un blocco in alto e in basso di mare di distanza tra un nave e l'altra

                    controllo = 1;
                }

                for (int k = 0; k < dimn; k++) {
                    if (campoGiocatore[*i + 1][*j + k] == 'N' || campoGiocatore[*i - 1][*j + k] == 'N') { // Controllo che ci sia uno spazio a destra e a sinistra di distanza tra un nave e l'altra
                        controllo = 1;
                    }
                }
            }
        }
    }while(controllo == 1);
}

void caricaNaviCasuale(char campoGiocatore[][COL], int tipopiazz){
    int i, j, dimnav = 1, connav = 'N';
    char cont;

    srand(time(NULL));

    for (int numnav = 0; numnav < 8; numnav++) {
        if(numnav == 1 || numnav == 3 || numnav == 5 || numnav == 7){ //Carica navi di lunghezze diverse in base all'avanzare del contatore
            dimnav++;

        }
        generaIndici(campoGiocatore, &cont, &i, &j, dimnav, tipopiazz); //Genera le posizioni delle navi secondo i criteri stabiliti all'inizio del programma

        if(cont == 'i'){ //Piazzo la nave in orizzontale o in verticale in base al carattere assegnato casualmente a cont
            for (int nav = 0; nav < dimnav; nav++) {
                campoGiocatore[i][j] = connav;
                i++;
            }
        } else {
            for (int nav = 0; nav < dimnav; nav++) {
                campoGiocatore[i][j] = connav;
                j++;
            }
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


void m_PlvsPl(char campoGiocatore1[][COL], char campoGiocatore2[][COL]){
    while(1) {
        printf("Turno del Giocatore 1:");
        printf("\n");
        visualizzaPartita(campoGiocatore2);
        attaccoGiocatore(campoGiocatore2);
        visualizzaPartita(campoGiocatore2);
        system("PAUSE");
        if(numeroNavi(campoGiocatore2) == 0){ //Rompe il ciclo nel caso non vengono rilevate navi nel campo
            break;
        }
        printf("Turno del Giocatore 2:");
        printf("\n");
        visualizzaPartita(campoGiocatore1);
        attaccoGiocatore(campoGiocatore1);
        visualizzaPartita(campoGiocatore1);
        system("PAUSE");
        if(numeroNavi(campoGiocatore1) == 0){ //Rompe il ciclo nel caso non vengono rilevate navi nel campo
            break;
        }
    }
    if(numeroNavi(campoGiocatore2) == 0){ // Decreta se ha vinto il giocatore 1 (campogiocatore2) o il giocatore 2 (campogiocatore1)
        printf("\nIl Giocatore Uno ha Vinto!");
        printf("\nForza Catania");
    } else {
        printf("\nIl Giocatore Due ha Vinto!");
        printf("\nSchifo Palermo");
    }
}

void m_PlvsBot(char campoGiocatore1[][COL], char campoGiocatore2[][COL]){


    while(1) {
        printf("Turno del Giocatore 1:");
        printf("\n");
        visualizzaPartita(campoGiocatore2);
        attaccoGiocatore(campoGiocatore2);
        visualizzaPartita(campoGiocatore2);
        system("PAUSE");
        if(numeroNavi(campoGiocatore2) == 0){ //Rompe il ciclo nel caso non vengono rilevate navi nel campo
            break;
        }
        printf("Turno del Bot:");
        printf("\n");
        visualizzaPartita(campoGiocatore1);
        attaccoGiocatoreAutomatico(campoGiocatore1);
        visualizzaPartita(campoGiocatore1);
        system("PAUSE");
        if(numeroNavi(campoGiocatore1) == 0){ //Rompe il ciclo nel caso non vengono rilevate navi nel campo
            break;
        }
    }
    if(numeroNavi(campoGiocatore2) == 0){ // Decreta se ha vinto il giocatore 1 (campogiocatore2) o il giocatore 2 (campogiocatore1)
        printf("\nIl Giocatore Uno ha Vinto!");
        printf("\nForza Catania");
    } else {
        printf("\nIl Bot ha Vinto!");
        printf("\nSchifo Palermo");
    }
}

void m_BotvsBot(char campoGiocatore1[][COL], char campoGiocatore2[][COL]){
    while(1) {
        printf("Turno del Bot 1:");
        printf("\n");
        visualizzaPartita(campoGiocatore2);
        attaccoGiocatoreAutomatico(campoGiocatore2);
        visualizzaPartita(campoGiocatore2);
        system("PAUSE");
        if(numeroNavi(campoGiocatore2) == 0){ //Rompe il ciclo nel caso non vengono rilevate navi nel campo
            break;
        }
        printf("Turno del Bot 2:");
        printf("\n");
        visualizzaPartita(campoGiocatore1);
        attaccoGiocatoreAutomatico(campoGiocatore1);
        visualizzaPartita(campoGiocatore1);
        system("PAUSE");
        if(numeroNavi(campoGiocatore1) == 0){ //Rompe il ciclo nel caso non vengono rilevate navi nel campo
            break;
        }
    }
    if(numeroNavi(campoGiocatore2) == 0){ // Decreta se ha vinto il giocatore 1 (campogiocatore2) o il giocatore 2 (campogiocatore1)
        printf("\nIl Giocatore Bot Uno ha Vinto!");
        printf("\nForza Catania");
    } else {
        printf("\nIl Bot Due ha Vinto!");
        printf("\nSchifo Palermo");
    }
}

int numeroNavi(char campoGiocatore[][COL]){
    int nnav;
    nnav = 0;
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            if(campoGiocatore[i][j] == 'N'){ //Scansiona ogni blocco della matrice per cercare un pezzo di nave
                nnav++;
            }
        }
    }
    return nnav;
}
void attaccoGiocatore(char campoGiocatore[][COL]){
    int cr;
    char cc;
    do {

        do {
            getchar();
            printf("Inserire la colonna (in maiuscolo) in cui si vuole eseguire l'attacco: ");
            scanf("%c", &cc);
        } while (cc < 'A' || cc > 'J');

        switch (cc) { // Converte la lettera in numero per essere interpretata dall'algoritmo
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
    }while(campoGiocatore[cr][cc] == 'X' || campoGiocatore[cr][cc] == 'O' ); // Riesegue l'algoritmo affinché l'attacco non venga eseguito correttamente

    if (campoGiocatore[cr][cc] == 'N') {
        printf("\nHai preso una nave!\n");
        campoGiocatore[cr][cc] = 'X';
    } else {
        printf("\nHai preso l'oceano!\n");
        campoGiocatore[cr][cc] = 'O';
    }

}
void attaccoGiocatoreAutomatico(char campoGiocatore[][COL]){
    int cr;
    char cc;
    do {
        cr = rand() % (10 - 1 + 1) + 1; // Esegue casualmente le coordinate dell'attacco
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