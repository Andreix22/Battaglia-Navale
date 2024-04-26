//
// Created by anton on 26/04/2024.
//

#ifndef BATTAGLIANAVALE_FUNCTIONS_H
#define BATTAGLIANAVALE_FUNCTIONS_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#define ROW 11
#define COL 11
extern void caricaCampoBattagliaNavale (char campoGiocatore [][COL]);
extern void VisualizzaPartita(char campoGiocatore[][COL]);
extern void caricaNaviCasuale(char campoGiocatore[][COL]);
extern void caricaNaviManuale(char campoGiocatore[][COL]);
extern void M_PlvsPl(char campoGiocatore1[][COL], char campoGiocatore2[][COL]);
extern void M_PlvsBot(char campoGiocatore1[][COL], char campoGiocatore2[][COL]);
extern void M_BotvsBot(char campoGiocatore1[][COL], char campoGiocatore2[][COL]);
extern int NumeroNavi(char campoGiocatore[][COL]);
extern void AttaccoGiocatore(char campoGiocatore[][COL]);
extern void AttaccoGiocatoreAutomatico(char campoGiocatore[][COL]);
#endif //BATTAGLIANAVALE_FUNCTIONS_H
