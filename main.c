#include "header.h"

//Affiche les regles du jeux
void regles()
{
    printf("----------------------------------------------- Regles de la bataille navale -----------------------------------------------------\n\n");
    printf("Le but du jeu est de couler tous les bateaux de son adversaire. Chaque joueur possede 10 bateaux qui sont places aleatoirement ");
    printf("sur la carte.\nAu debut de chaque tour le joueur peut choisir de tirer une torpille ou lancer une fusee eclairante qui revelle une ");
    printf("zone de 4x4.\nMais il peut aussi deplacer un de ses bateaux d'une case verticalement ou horizontalement.\nLa partie ce fini quand ");
    printf("l'ensembe des bateaux de l'aversaire est coule.\n");
    printf("Le joueur peut aussi sauvegarder la partie a tout moment en appuyant sur S.\nIl peut aussi abandonner a tout moment en appuyant ");
    printf("sur 4.\nIl a aussi la possibilite de tricher en appuyant sur v ce qui revele la carte de l'aversaire. Bonne chance dans vos futurs ");
    printf("partie.\n\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------\n\n");
}

void color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

//Initialise la grille 1
void iniboard1()
{
    int ligne, colonne;
    for(ligne=0 ; ligne < BoardSize ; ligne++ )
        for(colonne=0 ; colonne < BoardSize ; colonne++ )
            board1[ligne][colonne]=-1;
}
//Initialise la grille 2
void iniboard2()
{
    int ligne, colonne;
    for(ligne=0 ; ligne < BoardSize ; ligne++ )
        for(colonne=0 ; colonne < BoardSize ; colonne++ )
            board2[ligne][colonne]=-1;
}
//Initialise la grille 3
void iniboard3()
{
    int ligne, colonne;
    for(ligne=0 ; ligne < BoardSize ; ligne++ )
        for(colonne=0 ; colonne < BoardSize ; colonne++ )
            board3[ligne][colonne]=-1;
}
//Initialise la grille 4
void iniboard4()
{
    int ligne, colonne;
    for(ligne=0 ; ligne < BoardSize ; ligne++ )
        for(colonne=0 ; colonne < BoardSize ; colonne++ )
            board4[ligne][colonne]=-1;
}
//Place aleatoire les bateaux du joueur
void positionnementbateaux1()
{
    srand(time(NULL));
    t_porteavion PorteAvion;
    t_croiseur Croiseur;
    t_croiseur Croiseur1;
    t_destroyer Destroyer;
    t_destroyer Destroyer1;
    t_destroyer Destroyer2;
    t_sousmarrin SousMarrin;
    t_sousmarrin SousMarrin1;
    t_sousmarrin SousMarrin2;
    t_sousmarrin SousMarrin3;

    int i = 0;

    //////////////////PorteAvion/////////////////////
    PorteAvion.taille = 7;
    PorteAvion.condition=0;
    do {
        PorteAvion.positionx[0] = rand() % BoardSize;
        PorteAvion.positiony[0] = rand() % BoardSize;
        if (PorteAvion.positionx[0] < 8) {
            if (PorteAvion.positiony[0] < 8) {
                PorteAvion.orientation = rand()%Hasardb;
                if (PorteAvion.orientation == 0) {
                    for (i = 0; i < PorteAvion.taille - 1; i++) {
                        PorteAvion.positionx[i + 1] = PorteAvion.positionx[i];
                        PorteAvion.positiony[i + 1] = PorteAvion.positiony[i] + 1;
                    }
                    if ((board1[PorteAvion.positionx[0]][PorteAvion.positiony[0]]) == (-1) &&
                        (board1[PorteAvion.positionx[1]][PorteAvion.positiony[1]]) == (-1) &&
                        (board1[PorteAvion.positionx[2]][PorteAvion.positiony[2]]) == (-1) &&
                        (board1[PorteAvion.positionx[3]][PorteAvion.positiony[3]]) == (-1) &&
                        (board1[PorteAvion.positionx[4]][PorteAvion.positiony[4]]) == (-1) &&
                        (board1[PorteAvion.positionx[5]][PorteAvion.positiony[5]]) == (-1) &&
                        (board1[PorteAvion.positionx[6]][PorteAvion.positiony[6]]) == (-1))
                    {
                        for (i = 0; i < 7; i++) {
                            tabporteavion1x[i]=PorteAvion.positionx[i];
                            tabporteavion1y[i]=PorteAvion.positiony[i];
                            board1[tabporteavion1x[i]][tabporteavion1y[i]] = 4;
                        }
                        PorteAvion.condition = 1;
                    }
                }
                else {
                    for (i = 0; i < PorteAvion.taille - 1; i++) {
                        PorteAvion.positionx[i + 1] = PorteAvion.positionx[i] + 1;
                        PorteAvion.positiony[i + 1] = PorteAvion.positiony[i];
                    }
                    if ((board1[PorteAvion.positionx[0]][PorteAvion.positiony[0]]) == (-1) &&
                        (board1[PorteAvion.positionx[1]][PorteAvion.positiony[1]]) == (-1) &&
                        (board1[PorteAvion.positionx[2]][PorteAvion.positiony[2]]) == (-1) &&
                        (board1[PorteAvion.positionx[3]][PorteAvion.positiony[3]]) == (-1) &&
                        (board1[PorteAvion.positionx[4]][PorteAvion.positiony[4]]) == (-1) &&
                        (board1[PorteAvion.positionx[5]][PorteAvion.positiony[5]]) == (-1) &&
                        (board1[PorteAvion.positionx[6]][PorteAvion.positiony[6]]) == (-1))
                    {
                        for (i = 0; i < 7; i++) {
                            tabporteavion1x[i]=PorteAvion.positionx[i];
                            tabporteavion1y[i]=PorteAvion.positiony[i];
                            board1[tabporteavion1x[i]][tabporteavion1y[i]] = 4;
                        }
                        PorteAvion.condition = 1;
                    }
                }
            }
            else if (PorteAvion.positiony[0] > 7) {
                PorteAvion.orientation = 0;
                if (PorteAvion.orientation == 0) {
                    for (i = 0; i < PorteAvion.taille - 1; i++) {
                        PorteAvion.positionx[i + 1] = PorteAvion.positionx[i];
                        PorteAvion.positiony[i + 1] = PorteAvion.positiony[i] - 1;
                    }
                    if ((board1[PorteAvion.positionx[0]][PorteAvion.positiony[0]]) == (-1) &&
                        (board1[PorteAvion.positionx[1]][PorteAvion.positiony[1]]) == (-1) &&
                        (board1[PorteAvion.positionx[2]][PorteAvion.positiony[2]]) == (-1) &&
                        (board1[PorteAvion.positionx[3]][PorteAvion.positiony[3]]) == (-1) &&
                        (board1[PorteAvion.positionx[4]][PorteAvion.positiony[4]]) == (-1) &&
                        (board1[PorteAvion.positionx[5]][PorteAvion.positiony[5]]) == (-1) &&
                        (board1[PorteAvion.positionx[6]][PorteAvion.positiony[6]]) == (-1))
                    {
                        for (i = 0; i < 7; i++) {
                            tabporteavion1x[i]=PorteAvion.positionx[i];
                            tabporteavion1y[i]=PorteAvion.positiony[i];
                            board1[tabporteavion1x[i]][tabporteavion1y[i]] = 4;
                        }
                        PorteAvion.condition=1;
                    }
                }
                else {
                    for (i = 0; i < PorteAvion.taille - 1; i++) {
                        PorteAvion.positionx[i + 1] = PorteAvion.positionx[i] + 1;
                        PorteAvion.positiony[i + 1] = PorteAvion.positiony[i];
                    }
                    if ((board1[PorteAvion.positionx[0]][PorteAvion.positiony[0]]) == (-1) &&
                        (board1[PorteAvion.positionx[1]][PorteAvion.positiony[1]]) == (-1) &&
                        (board1[PorteAvion.positionx[2]][PorteAvion.positiony[2]]) == (-1) &&
                        (board1[PorteAvion.positionx[3]][PorteAvion.positiony[3]]) == (-1) &&
                        (board1[PorteAvion.positionx[4]][PorteAvion.positiony[4]]) == (-1) &&
                        (board1[PorteAvion.positionx[5]][PorteAvion.positiony[5]]) == (-1) &&
                        (board1[PorteAvion.positionx[6]][PorteAvion.positiony[6]]) == (-1))
                    {
                        for (i = 0; i < 7; i++) {
                            tabporteavion1x[i]=PorteAvion.positionx[i];
                            tabporteavion1y[i]=PorteAvion.positiony[i];
                            board1[tabporteavion1x[i]][tabporteavion1y[i]] = 4;
                        }
                        PorteAvion.condition=1;
                    }
                }
            }
        }
        else if (PorteAvion.positionx[0] > 7) {
            // droite
            if (PorteAvion.positiony[0] < 8) {
                PorteAvion.orientation = rand()%Hasardb;
                if (PorteAvion.orientation == 0) {
                    for (i = 0; i < PorteAvion.taille - 1; i++) {
                        PorteAvion.positionx[i + 1] = PorteAvion.positionx[i];
                        PorteAvion.positiony[i + 1] = PorteAvion.positiony[i] + 1;
                    }
                    if ((board1[PorteAvion.positionx[0]][PorteAvion.positiony[0]]) == (-1) &&
                        (board1[PorteAvion.positionx[1]][PorteAvion.positiony[1]]) == (-1) &&
                        (board1[PorteAvion.positionx[2]][PorteAvion.positiony[2]]) == (-1) &&
                        (board1[PorteAvion.positionx[3]][PorteAvion.positiony[3]]) == (-1) &&
                        (board1[PorteAvion.positionx[4]][PorteAvion.positiony[4]]) == (-1) &&
                        (board1[PorteAvion.positionx[5]][PorteAvion.positiony[5]]) == (-1) &&
                        (board1[PorteAvion.positionx[6]][PorteAvion.positiony[6]]) == (-1))
                    {
                        for (i = 0; i < 7; i++) {
                            tabporteavion1x[i]=PorteAvion.positionx[i];
                            tabporteavion1y[i]=PorteAvion.positiony[i];
                            board1[tabporteavion1x[i]][tabporteavion1y[i]] = 4;
                        }
                        PorteAvion.condition=1;
                    }
                }
                else {
                    for (i = 0; i < PorteAvion.taille - 1; i++) {
                        PorteAvion.positionx[i + 1] = PorteAvion.positionx[i] - 1;
                        PorteAvion.positiony[i + 1] = PorteAvion.positiony[i];
                    }
                    if ((board1[PorteAvion.positionx[0]][PorteAvion.positiony[0]]) == (-1) &&
                        (board1[PorteAvion.positionx[1]][PorteAvion.positiony[1]]) == (-1) &&
                        (board1[PorteAvion.positionx[2]][PorteAvion.positiony[2]]) == (-1) &&
                        (board1[PorteAvion.positionx[3]][PorteAvion.positiony[3]]) == (-1) &&
                        (board1[PorteAvion.positionx[4]][PorteAvion.positiony[4]]) == (-1) &&
                        (board1[PorteAvion.positionx[5]][PorteAvion.positiony[5]]) == (-1) &&
                        (board1[PorteAvion.positionx[6]][PorteAvion.positiony[6]]) == (-1))
                    {
                        for (i = 0; i < 7; i++) {
                            tabporteavion1x[i]=PorteAvion.positionx[i];
                            tabporteavion1y[i]=PorteAvion.positiony[i];
                            board1[tabporteavion1x[i]][tabporteavion1y[i]] = 4;
                        }
                        PorteAvion.condition=1;
                    }
                }
            }
            else if (PorteAvion.positiony > 7) {
                PorteAvion.orientation = 0;
                if (PorteAvion.orientation == 1) {
                    for (i = 0; i < PorteAvion.taille - 1; i++) {
                        PorteAvion.positionx[i + 1] = PorteAvion.positionx[i];
                        PorteAvion.positiony[i + 1] = PorteAvion.positiony[i] - 1;
                    }
                    if ((board1[PorteAvion.positionx[0]][PorteAvion.positiony[0]]) == (-1) &&
                        (board1[PorteAvion.positionx[1]][PorteAvion.positiony[1]]) == (-1) &&
                        (board1[PorteAvion.positionx[2]][PorteAvion.positiony[2]]) == (-1) &&
                        (board1[PorteAvion.positionx[3]][PorteAvion.positiony[3]]) == (-1) &&
                        (board1[PorteAvion.positionx[4]][PorteAvion.positiony[4]]) == (-1) &&
                        (board1[PorteAvion.positionx[5]][PorteAvion.positiony[5]]) == (-1) &&
                        (board1[PorteAvion.positionx[6]][PorteAvion.positiony[6]]) == (-1))
                    {
                        for (i = 0; i < 7; i++) {
                            tabporteavion1x[i]=PorteAvion.positionx[i];
                            tabporteavion1y[i]=PorteAvion.positiony[i];
                            board1[tabporteavion1x[i]][tabporteavion1y[i]] = 4;
                        }
                        PorteAvion.condition=1;
                    }
                }
                else {
                    for (i = 0; i < PorteAvion.taille - 1; i++) {
                        PorteAvion.positionx[i + 1] = PorteAvion.positionx[i] - 1;
                        PorteAvion.positiony[i + 1] = PorteAvion.positiony[i];
                    }
                    if ((board1[PorteAvion.positionx[0]][PorteAvion.positiony[0]]) == (-1) &&
                        (board1[PorteAvion.positionx[1]][PorteAvion.positiony[1]]) == (-1) &&
                        (board1[PorteAvion.positionx[2]][PorteAvion.positiony[2]]) == (-1) &&
                        (board1[PorteAvion.positionx[3]][PorteAvion.positiony[3]]) == (-1) &&
                        (board1[PorteAvion.positionx[4]][PorteAvion.positiony[4]]) == (-1) &&
                        (board1[PorteAvion.positionx[5]][PorteAvion.positiony[5]]) == (-1) &&
                        (board1[PorteAvion.positionx[6]][PorteAvion.positiony[6]]) == (-1))
                    {
                        for (i = 0; i < 7; i++) {
                            tabporteavion1x[i]=PorteAvion.positionx[i];
                            tabporteavion1y[i]=PorteAvion.positiony[i];
                            board1[tabporteavion1x[i]][tabporteavion1y[i]] = 4;
                        }
                        PorteAvion.condition=1;
                    }
                }
            }
        }
    }while(PorteAvion.condition==0);

    //////////////////Croiseur/////////////////////
    Croiseur.taille = 5;
    Croiseur.condition = 0;
    do {
        Croiseur.positionx[0] = rand() % BoardSize;
        Croiseur.positiony[0] = rand() % BoardSize;
        if (Croiseur.positionx[0] < 10) {
            if (Croiseur.positiony[0] < 10) {
                Croiseur.orientation = rand()%Hasardb;
                if (Croiseur.orientation == 0) {
                    for (i = 0; i < Croiseur.taille - 1; i++) {
                        Croiseur.positionx[i + 1] = Croiseur.positionx[i];
                        Croiseur.positiony[i + 1] = Croiseur.positiony[i] + 1;
                    }
                    if ((board1[Croiseur.positionx[0]][Croiseur.positiony[0]]) == (-1) &&
                        (board1[Croiseur.positionx[1]][Croiseur.positiony[1]]) == (-1) &&
                        (board1[Croiseur.positionx[2]][Croiseur.positiony[2]]) == (-1) &&
                        (board1[Croiseur.positionx[3]][Croiseur.positiony[3]]) == (-1) &&
                        (board1[Croiseur.positionx[4]][Croiseur.positiony[4]]) == (-1)) {
                        for (i = 0; i < 7; i++) {
                            tabcroiseur1ax[i]=Croiseur.positionx[i];
                            tabcroiseur1ay[i]=Croiseur.positiony[i];
                            board1[tabcroiseur1ax[i]][tabcroiseur1ay[i]] = 5;
                        }
                        Croiseur.condition = 1;
                    }
                } else {

                    for (i = 0; i < Croiseur.taille - 1; i++) {
                        Croiseur.positionx[i + 1] = Croiseur.positionx[i] + 1;
                        Croiseur.positiony[i + 1] = Croiseur.positiony[i];
                    }
                    if ((board1[Croiseur.positionx[0]][Croiseur.positiony[0]]) == (-1) &&
                        (board1[Croiseur.positionx[1]][Croiseur.positiony[1]]) == (-1) &&
                        (board1[Croiseur.positionx[2]][Croiseur.positiony[2]]) == (-1) &&
                        (board1[Croiseur.positionx[3]][Croiseur.positiony[3]]) == (-1) &&
                        (board1[Croiseur.positionx[4]][Croiseur.positiony[4]]) == (-1)) {
                        for (i = 0; i < 5; i++) {
                            tabcroiseur1ax[i]=Croiseur.positionx[i];
                            tabcroiseur1ay[i]=Croiseur.positiony[i];
                            board1[tabcroiseur1ax[i]][tabcroiseur1ay[i]] = 5;
                        }
                        Croiseur.condition = 1;
                    }
                }
            } else if (Croiseur.positiony[0] > 9) {
                Croiseur.orientation = 0;
                if (Croiseur.orientation == 0) {
                    for (i = 0; i < Croiseur.taille - 1; i++) {
                        Croiseur.positionx[i + 1] = Croiseur.positionx[i];
                        Croiseur.positiony[i + 1] = Croiseur.positiony[i] - 1;
                    }
                    if ((board1[Croiseur.positionx[0]][Croiseur.positiony[0]]) == (-1) &&
                        (board1[Croiseur.positionx[1]][Croiseur.positiony[1]]) == (-1) &&
                        (board1[Croiseur.positionx[2]][Croiseur.positiony[2]]) == (-1) &&
                        (board1[Croiseur.positionx[3]][Croiseur.positiony[3]]) == (-1) &&
                        (board1[Croiseur.positionx[4]][Croiseur.positiony[4]]) == (-1)) {
                        for (i = 0; i < 5; i++) {
                            tabcroiseur1ax[i]=Croiseur.positionx[i];
                            tabcroiseur1ay[i]=Croiseur.positiony[i];
                            board1[tabcroiseur1ax[i]][tabcroiseur1ay[i]] = 5;
                        }
                        Croiseur.condition = 1;
                    }
                } else {
                    for (i = 0; i < Croiseur.taille - 1; i++) {
                        Croiseur.positionx[i + 1] = Croiseur.positionx[i] + 1;
                        Croiseur.positiony[i + 1] = Croiseur.positiony[i];
                    }
                    if ((board1[Croiseur.positionx[0]][Croiseur.positiony[0]]) == (-1) &&
                        (board1[Croiseur.positionx[1]][Croiseur.positiony[1]]) == (-1) &&
                        (board1[Croiseur.positionx[2]][Croiseur.positiony[2]]) == (-1) &&
                        (board1[Croiseur.positionx[3]][Croiseur.positiony[3]]) == (-1) &&
                        (board1[Croiseur.positionx[4]][Croiseur.positiony[4]]) == (-1)) {
                        for (i = 0; i < 5; i++) {
                            tabcroiseur1ax[i]=Croiseur.positionx[i];
                            tabcroiseur1ay[i]=Croiseur.positiony[i];
                            board1[tabcroiseur1ax[i]][tabcroiseur1ay[i]] = 5;
                        }
                        Croiseur.condition = 1;
                    }
                }
            }
        } else if (Croiseur.positionx[0] > 9) {
            // droite
            if (Croiseur.positiony[0] < 10) {
                Croiseur.orientation = rand()%Hasardb;
                if (Croiseur.orientation == 1) {
                    for (i = 0; i < Croiseur.taille - 1; i++) {
                        Croiseur.positionx[i + 1] = Croiseur.positionx[i];
                        Croiseur.positiony[i + 1] = Croiseur.positiony[i] + 1;
                    }
                    if ((board1[Croiseur.positionx[0]][Croiseur.positiony[0]]) == (-1) &&
                        (board1[Croiseur.positionx[1]][Croiseur.positiony[1]]) == (-1) &&
                        (board1[Croiseur.positionx[2]][Croiseur.positiony[2]]) == (-1) &&
                        (board1[Croiseur.positionx[3]][Croiseur.positiony[3]]) == (-1) &&
                        (board1[Croiseur.positionx[4]][Croiseur.positiony[4]]) == (-1)) {
                        for (i = 0; i < 5; i++) {
                            tabcroiseur1ax[i]=Croiseur.positionx[i];
                            tabcroiseur1ay[i]=Croiseur.positiony[i];
                            board1[tabcroiseur1ax[i]][tabcroiseur1ay[i]] = 5;
                        }
                        Croiseur.condition = 1;
                    }
                } else {
                    for (i = 0; i < Croiseur.taille - 1; i++) {
                        Croiseur.positionx[i + 1] = Croiseur.positionx[i] - 1;
                        Croiseur.positiony[i + 1] = Croiseur.positiony[i];
                    }
                    if ((board1[Croiseur.positionx[0]][Croiseur.positiony[0]]) == (-1) &&
                        (board1[Croiseur.positionx[1]][Croiseur.positiony[1]]) == (-1) &&
                        (board1[Croiseur.positionx[2]][Croiseur.positiony[2]]) == (-1) &&
                        (board1[Croiseur.positionx[3]][Croiseur.positiony[3]]) == (-1) &&
                        (board1[Croiseur.positionx[4]][Croiseur.positiony[4]]) == (-1)) {
                        for (i = 0; i < 5; i++) {
                            tabcroiseur1ax[i]=Croiseur.positionx[i];
                            tabcroiseur1ay[i]=Croiseur.positiony[i];
                            board1[tabcroiseur1ax[i]][tabcroiseur1ay[i]] = 5;
                        }
                        Croiseur.condition = 1;
                    }
                }
            } else if (Croiseur.positiony > 9) {
                Croiseur.orientation = 0;
                if (Croiseur.orientation == 1) {
                    for (i = 0; i < Croiseur.taille - 1; i++) {
                        Croiseur.positionx[i + 1] = Croiseur.positionx[i];
                        Croiseur.positiony[i + 1] = Croiseur.positiony[i] - 1;
                    }
                    if ((board1[Croiseur.positionx[0]][Croiseur.positiony[0]]) == (-1) &&
                        (board1[Croiseur.positionx[1]][Croiseur.positiony[1]]) == (-1) &&
                        (board1[Croiseur.positionx[2]][Croiseur.positiony[2]]) == (-1) &&
                        (board1[Croiseur.positionx[3]][Croiseur.positiony[3]]) == (-1) &&
                        (board1[Croiseur.positionx[4]][Croiseur.positiony[4]]) == (-1)) {
                        for (i = 0; i < 5; i++) {
                            tabcroiseur1ax[i]=Croiseur.positionx[i];
                            tabcroiseur1ay[i]=Croiseur.positiony[i];
                            board1[tabcroiseur1ax[i]][tabcroiseur1ay[i]] = 5;
                        }
                        Croiseur.condition = 1;
                    }
                } else {
                    for (i = 0; i < Croiseur.taille - 1; i++) {
                        Croiseur.positionx[i + 1] = Croiseur.positionx[i] - 1;
                        Croiseur.positiony[i + 1] = Croiseur.positiony[i];
                    }
                    if ((board1[Croiseur.positionx[0]][Croiseur.positiony[0]]) == (-1) &&
                        (board1[Croiseur.positionx[1]][Croiseur.positiony[1]]) == (-1) &&
                        (board1[Croiseur.positionx[2]][Croiseur.positiony[2]]) == (-1) &&
                        (board1[Croiseur.positionx[3]][Croiseur.positiony[3]]) == (-1) &&
                        (board1[Croiseur.positionx[4]][Croiseur.positiony[4]]) == (-1)) {
                        for (i = 0; i < 5; i++) {
                            tabcroiseur1ax[i]=Croiseur.positionx[i];
                            tabcroiseur1ay[i]=Croiseur.positiony[i];
                            board1[tabcroiseur1ax[i]][tabcroiseur1ay[i]] = 5;
                        }
                        Croiseur.condition = 1;
                    }
                }
            }
        }
    } while (Croiseur.condition == 0);

    //////////////////Croiseur1/////////////////////
    Croiseur1.taille = 5;
    Croiseur1.condition = 0;
    do {
        Croiseur1.positionx[0] = rand() % BoardSize;
        Croiseur1.positiony[0] = rand() % BoardSize;
        if (Croiseur1.positionx[0] < 10) {
            if (Croiseur1.positiony[0] < 10) {
                Croiseur1.orientation = rand()%Hasardb;
                if (Croiseur1.orientation == 0) {
                    for (i = 0; i < Croiseur1.taille - 1; i++) {
                        Croiseur1.positionx[i + 1] = Croiseur1.positionx[i];
                        Croiseur1.positiony[i + 1] = Croiseur1.positiony[i] + 1;
                    }
                    if ((board1[Croiseur1.positionx[0]][Croiseur1.positiony[0]]) == (-1) &&
                        (board1[Croiseur1.positionx[1]][Croiseur1.positiony[1]]) == (-1) &&
                        (board1[Croiseur1.positionx[2]][Croiseur1.positiony[2]]) == (-1) &&
                        (board1[Croiseur1.positionx[3]][Croiseur1.positiony[3]]) == (-1) &&
                        (board1[Croiseur1.positionx[4]][Croiseur1.positiony[4]]) == (-1)) {
                        for (i = 0; i < 5; i++) {
                            tabcroiseur1bx[i]=Croiseur1.positionx[i];
                            tabcroiseur1by[i]=Croiseur1.positiony[i];
                            board1[tabcroiseur1bx[i]][tabcroiseur1by[i]] = 5;
                        }
                        Croiseur1.condition = 1;
                    }
                } else {

                    for (i = 0; i < Croiseur1.taille - 1; i++) {
                        Croiseur1.positionx[i + 1] = Croiseur1.positionx[i] + 1;
                        Croiseur1.positiony[i + 1] = Croiseur1.positiony[i];
                    }
                    if ((board1[Croiseur1.positionx[0]][Croiseur1.positiony[0]]) == (-1) &&
                        (board1[Croiseur1.positionx[1]][Croiseur1.positiony[1]]) == (-1) &&
                        (board1[Croiseur1.positionx[2]][Croiseur1.positiony[2]]) == (-1) &&
                        (board1[Croiseur1.positionx[3]][Croiseur1.positiony[3]]) == (-1) &&
                        (board1[Croiseur1.positionx[4]][Croiseur1.positiony[4]]) == (-1)) {
                        for (i = 0; i < 5; i++) {
                            tabcroiseur1bx[i]=Croiseur1.positionx[i];
                            tabcroiseur1by[i]=Croiseur1.positiony[i];
                            board1[tabcroiseur1bx[i]][tabcroiseur1by[i]] = 5;
                        }
                        Croiseur1.condition = 1;
                    }
                }
            } else if (Croiseur1.positiony[0] > 9) {
                Croiseur1.orientation = 0;
                if (Croiseur1.orientation == 0) {
                    for (i = 0; i < Croiseur1.taille - 1; i++) {
                        Croiseur1.positionx[i + 1] = Croiseur1.positionx[i];
                        Croiseur1.positiony[i + 1] = Croiseur1.positiony[i] - 1;
                    }
                    if ((board1[Croiseur1.positionx[0]][Croiseur1.positiony[0]]) == (-1) &&
                        (board1[Croiseur1.positionx[1]][Croiseur1.positiony[1]]) == (-1) &&
                        (board1[Croiseur1.positionx[2]][Croiseur1.positiony[2]]) == (-1) &&
                        (board1[Croiseur1.positionx[3]][Croiseur1.positiony[3]]) == (-1) &&
                        (board1[Croiseur1.positionx[4]][Croiseur1.positiony[4]]) == (-1)) {
                        for (i = 0; i < 5; i++) {
                            tabcroiseur1bx[i]=Croiseur1.positionx[i];
                            tabcroiseur1by[i]=Croiseur1.positiony[i];
                            board1[tabcroiseur1bx[i]][tabcroiseur1by[i]] = 5;
                        }
                        Croiseur1.condition = 1;
                    }
                } else {
                    for (i = 0; i < Croiseur1.taille - 1; i++) {
                        Croiseur1.positionx[i + 1] = Croiseur1.positionx[i] + 1;
                        Croiseur1.positiony[i + 1] = Croiseur1.positiony[i];
                    }
                    if ((board1[Croiseur1.positionx[0]][Croiseur1.positiony[0]]) == (-1) &&
                        (board1[Croiseur1.positionx[1]][Croiseur1.positiony[1]]) == (-1) &&
                        (board1[Croiseur1.positionx[2]][Croiseur1.positiony[2]]) == (-1) &&
                        (board1[Croiseur1.positionx[3]][Croiseur1.positiony[3]]) == (-1) &&
                        (board1[Croiseur1.positionx[4]][Croiseur1.positiony[4]]) == (-1)) {
                        for (i = 0; i < 5; i++) {
                            tabcroiseur1bx[i]=Croiseur1.positionx[i];
                            tabcroiseur1by[i]=Croiseur1.positiony[i];
                            board1[tabcroiseur1bx[i]][tabcroiseur1by[i]] = 5;
                        }
                        Croiseur1.condition = 1;
                    }
                }
            }
        } else if (Croiseur1.positionx[0] > 9) {
// droite
            if (Croiseur1.positiony[0] < 10) {
                Croiseur1.orientation = rand()%Hasardb;
                if (Croiseur1.orientation == 0) {
                    for (i = 0; i < Croiseur1.taille - 1; i++) {
                        Croiseur1.positionx[i + 1] = Croiseur1.positionx[i];
                        Croiseur1.positiony[i + 1] = Croiseur1.positiony[i] + 1;
                    }
                    if ((board1[Croiseur1.positionx[0]][Croiseur1.positiony[0]]) == (-1) &&
                        (board1[Croiseur1.positionx[1]][Croiseur1.positiony[1]]) == (-1) &&
                        (board1[Croiseur1.positionx[2]][Croiseur1.positiony[2]]) == (-1) &&
                        (board1[Croiseur1.positionx[3]][Croiseur1.positiony[3]]) == (-1) &&
                        (board1[Croiseur1.positionx[4]][Croiseur1.positiony[4]]) == (-1)) {
                        for (i = 0; i < 5; i++) {
                            tabcroiseur1bx[i]=Croiseur1.positionx[i];
                            tabcroiseur1by[i]=Croiseur1.positiony[i];
                            board1[tabcroiseur1bx[i]][tabcroiseur1by[i]] = 5;
                        }
                        Croiseur1.condition = 1;
                    }
                } else {

                    for (i = 0; i < Croiseur1.taille - 1; i++) {
                        Croiseur1.positionx[i + 1] = Croiseur1.positionx[i] - 1;
                        Croiseur1.positiony[i + 1] = Croiseur1.positiony[i];
                    }
                    if ((board1[Croiseur1.positionx[0]][Croiseur1.positiony[0]]) == (-1) &&
                        (board1[Croiseur1.positionx[1]][Croiseur1.positiony[1]]) == (-1) &&
                        (board1[Croiseur1.positionx[2]][Croiseur1.positiony[2]]) == (-1) &&
                        (board1[Croiseur1.positionx[3]][Croiseur1.positiony[3]]) == (-1) &&
                        (board1[Croiseur1.positionx[4]][Croiseur1.positiony[4]]) == (-1)) {
                        for (i = 0; i < 5; i++) {
                            tabcroiseur1bx[i]=Croiseur1.positionx[i];
                            tabcroiseur1by[i]=Croiseur1.positiony[i];
                            board1[tabcroiseur1bx[i]][tabcroiseur1by[i]] = 5;
                        }
                        Croiseur1.condition = 1;
                    }
                }
            } else if (Croiseur1.positiony > 9) {
                Croiseur1.orientation = 0;
                if (Croiseur1.orientation == 1) {
                    for (i = 0; i < Croiseur1.taille - 1; i++) {
                        Croiseur1.positionx[i + 1] = Croiseur1.positionx[i];
                        Croiseur1.positiony[i + 1] = Croiseur1.positiony[i] - 1;
                    }
                    if ((board1[Croiseur1.positionx[0]][Croiseur1.positiony[0]]) == (-1) &&
                        (board1[Croiseur1.positionx[1]][Croiseur1.positiony[1]]) == (-1) &&
                        (board1[Croiseur1.positionx[2]][Croiseur1.positiony[2]]) == (-1) &&
                        (board1[Croiseur1.positionx[3]][Croiseur1.positiony[3]]) == (-1) &&
                        (board1[Croiseur1.positionx[4]][Croiseur1.positiony[4]]) == (-1)) {
                        for (i = 0; i < 5; i++) {
                            tabcroiseur1bx[i]=Croiseur1.positionx[i];
                            tabcroiseur1by[i]=Croiseur1.positiony[i];
                            board1[tabcroiseur1bx[i]][tabcroiseur1by[i]] = 5;
                        }
                        Croiseur1.condition = 1;
                    }
                } else {
                    for (i = 0; i < Croiseur1.taille - 1; i++) {
                        Croiseur1.positionx[i + 1] = Croiseur1.positionx[i] - 1;
                        Croiseur1.positiony[i + 1] = Croiseur1.positiony[i];
                    }
                    if ((board1[Croiseur1.positionx[0]][Croiseur1.positiony[0]]) == (-1) &&
                        (board1[Croiseur1.positionx[1]][Croiseur1.positiony[1]]) == (-1) &&
                        (board1[Croiseur1.positionx[2]][Croiseur1.positiony[2]]) == (-1) &&
                        (board1[Croiseur1.positionx[3]][Croiseur1.positiony[3]]) == (-1) &&
                        (board1[Croiseur1.positionx[4]][Croiseur1.positiony[4]]) == (-1)) {
                        for (i = 0; i < 5; i++) {
                            tabcroiseur1bx[i]=Croiseur1.positionx[i];
                            tabcroiseur1by[i]=Croiseur1.positiony[i];
                            board1[tabcroiseur1bx[i]][tabcroiseur1by[i]] = 5;
                        }
                        Croiseur1.condition = 1;
                    }
                }
            }
        }
    } while (Croiseur1.condition == 0);

    //////////////////Destroyer/////////////////////
    Destroyer.taille = 3;
    sleep(1);
    Destroyer.condition=0;
    do {
        Destroyer.positionx[0] = rand() % BoardSize;
        Destroyer.positiony[0] = rand() % BoardSize;
        if (Destroyer.positionx[0] < 12) {
            if (Destroyer.positiony[0] < 12) {
                Destroyer.orientation = rand()%Hasard;
                if (Destroyer.orientation == 1) {
                    for (i = 0; i < Destroyer.taille - 1; i++) {
                        Destroyer.positionx[i + 1] = Destroyer.positionx[i];
                        Destroyer.positiony[i + 1] = Destroyer.positiony[i] + 1;
                    }
                    if ((board1[Destroyer.positionx[0]][Destroyer.positiony[0]]) == (-1) &&
                        (board1[Destroyer.positionx[1]][Destroyer.positiony[1]]) == (-1) &&
                        (board1[Destroyer.positionx[2]][Destroyer.positiony[2]]) == (-1))
                    {
                        for (i = 0; i < 3; i++) {
                            tabdestroyer1ax[i]=Destroyer.positionx[i];
                            tabdestroyer1ay[i]=Destroyer.positiony[i];
                            board1[tabdestroyer1ax[i]][tabdestroyer1ay[i]] = 6;
                        }
                        Destroyer.condition = 1;
                    }
                }
                else {
                    for (i = 0; i < Destroyer.taille - 1; i++) {
                        Destroyer.positionx[i + 1] = Destroyer.positionx[i] + 1;
                        Destroyer.positiony[i + 1] = Destroyer.positiony[i];
                    }
                    if ((board1[Destroyer.positionx[0]][Destroyer.positiony[0]]) == (-1) &&
                        (board1[Destroyer.positionx[1]][Destroyer.positiony[1]]) == (-1) &&
                        (board1[Destroyer.positionx[2]][Destroyer.positiony[2]]) == (-1))
                    {
                        for (i = 0; i < 3; i++) {
                            tabdestroyer1ax[i]=Destroyer.positionx[i];
                            tabdestroyer1ay[i]=Destroyer.positiony[i];
                            board1[tabdestroyer1ax[i]][tabdestroyer1ay[i]] = 6;
                        }
                        Destroyer.condition = 1;
                    }
                }
            }
            else if (Destroyer.positiony[0] > 11) {
                Destroyer.orientation = 0;
                if (Destroyer.orientation == 0) {
                    for (i = 0; i < Destroyer.taille - 1; i++) {
                        Destroyer.positionx[i + 1] = Destroyer.positionx[i];
                        Destroyer.positiony[i + 1] = Destroyer.positiony[i] - 1;
                    }
                    if ((board1[Destroyer.positionx[0]][Destroyer.positiony[0]])==(-1) &&
                        (board1[Destroyer.positionx[1]][Destroyer.positiony[1]])==(-1) &&
                        (board1[Destroyer.positionx[2]][Destroyer.positiony[2]])==(-1))
                    {
                        for (i = 0; i < 3; i++) {
                            tabdestroyer1ax[i]=Destroyer.positionx[i];
                            tabdestroyer1ay[i]=Destroyer.positiony[i];
                            board1[tabdestroyer1ax[i]][tabdestroyer1ay[i]] = 6;
                        }
                        Destroyer.condition=1;
                    }
                }
                else {
                    for (i = 0; i < Destroyer.taille - 1; i++) {
                        Destroyer.positionx[i + 1] = Destroyer.positionx[i] + 1;
                        Destroyer.positiony[i + 1] = Destroyer.positiony[i];
                    }
                    if ((board1[Destroyer.positionx[0]][Destroyer.positiony[0]])==(-1) &&
                        (board1[Destroyer.positionx[1]][Destroyer.positiony[1]])==(-1) &&
                        (board1[Destroyer.positionx[2]][Destroyer.positiony[2]])==(-1))
                    {
                        for (i = 0; i <3; i++) {
                            tabdestroyer1ax[i]=Destroyer.positionx[i];
                            tabdestroyer1ay[i]=Destroyer.positiony[i];
                            board1[tabdestroyer1ax[i]][tabdestroyer1ay[i]] = 6;
                        }
                        Destroyer.condition=1;
                    }
                }
            }
        }
        else if (Destroyer.positionx[0] > 11) {
            // droite
            if (Destroyer.positiony[0] < 12) {
                Destroyer.orientation = rand()%Hasard;
                if (Destroyer.orientation == 1) {
                    for (i = 0; i < Destroyer.taille - 1; i++) {
                        Destroyer.positionx[i + 1] = Destroyer.positionx[i];
                        Destroyer.positiony[i + 1] = Destroyer.positiony[i] + 1;
                    }
                    if ((board1[Destroyer.positionx[0]][Destroyer.positiony[0]])==(-1) &&
                        (board1[Destroyer.positionx[1]][Destroyer.positiony[1]])==(-1) &&
                        (board1[Destroyer.positionx[2]][Destroyer.positiony[2]])==(-1) ){
                        for (i = 0; i < 3; i++) {
                            tabdestroyer1ax[i]=Destroyer.positionx[i];
                            tabdestroyer1ay[i]=Destroyer.positiony[i];
                            board1[tabdestroyer1ax[i]][tabdestroyer1ay[i]] = 6;
                        }
                        Destroyer.condition=1;
                    }
                }
                else {
                    for (i = 0; i < Destroyer.taille - 1; i++) {
                        Destroyer.positionx[i + 1] = Destroyer.positionx[i] - 1;
                        Destroyer.positiony[i + 1] = Destroyer.positiony[i];
                    }
                    if ((board1[Destroyer.positionx[0]][Destroyer.positiony[0]])==(-1) &&
                        (board1[Destroyer.positionx[1]][Destroyer.positiony[1]])==(-1) &&
                        (board1[Destroyer.positionx[2]][Destroyer.positiony[2]])==(-1)){
                        for (i = 0; i < 3; i++) {
                            tabdestroyer1ax[i]=Destroyer.positionx[i];
                            tabdestroyer1ay[i]=Destroyer.positiony[i];
                            board1[tabdestroyer1ax[i]][tabdestroyer1ay[i]] = 6;
                        }
                        Destroyer.condition=1;
                    }
                }
            }
            else if (Destroyer.positiony > 11) {
                Destroyer.orientation = 0;
                if (Destroyer.orientation == 1) {
                    for (i = 0; i < Destroyer.taille - 1; i++) {
                        Destroyer.positionx[i + 1] = Destroyer.positionx[i];
                        Destroyer.positiony[i + 1] = Destroyer.positiony[i] - 1;
                    }
                    if ((board1[Destroyer.positionx[0]][Destroyer.positiony[0]])==(-1) &&
                        (board1[Destroyer.positionx[1]][Destroyer.positiony[1]])==(-1) &&
                        (board1[Destroyer.positionx[2]][Destroyer.positiony[2]])==(-1))
                    {
                        for (i = 0; i < 6; i++) {
                            tabdestroyer1ax[i]=Destroyer.positionx[i];
                            tabdestroyer1ay[i]=Destroyer.positiony[i];
                            board1[tabdestroyer1ax[i]][tabdestroyer1ay[i]] = 6;
                        }
                        Destroyer.condition=1;
                    }
                }
                else {
                    for (i = 0; i < Destroyer.taille - 1; i++) {
                        Destroyer.positionx[i + 1] = Destroyer.positionx[i] - 1;
                        Destroyer.positiony[i + 1] = Destroyer.positiony[i];
                    }
                    if ((board1[Destroyer.positionx[0]][Destroyer.positiony[0]])==(-1) &&
                        (board1[Destroyer.positionx[1]][Destroyer.positiony[1]])==(-1) &&
                        (board1[Destroyer.positionx[2]][Destroyer.positiony[2]])==(-1))
                    {
                        for (i = 0; i < 3; i++) {
                            tabdestroyer1ax[i]=Destroyer.positionx[i];
                            tabdestroyer1ay[i]=Destroyer.positiony[i];
                            board1[tabdestroyer1ax[i]][tabdestroyer1ay[i]] = 6;
                        }
                        Destroyer.condition=1;
                    }
                }
            }
        }
    }while(Destroyer.condition==0);

    //////////////////Destroyer1/////////////////////
    Destroyer1.taille = 3;
    Destroyer1.condition=0;
    do {
        Destroyer1.positionx[0] = rand() % BoardSize;
        Destroyer1.positiony[0] = rand() % BoardSize;
        if (Destroyer1.positionx[0] < 12) {
            if (Destroyer1.positiony[0] < 12) {
                Destroyer1.orientation = rand()%Hasard;
                if (Destroyer1.orientation == 1) {
                    for (i = 0; i < Destroyer1.taille - 1; i++) {
                        Destroyer1.positionx[i + 1] = Destroyer1.positionx[i];
                        Destroyer1.positiony[i + 1] = Destroyer1.positiony[i] + 1;
                    }
                    if ((board1[Destroyer1.positionx[0]][Destroyer1.positiony[0]]) == (-1) &&
                        (board1[Destroyer1.positionx[1]][Destroyer1.positiony[1]]) == (-1) &&
                        (board1[Destroyer1.positionx[2]][Destroyer1.positiony[2]]) == (-1))
                    {
                        for (i = 0; i < 3; i++) {
                            tabdestroyer1bx[i]=Destroyer1.positionx[i];
                            tabdestroyer1by[i]=Destroyer1.positiony[i];
                            board1[tabdestroyer1bx[i]][tabdestroyer1by[i]] = 6;
                        }
                        Destroyer1.condition = 1;
                    }
                }
                else {
                    for (i = 0; i < Destroyer1.taille - 1; i++) {
                        Destroyer1.positionx[i + 1] = Destroyer1.positionx[i] + 1;
                        Destroyer1.positiony[i + 1] = Destroyer1.positiony[i];
                    }
                    if ((board1[Destroyer1.positionx[0]][Destroyer1.positiony[0]]) == (-1) &&
                        (board1[Destroyer1.positionx[1]][Destroyer1.positiony[1]]) == (-1) &&
                        (board1[Destroyer1.positionx[2]][Destroyer1.positiony[2]]) == (-1))
                    {
                        for (i = 0; i < 3; i++) {
                            tabdestroyer1bx[i]=Destroyer1.positionx[i];
                            tabdestroyer1by[i]=Destroyer1.positiony[i];
                            board1[tabdestroyer1bx[i]][tabdestroyer1by[i]] = 6;
                        }
                        Destroyer1.condition = 1;
                    }
                }
            }
            else if (Destroyer1.positiony[0] > 11) {
                Destroyer1.orientation = 0;
                if (Destroyer1.orientation == 0) {
                    for (i = 0; i < Destroyer1.taille - 1; i++) {
                        Destroyer1.positionx[i + 1] = Destroyer1.positionx[i];
                        Destroyer1.positiony[i + 1] = Destroyer1.positiony[i] - 1;
                    }
                    if ((board1[Destroyer1.positionx[0]][Destroyer1.positiony[0]])==(-1) &&
                        (board1[Destroyer1.positionx[1]][Destroyer1.positiony[1]])==(-1) &&
                        (board1[Destroyer1.positionx[2]][Destroyer1.positiony[2]])==(-1))
                    {
                        for (i = 0; i < 3; i++) {
                            tabdestroyer1bx[i]=Destroyer1.positionx[i];
                            tabdestroyer1by[i]=Destroyer1.positiony[i];
                            board1[tabdestroyer1bx[i]][tabdestroyer1by[i]] = 6;
                        }
                        Destroyer1.condition=1;
                    }
                }
                else {
                    for (i = 0; i < Destroyer1.taille - 1; i++) {
                        Destroyer1.positionx[i + 1] = Destroyer1.positionx[i] + 1;
                        Destroyer1.positiony[i + 1] = Destroyer1.positiony[i];
                    }
                    if ((board1[Destroyer1.positionx[0]][Destroyer1.positiony[0]])==(-1) &&
                        (board1[Destroyer1.positionx[1]][Destroyer1.positiony[1]])==(-1) &&
                        (board1[Destroyer1.positionx[2]][Destroyer1.positiony[2]])==(-1))
                    {
                        for (i = 0; i <3; i++) {
                            tabdestroyer1bx[i]=Destroyer1.positionx[i];
                            tabdestroyer1by[i]=Destroyer1.positiony[i];
                            board1[tabdestroyer1bx[i]][tabdestroyer1by[i]] = 6;
                        }
                        Destroyer1.condition=1;
                    }
                }
            }
        }
        else if (Destroyer1.positionx[0] > 11) {
// droite
            if (Destroyer1.positiony[0] < 12) {
                Destroyer1.orientation = rand()%Hasard;
                if (Destroyer1.orientation == 1) {
                    for (i = 0; i < Destroyer1.taille - 1; i++) {
                        Destroyer1.positionx[i + 1] = Destroyer1.positionx[i];
                        Destroyer1.positiony[i + 1] = Destroyer1.positiony[i] + 1;
                    }
                    if ((board1[Destroyer1.positionx[0]][Destroyer1.positiony[0]])==(-1) &&
                        (board1[Destroyer1.positionx[1]][Destroyer1.positiony[1]])==(-1) &&
                        (board1[Destroyer1.positionx[2]][Destroyer1.positiony[2]])==(-1) ){
                        for (i = 0; i < 3; i++) {
                            tabdestroyer1bx[i]=Destroyer1.positionx[i];
                            tabdestroyer1by[i]=Destroyer1.positiony[i];
                            board1[tabdestroyer1bx[i]][tabdestroyer1by[i]] = 6;
                        }
                        Destroyer1.condition=1;
                    }
                }
                else {
                    for (i = 0; i < Destroyer1.taille - 1; i++) {
                        Destroyer1.positionx[i + 1] = Destroyer1.positionx[i] - 1;
                        Destroyer1.positiony[i + 1] = Destroyer1.positiony[i];
                    }
                    if ((board1[Destroyer1.positionx[0]][Destroyer1.positiony[0]])==(-1) &&
                        (board1[Destroyer1.positionx[1]][Destroyer1.positiony[1]])==(-1) &&
                        (board1[Destroyer1.positionx[2]][Destroyer1.positiony[2]])==(-1)){
                        for (i = 0; i < 3; i++) {
                            tabdestroyer1bx[i]=Destroyer1.positionx[i];
                            tabdestroyer1by[i]=Destroyer1.positiony[i];
                            board1[tabdestroyer1bx[i]][tabdestroyer1by[i]] = 6;
                        }
                        Destroyer1.condition=1;
                    }
                }
            }
            else if (Destroyer1.positiony > 11) {
                if (Destroyer1.orientation == 1) {
                    Destroyer1.orientation = 0;
                    for (i = 0; i < Destroyer1.taille - 1; i++) {
                        Destroyer1.positionx[i + 1] = Destroyer1.positionx[i];
                        Destroyer1.positiony[i + 1] = Destroyer1.positiony[i] - 1;
                    }
                    if ((board1[Destroyer1.positionx[0]][Destroyer1.positiony[0]])==(-1) &&
                        (board1[Destroyer1.positionx[1]][Destroyer1.positiony[1]])==(-1) &&
                        (board1[Destroyer1.positionx[2]][Destroyer1.positiony[2]])==(-1))
                    {
                        for (i = 0; i < 6; i++) {
                            tabdestroyer1bx[i]=Destroyer1.positionx[i];
                            tabdestroyer1by[i]=Destroyer1.positiony[i];
                            board1[tabdestroyer1bx[i]][tabdestroyer1by[i]] = 6;
                        }
                        Destroyer1.condition=1;
                    }
                }
                else {
                    for (i = 0; i < Destroyer1.taille - 1; i++) {
                        Destroyer1.positionx[i + 1] = Destroyer1.positionx[i] - 1;
                        Destroyer1.positiony[i + 1] = Destroyer1.positiony[i];
                    }
                    if ((board1[Destroyer1.positionx[0]][Destroyer1.positiony[0]])==(-1) &&
                        (board1[Destroyer1.positionx[1]][Destroyer1.positiony[1]])==(-1) &&
                        (board1[Destroyer1.positionx[2]][Destroyer1.positiony[2]])==(-1))
                    {
                        for (i = 0; i < 3; i++) {
                            tabdestroyer1bx[i]=Destroyer1.positionx[i];
                            tabdestroyer1by[i]=Destroyer1.positiony[i];
                            board1[tabdestroyer1bx[i]][tabdestroyer1by[i]] = 6;
                        }
                        Destroyer1.condition=1;
                    }
                }
            }
        }
    }while(Destroyer1.condition==0);

    //////////////////Destroyer2/////////////////////
    Destroyer2.taille = 3;
    Destroyer2.condition=0;
    do {
        Destroyer2.positionx[0] = rand() % BoardSize;
        Destroyer2.positiony[0] = rand() % BoardSize;
        if (Destroyer2.positionx[0] < 12) {
            if (Destroyer2.positiony[0] < 12) {
                Destroyer2.orientation = rand()%Hasard;
                if (Destroyer2.orientation == 1) {
                    for (i = 0; i < Destroyer2.taille - 1; i++) {
                        Destroyer2.positionx[i + 1] = Destroyer2.positionx[i];
                        Destroyer2.positiony[i + 1] = Destroyer2.positiony[i] + 1;
                    }
                    if ((board1[Destroyer2.positionx[0]][Destroyer2.positiony[0]]) == (-1) &&
                        (board1[Destroyer2.positionx[1]][Destroyer2.positiony[1]]) == (-1) &&
                        (board1[Destroyer2.positionx[2]][Destroyer2.positiony[2]]) == (-1))
                    {
                        for (i = 0; i < 3; i++) {
                            tabdestroyer1cx[i]=Destroyer2.positionx[i];
                            tabdestroyer1cy[i]=Destroyer2.positiony[i];
                            board1[tabdestroyer1cx[i]][tabdestroyer1cy[i]] = 6;
                        }
                        Destroyer2.condition = 1;
                    }
                }
                else {
                    for (i = 0; i < Destroyer2.taille - 1; i++) {
                        Destroyer2.positionx[i + 1] = Destroyer2.positionx[i] + 1;
                        Destroyer2.positiony[i + 1] = Destroyer2.positiony[i];
                    }
                    if ((board1[Destroyer2.positionx[0]][Destroyer2.positiony[0]]) == (-1) &&
                        (board1[Destroyer2.positionx[1]][Destroyer2.positiony[1]]) == (-1) &&
                        (board1[Destroyer2.positionx[2]][Destroyer2.positiony[2]]) == (-1) )
                    {
                        for (i = 0; i < 3; i++) {
                            tabdestroyer1cx[i]=Destroyer2.positionx[i];
                            tabdestroyer1cy[i]=Destroyer2.positiony[i];
                            board1[tabdestroyer1cx[i]][tabdestroyer1cy[i]] = 6;
                        }
                        Destroyer2.condition = 1;
                    }
                }
            }
            else if (Destroyer2.positiony[0] > 11) {
                Destroyer2.orientation = 0;
                if (Destroyer2.orientation == 0) {
                    for (i = 0; i < Destroyer2.taille - 1; i++) {
                        Destroyer2.positionx[i + 1] = Destroyer2.positionx[i];
                        Destroyer2.positiony[i + 1] = Destroyer2.positiony[i] - 1;
                    }
                    if ((board1[Destroyer2.positionx[0]][Destroyer2.positiony[0]])==(-1) &&
                        (board1[Destroyer2.positionx[1]][Destroyer2.positiony[1]])==(-1) &&
                        (board1[Destroyer2.positionx[2]][Destroyer2.positiony[2]])==(-1))
                    {
                        for (i = 0; i < 3; i++) {
                            tabdestroyer1cx[i]=Destroyer2.positionx[i];
                            tabdestroyer1cy[i]=Destroyer2.positiony[i];
                            board1[tabdestroyer1cx[i]][tabdestroyer1cy[i]] = 6;
                        }
                        Destroyer2.condition=1;
                    }
                }
                else {
                    for (i = 0; i < Destroyer2.taille - 1; i++) {
                        Destroyer2.positionx[i + 1] = Destroyer2.positionx[i] + 1;
                        Destroyer2.positiony[i + 1] = Destroyer2.positiony[i];
                    }
                    if ((board1[Destroyer2.positionx[0]][Destroyer2.positiony[0]])==(-1) &&
                        (board1[Destroyer2.positionx[1]][Destroyer2.positiony[1]])==(-1) &&
                        (board1[Destroyer2.positionx[2]][Destroyer2.positiony[2]])==(-1))
                    {
                        for (i = 0; i <3; i++) {
                            tabdestroyer1cx[i]=Destroyer2.positionx[i];
                            tabdestroyer1cy[i]=Destroyer2.positiony[i];
                            board1[tabdestroyer1cx[i]][tabdestroyer1cy[i]] = 6;
                        }
                        Destroyer2.condition=1;
                    }
                }
            }
        }
        else if (Destroyer2.positionx[0] > 11) {
// droite
            if (Destroyer2.positiony[0] < 12) {
                Destroyer2.orientation = rand()%Hasard;
                if (Destroyer2.orientation == 1) {
                    for (i = 0; i < Destroyer2.taille - 1; i++) {
                        Destroyer2.positionx[i + 1] = Destroyer2.positionx[i];
                        Destroyer2.positiony[i + 1] = Destroyer2.positiony[i] + 1;
                    }
                    if ((board1[Destroyer2.positionx[0]][Destroyer2.positiony[0]])==(-1) &&
                        (board1[Destroyer2.positionx[1]][Destroyer2.positiony[1]])==(-1) &&
                        (board1[Destroyer2.positionx[2]][Destroyer2.positiony[2]])==(-1)){
                        for (i = 0; i < 3; i++) {
                            tabdestroyer1cx[i]=Destroyer2.positionx[i];
                            tabdestroyer1cy[i]=Destroyer2.positiony[i];
                            board1[tabdestroyer1cx[i]][tabdestroyer1cy[i]] = 6;
                        }
                        Destroyer2.condition=1;
                    }
                }
                else {

                    for (i = 0; i < Destroyer2.taille - 1; i++) {
                        Destroyer2.positionx[i + 1] = Destroyer2.positionx[i] - 1;
                        Destroyer2.positiony[i + 1] = Destroyer2.positiony[i];
                    }
                    if ((board1[Destroyer2.positionx[0]][Destroyer2.positiony[0]])==(-1) &&
                        (board1[Destroyer2.positionx[1]][Destroyer2.positiony[1]])==(-1) &&
                        (board1[Destroyer2.positionx[2]][Destroyer2.positiony[2]])==(-1)){
                        for (i = 0; i < 3; i++) {
                            tabdestroyer1cx[i]=Destroyer2.positionx[i];
                            tabdestroyer1cy[i]=Destroyer2.positiony[i];
                            board1[tabdestroyer1cx[i]][tabdestroyer1cy[i]] = 6;
                        }
                        Destroyer2.condition=1;
                    }
                }
            }
            else if (Destroyer2.positiony > 11) {
                Destroyer2.orientation = 0;
                if (Destroyer2.orientation == 1) {
                    for (i = 0; i < Destroyer2.taille - 1; i++) {
                        Destroyer2.positionx[i + 1] = Destroyer2.positionx[i];
                        Destroyer2.positiony[i + 1] = Destroyer2.positiony[i] - 1;
                    }
                    if ((board1[Destroyer2.positionx[0]][Destroyer2.positiony[0]])==(-1) &&
                        (board1[Destroyer2.positionx[1]][Destroyer2.positiony[1]])==(-1) &&
                        (board1[Destroyer2.positionx[2]][Destroyer2.positiony[2]])==(-1) )
                    {
                        for (i = 0; i < 6; i++) {
                            tabdestroyer1cx[i]=Destroyer2.positionx[i];
                            tabdestroyer1cy[i]=Destroyer2.positiony[i];
                            board1[tabdestroyer1cx[i]][tabdestroyer1cy[i]] = 6;
                        }
                        Destroyer2.condition=1;
                    }
                }
                else {
                    for (i = 0; i < Destroyer2.taille - 1; i++) {
                        Destroyer2.positionx[i + 1] = Destroyer2.positionx[i] - 1;
                        Destroyer2.positiony[i + 1] = Destroyer2.positiony[i];
                    }
                    if ((board1[Destroyer2.positionx[0]][Destroyer2.positiony[0]])==(-1) &&
                        (board1[Destroyer2.positionx[1]][Destroyer2.positiony[1]])==(-1) &&
                        (board1[Destroyer2.positionx[2]][Destroyer2.positiony[2]])==(-1))
                    {
                        for (i = 0; i < 3; i++) {
                            tabdestroyer1cx[i]=Destroyer2.positionx[i];
                            tabdestroyer1cy[i]=Destroyer2.positiony[i];
                            board1[tabdestroyer1cx[i]][tabdestroyer1cy[i]] = 6;
                        }
                        Destroyer2.condition=1;
                    }
                }
            }
        }
    }while(Destroyer2.condition==0);

    //////////////////SousMarrin//////////////////
    SousMarrin.taille = 1;

    SousMarrin.condition=0;
    do {
        SousMarrin.positionx[0] = rand() % BoardSize;
        SousMarrin.positiony[0] = rand() % BoardSize;
        if (board1[SousMarrin.positionx[0]][SousMarrin.positiony[0]]==-1){
            tabsousmarrin1ay[0]=SousMarrin.positiony[0];
            tabsousmarrin1ax[0]=SousMarrin.positionx[0];
            board1[tabsousmarrin1ax[0]][tabsousmarrin1ay[0]]=7;
            SousMarrin.condition=1;
        }
    }while(SousMarrin.condition==0);

    //////////////////SousMarrin1/////////////////
    SousMarrin1.taille = 1;

    SousMarrin1.condition=0;
    do {
        SousMarrin1.positionx[0] = rand() % BoardSize;
        SousMarrin1.positiony[0] = rand() % BoardSize;
        if (board1[SousMarrin1.positionx[0]][SousMarrin1.positiony[0]]==-1){
            tabsousmarrin1by[0]=SousMarrin1.positiony[0];
            tabsousmarrin1bx[0]=SousMarrin1.positionx[0];
            board1[tabsousmarrin1bx[0]][tabsousmarrin1by[0]]=7;
            SousMarrin1.condition=1;
        }
    }while(SousMarrin1.condition==0);

    //////////////////SousMarrin2/////////////////
    SousMarrin2.taille = 1;

    SousMarrin2.condition=0;
    do {
        SousMarrin2.positionx[0] = rand() % BoardSize;
        SousMarrin2.positiony[0] = rand() % BoardSize;
        if (board1[SousMarrin2.positionx[0]][SousMarrin2.positiony[0]]==-1){
            tabsousmarrin1cy[0]=SousMarrin2.positiony[0];
            tabsousmarrin1cx[0]=SousMarrin2.positionx[0];
            board1[tabsousmarrin1cx[0]][tabsousmarrin1cy[0]]=7;
            SousMarrin2.condition=1;
        }
    }while(SousMarrin2.condition==0);

    //////////////////SousMarrin3//////////////////
    SousMarrin3.taille = 1;

    SousMarrin3.condition=0;
    do {
        SousMarrin3.positionx[0] = rand() % BoardSize;
        SousMarrin3.positiony[0] = rand() % BoardSize;
        if (board1[SousMarrin3.positionx[0]][SousMarrin3.positiony[0]]==-1){
            tabsousmarrin1dy[0]=SousMarrin3.positiony[0];
            tabsousmarrin1dx[0]=SousMarrin3.positionx[0];
            board1[tabsousmarrin1dx[0]][tabsousmarrin1dy[0]]=7;
            SousMarrin3.condition=1;
        }
    }while(SousMarrin3.condition==0);
    ///////////////////////////////////////////////

}
//Place aleatoire les bateaux de l'ordianteur
void positionnementbateaux2()
{
    srand(time(NULL));
    t_porteavion PorteAvion;
    t_croiseur Croiseur;
    t_croiseur Croiseur1;
    t_destroyer Destroyer;
    t_destroyer Destroyer1;
    t_destroyer Destroyer2;
    t_sousmarrin SousMarrin;
    t_sousmarrin SousMarrin1;
    t_sousmarrin SousMarrin2;
    t_sousmarrin SousMarrin3;

    int i = 0;

    //////////////////PorteAvion/////////////////////
    PorteAvion.taille = 7;
    PorteAvion.condition=0;
    do {
        PorteAvion.positionx[0] = rand() % BoardSize;
        PorteAvion.positiony[0] = rand() % BoardSize;
        if (PorteAvion.positionx[0] < 8) {
            if (PorteAvion.positiony[0] < 8) {
                PorteAvion.orientation = rand()%Hasardb;
                if (PorteAvion.orientation == 1) {
                    for (i = 0; i < PorteAvion.taille - 1; i++) {
                        PorteAvion.positionx[i + 1] = PorteAvion.positionx[i];
                        PorteAvion.positiony[i + 1] = PorteAvion.positiony[i] + 1;
                    }
                    if ((board2[PorteAvion.positionx[0]][PorteAvion.positiony[0]]) == (-1) &&
                        (board2[PorteAvion.positionx[1]][PorteAvion.positiony[1]]) == (-1) &&
                        (board2[PorteAvion.positionx[2]][PorteAvion.positiony[2]]) == (-1) &&
                        (board2[PorteAvion.positionx[3]][PorteAvion.positiony[3]]) == (-1) &&
                        (board2[PorteAvion.positionx[4]][PorteAvion.positiony[4]]) == (-1) &&
                        (board2[PorteAvion.positionx[5]][PorteAvion.positiony[5]]) == (-1) &&
                        (board2[PorteAvion.positionx[6]][PorteAvion.positiony[6]]) == (-1))
                    {
                        for (i = 0; i < 7; i++) {
                            tabporteavion2x[i]=PorteAvion.positionx[i];
                            tabporteavion2y[i]=PorteAvion.positiony[i];
                            board2[tabporteavion2x[i]][tabporteavion2y[i]] = 4;
                        }
                        PorteAvion.condition = 1;
                    }
                }
                else {
                    for (i = 0; i < PorteAvion.taille - 1; i++) {
                        PorteAvion.positionx[i + 1] = PorteAvion.positionx[i] + 1;
                        PorteAvion.positiony[i + 1] = PorteAvion.positiony[i];
                    }
                    if ((board2[PorteAvion.positionx[0]][PorteAvion.positiony[0]]) == (-1) &&
                        (board2[PorteAvion.positionx[1]][PorteAvion.positiony[1]]) == (-1) &&
                        (board2[PorteAvion.positionx[2]][PorteAvion.positiony[2]]) == (-1) &&
                        (board2[PorteAvion.positionx[3]][PorteAvion.positiony[3]]) == (-1) &&
                        (board2[PorteAvion.positionx[4]][PorteAvion.positiony[4]]) == (-1) &&
                        (board2[PorteAvion.positionx[5]][PorteAvion.positiony[5]]) == (-1) &&
                        (board2[PorteAvion.positionx[6]][PorteAvion.positiony[6]]) == (-1))
                    {
                        for (i = 0; i < 7; i++) {
                            tabporteavion2x[i]=PorteAvion.positionx[i];
                            tabporteavion2y[i]=PorteAvion.positiony[i];
                            board2[tabporteavion2x[i]][tabporteavion2y[i]] = 4;
                        }
                        PorteAvion.condition = 1;
                    }
                }
            }
            else if (PorteAvion.positiony[0] > 7) {
                PorteAvion.orientation = 0;
                if (PorteAvion.orientation == 0) {
                    for (i = 0; i < PorteAvion.taille - 1; i++) {
                        PorteAvion.positionx[i + 1] = PorteAvion.positionx[i];
                        PorteAvion.positiony[i + 1] = PorteAvion.positiony[i] - 1;
                    }
                    if ((board2[PorteAvion.positionx[0]][PorteAvion.positiony[0]]) == (-1) &&
                        (board2[PorteAvion.positionx[1]][PorteAvion.positiony[1]]) == (-1) &&
                        (board2[PorteAvion.positionx[2]][PorteAvion.positiony[2]]) == (-1) &&
                        (board2[PorteAvion.positionx[3]][PorteAvion.positiony[3]]) == (-1) &&
                        (board2[PorteAvion.positionx[4]][PorteAvion.positiony[4]]) == (-1) &&
                        (board2[PorteAvion.positionx[5]][PorteAvion.positiony[5]]) == (-1) &&
                        (board2[PorteAvion.positionx[6]][PorteAvion.positiony[6]]) == (-1))
                    {
                        for (i = 0; i < 7; i++) {
                            tabporteavion2x[i]=PorteAvion.positionx[i];
                            tabporteavion2y[i]=PorteAvion.positiony[i];
                            board2[tabporteavion2x[i]][tabporteavion2y[i]] = 4;
                        }
                        PorteAvion.condition=1;
                    }
                }
                else {
                    for (i = 0; i < PorteAvion.taille - 1; i++) {
                        PorteAvion.positionx[i + 1] = PorteAvion.positionx[i] + 1;
                        PorteAvion.positiony[i + 1] = PorteAvion.positiony[i];
                    }
                    if ((board2[PorteAvion.positionx[0]][PorteAvion.positiony[0]]) == (-1) &&
                        (board2[PorteAvion.positionx[1]][PorteAvion.positiony[1]]) == (-1) &&
                        (board2[PorteAvion.positionx[2]][PorteAvion.positiony[2]]) == (-1) &&
                        (board2[PorteAvion.positionx[3]][PorteAvion.positiony[3]]) == (-1) &&
                        (board2[PorteAvion.positionx[4]][PorteAvion.positiony[4]]) == (-1) &&
                        (board2[PorteAvion.positionx[5]][PorteAvion.positiony[5]]) == (-1) &&
                        (board2[PorteAvion.positionx[6]][PorteAvion.positiony[6]]) == (-1))
                    {
                        for (i = 0; i < 7; i++) {
                            tabporteavion2x[i]=PorteAvion.positionx[i];
                            tabporteavion2y[i]=PorteAvion.positiony[i];
                            board2[tabporteavion2x[i]][tabporteavion2y[i]] = 4;
                        }
                        PorteAvion.condition=1;
                    }
                }
            }
        }
        else if (PorteAvion.positionx[0] > 7) {
            // droite
            if (PorteAvion.positiony[0] < 8) {
                PorteAvion.orientation = rand()%Hasardb;
                if (PorteAvion.orientation == 1) {
                    for (i = 0; i < PorteAvion.taille - 1; i++) {
                        PorteAvion.positionx[i + 1] = PorteAvion.positionx[i];
                        PorteAvion.positiony[i + 1] = PorteAvion.positiony[i] + 1;
                    }
                    if ((board2[PorteAvion.positionx[0]][PorteAvion.positiony[0]]) == (-1) &&
                        (board2[PorteAvion.positionx[1]][PorteAvion.positiony[1]]) == (-1) &&
                        (board2[PorteAvion.positionx[2]][PorteAvion.positiony[2]]) == (-1) &&
                        (board2[PorteAvion.positionx[3]][PorteAvion.positiony[3]]) == (-1) &&
                        (board2[PorteAvion.positionx[4]][PorteAvion.positiony[4]]) == (-1) &&
                        (board2[PorteAvion.positionx[5]][PorteAvion.positiony[5]]) == (-1) &&
                        (board2[PorteAvion.positionx[6]][PorteAvion.positiony[6]]) == (-1))
                    {
                        for (i = 0; i < 7; i++) {
                            tabporteavion2x[i]=PorteAvion.positionx[i];
                            tabporteavion2y[i]=PorteAvion.positiony[i];
                            board2[tabporteavion2x[i]][tabporteavion2y[i]] = 4;
                        }
                        PorteAvion.condition=1;
                    }
                }
                else {
                    for (i = 0; i < PorteAvion.taille - 1; i++) {
                        PorteAvion.positionx[i + 1] = PorteAvion.positionx[i] - 1;
                        PorteAvion.positiony[i + 1] = PorteAvion.positiony[i];
                    }
                    if ((board2[PorteAvion.positionx[0]][PorteAvion.positiony[0]]) == (-1) &&
                        (board2[PorteAvion.positionx[1]][PorteAvion.positiony[1]]) == (-1) &&
                        (board2[PorteAvion.positionx[2]][PorteAvion.positiony[2]]) == (-1) &&
                        (board2[PorteAvion.positionx[3]][PorteAvion.positiony[3]]) == (-1) &&
                        (board2[PorteAvion.positionx[4]][PorteAvion.positiony[4]]) == (-1) &&
                        (board2[PorteAvion.positionx[5]][PorteAvion.positiony[5]]) == (-1) &&
                        (board2[PorteAvion.positionx[6]][PorteAvion.positiony[6]]) == (-1))
                    {
                        for (i = 0; i < 7; i++) {
                            tabporteavion2x[i]=PorteAvion.positionx[i];
                            tabporteavion2y[i]=PorteAvion.positiony[i];
                            board2[tabporteavion2x[i]][tabporteavion2y[i]] = 4;
                        }
                        PorteAvion.condition=1;
                    }
                }
            }
            else if (PorteAvion.positiony > 7) {
                PorteAvion.orientation = 0;
                if (PorteAvion.orientation == 1) {
                    for (i = 0; i < PorteAvion.taille - 1; i++) {
                        PorteAvion.positionx[i + 1] = PorteAvion.positionx[i];
                        PorteAvion.positiony[i + 1] = PorteAvion.positiony[i] - 1;
                    }
                    if ((board2[PorteAvion.positionx[0]][PorteAvion.positiony[0]]) == (-1) &&
                        (board2[PorteAvion.positionx[1]][PorteAvion.positiony[1]]) == (-1) &&
                        (board2[PorteAvion.positionx[2]][PorteAvion.positiony[2]]) == (-1) &&
                        (board2[PorteAvion.positionx[3]][PorteAvion.positiony[3]]) == (-1) &&
                        (board2[PorteAvion.positionx[4]][PorteAvion.positiony[4]]) == (-1) &&
                        (board2[PorteAvion.positionx[5]][PorteAvion.positiony[5]]) == (-1) &&
                        (board2[PorteAvion.positionx[6]][PorteAvion.positiony[6]]) == (-1))
                    {
                        for (i = 0; i < 7; i++) {
                            tabporteavion2x[i]=PorteAvion.positionx[i];
                            tabporteavion2y[i]=PorteAvion.positiony[i];
                            board2[tabporteavion2x[i]][tabporteavion2y[i]] = 4;
                        }
                        PorteAvion.condition=1;
                    }
                }
                else {
                    for (i = 0; i < PorteAvion.taille - 1; i++) {
                        PorteAvion.positionx[i + 1] = PorteAvion.positionx[i] - 1;
                        PorteAvion.positiony[i + 1] = PorteAvion.positiony[i];
                    }
                    if ((board2[PorteAvion.positionx[0]][PorteAvion.positiony[0]]) == (-1) &&
                        (board2[PorteAvion.positionx[1]][PorteAvion.positiony[1]]) == (-1) &&
                        (board2[PorteAvion.positionx[2]][PorteAvion.positiony[2]]) == (-1) &&
                        (board2[PorteAvion.positionx[3]][PorteAvion.positiony[3]]) == (-1) &&
                        (board2[PorteAvion.positionx[4]][PorteAvion.positiony[4]]) == (-1) &&
                        (board2[PorteAvion.positionx[5]][PorteAvion.positiony[5]]) == (-1) &&
                        (board2[PorteAvion.positionx[6]][PorteAvion.positiony[6]]) == (-1))
                    {
                        for (i = 0; i < 7; i++) {
                            tabporteavion2x[i]=PorteAvion.positionx[i];
                            tabporteavion2y[i]=PorteAvion.positiony[i];
                            board2[tabporteavion2x[i]][tabporteavion2y[i]] = 4;
                        }
                        PorteAvion.condition=1;
                    }
                }
            }
        }
    }while(PorteAvion.condition==0);

    //////////////////Croiseur/////////////////////
    Croiseur.taille = 5;
    Croiseur.condition = 0;
    do {
        Croiseur.positionx[0] = rand() % BoardSize;
        Croiseur.positiony[0] = rand() % BoardSize;
        if (Croiseur.positionx[0] < 10) {
            if (Croiseur.positiony[0] < 10) {
                Croiseur.orientation = rand()%Hasardb;
                if (Croiseur.orientation == 1) {
                    for (i = 0; i < Croiseur.taille - 1; i++) {
                        Croiseur.positionx[i + 1] = Croiseur.positionx[i];
                        Croiseur.positiony[i + 1] = Croiseur.positiony[i] + 1;
                    }
                    if ((board2[Croiseur.positionx[0]][Croiseur.positiony[0]]) == (-1) &&
                        (board2[Croiseur.positionx[1]][Croiseur.positiony[1]]) == (-1) &&
                        (board2[Croiseur.positionx[2]][Croiseur.positiony[2]]) == (-1) &&
                        (board2[Croiseur.positionx[3]][Croiseur.positiony[3]]) == (-1) &&
                        (board2[Croiseur.positionx[4]][Croiseur.positiony[4]]) == (-1)) {
                        for (i = 0; i < 5; i++) {
                            tabcroiseur2ax[i]=Croiseur.positionx[i];
                            tabcroiseur2ay[i]=Croiseur.positiony[i];
                            board2[tabcroiseur2ax[i]][tabcroiseur2ay[i]] = 5;
                        }
                        Croiseur.condition = 1;
                    }
                } else {

                    for (i = 0; i < Croiseur.taille - 1; i++) {
                        Croiseur.positionx[i + 1] = Croiseur.positionx[i] + 1;
                        Croiseur.positiony[i + 1] = Croiseur.positiony[i];
                    }
                    if ((board2[Croiseur.positionx[0]][Croiseur.positiony[0]]) == (-1) &&
                        (board2[Croiseur.positionx[1]][Croiseur.positiony[1]]) == (-1) &&
                        (board2[Croiseur.positionx[2]][Croiseur.positiony[2]]) == (-1) &&
                        (board2[Croiseur.positionx[3]][Croiseur.positiony[3]]) == (-1) &&
                        (board2[Croiseur.positionx[4]][Croiseur.positiony[4]]) == (-1)) {
                        for (i = 0; i < 5; i++) {
                            tabcroiseur2ax[i]=Croiseur.positionx[i];
                            tabcroiseur2ay[i]=Croiseur.positiony[i];
                            board2[tabcroiseur2ax[i]][tabcroiseur2ay[i]] = 5;
                        }
                        Croiseur.condition = 1;
                    }
                }
            } else if (Croiseur.positiony[0] > 9) {
                Croiseur.orientation = 0;
                if (Croiseur.orientation == 0) {
                    for (i = 0; i < Croiseur.taille - 1; i++) {
                        Croiseur.positionx[i + 1] = Croiseur.positionx[i];
                        Croiseur.positiony[i + 1] = Croiseur.positiony[i] - 1;
                    }
                    if ((board2[Croiseur.positionx[0]][Croiseur.positiony[0]]) == (-1) &&
                        (board2[Croiseur.positionx[1]][Croiseur.positiony[1]]) == (-1) &&
                        (board2[Croiseur.positionx[2]][Croiseur.positiony[2]]) == (-1) &&
                        (board2[Croiseur.positionx[3]][Croiseur.positiony[3]]) == (-1) &&
                        (board2[Croiseur.positionx[4]][Croiseur.positiony[4]]) == (-1)) {
                        for (i = 0; i < 5; i++) {
                            tabcroiseur2ax[i]=Croiseur.positionx[i];
                            tabcroiseur2ay[i]=Croiseur.positiony[i];
                            board2[tabcroiseur2ax[i]][tabcroiseur2ay[i]] = 5;
                        }
                        Croiseur.condition = 1;
                    }
                } else {
                    for (i = 0; i < Croiseur.taille - 1; i++) {
                        Croiseur.positionx[i + 1] = Croiseur.positionx[i] + 1;
                        Croiseur.positiony[i + 1] = Croiseur.positiony[i];
                    }
                    if ((board2[Croiseur.positionx[0]][Croiseur.positiony[0]]) == (-1) &&
                        (board2[Croiseur.positionx[1]][Croiseur.positiony[1]]) == (-1) &&
                        (board2[Croiseur.positionx[2]][Croiseur.positiony[2]]) == (-1) &&
                        (board2[Croiseur.positionx[3]][Croiseur.positiony[3]]) == (-1) &&
                        (board2[Croiseur.positionx[4]][Croiseur.positiony[4]]) == (-1)) {
                        for (i = 0; i < 5; i++) {
                            tabcroiseur2ax[i]=Croiseur.positionx[i];
                            tabcroiseur2ay[i]=Croiseur.positiony[i];
                            board2[tabcroiseur2ax[i]][tabcroiseur2ay[i]] = 5;
                        }
                        Croiseur.condition = 1;
                    }
                }
            }
        } else if (Croiseur.positionx[0] > 9) {
            // droite
            if (Croiseur.positiony[0] < 10) {
                Croiseur.orientation = rand()%Hasardb;
                if (Croiseur.orientation == 1) {
                    for (i = 0; i < Croiseur.taille - 1; i++) {
                        Croiseur.positionx[i + 1] = Croiseur.positionx[i];
                        Croiseur.positiony[i + 1] = Croiseur.positiony[i] + 1;
                    }
                    if ((board2[Croiseur.positionx[0]][Croiseur.positiony[0]]) == (-1) &&
                        (board2[Croiseur.positionx[1]][Croiseur.positiony[1]]) == (-1) &&
                        (board2[Croiseur.positionx[2]][Croiseur.positiony[2]]) == (-1) &&
                        (board2[Croiseur.positionx[3]][Croiseur.positiony[3]]) == (-1) &&
                        (board2[Croiseur.positionx[4]][Croiseur.positiony[4]]) == (-1)) {
                        for (i = 0; i < 5; i++) {
                            tabcroiseur2ax[i]=Croiseur.positionx[i];
                            tabcroiseur2ay[i]=Croiseur.positiony[i];
                            board2[tabcroiseur2ax[i]][tabcroiseur2ay[i]] = 5;
                        }
                        Croiseur.condition = 1;
                    }
                } else {
                    for (i = 0; i < Croiseur.taille - 1; i++) {
                        Croiseur.positionx[i + 1] = Croiseur.positionx[i] - 1;
                        Croiseur.positiony[i + 1] = Croiseur.positiony[i];
                    }
                    if ((board2[Croiseur.positionx[0]][Croiseur.positiony[0]]) == (-1) &&
                        (board2[Croiseur.positionx[1]][Croiseur.positiony[1]]) == (-1) &&
                        (board2[Croiseur.positionx[2]][Croiseur.positiony[2]]) == (-1) &&
                        (board2[Croiseur.positionx[3]][Croiseur.positiony[3]]) == (-1) &&
                        (board2[Croiseur.positionx[4]][Croiseur.positiony[4]]) == (-1)) {
                        for (i = 0; i < 5; i++) {
                            tabcroiseur2ax[i]=Croiseur.positionx[i];
                            tabcroiseur2ay[i]=Croiseur.positiony[i];
                            board2[tabcroiseur2ax[i]][tabcroiseur2ay[i]] = 5;
                        }
                        Croiseur.condition = 1;
                    }
                }
            } else if (Croiseur.positiony > 9) {
                Croiseur.orientation =0;
                if (Croiseur.orientation == 1) {
                    for (i = 0; i < Croiseur.taille - 1; i++) {
                        Croiseur.positionx[i + 1] = Croiseur.positionx[i];
                        Croiseur.positiony[i + 1] = Croiseur.positiony[i] - 1;
                    }
                    if ((board2[Croiseur.positionx[0]][Croiseur.positiony[0]]) == (-1) &&
                        (board2[Croiseur.positionx[1]][Croiseur.positiony[1]]) == (-1) &&
                        (board2[Croiseur.positionx[2]][Croiseur.positiony[2]]) == (-1) &&
                        (board2[Croiseur.positionx[3]][Croiseur.positiony[3]]) == (-1) &&
                        (board2[Croiseur.positionx[4]][Croiseur.positiony[4]]) == (-1)) {
                        for (i = 0; i < 5; i++) {
                            tabcroiseur2ax[i]=Croiseur.positionx[i];
                            tabcroiseur2ay[i]=Croiseur.positiony[i];
                            board2[tabcroiseur2ax[i]][tabcroiseur2ay[i]] = 5;
                        }
                        Croiseur.condition = 1;
                    }
                } else {
                    for (i = 0; i < Croiseur.taille - 1; i++) {
                        Croiseur.positionx[i + 1] = Croiseur.positionx[i] - 1;
                        Croiseur.positiony[i + 1] = Croiseur.positiony[i];
                    }
                    if ((board2[Croiseur.positionx[0]][Croiseur.positiony[0]]) == (-1) &&
                        (board2[Croiseur.positionx[1]][Croiseur.positiony[1]]) == (-1) &&
                        (board2[Croiseur.positionx[2]][Croiseur.positiony[2]]) == (-1) &&
                        (board2[Croiseur.positionx[3]][Croiseur.positiony[3]]) == (-1) &&
                        (board2[Croiseur.positionx[4]][Croiseur.positiony[4]]) == (-1)) {
                        for (i = 0; i < 5; i++) {
                            tabcroiseur2ax[i]=Croiseur.positionx[i];
                            tabcroiseur2ay[i]=Croiseur.positiony[i];
                            board2[tabcroiseur2ax[i]][tabcroiseur2ay[i]] = 5;
                        }
                        Croiseur.condition = 1;
                    }
                }
            }
        }
    } while (Croiseur.condition == 0);

    //////////////////Croiseur1/////////////////////
    Croiseur1.taille = 5;
    Croiseur1.condition = 0;
    do {
        Croiseur1.positionx[0] = rand() % BoardSize;
        Croiseur1.positiony[0] = rand() % BoardSize;
        if (Croiseur1.positionx[0] < 10) {
            if (Croiseur1.positiony[0] < 10) {
                Croiseur1.orientation = rand()%Hasardb;
                if (Croiseur1.orientation == 1) {
                    for (i = 0; i < Croiseur1.taille - 1; i++) {
                        Croiseur1.positionx[i + 1] = Croiseur1.positionx[i];
                        Croiseur1.positiony[i + 1] = Croiseur1.positiony[i] + 1;
                    }
                    if ((board2[Croiseur1.positionx[0]][Croiseur1.positiony[0]]) == (-1) &&
                        (board2[Croiseur1.positionx[1]][Croiseur1.positiony[1]]) == (-1) &&
                        (board2[Croiseur1.positionx[2]][Croiseur1.positiony[2]]) == (-1) &&
                        (board2[Croiseur1.positionx[3]][Croiseur1.positiony[3]]) == (-1) &&
                        (board2[Croiseur1.positionx[4]][Croiseur1.positiony[4]]) == (-1)) {
                        for (i = 0; i < 5; i++) {
                            tabcroiseur2bx[i]=Croiseur1.positionx[i];
                            tabcroiseur2by[i]=Croiseur1.positiony[i];
                            board2[tabcroiseur2bx[i]][tabcroiseur2by[i]] = 5;
                        }
                        Croiseur1.condition = 1;
                    }
                } else {

                    for (i = 0; i < Croiseur1.taille - 1; i++) {
                        Croiseur1.positionx[i + 1] = Croiseur1.positionx[i] + 1;
                        Croiseur1.positiony[i + 1] = Croiseur1.positiony[i];
                    }
                    if ((board2[Croiseur1.positionx[0]][Croiseur1.positiony[0]]) == (-1) &&
                        (board2[Croiseur1.positionx[1]][Croiseur1.positiony[1]]) == (-1) &&
                        (board2[Croiseur1.positionx[2]][Croiseur1.positiony[2]]) == (-1) &&
                        (board2[Croiseur1.positionx[3]][Croiseur1.positiony[3]]) == (-1) &&
                        (board2[Croiseur1.positionx[4]][Croiseur1.positiony[4]]) == (-1)) {
                        for (i = 0; i < 5; i++) {
                            tabcroiseur2bx[i]=Croiseur1.positionx[i];
                            tabcroiseur2by[i]=Croiseur1.positiony[i];
                            board2[tabcroiseur2bx[i]][tabcroiseur2by[i]] = 5;
                        }
                        Croiseur1.condition = 1;
                    }
                }
            } else if (Croiseur1.positiony[0] > 9) {
                Croiseur1.orientation = 0;
                if (Croiseur1.orientation == 0) {
                    for (i = 0; i < Croiseur1.taille - 1; i++) {
                        Croiseur1.positionx[i + 1] = Croiseur1.positionx[i];
                        Croiseur1.positiony[i + 1] = Croiseur1.positiony[i] - 1;
                    }
                    if ((board2[Croiseur1.positionx[0]][Croiseur1.positiony[0]]) == (-1) &&
                        (board2[Croiseur1.positionx[1]][Croiseur1.positiony[1]]) == (-1) &&
                        (board2[Croiseur1.positionx[2]][Croiseur1.positiony[2]]) == (-1) &&
                        (board2[Croiseur1.positionx[3]][Croiseur1.positiony[3]]) == (-1) &&
                        (board2[Croiseur1.positionx[4]][Croiseur1.positiony[4]]) == (-1)) {
                        for (i = 0; i < 5; i++) {
                            tabcroiseur2bx[i]=Croiseur1.positionx[i];
                            tabcroiseur2by[i]=Croiseur1.positiony[i];
                            board2[tabcroiseur2bx[i]][tabcroiseur2by[i]] = 5;
                        }
                        Croiseur1.condition = 1;
                    }
                } else {
                    for (i = 0; i < Croiseur1.taille - 1; i++) {
                        Croiseur1.positionx[i + 1] = Croiseur1.positionx[i] + 1;
                        Croiseur1.positiony[i + 1] = Croiseur1.positiony[i];
                    }
                    if ((board2[Croiseur1.positionx[0]][Croiseur1.positiony[0]]) == (-1) &&
                        (board2[Croiseur1.positionx[1]][Croiseur1.positiony[1]]) == (-1) &&
                        (board2[Croiseur1.positionx[2]][Croiseur1.positiony[2]]) == (-1) &&
                        (board2[Croiseur1.positionx[3]][Croiseur1.positiony[3]]) == (-1) &&
                        (board2[Croiseur1.positionx[4]][Croiseur1.positiony[4]]) == (-1)) {
                        for (i = 0; i < 5; i++) {
                            tabcroiseur2bx[i]=Croiseur1.positionx[i];
                            tabcroiseur2by[i]=Croiseur1.positiony[i];
                            board2[tabcroiseur2bx[i]][tabcroiseur2by[i]] = 5;
                        }
                        Croiseur1.condition = 1;
                    }
                }
            }
        } else if (Croiseur1.positionx[0] > 9) {
// droite
            if (Croiseur1.positiony[0] < 10) {
                Croiseur1.orientation = rand()%Hasardb;
                if (Croiseur1.orientation == 1) {
                    for (i = 0; i < Croiseur1.taille - 1; i++) {
                        Croiseur1.positionx[i + 1] = Croiseur1.positionx[i];
                        Croiseur1.positiony[i + 1] = Croiseur1.positiony[i] + 1;
                    }
                    if ((board2[Croiseur1.positionx[0]][Croiseur1.positiony[0]]) == (-1) &&
                        (board2[Croiseur1.positionx[1]][Croiseur1.positiony[1]]) == (-1) &&
                        (board2[Croiseur1.positionx[2]][Croiseur1.positiony[2]]) == (-1) &&
                        (board2[Croiseur1.positionx[3]][Croiseur1.positiony[3]]) == (-1) &&
                        (board2[Croiseur1.positionx[4]][Croiseur1.positiony[4]]) == (-1)) {
                        for (i = 0; i < 5; i++) {
                            tabcroiseur2bx[i]=Croiseur1.positionx[i];
                            tabcroiseur2by[i]=Croiseur1.positiony[i];
                            board2[tabcroiseur2bx[i]][tabcroiseur2by[i]] = 5;
                        }
                        Croiseur1.condition = 1;
                    }
                } else {

                    for (i = 0; i < Croiseur1.taille - 1; i++) {
                        Croiseur1.positionx[i + 1] = Croiseur1.positionx[i] - 1;
                        Croiseur1.positiony[i + 1] = Croiseur1.positiony[i];
                    }
                    if ((board2[Croiseur1.positionx[0]][Croiseur1.positiony[0]]) == (-1) &&
                        (board2[Croiseur1.positionx[1]][Croiseur1.positiony[1]]) == (-1) &&
                        (board2[Croiseur1.positionx[2]][Croiseur1.positiony[2]]) == (-1) &&
                        (board2[Croiseur1.positionx[3]][Croiseur1.positiony[3]]) == (-1) &&
                        (board2[Croiseur1.positionx[4]][Croiseur1.positiony[4]]) == (-1)) {
                        for (i = 0; i < 5; i++) {
                            tabcroiseur2bx[i]=Croiseur1.positionx[i];
                            tabcroiseur2by[i]=Croiseur1.positiony[i];
                            board2[tabcroiseur2bx[i]][tabcroiseur2by[i]] = 5;
                        }
                        Croiseur1.condition = 1;
                    }
                }
            } else if (Croiseur1.positiony > 9) {
                Croiseur1.orientation = 0;
                if (Croiseur1.orientation == 1) {
                    for (i = 0; i < Croiseur1.taille - 1; i++) {
                        Croiseur1.positionx[i + 1] = Croiseur1.positionx[i];
                        Croiseur1.positiony[i + 1] = Croiseur1.positiony[i] - 1;
                    }
                    if ((board2[Croiseur1.positionx[0]][Croiseur1.positiony[0]]) == (-1) &&
                        (board2[Croiseur1.positionx[1]][Croiseur1.positiony[1]]) == (-1) &&
                        (board2[Croiseur1.positionx[2]][Croiseur1.positiony[2]]) == (-1) &&
                        (board2[Croiseur1.positionx[3]][Croiseur1.positiony[3]]) == (-1) &&
                        (board2[Croiseur1.positionx[4]][Croiseur1.positiony[4]]) == (-1)) {
                        for (i = 0; i < 5; i++) {
                            tabcroiseur2bx[i]=Croiseur1.positionx[i];
                            tabcroiseur2by[i]=Croiseur1.positiony[i];
                            board2[tabcroiseur2bx[i]][tabcroiseur2by[i]] = 5;
                        }
                        Croiseur1.condition = 1;
                    }
                } else {
                    for (i = 0; i < Croiseur1.taille - 1; i++) {
                        Croiseur1.positionx[i + 1] = Croiseur1.positionx[i] - 1;
                        Croiseur1.positiony[i + 1] = Croiseur1.positiony[i];
                    }
                    if ((board2[Croiseur1.positionx[0]][Croiseur1.positiony[0]]) == (-1) &&
                        (board2[Croiseur1.positionx[1]][Croiseur1.positiony[1]]) == (-1) &&
                        (board2[Croiseur1.positionx[2]][Croiseur1.positiony[2]]) == (-1) &&
                        (board2[Croiseur1.positionx[3]][Croiseur1.positiony[3]]) == (-1) &&
                        (board2[Croiseur1.positionx[4]][Croiseur1.positiony[4]]) == (-1)) {
                        for (i = 0; i < 5; i++) {
                            tabcroiseur2bx[i]=Croiseur1.positionx[i];
                            tabcroiseur2by[i]=Croiseur1.positiony[i];
                            board2[tabcroiseur2bx[i]][tabcroiseur2by[i]] = 5;
                        }
                        Croiseur1.condition = 1;
                    }
                }
            }
        }
    } while (Croiseur1.condition == 0);

    //////////////////Destroyer/////////////////////
    Destroyer.taille = 3;
    Destroyer.condition=0;
    do {
        Destroyer.positionx[0] = rand() % BoardSize;
        Destroyer.positiony[0] = rand() % BoardSize;
        if (Destroyer.positionx[0] < 12) {
            if (Destroyer.positiony[0] < 12) {
                Destroyer.orientation = rand()%Hasardb;
                if (Destroyer.orientation == 1) {
                    for (i = 0; i < Destroyer.taille - 1; i++) {
                        Destroyer.positionx[i + 1] = Destroyer.positionx[i];
                        Destroyer.positiony[i + 1] = Destroyer.positiony[i] + 1;
                    }
                    if ((board2[Destroyer.positionx[0]][Destroyer.positiony[0]]) == (-1) &&
                        (board2[Destroyer.positionx[1]][Destroyer.positiony[1]]) == (-1) &&
                        (board2[Destroyer.positionx[2]][Destroyer.positiony[2]]) == (-1))
                    {
                        for (i = 0; i < 3; i++) {
                            tabdestroyer2ax[i]=Destroyer.positionx[i];
                            tabdestroyer2ay[i]=Destroyer.positiony[i];
                            board2[tabdestroyer2ax[i]][tabdestroyer2ay[i]] = 6;
                        }
                        Destroyer.condition = 1;
                    }
                }
                else {
                    for (i = 0; i < Destroyer.taille - 1; i++) {
                        Destroyer.positionx[i + 1] = Destroyer.positionx[i] + 1;
                        Destroyer.positiony[i + 1] = Destroyer.positiony[i];
                    }
                    if ((board2[Destroyer.positionx[0]][Destroyer.positiony[0]]) == (-1) &&
                        (board2[Destroyer.positionx[1]][Destroyer.positiony[1]]) == (-1) &&
                        (board2[Destroyer.positionx[2]][Destroyer.positiony[2]]) == (-1))
                    {
                        for (i = 0; i < 3; i++) {
                            tabdestroyer2ax[i]=Destroyer.positionx[i];
                            tabdestroyer2ay[i]=Destroyer.positiony[i];
                            board2[tabdestroyer2ax[i]][tabdestroyer2ay[i]] = 6;
                        }
                        Destroyer.condition = 1;
                    }
                }
            }
            else if (Destroyer.positiony[0] > 11) {
                Destroyer.orientation = 0;
                if (Destroyer.orientation == 0) {
                    for (i = 0; i < Destroyer.taille - 1; i++) {
                        Destroyer.positionx[i + 1] = Destroyer.positionx[i];
                        Destroyer.positiony[i + 1] = Destroyer.positiony[i] - 1;
                    }
                    if ((board2[Destroyer.positionx[0]][Destroyer.positiony[0]])==(-1) &&
                        (board2[Destroyer.positionx[1]][Destroyer.positiony[1]])==(-1) &&
                        (board2[Destroyer.positionx[2]][Destroyer.positiony[2]])==(-1))
                    {
                        for (i = 0; i < 3; i++) {
                            tabdestroyer2ax[i]=Destroyer.positionx[i];
                            tabdestroyer2ay[i]=Destroyer.positiony[i];
                            board2[tabdestroyer2ax[i]][tabdestroyer2ay[i]] = 6;
                        }
                        Destroyer.condition=1;
                    }
                }
                else {
                    for (i = 0; i < Destroyer.taille - 1; i++) {
                        Destroyer.positionx[i + 1] = Destroyer.positionx[i] + 1;
                        Destroyer.positiony[i + 1] = Destroyer.positiony[i];
                    }
                    if ((board2[Destroyer.positionx[0]][Destroyer.positiony[0]])==(-1) &&
                        (board2[Destroyer.positionx[1]][Destroyer.positiony[1]])==(-1) &&
                        (board2[Destroyer.positionx[2]][Destroyer.positiony[2]])==(-1))
                    {
                        for (i = 0; i <3; i++) {
                            tabdestroyer2ax[i]=Destroyer.positionx[i];
                            tabdestroyer2ay[i]=Destroyer.positiony[i];
                            board2[tabdestroyer2ax[i]][tabdestroyer2ay[i]] = 6;
                        }
                        Destroyer.condition=1;
                    }
                }
            }
        }
        else if (Destroyer.positionx[0] > 11) {
            // droite
            if (Destroyer.positiony[0] < 12) {
                Destroyer.orientation = rand()%Hasard;
                if (Destroyer.orientation == 1) {
                    for (i = 0; i < Destroyer.taille - 1; i++) {
                        Destroyer.positionx[i + 1] = Destroyer.positionx[i];
                        Destroyer.positiony[i + 1] = Destroyer.positiony[i] + 1;
                    }
                    if ((board2[Destroyer.positionx[0]][Destroyer.positiony[0]])==(-1) &&
                        (board2[Destroyer.positionx[1]][Destroyer.positiony[1]])==(-1) &&
                        (board2[Destroyer.positionx[2]][Destroyer.positiony[2]])==(-1) ){
                        for (i = 0; i < 3; i++) {
                            tabdestroyer2ax[i]=Destroyer.positionx[i];
                            tabdestroyer2ay[i]=Destroyer.positiony[i];
                            board2[tabdestroyer2ax[i]][tabdestroyer2ay[i]] = 6;
                        }
                        Destroyer.condition=1;
                    }
                }
                else {
                    for (i = 0; i < Destroyer.taille - 1; i++) {
                        Destroyer.positionx[i + 1] = Destroyer.positionx[i] - 1;
                        Destroyer.positiony[i + 1] = Destroyer.positiony[i];
                    }
                    if ((board2[Destroyer.positionx[0]][Destroyer.positiony[0]])==(-1) &&
                        (board2[Destroyer.positionx[1]][Destroyer.positiony[1]])==(-1) &&
                        (board2[Destroyer.positionx[2]][Destroyer.positiony[2]])==(-1)){
                        for (i = 0; i < 3; i++) {
                            tabdestroyer2ax[i]=Destroyer.positionx[i];
                            tabdestroyer2ay[i]=Destroyer.positiony[i];
                            board2[tabdestroyer2ax[i]][tabdestroyer2ay[i]] = 6;
                        }
                        Destroyer.condition=1;
                    }
                }
            }
            else if (Destroyer.positiony > 11) {
                Destroyer.orientation = 0;
                if (Destroyer.orientation == 1) {
                    for (i = 0; i < Destroyer.taille - 1; i++) {
                        Destroyer.positionx[i + 1] = Destroyer.positionx[i];
                        Destroyer.positiony[i + 1] = Destroyer.positiony[i] - 1;
                    }
                    if ((board2[Destroyer.positionx[0]][Destroyer.positiony[0]])==(-1) &&
                        (board2[Destroyer.positionx[1]][Destroyer.positiony[1]])==(-1) &&
                        (board2[Destroyer.positionx[2]][Destroyer.positiony[2]])==(-1))
                    {
                        for (i = 0; i < 6; i++) {
                            tabdestroyer2ax[i]=Destroyer.positionx[i];
                            tabdestroyer2ay[i]=Destroyer.positiony[i];
                            board2[tabdestroyer2ax[i]][tabdestroyer2ay[i]] = 6;
                        }
                        Destroyer.condition=1;
                    }
                }
                else {
                    for (i = 0; i < Destroyer.taille - 1; i++) {
                        Destroyer.positionx[i + 1] = Destroyer.positionx[i] - 1;
                        Destroyer.positiony[i + 1] = Destroyer.positiony[i];
                    }
                    if ((board2[Destroyer.positionx[0]][Destroyer.positiony[0]])==(-1) &&
                        (board2[Destroyer.positionx[1]][Destroyer.positiony[1]])==(-1) &&
                        (board2[Destroyer.positionx[2]][Destroyer.positiony[2]])==(-1))
                    {
                        for (i = 0; i < 3; i++) {
                            tabdestroyer2ax[i]=Destroyer.positionx[i];
                            tabdestroyer2ay[i]=Destroyer.positiony[i];
                            board2[tabdestroyer2ax[i]][tabdestroyer2ay[i]] = 6;
                        }
                        Destroyer.condition=1;
                    }
                }
            }
        }
    }while(Destroyer.condition==0);

    //////////////////Destroyer1/////////////////////
    Destroyer1.taille = 3;
    Destroyer1.condition=0;
    do {
        Destroyer1.positionx[0] = rand() % BoardSize;
        Destroyer1.positiony[0] = rand() % BoardSize;
        if (Destroyer1.positionx[0] < 12) {
            if (Destroyer1.positiony[0] < 12) {
                Destroyer1.orientation = rand()%Hasardb;
                if (Destroyer1.orientation == 1) {
                    for (i = 0; i < Destroyer1.taille - 1; i++) {
                        Destroyer1.positionx[i + 1] = Destroyer1.positionx[i];
                        Destroyer1.positiony[i + 1] = Destroyer1.positiony[i] + 1;
                    }
                    if ((board2[Destroyer1.positionx[0]][Destroyer1.positiony[0]]) == (-1) &&
                        (board2[Destroyer1.positionx[1]][Destroyer1.positiony[1]]) == (-1) &&
                        (board2[Destroyer1.positionx[2]][Destroyer1.positiony[2]]) == (-1))
                    {
                        for (i = 0; i < 3; i++) {
                            tabdestroyer2bx[i]=Destroyer1.positionx[i];
                            tabdestroyer2by[i]=Destroyer1.positiony[i];
                            board2[tabdestroyer2bx[i]][tabdestroyer2by[i]] = 6;
                        }
                        Destroyer1.condition = 1;
                    }
                }
                else {
                    for (i = 0; i < Destroyer1.taille - 1; i++) {
                        Destroyer1.positionx[i + 1] = Destroyer1.positionx[i] + 1;
                        Destroyer1.positiony[i + 1] = Destroyer1.positiony[i];
                    }
                    if ((board2[Destroyer1.positionx[0]][Destroyer1.positiony[0]]) == (-1) &&
                        (board2[Destroyer1.positionx[1]][Destroyer1.positiony[1]]) == (-1) &&
                        (board2[Destroyer1.positionx[2]][Destroyer1.positiony[2]]) == (-1))
                    {
                        for (i = 0; i < 3; i++) {
                            tabdestroyer2bx[i]=Destroyer1.positionx[i];
                            tabdestroyer2by[i]=Destroyer1.positiony[i];
                            board2[tabdestroyer2bx[i]][tabdestroyer2by[i]] = 6;
                        }
                        Destroyer1.condition = 1;
                    }
                }
            }
            else if (Destroyer1.positiony[0] > 11) {
                Destroyer1.orientation = 0;
                if (Destroyer1.orientation == 0) {
                    for (i = 0; i < Destroyer1.taille - 1; i++) {
                        Destroyer1.positionx[i + 1] = Destroyer1.positionx[i];
                        Destroyer1.positiony[i + 1] = Destroyer1.positiony[i] - 1;
                    }
                    if ((board2[Destroyer1.positionx[0]][Destroyer1.positiony[0]])==(-1) &&
                        (board2[Destroyer1.positionx[1]][Destroyer1.positiony[1]])==(-1) &&
                        (board2[Destroyer1.positionx[2]][Destroyer1.positiony[2]])==(-1))
                    {
                        for (i = 0; i < 3; i++) {
                            tabdestroyer2bx[i]=Destroyer1.positionx[i];
                            tabdestroyer2by[i]=Destroyer1.positiony[i];
                            board2[tabdestroyer2bx[i]][tabdestroyer2by[i]] = 6;
                        }
                        Destroyer1.condition=1;
                    }
                }
                else {
                    for (i = 0; i < Destroyer1.taille - 1; i++) {
                        Destroyer1.positionx[i + 1] = Destroyer1.positionx[i] + 1;
                        Destroyer1.positiony[i + 1] = Destroyer1.positiony[i];
                    }
                    if ((board2[Destroyer1.positionx[0]][Destroyer1.positiony[0]])==(-1) &&
                        (board2[Destroyer1.positionx[1]][Destroyer1.positiony[1]])==(-1) &&
                        (board2[Destroyer1.positionx[2]][Destroyer1.positiony[2]])==(-1))
                    {
                        for (i = 0; i <3; i++) {
                            tabdestroyer2bx[i]=Destroyer1.positionx[i];
                            tabdestroyer2by[i]=Destroyer1.positiony[i];
                            board2[tabdestroyer2bx[i]][tabdestroyer2by[i]] = 6;
                        }
                        Destroyer1.condition=1;
                    }
                }
            }
        }
        else if (Destroyer1.positionx[0] > 11) {
// droite
            if (Destroyer1.positiony[0] < 12) {
                Destroyer1.orientation = rand()%Hasardb;
                if (Destroyer1.orientation == 1) {
                    for (i = 0; i < Destroyer1.taille - 1; i++) {
                        Destroyer1.positionx[i + 1] = Destroyer1.positionx[i];
                        Destroyer1.positiony[i + 1] = Destroyer1.positiony[i] + 1;
                    }
                    if ((board2[Destroyer1.positionx[0]][Destroyer1.positiony[0]])==(-1) &&
                        (board2[Destroyer1.positionx[1]][Destroyer1.positiony[1]])==(-1) &&
                        (board2[Destroyer1.positionx[2]][Destroyer1.positiony[2]])==(-1) ){
                        for (i = 0; i < 3; i++) {
                            tabdestroyer2bx[i]=Destroyer1.positionx[i];
                            tabdestroyer2by[i]=Destroyer1.positiony[i];
                            board2[tabdestroyer2bx[i]][tabdestroyer2by[i]] = 6;
                        }
                        Destroyer1.condition=1;
                    }
                }
                else {
                    for (i = 0; i < Destroyer1.taille - 1; i++) {
                        Destroyer1.positionx[i + 1] = Destroyer1.positionx[i] - 1;
                        Destroyer1.positiony[i + 1] = Destroyer1.positiony[i];
                    }
                    if ((board2[Destroyer1.positionx[0]][Destroyer1.positiony[0]])==(-1) &&
                        (board2[Destroyer1.positionx[1]][Destroyer1.positiony[1]])==(-1) &&
                        (board2[Destroyer1.positionx[2]][Destroyer1.positiony[2]])==(-1)){
                        for (i = 0; i < 3; i++) {
                            tabdestroyer2bx[i]=Destroyer1.positionx[i];
                            tabdestroyer2by[i]=Destroyer1.positiony[i];
                            board2[tabdestroyer2bx[i]][tabdestroyer2by[i]] = 6;
                        }
                        Destroyer1.condition=1;
                    }
                }
            }
            else if (Destroyer1.positiony > 11) {
                Destroyer1.orientation = 0;
                if (Destroyer1.orientation == 1) {
                    for (i = 0; i < Destroyer1.taille - 1; i++) {
                        Destroyer1.positionx[i + 1] = Destroyer1.positionx[i];
                        Destroyer1.positiony[i + 1] = Destroyer1.positiony[i] - 1;
                    }
                    if ((board2[Destroyer1.positionx[0]][Destroyer1.positiony[0]])==(-1) &&
                        (board2[Destroyer1.positionx[1]][Destroyer1.positiony[1]])==(-1) &&
                        (board2[Destroyer1.positionx[2]][Destroyer1.positiony[2]])==(-1))
                    {
                        for (i = 0; i < 6; i++) {
                            tabdestroyer2bx[i]=Destroyer1.positionx[i];
                            tabdestroyer2by[i]=Destroyer1.positiony[i];
                            board2[tabdestroyer2bx[i]][tabdestroyer2by[i]] = 6;
                        }
                        Destroyer1.condition=1;
                    }
                }
                else {
                    for (i = 0; i < Destroyer1.taille - 1; i++) {
                        Destroyer1.positionx[i + 1] = Destroyer1.positionx[i] - 1;
                        Destroyer1.positiony[i + 1] = Destroyer1.positiony[i];
                    }
                    if ((board2[Destroyer1.positionx[0]][Destroyer1.positiony[0]])==(-1) &&
                        (board2[Destroyer1.positionx[1]][Destroyer1.positiony[1]])==(-1) &&
                        (board2[Destroyer1.positionx[2]][Destroyer1.positiony[2]])==(-1))
                    {
                        for (i = 0; i < 3; i++) {
                            tabdestroyer2bx[i]=Destroyer1.positionx[i];
                            tabdestroyer2by[i]=Destroyer1.positiony[i];
                            board2[tabdestroyer2bx[i]][tabdestroyer2by[i]] = 6;
                        }
                        Destroyer1.condition=1;
                    }
                }
            }
        }
    }while(Destroyer1.condition==0);

    //////////////////Destroyer2/////////////////////
    Destroyer2.taille = 3;
    Destroyer2.condition=0;
    do {
        Destroyer2.positionx[0] = rand() % BoardSize;
        Destroyer2.positiony[0] = rand() % BoardSize;
        if (Destroyer2.positionx[0] < 12) {
            if (Destroyer2.positiony[0] < 12) {
                Destroyer2.orientation = rand()%Hasardb;
                if (Destroyer2.orientation == 1) {
                    for (i = 0; i < Destroyer2.taille - 1; i++) {
                        Destroyer2.positionx[i + 1] = Destroyer2.positionx[i];
                        Destroyer2.positiony[i + 1] = Destroyer2.positiony[i] + 1;
                    }
                    if ((board2[Destroyer2.positionx[0]][Destroyer2.positiony[0]]) == (-1) &&
                        (board2[Destroyer2.positionx[1]][Destroyer2.positiony[1]]) == (-1) &&
                        (board2[Destroyer2.positionx[2]][Destroyer2.positiony[2]]) == (-1))
                    {
                        for (i = 0; i < 3; i++) {
                            tabdestroyer2cx[i]=Destroyer2.positionx[i];
                            tabdestroyer2cy[i]=Destroyer2.positiony[i];
                            board2[tabdestroyer2cx[i]][tabdestroyer2cy[i]] = 6;
                        }
                        Destroyer2.condition = 1;
                    }
                }
                else {
                    for (i = 0; i < Destroyer2.taille - 1; i++) {
                        Destroyer2.positionx[i + 1] = Destroyer2.positionx[i] + 1;
                        Destroyer2.positiony[i + 1] = Destroyer2.positiony[i];
                    }
                    if ((board2[Destroyer2.positionx[0]][Destroyer2.positiony[0]]) == (-1) &&
                        (board2[Destroyer2.positionx[1]][Destroyer2.positiony[1]]) == (-1) &&
                        (board2[Destroyer2.positionx[2]][Destroyer2.positiony[2]]) == (-1) )
                    {
                        for (i = 0; i < 3; i++) {
                            tabdestroyer2cx[i]=Destroyer2.positionx[i];
                            tabdestroyer2cy[i]=Destroyer2.positiony[i];
                            board2[tabdestroyer2cx[i]][tabdestroyer2cy[i]] = 6;
                        }
                        Destroyer2.condition = 1;
                    }
                }
            }
            else if (Destroyer2.positiony[0] > 11) {
                Destroyer2.orientation = 0;
                if (Destroyer2.orientation == 0) {
                    for (i = 0; i < Destroyer2.taille - 1; i++) {
                        Destroyer2.positionx[i + 1] = Destroyer2.positionx[i];
                        Destroyer2.positiony[i + 1] = Destroyer2.positiony[i] - 1;
                    }
                    if ((board2[Destroyer2.positionx[0]][Destroyer2.positiony[0]])==(-1) &&
                        (board2[Destroyer2.positionx[1]][Destroyer2.positiony[1]])==(-1) &&
                        (board2[Destroyer2.positionx[2]][Destroyer2.positiony[2]])==(-1))
                    {
                        for (i = 0; i < 3; i++) {
                            tabdestroyer2cx[i]=Destroyer2.positionx[i];
                            tabdestroyer2cy[i]=Destroyer2.positiony[i];
                            board2[tabdestroyer2cx[i]][tabdestroyer2cy[i]] = 6;
                        }
                        Destroyer2.condition=1;
                    }
                }
                else {
                    for (i = 0; i < Destroyer2.taille - 1; i++) {
                        Destroyer2.positionx[i + 1] = Destroyer2.positionx[i] + 1;
                        Destroyer2.positiony[i + 1] = Destroyer2.positiony[i];
                    }
                    if ((board2[Destroyer2.positionx[0]][Destroyer2.positiony[0]])==(-1) &&
                        (board2[Destroyer2.positionx[1]][Destroyer2.positiony[1]])==(-1) &&
                        (board2[Destroyer2.positionx[2]][Destroyer2.positiony[2]])==(-1))
                    {
                        for (i = 0; i <3; i++) {
                            tabdestroyer2cx[i]=Destroyer2.positionx[i];
                            tabdestroyer2cy[i]=Destroyer2.positiony[i];
                            board2[tabdestroyer2cx[i]][tabdestroyer2cy[i]] = 6;
                        }
                        Destroyer2.condition=1;
                    }
                }
            }
        }
        else if (Destroyer2.positionx[0] > 11) {
// droite
            if (Destroyer2.positiony[0] < 12) {
                Destroyer2.orientation = rand()%Hasardb;
                if (Destroyer2.orientation == 1) {
                    for (i = 0; i < Destroyer2.taille - 1; i++) {
                        Destroyer2.positionx[i + 1] = Destroyer2.positionx[i];
                        Destroyer2.positiony[i + 1] = Destroyer2.positiony[i] + 1;
                    }
                    if ((board2[Destroyer2.positionx[0]][Destroyer2.positiony[0]])==(-1) &&
                        (board2[Destroyer2.positionx[1]][Destroyer2.positiony[1]])==(-1) &&
                        (board2[Destroyer2.positionx[2]][Destroyer2.positiony[2]])==(-1)){
                        for (i = 0; i < 3; i++) {
                            tabdestroyer2cx[i]=Destroyer2.positionx[i];
                            tabdestroyer2cy[i]=Destroyer2.positiony[i];
                            board2[tabdestroyer2cx[i]][tabdestroyer2cy[i]] = 6;
                        }
                        Destroyer2.condition=1;
                    }
                }
                else {

                    for (i = 0; i < Destroyer2.taille - 1; i++) {
                        Destroyer2.positionx[i + 1] = Destroyer2.positionx[i] - 1;
                        Destroyer2.positiony[i + 1] = Destroyer2.positiony[i];
                    }
                    if ((board2[Destroyer2.positionx[0]][Destroyer2.positiony[0]])==(-1) &&
                        (board2[Destroyer2.positionx[1]][Destroyer2.positiony[1]])==(-1) &&
                        (board2[Destroyer2.positionx[2]][Destroyer2.positiony[2]])==(-1)){
                        for (i = 0; i < 3; i++) {
                            tabdestroyer2cx[i]=Destroyer2.positionx[i];
                            tabdestroyer2cy[i]=Destroyer2.positiony[i];
                            board2[tabdestroyer2cx[i]][tabdestroyer2cy[i]] = 6;
                        }
                        Destroyer2.condition=1;
                    }
                }
            }
            else if (Destroyer2.positiony > 11) {
                Destroyer2.orientation = 0;
                if (Destroyer2.orientation == 1) {
                    for (i = 0; i < Destroyer2.taille - 1; i++) {
                        Destroyer2.positionx[i + 1] = Destroyer2.positionx[i];
                        Destroyer2.positiony[i + 1] = Destroyer2.positiony[i] - 1;
                    }
                    if ((board2[Destroyer2.positionx[0]][Destroyer2.positiony[0]])==(-1) &&
                        (board2[Destroyer2.positionx[1]][Destroyer2.positiony[1]])==(-1) &&
                        (board2[Destroyer2.positionx[2]][Destroyer2.positiony[2]])==(-1) )
                    {
                        for (i = 0; i < 6; i++) {
                            tabdestroyer2cx[i]=Destroyer2.positionx[i];
                            tabdestroyer2cy[i]=Destroyer2.positiony[i];
                            board2[tabdestroyer2cx[i]][tabdestroyer2cy[i]] = 6;
                        }
                        Destroyer2.condition=1;
                    }
                }
                else {
                    for (i = 0; i < Destroyer2.taille - 1; i++) {
                        Destroyer2.positionx[i + 1] = Destroyer2.positionx[i] - 1;
                        Destroyer2.positiony[i + 1] = Destroyer2.positiony[i];
                    }
                    if ((board2[Destroyer2.positionx[0]][Destroyer2.positiony[0]])==(-1) &&
                        (board2[Destroyer2.positionx[1]][Destroyer2.positiony[1]])==(-1) &&
                        (board2[Destroyer2.positionx[2]][Destroyer2.positiony[2]])==(-1))
                    {
                        for (i = 0; i < 3; i++) {
                            tabdestroyer2cx[i]=Destroyer2.positionx[i];
                            tabdestroyer2cy[i]=Destroyer2.positiony[i];
                            board2[tabdestroyer2cx[i]][tabdestroyer2cy[i]] = 6;
                        }
                        Destroyer2.condition=1;
                    }
                }
            }
        }
    }while(Destroyer2.condition==0);

    //////////////////SousMarrin//////////////////
    SousMarrin.taille = 1;

    SousMarrin.condition=0;
    do {
        SousMarrin.positionx[0] = rand() % BoardSize;
        SousMarrin.positiony[0] = rand() % BoardSize;
        if (board2[SousMarrin.positionx[0]][SousMarrin.positiony[0]]==-1){
            tabsousmarrin2ay[0]=SousMarrin.positiony[0];
            tabsousmarrin2ax[0]=SousMarrin.positionx[0];
            board2[tabsousmarrin2ax[0]][tabsousmarrin2ay[0]]=7;
            SousMarrin.condition=1;
        }
    }while(SousMarrin.condition==0);

    //////////////////SousMarrin1/////////////////
    SousMarrin1.taille = 1;

    SousMarrin1.condition=0;
    do {
        SousMarrin1.positionx[0] = rand() % BoardSize;
        SousMarrin1.positiony[0] = rand() % BoardSize;
        if (board2[SousMarrin1.positionx[0]][SousMarrin1.positiony[0]]==-1){
            tabsousmarrin2by[0]=SousMarrin1.positiony[0];
            tabsousmarrin2bx[0]=SousMarrin1.positionx[0];
            board2[tabsousmarrin2bx[0]][tabsousmarrin2by[0]]=7;
            SousMarrin1.condition=1;
        }
    }while(SousMarrin1.condition==0);

    //////////////////SousMarrin2/////////////////
    SousMarrin2.taille = 1;

    SousMarrin2.condition=0;
    do {
        SousMarrin2.positionx[0] = rand() % BoardSize;
        SousMarrin2.positiony[0] = rand() % BoardSize;
        if (board2[SousMarrin2.positionx[0]][SousMarrin2.positiony[0]]==-1){
            tabsousmarrin2cy[0]=SousMarrin2.positiony[0];
            tabsousmarrin2cx[0]=SousMarrin2.positionx[0];
            board2[tabsousmarrin2cx[0]][tabsousmarrin2cy[0]]=7;
            SousMarrin2.condition=1;
        }
    }while(SousMarrin2.condition==0);

    //////////////////SousMarrin3//////////////////
    SousMarrin3.taille = 1;

    SousMarrin3.condition=0;
    do {
        SousMarrin3.positionx[0] = rand() % BoardSize;
        SousMarrin3.positiony[0] = rand() % BoardSize;
        if (board2[SousMarrin3.positionx[0]][SousMarrin3.positiony[0]]==-1){
            tabsousmarrin2dy[0]=SousMarrin3.positiony[0];
            tabsousmarrin2dx[0]=SousMarrin3.positionx[0];
            board2[tabsousmarrin2dx[0]][tabsousmarrin2dy[0]]=7;
            SousMarrin3.condition=1;
        }
    }while(SousMarrin3.condition==0);
    ///////////////////////////////////////////////

}
//Enregistre les coordonnees de tire
void Coortire(){
    printf("Ligne: ");
    scanf("%d",&shot[0]);

    printf("Colonne: ");
    scanf("%d",&shot[1]);

    printf("shot: %d / %d\n",shot[0],shot[1]);
}
//test si le tire a touche (joueur)
int testssitouche1() {

    if (board4[shot[0]][shot[1]] == 0) {
        printf("Dejà tire!\n");
    }
    else if (board4[shot[0]][shot[1]] == 1) {
        printf("Dejà touche!\n");
    }
    else if (board1[shot[0]][shot[1]] == board1[tabporteavion1x[0]][tabporteavion1y[0]] || board1[shot[0]][shot[1]] == board1[tabporteavion1x[1]][tabporteavion1y[1]] || board1[shot[0]][shot[1]] == board1[tabporteavion1x[2]][tabporteavion1y[2]] || board1[shot[0]][shot[1]] == board1[tabporteavion1x[3]][tabporteavion1y[3]] || board1[shot[0]][shot[1]] == board1[tabporteavion1x[4]][tabporteavion1y[4]] || board1[shot[0]][shot[1]] == board1[tabporteavion1x[5]][tabporteavion1y[5]] || board1[shot[0]][shot[1]] == board1[tabporteavion1x[6]][tabporteavion1y[6]]) {
        board4[shot[0]][shot[1]] = 1;
        compteurporteavion1[0]++;
        printf("Touche!\n");
    }
    else if (board1[shot[0]][shot[1]] == board1[tabcroiseur1ax[0]][tabcroiseur1ay[0]] || board1[shot[0]][shot[1]] == board1[tabcroiseur1ax[1]][tabcroiseur1ay[1]] || board1[shot[0]][shot[1]] == board1[tabcroiseur1ax[2]][tabcroiseur1ay[2]] || board1[shot[0]][shot[1]] == board1[tabcroiseur1ax[3]][tabcroiseur1ay[3]] || board1[shot[0]][shot[1]] == board1[tabcroiseur1ax[4]][tabcroiseur1ay[4]]) {
        board4[shot[0]][shot[1]] = 1;
        compteurcroiseur1a[0]++;
        printf("Touche!\n");
    }
    else if (board1[shot[0]][shot[1]] == board1[tabcroiseur1bx[0]][tabcroiseur1by[0]] || board1[shot[0]][shot[1]] == board1[tabcroiseur1bx[1]][tabcroiseur1by[1]] || board1[shot[0]][shot[1]] == board1[tabcroiseur1bx[2]][tabcroiseur1by[2]] || board1[shot[0]][shot[1]] == board1[tabcroiseur1bx[3]][tabcroiseur1by[3]] || board1[shot[0]][shot[1]] == board1[tabcroiseur1bx[4]][tabcroiseur1by[4]]) {
        board4[shot[0]][shot[1]] = 1;
        compteurcroiseur1b[0]++;
        printf("Touche!\n");
    }
    else if (board1[shot[0]][shot[1]] == board1[tabdestroyer1ax[0]][tabdestroyer1ay[0]] ||board1[shot[0]][shot[1]]== board1[tabdestroyer1ax[1]][tabdestroyer1ay[1]] ||board1[shot[0]][shot[1]]== board1[tabdestroyer1ax[2]][tabdestroyer1ay[2]]) {
        board4[shot[0]][shot[1]] = 1;
        compteurdestroyer1a[0]++;
        printf("Touche!\n");
    }
    else if (board1[shot[0]][shot[1]] == board1[tabdestroyer1bx[0]][tabdestroyer1by[0]] ||board1[shot[0]][shot[1]]== board1[tabdestroyer1bx[1]][tabdestroyer1by[1]] ||board1[shot[0]][shot[1]]== board1[tabdestroyer1bx[2]][tabdestroyer1by[2]]) {
        board4[shot[0]][shot[1]] = 1;
        compteurdestroyer1b[0]++;
        printf("Touche!\n");
    }
    else if (board1[shot[0]][shot[1]] == board1[tabdestroyer1cx[0]][tabdestroyer1cy[0]] ||board1[shot[0]][shot[1]]== board1[tabdestroyer1cx[1]][tabdestroyer1cy[1]] ||board1[shot[0]][shot[1]]== board1[tabdestroyer1cx[2]][tabdestroyer1cy[2]]) {
        board4[shot[0]][shot[1]] = 1;
        compteurdestroyer1c[0]++;
        printf("Touche!\n");
    }
    else if (board1[shot[0]][shot[1]] == board1[tabsousmarrin1ax[0]][tabsousmarrin1ay[0]] || board1[shot[0]][shot[1]] == board1[tabsousmarrin1bx[0]][tabsousmarrin1by[0]] || board1[shot[0]][shot[1]] == board1[tabsousmarrin1cx[0]][tabsousmarrin1cy[0]] ||board1[shot[0]][shot[1]] == board1[tabsousmarrin1dx[0]][tabsousmarrin1dy[0]]) {
        board4[shot[0]][shot[1]] = 1;
        compteursousmarrin1a[0]++;
        printf("Touche!\n");
    }
    else {
        board1[shot[0]][shot[1]] = 0;
        printf("Rate!\n");
    }
    shot[0]=0;
    shot[1]=0;
}
//test si le tire a touche (ordi)
int testssitouche2() {
    shot[0]--;
    shot[1]--;

    if (board3[shot[0]][shot[1]] == 0) {
        printf("Dejà tire!\n");
    }
    else if (board3[shot[0]][shot[1]] == 1) {
        printf("Dejà touche!\n");
    }
    else if (board2[shot[0]][shot[1]] == board2[tabporteavion2x[0]][tabporteavion2y[0]] || board2[shot[0]][shot[1]] == board2[tabporteavion2x[1]][tabporteavion2y[1]] || board2[shot[0]][shot[1]] == board2[tabporteavion2x[2]][tabporteavion2y[2]] || board2[shot[0]][shot[1]] == board2[tabporteavion2x[3]][tabporteavion2y[3]] || board2[shot[0]][shot[1]] == board2[tabporteavion2x[4]][tabporteavion2y[4]] || board2[shot[0]][shot[1]] == board2[tabporteavion2x[5]][tabporteavion2y[5]] || board2[shot[0]][shot[1]] == board2[tabporteavion2x[6]][tabporteavion2y[6]]) {
        board3[shot[0]][shot[1]] = 1;
        compteurporteavion2[0]++;
        printf("Touche!\n");
    }
    else if (board2[shot[0]][shot[1]] == board2[tabcroiseur2ax[0]][tabcroiseur2ay[0]] || board2[shot[0]][shot[1]] == board2[tabcroiseur2ax[1]][tabcroiseur2ay[1]] || board2[shot[0]][shot[1]] == board2[tabcroiseur2ax[2]][tabcroiseur2ay[2]] || board2[shot[0]][shot[1]] == board2[tabcroiseur2ax[3]][tabcroiseur2ay[3]] || board2[shot[0]][shot[1]] == board2[tabcroiseur2ax[4]][tabcroiseur2ay[4]]) {
        board3[shot[0]][shot[1]] = 1;
        compteurcroiseur2a[0]++;
        printf("Touche!\n");
    }
    else if (board2[shot[0]][shot[1]] == board2[tabcroiseur2bx[0]][tabcroiseur2by[0]] || board2[shot[0]][shot[1]] == board2[tabcroiseur2bx[1]][tabcroiseur2by[1]] || board2[shot[0]][shot[1]] == board2[tabcroiseur2bx[2]][tabcroiseur2by[2]] || board2[shot[0]][shot[1]] == board2[tabcroiseur2bx[3]][tabcroiseur2by[3]] || board2[shot[0]][shot[1]] == board2[tabcroiseur2bx[4]][tabcroiseur2by[4]]) {
        board3[shot[0]][shot[1]] = 1;
        compteurcroiseur2b[0]++;
        printf("Touche!\n");
    }
    else if (board2[shot[0]][shot[1]] == board2[tabdestroyer2ax[0]][tabdestroyer2ay[0]] ||board2[shot[0]][shot[1]]== board2[tabdestroyer2ax[1]][tabdestroyer2ay[1]] ||board2[shot[0]][shot[1]]== board2[tabdestroyer2ax[2]][tabdestroyer2ay[2]]) {
        board3[shot[0]][shot[1]] = 1;
        compteurdestroyer2a[0]++;
        printf("Touche!\n");
    }
    else if (board2[shot[0]][shot[1]] == board2[tabdestroyer2bx[0]][tabdestroyer2by[0]] ||board2[shot[0]][shot[1]]== board2[tabdestroyer2bx[1]][tabdestroyer2by[1]] ||board2[shot[0]][shot[1]]== board2[tabdestroyer2bx[2]][tabdestroyer2by[2]]) {
        board3[shot[0]][shot[1]] = 1;
        compteurdestroyer2b[0]++;
        printf("Touche!\n");
    }
    else if (board2[shot[0]][shot[1]] == board2[tabdestroyer2cx[0]][tabdestroyer2cy[0]] ||board2[shot[0]][shot[1]]== board2[tabdestroyer2cx[1]][tabdestroyer2cy[1]] ||board2[shot[0]][shot[1]]== board2[tabdestroyer2cx[2]][tabdestroyer2cy[2]]) {
        board3[shot[0]][shot[1]] = 1;
        compteurdestroyer2c[0]++;
        printf("Touche!\n");
    }

    else if (board2[shot[0]][shot[1]] == board2[tabsousmarrin2ax[0]][tabsousmarrin2ay[0]] || board2[shot[0]][shot[1]] == board2[tabsousmarrin2bx[0]][tabsousmarrin2by[0]] || board2[shot[0]][shot[1]] == board2[tabsousmarrin2cx[0]][tabsousmarrin2cy[0]] ||board2[shot[0]][shot[1]] == board2[tabsousmarrin2dx[0]][tabsousmarrin2dy[0]]) {
        board3[shot[0]][shot[1]] = 1;
        compteursousmarrin2a[0]++;
        printf("Touche!\n");
    }
    else {
        board3[shot[0]][shot[1]] = 0;
        printf("Rate!\n");
    }
    shot[0]=0;
    shot[1]=0;
}
//Enregistre les coordonnees du fumigene
void Coorfumi(){
    printf("Ligne: ");
    scanf("%d",&fumi[0]);

    printf("Colonne: ");
    scanf("%d",&fumi[1]);

    printf("fumi: %d %d\n",fumi[0],fumi[1]);
}
//test si le fumigene a touche (joueur)
int testsifumitouche1() {

    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            if (fumi[0]+i<BoardSize && fumi[1]+j<BoardSize){
                if (board1[fumi[0]+i][fumi[1]+j]==-1){
                    board4[fumi[0]+i][fumi[1]+j]=2;
                }
                else if (board1[fumi[0]+i][fumi[1]+j]==4 || board1[fumi[0]+i][fumi[1]+j]==5 || board1[fumi[0]+i][fumi[1]+j]==6 || board1[fumi[0]+i][fumi[1]+j]==7){
                    board4[fumi[0]+i][fumi[1]+j]=3;
                }
            }
        }
    }
    fumi[0]=0;
    fumi[1]=0;
}
//test si le fumigene a touche (ordi)
int testsifumitouche2() {
    fumi[0]--;
    fumi[1]--;

    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            if (fumi[0]+i<BoardSize && fumi[1]+j<BoardSize){
                if (board2[fumi[0]+i][fumi[1]+j]==-1){
                    board3[fumi[0]+i][fumi[1]+j]=2;
                }
                else if (board2[fumi[0]+i][fumi[1]+j]==4 || board2[fumi[0]+i][fumi[1]+j]==5 || board2[fumi[0]+i][fumi[1]+j]==6 || board2[fumi[0]+i][fumi[1]+j]==7){
                    board3[fumi[0]+i][fumi[1]+j]=3;
                }
            }
        }
    }
    fumi[0]=0;
    fumi[1]=0;
}
//Deplace les bateaux
int bougerbateau(){
    int deplacement[2];
    int direction[1];
    int i;

    printf("Selectionnez une case d'un bateaux que vous souhaitez deplacer\n");
    printf("Ligne :\n");
    scanf("%d",&deplacement[0]);
    deplacement[0]--;
    printf("Colonne :\n");
    scanf("%d",&deplacement[1]);
    deplacement[1]--;
    printf("Si votre bateau est horizontal il peut ce deplacer a droite (tapez 3) ou a gauche (taper 2)\n");
    printf("Si votre bateau est vertical il peut ce deplacer vers le haut (tapez 0) ou vers le bas (taper 1)\n");
    scanf("%d",&direction[0]);

    //Blindage Porte Avion deplacement //
    if(board1[deplacement[0]][deplacement[1]]==4 ) {
        if(direction[0]==0) {
            if (tabporteavion1x[0] > 0 && tabporteavion1x[1] > 0 && tabporteavion1x[2] > 0 &&
                tabporteavion1x[3] > 0 && tabporteavion1x[4] > 0 && tabporteavion1x[5] > 0 &&
                tabporteavion1x[6] > 0) {
                if (compteurporteavion1[0] <= 7) {
                    for (i = 0; i < 7; i++) { ;
                        board1[tabporteavion1x[i]][tabporteavion1y[i]] = -1;
                    }
                    for (i = 0; i < 7; i++) {

                        tabporteavion1x[i] = tabporteavion1x[i] - 1;
                        board1[tabporteavion1x[i]][tabporteavion1y[i]] = 4;
                    }
                }
                else {
                    printf("Vous ne pouvez pas bouger le bateau il est coule\n");
                }
            }
            else{
                printf("Vous ne pouvez pas vous deplacer dans ce sens\n");
            }
        }
        else if(direction[0]==1) {
            if (tabporteavion1x[0] > 15 && tabporteavion1x[1] > 15 && tabporteavion1x[2] > 15 &&
                tabporteavion1x[3] > 15 && tabporteavion1x[4] > 15 && tabporteavion1x[5] > 15 &&
                tabporteavion1x[6] > 15) {
                if(compteurporteavion1[0] !=7) {
                    for (i = 0; i < 7; i++) { ;
                        board1[tabporteavion1x[i]][tabporteavion1y[i]] = -1;
                    }
                    for (i = 0; i < 7; i++) {

                        tabporteavion1x[i] = tabporteavion1x[i] + 1;
                        board1[tabporteavion1x[i]][tabporteavion1y[i]] = 4;
                    }
                }
                else {
                    printf("Vous ne pouvez pas bouger le bateau il est coule\n");
                }
            }
            else {
                printf("Vous ne pouvez pas vous deplacer dans ce sens\n");
            }
        }
        else if(direction[0]==2) {
            if (tabporteavion1x[0] > 0 && tabporteavion1x[1] > 0 && tabporteavion1x[2] > 0 &&
                tabporteavion1x[3] > 0 && tabporteavion1x[4] > 0 && tabporteavion1x[5] > 0 &&
                tabporteavion1x[6] > 0) {
                if(compteurporteavion1[0] !=7) {
                    for (i = 0; i < 7; i++) { ;
                        board1[tabporteavion1x[i]][tabporteavion1y[i]] = -1;
                    }
                    for (i = 0; i < 7; i++) {

                        tabporteavion1y[i] = tabporteavion1y[i] - 1;
                        board1[tabporteavion1x[i]][tabporteavion1y[i]] = 4;
                    }
                }
                else {
                    printf("Vous ne pouvez pas bouger le bateau il est coule\n");
                }
            }
            else {
                printf("Vous ne pouvez pas vous deplacer dans ce sens\n");
            }
        }
        else{
            if (tabporteavion1x[0] > 0 && tabporteavion1x[1] > 0 && tabporteavion1x[2] > 0 &&
                tabporteavion1x[3] > 0 && tabporteavion1x[4] > 0 && tabporteavion1x[5] > 0 &&
                tabporteavion1x[6] > 0) {
                if(compteurporteavion1[0] !=7) {
                    for (i = 0; i < 7; i++) { ;
                        board1[tabporteavion1x[i]][tabporteavion1y[i]] = -1;
                    }
                    for (i = 0; i < 7; i++) {

                        tabporteavion1y[i] = tabporteavion1y[i] + 1;
                        board1[tabporteavion1x[i]][tabporteavion1y[i]] = 4;
                    }
                }

                else {
                    printf("Vous ne pouvez pas bouger le bateau il est coule\n");
                }
            }
            else{
                printf("Vous ne pouvez pas vous deplacer dans ce sens\n");
            }
        }
    }
        //Blindage Croiseur deplacement //
    else if(board1[deplacement[0]][deplacement[1]]==5 ) {
        if(direction[0]==2) {
            if (tabcroiseur1ay[0] > 0 && tabcroiseur1ay[1] > 0 && tabcroiseur1ay[2] > 0 &&
                tabcroiseur1ay[3] > 0 && tabcroiseur1ay[4] > 0) {
                if (compteurcroiseur1a[0]  != 5) {
                    for (i = 0; i < 5; i++) { ;
                        board1[tabcroiseur1ax[i]][tabcroiseur1ay[i]] = -1;
                    }
                    for (i = 0; i < 5; i++) {

                        tabcroiseur1ay[i] = tabcroiseur1ay[i] - 1;
                        board1[tabcroiseur1ax[i]][tabcroiseur1ay[i]] = 5;
                    }
                }
                else {
                    printf("Vous ne pouvez pas bouger le bateau il est coule\n");
                }
            }
            else{
                printf("Vous ne pouvez pas vous deplacer dans ce sens\n");
            }
        }
        else if(direction[0]==3) {
            if (tabcroiseur1ay[0] > 15 && tabcroiseur1ay[1] > 15 && tabcroiseur1ay[2] > 15 &&
                tabcroiseur1ay[3] > 15 && tabcroiseur1ay[4] > 15 ) {
                if(compteurcroiseur1a[0] !=5) {

                    for (i = 0; i < 5; i++) { ;
                        board1[tabcroiseur1ax[i]][tabcroiseur1ay[i]] = -1;
                    }
                    for (i = 0; i < 5; i++) {

                        tabcroiseur1ay[i] = tabcroiseur1ay[i] + 1;
                        board1[tabcroiseur1ax[i]][tabcroiseur1ay[i]] = 5;
                    }
                }
                else {
                    printf("Vous ne pouvez pas bouger le bateau il est coule\n");
                }
            }
            else {
                printf("Vous ne pouvez pas vous deplacer dans ce sens\n");
            }
        }
        else if(direction[0]==0) {
            if (tabcroiseur1ax[0] > 0 && tabcroiseur1ax[1] > 0 && tabcroiseur1ax[2] > 0 &&
                tabcroiseur1ax[3] > 0 && tabcroiseur1ax[4] > 0) {
                if(compteurcroiseur1a[0] !=5) {
                    for (i = 0; i < 5; i++) { ;
                        board1[tabcroiseur1ax[i]][tabcroiseur1ay[i]] = -1;
                    }
                    for (i = 0; i < 5; i++) {

                        tabcroiseur1ax[i] = tabcroiseur1ax[i] - 1;
                        board1[tabcroiseur1ax[i]][tabcroiseur1ay[i]] = 5;
                    }
                }
                else {
                    printf("Vous ne pouvez pas bouger le bateau il est coule\n");
                }
            }
            else {
                printf("Vous ne pouvez pas vous deplacer dans ce sens\n");
            }
        }
        else{
            if (tabcroiseur1ax[0] > 0 && tabcroiseur1ax[1] > 0 && tabcroiseur1ax[2] > 0 &&
                tabcroiseur1ax[3] > 0 && tabcroiseur1ax[4] > 0) {
                if(compteurcroiseur1a[0] !=5) {
                    for (i = 0; i < 5; i++) { ;
                        board1[tabcroiseur1ax[i]][tabcroiseur1ay[i]] = -1;
                    }
                    for (i = 0; i < 5; i++) {

                        tabcroiseur1ax[i] = tabcroiseur1ax[i] + 1;
                        board1[tabcroiseur1ax[i]][tabcroiseur1ay[i]] = 5;
                    }
                }
                else {
                    printf("Vous ne pouvez pas bouger le bateau il est coule\n");
                }
            }
            else{
                printf("Vous ne pouvez pas vous deplacer dans ce sens\n");
            }
        }
    }
        //Blindage Croiseur1 deplacement //
    else if(board1[deplacement[0]][deplacement[1]]==5 ) {
        if(direction[0]==2) {
            if (tabcroiseur1by[0] > 0 && tabcroiseur1by[1] > 0 && tabcroiseur1by[2] > 0 &&
                tabcroiseur1by[3] > 0 && tabcroiseur1by[4] > 0) {
                if (compteurcroiseur1b[0]  != 5) {
                    for (i = 0; i < 5; i++) { ;
                        board1[tabcroiseur1bx[i]][tabcroiseur1by[i]] = -1;
                    }
                    for (i = 0; i < 5; i++) {

                        tabcroiseur1by[i] = tabcroiseur1by[i] - 1;
                        board1[tabcroiseur1bx[i]][tabcroiseur1by[i]] = 5;
                    }
                }
                else {
                    printf("Vous ne pouvez pas bouger le bateau il est coule\n");
                }
            }
            else{
                printf("Vous ne pouvez pas vous deplacer dans ce sens\n");
            }
        }
        else if(direction[0]==3) {
            if (tabcroiseur1by[0] > 15 && tabcroiseur1by[1] > 15 && tabcroiseur1by[2] > 15 &&
                tabcroiseur1by[3] > 15 && tabcroiseur1by[4] > 15 ) {
                if(compteurcroiseur1b[0] !=5) {
                    for (i = 0; i < 5; i++) { ;
                        board1[tabcroiseur1bx[i]][tabcroiseur1by[i]] = -1;
                    }
                    for (i = 0; i < 5; i++) {

                        tabcroiseur1by[i] = tabcroiseur1by[i] + 1;
                        board1[tabcroiseur1bx[i]][tabcroiseur1by[i]] = 5;
                    }
                }
                else {
                    printf("Vous ne pouvez pas bouger le bateau il est coule\n");
                }
            }
            else {
                printf("Vous ne pouvez pas vous deplacer dans ce sens\n");
            }
        }
        else if(direction[0]==0) {
            if (tabcroiseur1bx[0] > 0 && tabcroiseur1bx[1] > 0 && tabcroiseur1bx[2] > 0 &&
                tabcroiseur1bx[3] > 0 && tabcroiseur1bx[4] > 0) {
                if(compteurcroiseur1b[0] !=5) {
                    for (i = 0; i < 5; i++) { ;
                        board1[tabcroiseur1bx[i]][tabcroiseur1by[i]] = -1;
                    }
                    for (i = 0; i < 5; i++) {

                        tabcroiseur1bx[i] = tabcroiseur1bx[i] - 1;
                        board1[tabcroiseur1bx[i]][tabcroiseur1by[i]] = 5;
                    }
                }
                else {
                    printf("Vous ne pouvez pas bouger le bateau il est coule\n");
                }
            }
            else {
                printf("Vous ne pouvez pas vous deplacer dans ce sens\n");
            }
        }
        else{
            if (tabcroiseur1bx[0] > 0 && tabcroiseur1bx[1] > 0 && tabcroiseur1bx[2] > 0 &&
                tabcroiseur1bx[3] > 0 && tabcroiseur1bx[4] > 0) {
                if(compteurcroiseur1b[0] !=5) {
                    for (i = 0; i < 5; i++) { ;
                        board1[tabcroiseur1bx[i]][tabcroiseur1by[i]] = -1;
                    }
                    for (i = 0; i < 5; i++) {

                        tabcroiseur1bx[i] = tabcroiseur1bx[i] + 1;
                        board1[tabcroiseur1bx[i]][tabcroiseur1by[i]] = 5;
                    }
                }
                else {
                    printf("Vous ne pouvez pas bouger le bateau il est coule\n");
                }
            }
            else{
                printf("Vous ne pouvez pas vous deplacer dans ce sens\n");
            }
        }
    }
        //Blindage Destroyer deplacement //
    else if(board1[deplacement[0]][deplacement[1]]==6 ) {
        if(direction[0]==2) {
            if (tabdestroyer1ay[0] > 0 && tabdestroyer1ay[1] > 0 && tabdestroyer1ay[2] > 0 ) {
                if (compteurdestroyer1a[0]  != 3) {
                    for (i = 0; i < 3; i++) { ;
                        board1[tabdestroyer1ax[i]][tabdestroyer1ay[i]] = -1;
                    }
                    for (i = 0; i < 3; i++) {

                        tabdestroyer1ay[i] = tabdestroyer1ay[i] - 1;
                        board1[tabdestroyer1ax[i]][tabdestroyer1ay[i]] = 6;
                    }
                }
                else {
                    printf("Vous ne pouvez pas bouger le bateau il est coule\n");
                }
            }
            else{
                printf("Vous ne pouvez pas vous deplacer dans ce sens\n");
            }
        }
        else if(direction[0]==3) {
            if (tabdestroyer1ay[0] > 15 && tabdestroyer1ay[1] > 15 && tabdestroyer1ay[2] > 15 ) {
                if(compteurdestroyer1a[0] !=3) {
                    for (i = 0; i < 3; i++) { ;
                        board1[tabdestroyer1ax[i]][tabdestroyer1ay[i]] = -1;
                    }
                    for (i = 0; i < 3; i++) {

                        tabdestroyer1ay[i] = tabdestroyer1ay[i] + 1;
                        board1[tabdestroyer1ax[i]][tabdestroyer1ay[i]] = 6;
                    }
                }
                else {
                    printf("Vous ne pouvez pas bouger le bateau il est coule\n");
                }
            }
            else {
                printf("Vous ne pouvez pas vous deplacer dans ce sens\n");
            }
        }
        else if(direction[0]==0) {
            if (tabdestroyer1ax[0] > 0 && tabdestroyer1ax[1] > 0 && tabdestroyer1ax[2] > 0) {
                if(compteurdestroyer1a[0] !=3) {
                    for (i = 0; i < 3; i++) { ;
                        board1[tabdestroyer1ax[i]][tabdestroyer1ay[i]] = -1;
                    }
                    for (i = 0; i < 3; i++) {

                        tabdestroyer1ax[i] = tabdestroyer1ax[i] - 1;
                        board1[tabdestroyer1ax[i]][tabdestroyer1ay[i]] = 6;
                    }
                }
                else {
                    printf("Vous ne pouvez pas bouger le bateau il est coule\n");
                }
            }
            else {
                printf("Vous ne pouvez pas vous deplacer dans ce sens\n");
            }
        }
        else{
            if (tabdestroyer1ax[0] > 0 && tabdestroyer1ax[1] > 0 && tabdestroyer1ax[2] > 0 ) {
                if(compteurdestroyer1a[0] !=3) {
                    for (i = 0; i < 3; i++) { ;
                        board1[tabdestroyer1ax[i]][tabdestroyer1ay[i]] = -1;
                    }
                    for (i = 0; i < 3; i++) {

                        tabdestroyer1ax[i] = tabdestroyer1ax[i] + 1;
                        board1[tabdestroyer1ax[i]][tabdestroyer1ay[i]] = 6;
                    }
                }
                else {
                    printf("Vous ne pouvez pas bouger le bateau il est coule\n");
                }
            }
            else{
                printf("Vous ne pouvez pas vous deplacer dans ce sens\n");
            }
        }
    }
        //Blindage Destroyer1 deplacement //
    else if(board1[deplacement[0]][deplacement[1]]==6 ) {
        if(direction[0]==2) {
            if (tabdestroyer1by[0] > 0 && tabdestroyer1by[1] > 0 && tabdestroyer1by[2] > 0 ) {
                if (compteurdestroyer1b[0]  != 3) {
                    for (i = 0; i < 3; i++) { ;
                        board1[tabdestroyer1bx[i]][tabdestroyer1by[i]] = -1;
                    }
                    for (i = 0; i < 3; i++) {

                        tabdestroyer1by[i] = tabdestroyer1by[i] - 1;
                        board1[tabdestroyer1bx[i]][tabdestroyer1by[i]] = 6;
                    }
                }
                else {
                    printf("Vous ne pouvez pas bouger le bateau il est coule\n");
                }
            }
            else{
                printf("Vous ne pouvez pas vous deplacer dans ce sens\n");
            }
        }
        else if(direction[0]==3) {
            if (tabdestroyer1by[0] > 15 && tabdestroyer1by[1] > 15 && tabdestroyer1by[2] > 15 ) {
                if(compteurdestroyer1b[0] !=3) {
                    for (i = 0; i < 3; i++) { ;
                        board1[tabdestroyer1bx[i]][tabdestroyer1by[i]] = -1;
                    }
                    for (i = 0; i < 3; i++) {

                        tabdestroyer1by[i] = tabdestroyer1by[i] + 1;
                        board1[tabdestroyer1bx[i]][tabdestroyer1by[i]] = 6;
                    }
                }
                else {
                    printf("Vous ne pouvez pas bouger le bateau il est coule\n");
                }
            }
            else {
                printf("Vous ne pouvez pas vous deplacer dans ce sens\n");
            }
        }
        else if(direction[0]==0) {
            if (tabdestroyer1bx[0] > 0 && tabdestroyer1bx[1] > 0 && tabdestroyer1bx[2] > 0) {
                if(compteurdestroyer1b[0] !=3) {
                    for (i = 0; i < 3; i++) { ;
                        board1[tabdestroyer1bx[i]][tabdestroyer1by[i]] = -1;
                    }
                    for (i = 0; i < 3; i++) {

                        tabdestroyer1bx[i] = tabdestroyer1bx[i] - 1;
                        board1[tabdestroyer1bx[i]][tabdestroyer1by[i]] = 6;
                    }
                }
                else {
                    printf("Vous ne pouvez pas bouger le bateau il est coule\n");
                }
            }
            else {
                printf("Vous ne pouvez pas vous deplacer dans ce sens\n");
            }
        }
        else{
            if (tabdestroyer1bx[0] > 0 && tabdestroyer1bx[1] > 0 && tabdestroyer1bx[2] > 0 ) {
                if(compteurdestroyer1b[0] !=3) {
                    for (i = 0; i < 3; i++) { ;
                        board1[tabdestroyer1bx[i]][tabdestroyer1by[i]] = -1;
                    }
                    for (i = 0; i < 3; i++) {

                        tabdestroyer1bx[i] = tabdestroyer1bx[i] + 1;
                        board1[tabdestroyer1bx[i]][tabdestroyer1by[i]] = 6;
                    }
                }
                else {
                    printf("Vous ne pouvez pas bouger le bateau il est coule\n");
                }
            }
            else{
                printf("Vous ne pouvez pas vous deplacer dans ce sens\n");
            }
        }
    }
        //Blindage Destroyer2 deplacement //
    else if(board1[deplacement[0]][deplacement[1]]==6 ) {
        if(direction[0]==2) {
            if (tabdestroyer1cy[0] > 0 && tabdestroyer1cy[1] > 0 && tabdestroyer1cy[2] > 0 ) {
                if (compteurdestroyer1c[0]  != 3) {
                    for (i = 0; i < 3; i++) { ;
                        board1[tabdestroyer1cx[i]][tabdestroyer1cy[i]] = -1;
                    }
                    for (i = 0; i < 3; i++) {

                        tabdestroyer1cy[i] = tabdestroyer1cy[i] - 1;
                        board1[tabdestroyer1cx[i]][tabdestroyer1cy[i]] = 6;
                    }
                }
                else {
                    printf("Vous ne pouvez pas bouger le bateau il est coule\n");
                }
            }
            else{
                printf("Vous ne pouvez pas vous deplacer dans ce sens\n");
            }
        }
        else if(direction[0]==3) {
            if (tabdestroyer1cy[0] > 15 && tabdestroyer1cy[1] > 15 && tabdestroyer1cy[2] > 15 ) {
                if(compteurdestroyer1c[0] !=3) {
                    for (i = 0; i < 3; i++) { ;
                        board1[tabdestroyer1cx[i]][tabdestroyer1cy[i]] = -1;
                    }
                    for (i = 0; i < 3; i++) {

                        tabdestroyer1cy[i] = tabdestroyer1cy[i] + 1;
                        board1[tabdestroyer1cx[i]][tabdestroyer1cy[i]] = 6;
                    }
                }
                else {
                    printf("Vous ne pouvez pas bouger le bateau il est coule\n");
                }
            }
            else {
                printf("Vous ne pouvez pas vous deplacer dans ce sens\n");
            }
        }
        else if(direction[0]==0) {
            if (tabdestroyer1cx[0] > 0 && tabdestroyer1cx[1] > 0 && tabdestroyer1cx[2] > 0) {
                if(compteurdestroyer1c[0] !=3) {
                    for (i = 0; i < 3; i++) { ;
                        board1[tabdestroyer1cx[i]][tabdestroyer1cy[i]] = -1;
                    }
                    for (i = 0; i < 3; i++) {

                        tabdestroyer1cx[i] = tabdestroyer1cx[i] - 1;
                        board1[tabdestroyer1cx[i]][tabdestroyer1cy[i]] = 6;
                    }
                }
                else {
                    printf("Vous ne pouvez pas bouger le bateau il est coule\n");
                }
            }
            else {
                printf("Vous ne pouvez pas vous deplacer dans ce sens\n");
            }
        }
        else{
            if (tabdestroyer1cx[0] > 0 && tabdestroyer1cx[1] > 0 && tabdestroyer1cx[2] > 0 ) {
                if(compteurdestroyer1c[0] !=3) {
                    for (i = 0; i < 3; i++) { ;
                        board1[tabdestroyer1cx[i]][tabdestroyer1cy[i]] = -1;
                    }
                    for (i = 0; i < 3; i++) {

                        tabdestroyer1cx[i] = tabdestroyer1cx[i] + 1;
                        board1[tabdestroyer1cx[i]][tabdestroyer1cy[i]] = 6;
                    }
                }
                else {
                    printf("Vous ne pouvez pas bouger le bateau il est coule\n");
                }
            }
            else{
                printf("Vous ne pouvez pas vous deplacer dans ce sens\n");
            }
        }
    }
        //Blindage sous marrin deplacement //
    else if(board1[deplacement[0]][deplacement[1]]==7 ) {
        if(direction[0]==2) {
            if (tabsousmarrin1ay[0] > 0 ) {
                if (compteursousmarrin1a[0]  != 1) {
                    for (i = 0; i < 1; i++) { ;
                        board1[tabsousmarrin1ax[i]][tabsousmarrin1ay[i]] = -1;
                    }
                    for (i = 0; i < 1; i++) {

                        tabsousmarrin1ay[i] = tabsousmarrin1ay[i] - 1;
                        board1[tabsousmarrin1ax[i]][tabsousmarrin1ay[i]] = 7;
                    }
                }
                else {
                    printf("Vous ne pouvez pas bouger le bateau il est coule\n");
                }
            }
            else{
                printf("Vous ne pouvez pas vous deplacer dans ce sens\n");
            }
        }
        else if(direction[0]==3) {
            if (tabsousmarrin1ay[0] > 15 ) {
                if(compteursousmarrin1a[0] !=1) {
                    for (i = 0; i < 1; i++) { ;
                        board1[tabsousmarrin1ax[i]][tabsousmarrin1ay[i]] = -1;
                    }
                    for (i = 0; i < 1; i++) {

                        tabsousmarrin1ay[i] = tabsousmarrin1ay[i] + 1;
                        board1[tabsousmarrin1ax[i]][tabsousmarrin1ay[i]] = 7;
                    }
                }
                else {
                    printf("Vous ne pouvez pas bouger le bateau il est coule\n");
                }
            }
            else {
                printf("Vous ne pouvez pas vous deplacer dans ce sens\n");
            }
        }
        else if(direction[0]==0) {
            if (tabsousmarrin1ax[0] > 0) {
                if(compteursousmarrin1a[0] !=3) {
                    for (i = 0; i < 1; i++) { ;
                        board1[tabsousmarrin1ax[i]][tabsousmarrin1ay[i]] = -1;
                    }
                    for (i = 0; i < 1; i++) {

                        tabsousmarrin1ax[i] = tabsousmarrin1ax[i] - 1;
                        board1[tabsousmarrin1ax[i]][tabsousmarrin1ay[i]] = 7;
                    }
                }
                else {
                    printf("Vous ne pouvez pas bouger le bateau il est coule\n");
                }
            }
            else {
                printf("Vous ne pouvez pas vous deplacer dans ce sens\n");
            }
        }
        else{
            if (tabsousmarrin1ax[0] > 0 ) {
                if(compteursousmarrin1a[0] !=3) {
                    for (i = 0; i < 1; i++) { ;
                        board1[tabsousmarrin1ax[i]][tabsousmarrin1ay[i]] = -1;
                    }
                    for (i = 0; i < 1; i++) {

                        tabsousmarrin1ax[i] = tabsousmarrin1ax[i] + 1;
                        board1[tabsousmarrin1ax[i]][tabsousmarrin1ay[i]] = 7;
                    }
                }
                else {
                    printf("Vous ne pouvez pas bouger le bateau il est coule\n");
                }
            }
            else{
                printf("Vous ne pouvez pas vous deplacer dans ce sens\n");
            }
        }
    }
        //Blindage sous marrin2 deplacement //
    else if(board1[deplacement[0]][deplacement[1]]==7 ) {
        if(direction[0]==2) {
            if (tabsousmarrin1by[0] > 0 ) {
                if (compteursousmarrin1b[0]  != 1) {
                    for (i = 0; i < 1; i++) { ;
                        board1[tabsousmarrin1bx[i]][tabsousmarrin1by[i]] = -1;
                    }
                    for (i = 0; i < 1; i++) {

                        tabsousmarrin1by[i] = tabsousmarrin1by[i] - 1;
                        board1[tabsousmarrin1bx[i]][tabsousmarrin1by[i]] = 7;
                    }
                }
                else {
                    printf("Vous ne pouvez pas bouger le bateau il est coule\n");
                }
            }
            else{
                printf("Vous ne pouvez pas vous deplacer dans ce sens\n");
            }
        }
        else if(direction[0]==3) {
            if (tabsousmarrin1by[0] > 15 ) {
                if(compteursousmarrin1b[0] !=1) {
                    for (i = 0; i < 1; i++) { ;
                        board1[tabsousmarrin1bx[i]][tabsousmarrin1by[i]] = -1;
                    }
                    for (i = 0; i < 1; i++) {

                        tabsousmarrin1by[i] = tabsousmarrin1by[i] + 1;
                        board1[tabsousmarrin1bx[i]][tabsousmarrin1by[i]] = 7;
                    }
                }
                else {
                    printf("Vous ne pouvez pas bouger le bateau il est coule\n");
                }
            }
            else {
                printf("Vous ne pouvez pas vous deplacer dans ce sens\n");
            }
        }
        else if(direction[0]==0) {
            if (tabsousmarrin1bx[0] > 0) {
                if(compteursousmarrin1b[0] !=3) {
                    for (i = 0; i < 1; i++) { ;
                        board1[tabsousmarrin1bx[i]][tabsousmarrin1by[i]] = -1;
                    }
                    for (i = 0; i < 1; i++) {

                        tabsousmarrin1bx[i] = tabsousmarrin1bx[i] - 1;
                        board1[tabsousmarrin1bx[i]][tabsousmarrin1by[i]] = 7;
                    }
                }
                else {
                    printf("Vous ne pouvez pas bouger le bateau il est coule\n");
                }
            }
            else {
                printf("Vous ne pouvez pas vous deplacer dans ce sens\n");
            }
        }
        else{
            if (tabsousmarrin1bx[0] > 0 ) {
                if(compteursousmarrin1b[0] !=3) {
                    for (i = 0; i < 1; i++) { ;
                        board1[tabsousmarrin1bx[i]][tabsousmarrin1by[i]] = -1;
                    }
                    for (i = 0; i < 1; i++) {

                        tabsousmarrin1bx[i] = tabsousmarrin1bx[i] + 1;
                        board1[tabsousmarrin1bx[i]][tabsousmarrin1by[i]] = 7;
                    }
                }
                else {
                    printf("Vous ne pouvez pas bouger le bateau il est coule\n");
                }
            }
            else{
                printf("Vous ne pouvez pas vous deplacer dans ce sens\n");
            }
        }
    }
        //Blindage sous marrin3 deplacement //
    else if(board1[deplacement[0]][deplacement[1]]==7 ) {
        if(direction[0]==2) {
            if (tabsousmarrin1cy[0] > 0 ) {
                if (compteursousmarrin1c[0]  != 1) {
                    for (i = 0; i < 1; i++) { ;
                        board1[tabsousmarrin1cx[i]][tabsousmarrin1cy[i]] = -1;
                    }
                    for (i = 0; i < 1; i++) {

                        tabsousmarrin1cy[i] = tabsousmarrin1cy[i] - 1;
                        board1[tabsousmarrin1cx[i]][tabsousmarrin1cy[i]] = 7;
                    }
                }
                else {
                    printf("Vous ne pouvez pas bouger le bateau il est coule\n");
                }
            }
            else{
                printf("Vous ne pouvez pas vous deplacer dans ce sens\n");
            }
        }
        else if(direction[0]==3) {
            if (tabsousmarrin1cy[0] > 15 ) {
                if(compteursousmarrin1c[0] !=1) {
                    for (i = 0; i < 1; i++) { ;
                        board1[tabsousmarrin1cx[i]][tabsousmarrin1cy[i]] = -1;
                    }
                    for (i = 0; i < 1; i++) {

                        tabsousmarrin1cy[i] = tabsousmarrin1cy[i] + 1;
                        board1[tabsousmarrin1cx[i]][tabsousmarrin1cy[i]] = 7;
                    }
                }

                else {
                    printf("Vous ne pouvez pas bouger le bateau il est coule\n");
                }
            }
            else {
                printf("Vous ne pouvez pas vous deplacer dans ce sens\n");
            }
        }
        else if(direction[0]==0) {
            if (tabsousmarrin1cx[0] > 0) {
                if(compteursousmarrin1c[0] !=3) {
                    for (i = 0; i < 1; i++) { ;
                        board1[tabsousmarrin1cx[i]][tabsousmarrin1cy[i]] = -1;
                    }
                    for (i = 0; i < 1; i++) {

                        tabsousmarrin1cx[i] = tabsousmarrin1cx[i] - 1;
                        board1[tabsousmarrin1cx[i]][tabsousmarrin1cy[i]] = 7;
                    }
                }
                else {
                    printf("Vous ne pouvez pas bouger le bateau il est coule\n");
                }
            }
            else {
                printf("Vous ne pouvez pas vous deplacer dans ce sens\n");
            }
        }
        else{
            if (tabsousmarrin1cx[0] > 0 ) {
                if(compteursousmarrin1c[0] !=3) {
                    for (i = 0; i < 1; i++) { ;
                        board1[tabsousmarrin1cx[i]][tabsousmarrin1cy[i]] = -1;
                    }
                    for (i = 0; i < 1; i++) {

                        tabsousmarrin1cx[i] = tabsousmarrin1cx[i] + 1;
                        board1[tabsousmarrin1cx[i]][tabsousmarrin1cy[i]] = 7;
                    }
                }
                else {
                    printf("Vous ne pouvez pas bouger le bateau il est coule\n");
                }
            }
            else{
                printf("Vous ne pouvez pas vous deplacer dans ce sens\n");
            }
        }
    }
        //Blindage sous marrin3 deplacement //
    else if(board1[deplacement[0]][deplacement[1]]==7 ) {
        if(direction[0]==2) {
            if (tabsousmarrin1dy[0] > 0 ) {
                if (compteursousmarrin1d[0]  != 1) {
                    for (i = 0; i < 1; i++) { ;
                        board1[tabsousmarrin1dx[i]][tabsousmarrin1dy[i]] = -1;
                    }
                    for (i = 0; i < 1; i++) {

                        tabsousmarrin1dy[i] = tabsousmarrin1dy[i] - 1;
                        board1[tabsousmarrin1dx[i]][tabsousmarrin1dy[i]] = 7;
                    }
                }
                else {
                    printf("Vous ne pouvez pas bouger le bateau il est coule\n");
                }
            }
            else{
                printf("Vous ne pouvez pas vous deplacer dans ce sens\n");
            }
        }
        else if(direction[0]==3) {
            if (tabsousmarrin1dy[0] > 15 ) {
                if(compteursousmarrin1d[0] !=1) {
                    for (i = 0; i < 1; i++) { ;
                        board1[tabsousmarrin1dx[i]][tabsousmarrin1dy[i]] = -1;
                    }
                    for (i = 0; i < 1; i++) {

                        tabsousmarrin1dy[i] = tabsousmarrin1dy[i] + 1;
                        board1[tabsousmarrin1dx[i]][tabsousmarrin1dy[i]] = 7;
                    }
                }
                else {
                    printf("Vous ne pouvez pas bouger le bateau il est coule\n");
                }
            }
            else {
                printf("Vous ne pouvez pas vous deplacer dans ce sens\n");
            }
        }
        else if(direction[0]==0) {
            if (tabsousmarrin1dx[0] > 0) {
                if(compteursousmarrin1d[0] !=3) {
                    for (i = 0; i < 1; i++) { ;
                        board1[tabsousmarrin1dx[i]][tabsousmarrin1dy[i]] = -1;
                    }
                    for (i = 0; i < 1; i++) {

                        tabsousmarrin1dx[i] = tabsousmarrin1dx[i] - 1;
                        board1[tabsousmarrin1dx[i]][tabsousmarrin1dy[i]] = 7;
                    }
                }
                else {
                    printf("Vous ne pouvez pas bouger le bateau il est coule\n");
                }
            }
            else {
                printf("Vous ne pouvez pas vous deplacer dans ce sens\n");
            }
        }
        else{
            if (tabsousmarrin1dx[0] > 0 ) {
                if(compteursousmarrin1d[0] !=3) {
                    for (i = 0; i < 1; i++) { ;
                        board1[tabsousmarrin1dx[i]][tabsousmarrin1dy[i]] = -1;
                    }
                    for (i = 0; i < 1; i++) {

                        tabsousmarrin1dx[i] = tabsousmarrin1dx[i] + 1;
                        board1[tabsousmarrin1dx[i]][tabsousmarrin1dy[i]] = 7;
                    }
                }
                else {
                    printf("Vous ne pouvez pas bouger le bateau il est coule\n");
                }
            }
            else{
                printf("Vous ne pouvez pas vous deplacer dans ce sens\n");
            }
        }
    }
    else{
        printf("Vous avez choisie une case ou il n'y a pas de bateau vous perdez votre tour\n");
    }
}
//Fonctionnement de l'iA
int IA(){
    int coup;
    sleep(1);
    coup=rand()%Hasard;
    int i,j;
    if (coup == 0) {
        sleep(1);
        shot[0] = rand() % BoardSize;
        shot[1] = rand() % BoardSize1;
        printf("\n=============Coup de l'ordinateur==============\n");
        printf("\nshot: %d / %d\n", shot[0] + 1, shot[1] + 1);
        testssitouche1();
    } else if (coup == 1) {
        sleep(1);
        fumi[0] = rand() % BoardSize;
        fumi[1] = rand() % BoardSize1;
        printf("\n============ Coup de l'ordinateur =============\n");
        printf("\nfumi: %d / %d\n", fumi[0] + 1, fumi[1] = 1);
        testsifumitouche1();
    }
}
//Affiche le tableau recapitulatif
void information(){

    printf("\n============== Informations ==================\n\n");
    printf("////////////////////Vos bateaux///////////////\n");

    if(compteurporteavion1[0]==7)
        printf("Votre porte avion est coule\n");
    else
        printf("Le porte avion a ete touche : %d\n",compteurporteavion1[0]);

    if(compteurcroiseur1a[0]==5)
        printf("Votre croiseur n 1 est coule\n");
    else
        printf("Le croiseur n 1 a ete touche : %d\n",compteurcroiseur1a[0]);

    if(compteurcroiseur1b[0]==5)
        printf("Votre croiseur n 2 est coule\n");
    else
        printf("Le croiseur n 2 a ete touche : %d\n",compteurcroiseur1b[0]);

    if(compteurdestroyer1a[0]==3)
        printf("Votre destroyer n 1 est coule\n");
    else
        printf("Le destroyer n 1 a ete touche : %d\n",compteurdestroyer1a[0]);
    if(compteurdestroyer1b[0]==3)
        printf("Votre destroyer n 2 est coule\n");
    else
        printf("Le destroyer n 2 a ete touche : %d\n",compteurdestroyer1b[0]);
    if(compteurdestroyer1c[0]==3)
        printf("Votre destroyer n 3 est coule\n");
    else
        printf("Le destroyer n 3 a ete touche : %d\n",compteurdestroyer1c[0]);
    if(compteursousmarrin1a[0]==4)
        printf("Vous avez coule tous les sous marrins \n");
    else
        printf("Vous avez perdu %d sous marrin\n",compteursousmarrin1a[0]);
    printf("\n");

    printf("///////Les bateaux de votre adversaire///////\n");
    if(compteurporteavion2[0]==7)
        printf("Vous avez coule le porte avion\n");
    else
        printf("Le porte avion a ete touche : %d\n",compteurporteavion2[0]);
    if(compteurcroiseur2a[0]==5)
        printf("Vous avez coule le croiseur n 1\n");
    else
        printf("Le croiseur n 1 a ete touche : %d\n",compteurcroiseur2a[0]);
    if(compteurcroiseur2b[0]==5)
        printf("Vous avez coule le croiseur n 2\n");
    else
        printf("Le croiseur n 2 a ete touche : %d\n",compteurcroiseur2b[0]);
    if(compteurdestroyer2a[0]==3)
        printf("Vous avez coule le destroyer n 1\n");
    else
        printf("Le destroyer n 1 a ete touche : %d\n",compteurdestroyer2a[0]);
    if(compteurdestroyer2b[0]==3)
        printf("Vous avez coule le destroyer n 2\n");
    else
        printf("Le destroyer n 2 a ete touche : %d\n",compteurdestroyer2b[0]);
    if(compteurdestroyer2c[0]==3)
        printf("Votre destroyer n 3 est coule\n");
    else
        printf("Le destroyer n 3 a ete touche : %d\n",compteurdestroyer1c[0]);
    if(compteursousmarrin2a[0]==4)
        printf("Vous avez coule tous les sous marrins \n");
    else
        printf("Vous avez coule %d sous marrin\n",compteursousmarrin2a[0]);
    printf("\n");
}
//Affiche la grille des bateaux du joueur
void afficherboard1()
{
    int ligne, colonne;
    printf("  | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11| 12| 13| 14| 15|");
    printf("\n");
    for(ligne=0 ; ligne < BoardSize ; ligne++ ){
        if(ligne<9) {
            printf("%d |", ligne + 1);
        }
        else{
            printf("%d|", ligne + 1);
        }
        for(colonne=0 ; colonne < BoardSize ; colonne++ ){
            // pas de bateau
            if(board1[ligne][colonne]==-1){
                color(15,3);
                printf("   ");
                color(15,0);
                printf("|");
            }
                // rate
            else if(board1[ligne][colonne]==0){
                printf(" * |");
            }
                // touche
            else if(board1[ligne][colonne]==1){
                printf(" T |");
            }
                // fumigene sans bateau
            else if(board1[ligne][colonne]==2){
                printf(" 0 |");
            }
                // fumigene si bateau present
            else if(board1[ligne][colonne]==3){
                printf(" F |");
            }
            else if(board1[ligne][colonne]==4){
                color(0,7);
                printf(" P ");
                color(15,0);
                printf("|");
            }
            else if(board1[ligne][colonne]==5){
                color(0,7);
                printf(" C ");
                color(15,0);
                printf("|");
            }
            else if(board1[ligne][colonne]==6){
                color(0,7);
                printf(" D ");
                color(15,0);
                printf("|");
            }
            else if(board1[ligne][colonne]==7){
                color(0,7);
                printf(" S ");
                color(15,0);
                printf("|");
            }
            else if(board1[ligne][colonne]==8){
                printf(" B |");
            }
        }
        printf("\n");
        puts("  +---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+");
    }
    printf("\n\n");
}
//Affiche la grille cachee sur laquelle le joueur tire
void afficherboard2()
{
    int ligne, colonne;
    printf("  | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11| 12| 13| 14| 15|");
    printf("\n");
    for(ligne=0 ; ligne < BoardSize ; ligne++ ){
        if(ligne<9) {
            printf("%d |", ligne + 1);
        }
        else{
            printf("%d|", ligne + 1);
        }
        for(colonne=0 ; colonne < BoardSize ; colonne++ ){
            // pas de bateau
            if(board2[ligne][colonne]==-1){
                color(15,3);
                printf("   ");
                color(15,0);
                printf("|");
            }
                // rate
            else if(board2[ligne][colonne]==0){
                printf(" * |");
            }
                // touche
            else if(board2[ligne][colonne]==1){
                printf(" T |");
            }
                // fumigene sans bateau
            else if(board2[ligne][colonne]==2){
                printf(" 0 |");
            }
                // fumigene si bateau present
            else if(board2[ligne][colonne]==3){
                printf(" F |");
            }
            else if(board2[ligne][colonne]==4){
                color(0,7);
                printf(" P ");
                color(15,0);
                printf("|");
            }
            else if(board2[ligne][colonne]==5){
                color(0,7);
                printf(" C ");
                color(15,0);
                printf("|");
            }
            else if(board2[ligne][colonne]==6){
                color(0,7);
                printf(" D ");
                color(15,0);
                printf("|");
            }
            else if(board2[ligne][colonne]==7){
                color(0,7);
                printf(" S ");
                color(15,0);
                printf("|");
            }
            else if(board2[ligne][colonne]==8){
                printf(" B |");
            }
        }
        printf("\n");
        puts("  +---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+");
    }
}
//Affiche la grille des bateaux de l'ordi
void afficherboard3()
{
    int ligne, colonne;
    printf("  | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11| 12| 13| 14| 15|");
    printf("\n");
    for(ligne=0 ; ligne < BoardSize ; ligne++ ){
        if(ligne<9) {
            printf("%d |", ligne + 1);
        }
        else{
            printf("%d|", ligne + 1);
        }
        for(colonne=0 ; colonne < BoardSize ; colonne++ ){
            // pas de bateau
            if(board3[ligne][colonne]==-1){
                color(15,3);
                printf("   ");
                color(15,0);
                printf("|");
            }
                // rate
            else if(board3[ligne][colonne]==0){
                color(15,8);
                printf("   ");
                color(15,0);
                printf("|");
            }
                // touche
            else if(board3[ligne][colonne]==1){
                color(15,4);
                printf(" T ");
                color(15,0);
                printf("|");
            }
                // fumigene sans bateau
            else if(board3[ligne][colonne]==2){
                color(15,1);
                printf("   ");
                color(15,0);
                printf("|");
            }
                // fumigene si bateau present
            else if(board3[ligne][colonne]==3){
                color(15,13);
                printf("   ");
                color(15,0);
                printf("|");
            }
            else if(board3[ligne][colonne]==4){
                printf(" P |");
            }
            else if(board3[ligne][colonne]==5){
                printf(" C |");
            }
            else if(board3[ligne][colonne]==6){
                printf(" D |");
            }
            else if(board3[ligne][colonne]==7){
                printf(" S |");
            }
        }
        printf("\n");
        puts("  +---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+");
    }
}

