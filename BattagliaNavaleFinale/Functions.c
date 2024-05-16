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
    campoGiocatore[10][0] = '10';
    for (int i = 1; i < ROW; ++i) {
        for (int j = 1; j < COL; j++) { // Genera l'interno nel campo
            campoGiocatore[i][j] = 219;
        }
    }
}
void visualizzaPartita(char campoGiocatore[][COL]){
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            printf("%3c", campoGiocatore[i][j]); //Stampa ogni blocco del campo
        }
        printf("\n");
    }

}
void generaIndici(char campoGiocatore [][COL], char *carat, int *i, int *j, int dimn, int tp){
    int controllo;

    char car[] = {'i', 'j'};


    do {
        *carat = car[rand() % 2]; //Decide in modo casuale se generare la nave in verticale o in orizzontale
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

            if(tp == 2 || tp == 3) { // Nel caso l'utente abbia scelto di generare le navi con contorni

                if (campoGiocatore[*i - 1][*j] == 'N' || campoGiocatore[*i + dimn][*j] == 'N') { // Controllo che ci sia un blocco in alto e in basso di mare di distanza tra un nave e l'altra
                    controllo = 1;
                }


                for (int k = 0; k < dimn; k++) {
                    if (campoGiocatore[*i + k][*j + 1] == 'N' || campoGiocatore[*i + k][*j - 1] == 'N') { // Controllo che ci sia uno spazio a destra e a sinistra di distanza tra un nave e l'altra
                        controllo = 1;
                    }
                }
                if(tp == 3){
                    if(campoGiocatore[*i - 1][*j - 1] == 'N' || campoGiocatore[*i - 1][*j + 1] == 'N' || campoGiocatore[*i + dimn][*j - 1] == 'N' || campoGiocatore[*i + dimn][*j + 1] == 'N' ){
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

            if(tp == 2 || tp == 3) { // Nel caso l'utente abbia scelto di generare le navi con contorni

                if (campoGiocatore[*i][*j - 1] == 'N' || campoGiocatore[*i][*j + dimn] == 'N') { // Controllo che ci sia un blocco in alto e in basso di mare di distanza tra un nave e l'altra

                    controllo = 1;
                }

                for (int k = 0; k < dimn; k++) {
                    if (campoGiocatore[*i + 1][*j + k] == 'N' || campoGiocatore[*i - 1][*j + k] == 'N') { // Controllo che ci sia uno spazio a destra e a sinistra di distanza tra un nave e l'altra
                        controllo = 1;
                    }
                }
                if(tp == 3){
                    if(campoGiocatore[*i - 1][*j - 1] == 'N' || campoGiocatore[*i + 1][*j - 1] == 'N' || campoGiocatore[*i - 1][*j + dimn] == 'N' || campoGiocatore[*i + 1][*j + dimn] == 'N' ){
                        controllo = 1;
                    }
                }
            }
        }
    }while(controllo == 1); //Ripete il ciclo fin quando "controllo" viene flaggata
}

int controlloIndici(char campoGiocatore [][COL], char carat, int i, int j, int dimn, int tp){
    int controllo;



    controllo = 0;

    srand(time(NULL));


    if (carat == 'i') { //Distinguo i controlli in base a se la nave è disposta in orizzontale o verticale

        if (i + dimn > 10) { // Controllo che la nave non esca dai bordi del campo
            controllo = 1;
        }
        for(int k = 0; k < dimn ; k++){
            if(campoGiocatore[i + k][j] == 'N'){ // Controllo che le navi non si sovrappongono tra di loro
                controllo = 1;
            }
        }

        if(tp == 2 || tp == 3) { // Nel caso l'utente abbia scelto di generare le navi con contorni

            if (campoGiocatore[i - 1][j] == 'N' || campoGiocatore[i + dimn][j] == 'N') { // Controllo che ci sia un blocco in alto e in basso di mare di distanza tra un nave e l'altra
                controllo = 1;
            }


            for (int k = 0; k < dimn; k++) {
                if (campoGiocatore[i + k][j + 1] == 'N' || campoGiocatore[i + k][j - 1] == 'N') { // Controllo che ci sia uno spazio a destra e a sinistra di distanza tra un nave e l'altra
                    controllo = 1;
                }
            }
            if(tp == 3){
                //Controlla che le navi non condividano il contorno
                if(campoGiocatore[i - 1][j - 1] == 'N' || campoGiocatore[i - 1][j + 1] == 'N' || campoGiocatore[i + dimn][j - 1] == 'N' || campoGiocatore[i + dimn][j + 1] == 'N' ){
                    controllo = 1;
                }
            }
        }
    } else { //Distinguo i controlli in base a se la nave è disposta in orizzontale o verticale

        if (j + dimn > 10) { // Controllo che la nave non esca dai bordi del campo
            controllo = 1;
        }
        for (int k = 0; k < dimn; k++) {
            if (campoGiocatore[i][j + k] == 'N') { // Controllo che le navi non si sovrappongono tra di loro
                controllo = 1;
            }
        }

        if(tp == 2 || tp == 3) { // Nel caso l'utente abbia scelto di generare le navi con contorni

            if (campoGiocatore[i][j - 1] == 'N' || campoGiocatore[i][j + dimn] == 'N') { // Controllo che ci sia un blocco in alto e in basso di mare di distanza tra un nave e l'altra

                controllo = 1;
            }

            for (int k = 0; k < dimn; k++) {
                if (campoGiocatore[i + 1][j + k] == 'N' || campoGiocatore[i - 1][j + k] == 'N') { // Controllo che ci sia uno spazio a destra e a sinistra di distanza tra un nave e l'altra
                    controllo = 1;
                }
            }
            if(tp == 3){
                //Controlla che le navi non condividano il contorno
                if(campoGiocatore[i - 1][j - 1] == 'N' || campoGiocatore[i + 1][j - 1] == 'N' || campoGiocatore[i - 1][j + dimn] == 'N' || campoGiocatore[i + 1][j + dimn] == 'N' ){
                    controllo = 1;
                }
            }
        }
    }
    return controllo;
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
void caricaNaviManuale(char campoGiocatore[][COL], int tipop) {
    int i, j, dimnav = 1, connav = 'N';
    char orient;
    visualizzaPartita(campoGiocatore);
    for(int numnav = 0; numnav < 8; numnav++) {
        if(numnav == 1 || numnav == 3 || numnav == 5 || numnav == 7){ //Carica navi di lunghezze diverse in base all'avanzare del contatore
            dimnav++;
        }
        do {
            if(numnav == 0){
                printf("Piazzare una nave di lunghezza 1:");
            }
            if(numnav == 1 || numnav == 2){
                printf("Piazzare una nave di lunghezza 2:");
            }
            if(numnav == 3 || numnav == 4){
                printf("Piazzare una nave di lunghezza 3:");
            }
            if(numnav == 5 || numnav == 6){
                printf("Piazzare una nave di lunghezza 4:");
            }
            if(numnav == 7){
                printf("Piazzare una nave di lunghezza 5:");
            }
            do {
                getchar();
                printf("\nInserire la colonna (in maiuscolo) in cui si vuole piazzare la nave: \n");
                scanf("%c", &j);
            } while (j < 'A' || j > 'J');

            switch (j) { // Converte la lettera in numero per essere interpretata dall'algoritmo
                case 'A':
                    j = 1;
                    break;
                case 'B':
                    j = 2;
                    break;
                case 'C':
                    j = 3;
                    break;
                case 'D':
                    j = 4;
                    break;
                case 'E':
                    j = 5;
                    break;
                case 'F':
                    j = 6;
                    break;
                case 'G':
                    j = 7;
                    break;
                case 'H':
                    j = 8;
                    break;
                case 'I':
                    j = 9;
                    break;
                case 'J':
                    j = 10;
                    break;
            }

            do {
                getchar();
                printf("\nInserire la riga in cui si vuole piazzare la nave: \n");
                scanf("%d", &i);
            } while (i < 1 || i > 10);

            do {
                getchar();
                printf("\nInserire il verso in cui si vuole posizionare la nave(V = verticale, O = orizzontale): \n");
                scanf("%c", &orient);
            } while (orient != 'O' && orient != 'V');

            if (orient == 'V') {
                orient = 'i';
            } else {
                orient = 'j';
            }
        } while (controlloIndici(campoGiocatore, orient, i, j, dimnav, tipop) == 1);// Riesegue l'algoritmo affinché l'attacco non venga eseguito correttamente


        if(orient == 'i') { //Piazzo la nave in orizzontale o in verticale in base al carattere assegnato casualmente a cont
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
        visualizzaPartita(campoGiocatore);
    }
}


void m_PlvsPl(char campoGiocatore1[][COL], char campoGiocatore2[][COL]){
    int ncolp1 = 0, ncolp2 = 0;
    while(1) {
        printf("Turno del Giocatore 1:");
        printf("\n");
        visualizzaPartita(campoGiocatore2);
        attaccoGiocatore(campoGiocatore2);
        ncolp1++;
        if(ncolp1 == 76){ //Se il numero di colpi sparati supera 76 finisce la partita
            break;
        }
        visualizzaPartita(campoGiocatore2);
        system("PAUSE");
        if(numeroNavi(campoGiocatore2) == 0){ //Rompe il ciclo nel caso non vengono rilevate navi nel campo
            break;
        }
        printf("Turno del Giocatore 2:");
        printf("\n");
        visualizzaPartita(campoGiocatore1);
        attaccoGiocatore(campoGiocatore1);
        ncolp2++;
        if(ncolp2 == 76){ //Se il numero di colpi sparati supera 76 finisce la partita
            break;
        }
        visualizzaPartita(campoGiocatore1);
        system("PAUSE");
        if(numeroNavi(campoGiocatore1) == 0){ //Rompe il ciclo nel caso non vengono rilevate navi nel campo
            break;
        }
    }
    if(numeroNavi(campoGiocatore2) < numeroNavi(campoGiocatore1)){ // Decreta se ha vinto il giocatore 1 (campogiocatore2) o il giocatore 2 (campogiocatore1)
        printf("\nIl Giocatore Uno ha Vinto!");
    } else {
        printf("\nIl Giocatore Due ha Vinto!");
    }
}

void m_PlvsBot(char campoGiocatore1[][COL], char campoGiocatore2[][COL]){
    int ncolp1 = 0, ncolp2 = 0;
    while(1) {
        printf("Turno del Giocatore 1:");
        printf("\n");
        visualizzaPartita(campoGiocatore2);
        attaccoGiocatore(campoGiocatore2);
        ncolp1++;
        if(ncolp1 == 76){ //Se il numero di colpi sparati supera 76 finisce la partita
            break;
        }
        visualizzaPartita(campoGiocatore2);
        system("PAUSE");
        if(numeroNavi(campoGiocatore2) == 0){ //Rompe il ciclo nel caso non vengono rilevate navi nel campo
            break;
        }
        printf("Turno del Bot:");
        printf("\n");
        visualizzaPartita(campoGiocatore1);
        attaccoGiocatoreAutomatico(campoGiocatore1);
        ncolp2++;
        if(ncolp2 == 76){ //Se il numero di colpi sparati supera 76 finisce la partita
            break;
        }
        visualizzaPartita(campoGiocatore1);
        system("PAUSE");
        if(numeroNavi(campoGiocatore1) == 0){ //Rompe il ciclo nel caso non vengono rilevate navi nel campo
            break;
        }
    }
    if(numeroNavi(campoGiocatore2) < numeroNavi(campoGiocatore1)){ // Decreta se ha vinto il giocatore 1 (campogiocatore2) o il giocatore 2 (campogiocatore1)
        printf("\nIl Giocatore Uno ha Vinto!");
    } else {
        printf("\nIl Bot ha Vinto!");
    }
}

void m_BotvsBot(char campoGiocatore1[][COL], char campoGiocatore2[][COL]){
    int ncolp1 = 0, ncolp2 = 0;
    while(1) {
        printf("Turno del Bot 1:");
        printf("\n");
        visualizzaPartita(campoGiocatore2);
        attaccoGiocatoreAutomatico(campoGiocatore2);
        ncolp1++;
        if(ncolp1 == 76){ //Se il numero di colpi sparati supera 76 finisce la partita
            break;
        }
        visualizzaPartita(campoGiocatore2);
        system("PAUSE");
        if(numeroNavi(campoGiocatore2) == 0){ //Rompe il ciclo nel caso non vengono rilevate navi nel campo
            break;
        }
        printf("Turno del Bot 2:");
        printf("\n");
        visualizzaPartita(campoGiocatore1);
        attaccoGiocatoreAutomatico(campoGiocatore1);
        ncolp2++;
        if(ncolp2 == 76){ //Se il numero di colpi sparati supera 76 finisce la partita
            break;
        }
        visualizzaPartita(campoGiocatore1);
        system("PAUSE");
        if(numeroNavi(campoGiocatore1) == 0){ //Rompe il ciclo nel caso non vengono rilevate navi nel campo
            break;
        }
    }
    if(numeroNavi(campoGiocatore2) < numeroNavi(campoGiocatore1)){ // Decreta se ha vinto il giocatore 1 (campogiocatore2) o il giocatore 2 (campogiocatore1)
        printf("\nIl Giocatore Bot Uno ha Vinto!");
    } else {
        printf("\nIl Bot Due ha Vinto!");
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
