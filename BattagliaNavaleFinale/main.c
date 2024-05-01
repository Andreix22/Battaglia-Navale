#include "Functions.h"

int main() {
    char CampoGiocatore1[ROW][COL], CampoGiocatore2[ROW][COL];
    int sceltamodalita, piazznavi1, contnavi1, piazznavi2, contnavi2;

    caricaCampoBattagliaNavale(CampoGiocatore1); //Genero il campo base
    caricaCampoBattagliaNavale(CampoGiocatore2);

    srand(time(NULL));

    printf("\nBenvenuto nella battaglia navale!\n");
    do{
        printf("Scegliere la modalita' di gioco: ");
        printf("\n1. Giocatore contro Giocatore ");
        printf("\n2. Giocatore contro Bot ");
        printf("\n3. Bot contro Bot \n");
        scanf("%d", &sceltamodalita);
    }while(sceltamodalita < 1 || sceltamodalita > 3);

    if(sceltamodalita == 1 || sceltamodalita == 2) {
        do {
            printf("\nIn che modo devono essere piazzate le navi del Giocatore Uno?");
            printf("\n1. Randomico");
            printf("\n2. Manuale \n");
            scanf("%d", &piazznavi1);
        } while (piazznavi1 < 1 || piazznavi1 > 3);
    } else {
        printf("\nIn che modo devono essere piazzate le navi del Bot Uno?");
        printf("\n1. Randomico");
        printf("\n2. Manuale \n");
        scanf("%d", &piazznavi1);
    } while (piazznavi1 < 1 || piazznavi1 > 3);

    do{
        printf("\nSecondo quale criterio devono essere piazzate?");
        printf("\n1.Opzione libera");
        printf("\n2.Con contorni");
        printf("\n3.Senza contorni\n");
        scanf("%d", &contnavi1);
    }while(contnavi1 < 1 || contnavi1 > 3);

    if(sceltamodalita == 1) {
        do {
            printf("\nIn che modo devono essere piazzate le navi del Giocatore Due?");
            printf("\n1. Randomico");
            printf("\n2. Manuale \n");
            scanf("%d", &piazznavi2);
        } while (piazznavi2 < 1 || piazznavi2 > 3);
    } else {
        printf("\nIn che modo devono essere piazzate le navi del Bot Due?");
        printf("\n1. Randomico");
        printf("\n2. Manuale \n");
        scanf("%d", &piazznavi2);
    } while (piazznavi2 < 1 || piazznavi2 > 3);

    do{
        printf("\nSecondo quale criterio devono essere piazzate?");
        printf("\n1.Opzione libera");
        printf("\n2.Con contorni");
        printf("\n3.Senza contorni\n");
        scanf("%d", &contnavi2);
    }while(contnavi2 < 1 || contnavi2 > 3);


    if(sceltamodalita == 1 || sceltamodalita == 2) {
        printf("\nPiazzamento navi del Giocatore Uno....\n");
    } else {
        printf("\nPiazzamento navi del Bot Uno....\n");
    }

    if(piazznavi1 == 1) { // Scelta di piazzamento delle navi
        caricaNaviCasuale(CampoGiocatore1, contnavi1);
    } else {
        caricaNaviManuale(CampoGiocatore1, contnavi1);
    }

    if(sceltamodalita == 1){
        printf("\nPiazziamento navi del Giocatore Due....\n");
    } else {
        printf("\nPiazziamento navi del Bot Due....\n");
    }

    if(piazznavi2 == 1) { // Scelta di piazzamento delle navi
        caricaNaviCasuale(CampoGiocatore2, contnavi2);
    } else {
        caricaNaviManuale(CampoGiocatore2, contnavi2);
    }



    if(sceltamodalita == 1){ // Scelta modalità
        m_PlvsPl(CampoGiocatore1, CampoGiocatore2);
    }
    if(sceltamodalita == 2){
        m_PlvsBot(CampoGiocatore1, CampoGiocatore2);
    }
    if(sceltamodalita == 3){
        m_BotvsBot(CampoGiocatore1, CampoGiocatore2);
    }

    return 0;
}