//Fonction qui permet de quitter a tout moment le programme
int quitter()
{
    printf("Vous avez quittez la partie\n");
    return 0;
}

//Choix du menu principale
int menu(int choixmenu)
{
    printf("1. Lancer une nouvelle partie\n");
    printf("2. Charger une partie\n");
    printf("3. Regles de la bataille naval\n");
    printf("4. Quittez le jeu\n\n");
    scanf("%d",&choixmenu);
    return choixmenu;
}

//Fonction principale qui permet de controler la partie
int main(){
    int choixmenu = 0;
    int i;
    iniboard1();
    iniboard2();
    iniboard3();
    iniboard4();
    positionnementbateaux1();
    sleep(1);
    positionnementbateaux2();
    clock_t start = clock();
    do {
        choixmenu=menu(&choixmenu);
        switch (choixmenu) {
            case 1:
                printf("Notre grille :\n");
                afficherboard1();
                printf("Grille adversaire :\n");
                afficherboard3();
                do {
                    printf("1. Lancer une torpille\n");
                    printf("2. Lancer un fumigene\n");
                    printf("3. Deplacer un bateau\n");
                    printf("4. Reveler les bateaux ennemis\n");
                    printf("5. Quitter la partie\n");
                    scanf("%d", &choixmenu);
                    switch (choixmenu) {
                        case 1:
                            Coortire();
                            testssitouche2();
                            afficherboard1();
                            afficherboard3();
                            printf("\n=============Coup du joueur==============\n");
                            printf("\nLe joueur a lance un missile !\n");
                            IA();
                            information();
                            printf("================= Fin du tour ===============\n\n");
                            if(compteurporteavion1[0]>=7 && compteurcroiseur1a[0] >=5 && compteurcroiseur1b[0]>=5 && compteurdestroyer1a[0]>=3 && compteurdestroyer1b[0]>=3 && compteurdestroyer1c[0]>=3 && compteursousmarrin1a[0]>=4){
                                printf("La partie est terminee, elle a duree %d minute(s) et %d seconde(s)\n", (clock() - start) / CLOCKS_PER_SEC / 60, (clock() - start) / CLOCKS_PER_SEC % 60);
                                printf("\n=============================================\n");
                                printf("         Vous avez perdu la partie\n");
                                printf("=============================================\n\n");
                                choixmenu=5;
                            }
                            if(compteurporteavion2[0]>=7 && compteurcroiseur2a[0] >=5 && compteurcroiseur2b[0]>=5 && compteurdestroyer2a[0]>=3 && compteurdestroyer2b[0]>=3 && compteurdestroyer2c[0]>=3 && compteursousmarrin2a[0]>=4){
                                printf("La partie est terminee, elle a duree %d minute(s) et %d seconde(s)\n", (clock() - start) / CLOCKS_PER_SEC / 60, (clock() - start) / CLOCKS_PER_SEC % 60);
                                printf("\n=============================================\n");
                                printf("         Vous avez gagne la partie\n");
                                printf("=============================================\n\n");
                                choixmenu=5;
                            }
                            break;
                        case 2:
                            Coorfumi();
                            testsifumitouche2();
                            afficherboard1();
                            afficherboard3();
                            printf("\n=============Coup du joueur==============\n");
                            printf("\nLe joueur a lance une fumigène !\n");
                            IA();
                            information();
                            printf("================= Fin du tour ===============\n");
                            break;
                        case 3:
                            bougerbateau();
                            afficherboard1();
                            afficherboard3();
                            printf("\n=============Coup du joueur==============\n");
                            printf("\nLe joueur a bouge un bateaux !\n");
                            IA();
                            information();
                            printf("================= Fin du tour ===============\n");
                            break;
                        case 4:
                            afficherboard1();
                            afficherboard2();
                            printf("\n=============Coup du joueur==============\n");
                            printf("\nVous avez triche !\n");
                            IA();
                            information();
                            printf("================= Fin du tour ===============\n");
                            break;
                    }
                } while (choixmenu != 5);
                printf("\nVous avez quitte la partie, elle a duree %d minute(s) et %d seconde(s)\n", (clock() - start) / CLOCKS_PER_SEC / 60, (clock() - start) / CLOCKS_PER_SEC % 60);
                break;
            case 2:
                break;
            case 3:
                regles();
                break;
        }
    } while (choixmenu != 4);
    quitter();
}