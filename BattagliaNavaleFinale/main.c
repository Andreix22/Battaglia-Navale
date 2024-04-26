#include "Functions.h"

int main() {
    char CampoGiocatore1[ROW][COL], CampoGiocatore2[ROW][COL];
    int sceltamodalita, piazznavi;

    caricaCampoBattagliaNavale(CampoGiocatore1);
    caricaCampoBattagliaNavale(CampoGiocatore2);



    printf("\nBenvenuto nella battaglia navale!\n");
    do{
        printf("Scegliere la modalita' di gioco: ");
        printf("\n1. Giocatore contro Giocatore ");
        printf("\n2. Giocatore contro Bot ");
        printf("\n3. Bot contro Bot \n");
        scanf("%d", &sceltamodalita);
    }while(sceltamodalita < 1 || sceltamodalita > 3);

    do {
        printf("\nIn che modo devono essere piazzate le navi?\n");
        printf("\n1. Randomico");
        printf("\n2. Manuale \n");
        scanf("%d", &piazznavi);
    } while(piazznavi < 1 || piazznavi > 3);

    if(piazznavi == 1){
        caricaNaviCasuale(CampoGiocatore1);
        caricaNaviCasuale(CampoGiocatore2);
    } else {
        caricaNaviManuale(CampoGiocatore1);
        caricaNaviManuale(CampoGiocatore2);
    }


    if(sceltamodalita == 1){
        M_PlvsPl(CampoGiocatore1, CampoGiocatore2);
    }
    if(sceltamodalita == 2){
        M_PlvsBot(CampoGiocatore1, CampoGiocatore2);
    }
    if(sceltamodalita == 3){
        M_BotvsBot(CampoGiocatore1, CampoGiocatore2);
    }

    return 0;
}