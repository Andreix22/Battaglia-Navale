#include "Functions.h"

int main() {
    char CampoGiocatore1[ROW][COL], CampoGiocatore2[ROW][COL];
    int sceltamodalita, piazznavi, contnavi;

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

    do {
        printf("\nIn che modo devono essere piazzate le navi?");
        printf("\n1. Randomico");
        printf("\n2. Manuale \n");
        scanf("%d", &piazznavi);
    } while(piazznavi < 1 || piazznavi > 3);

    do{
        printf("\nSecondo quale criterio devono essere piazzate?");
        printf("\n1.Opzione libera");
        printf("\n2.Con contorni\n");
        scanf("%d", &contnavi);
    }while(contnavi < 1 || contnavi > 2);

    if(piazznavi == 1){ // Scelta di piazzamento delle navi
        caricaNaviCasuale(CampoGiocatore1, contnavi);
        caricaNaviCasuale(CampoGiocatore2, contnavi);
    } else {
        caricaNaviManuale(CampoGiocatore1);
        caricaNaviManuale(CampoGiocatore2);
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