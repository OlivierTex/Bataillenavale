
#ifndef SAUVAGE_HEADER_H
#define SAUVAGE_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>

//Variables tres utilise
#define BoardSize 15
#define BoardSize1 15
#define tabshot 2
#define tabfumi 2
#define Hasard 2
#define Hasardb 100

int shot[tabshot];

int fumi[tabfumi];

int board1[BoardSize][BoardSize];

int board2[BoardSize][BoardSize];

int board3[BoardSize][BoardSize];

int board4[BoardSize][BoardSize];


//Strucute des differents types de bateaux
typedef struct
{
    int orientation;
    int taille;
    int positionx[7];
    int positiony[7];
    int condition;
}t_porteavion;

typedef struct
{
    int orientation;
    int taille;
    int positionx[5];
    int positiony[5];
    int condition;
}t_croiseur;

typedef struct
{
    int orientation;
    int taille;
    int positionx[3];
    int positiony[3];
    int condition;
}t_destroyer;

typedef struct
{
    int orientation;
    int taille;
    int positionx[1];
    int positiony[1];
    int condition;
}t_sousmarrin;

//Tableau qui sont appele dans les different programme
int tabporteavion1x[7];
int tabporteavion1y[7];
int compteurporteavion1[1];

int tabcroiseur1ax[5];
int tabcroiseur1ay[5];
int compteurcroiseur1a[1];

int tabcroiseur1bx[5];
int tabcroiseur1by[5];
int compteurcroiseur1b[1];

int tabdestroyer1ax[3];
int tabdestroyer1ay[3];
int compteurdestroyer1a[1];

int tabdestroyer1bx[3];
int tabdestroyer1by[3];
int compteurdestroyer1b[1];

int tabdestroyer1cx[3];
int tabdestroyer1cy[3];
int compteurdestroyer1c[1];

int tabsousmarrin1ax[1];
int tabsousmarrin1ay[1];
int compteursousmarrin1a[1];

int tabsousmarrin1bx[1];
int tabsousmarrin1by[1];
int compteursousmarrin1b[1];

int tabsousmarrin1cx[1];
int tabsousmarrin1cy[1];
int compteursousmarrin1c[1];

int tabsousmarrin1dx[1];
int tabsousmarrin1dy[1];
int compteursousmarrin1d[1];

int tabporteavion2x[7];
int tabporteavion2y[7];
int compteurporteavion2[1];

int tabcroiseur2ax[5];
int tabcroiseur2ay[5];
int compteurcroiseur2a[1];

int tabcroiseur2bx[5];
int tabcroiseur2by[5];
int compteurcroiseur2b[1];

int tabdestroyer2ax[3];
int tabdestroyer2ay[3];
int compteurdestroyer2a[1];

int tabdestroyer2bx[3];
int tabdestroyer2by[3];
int compteurdestroyer2b[1];

int tabdestroyer2cx[3];
int tabdestroyer2cy[3];
int compteurdestroyer2c[1];

int tabsousmarrin2ax[1];
int tabsousmarrin2ay[1];
int compteursousmarrin2a[1];

int tabsousmarrin2bx[1];
int tabsousmarrin2by[1];
int compteursousmarrin2b[1];

int tabsousmarrin2cx[1];
int tabsousmarrin2cy[1];
int compteursousmarrin2c[1];

int tabsousmarrin2dx[1];
int tabsousmarrin2dy[1];
int compteursousmarrin2d[1];

#endif //SAUVAGE_HEADER_H
