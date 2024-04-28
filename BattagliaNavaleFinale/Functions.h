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
extern void visualizzaPartita(char campoGiocatore[][COL]);
extern void controlloSovrapposizioni(char campoGiocatore [][COL], char*, int*, int*, int);
extern void caricaNaviCasuale(char campoGiocatore[][COL]);
extern void caricaNaviManuale(char campoGiocatore[][COL]);
extern void m_PlvsPl(char campoGiocatore1[][COL], char campoGiocatore2[][COL]);
extern void m_PlvsBot(char campoGiocatore1[][COL], char campoGiocatore2[][COL]);
extern void m_BotvsBot(char campoGiocatore1[][COL], char campoGiocatore2[][COL]);
extern int numeroNavi(char campoGiocatore[][COL]);
extern void attaccoGiocatore(char campoGiocatore[][COL]);
extern void attaccoGiocatoreAutomatico(char campoGiocatore[][COL]);
#endif //BATTAGLIANAVALE_FUNCTIONS_H
