#ifndef __GESTIONADHERENTS_H__
#define __GESTIONADHERENTS_H__

#include <donnees/types.h>

/* Définition de l'annuaire et de sa taille maximum en nombre d'adhérents
   sous optimum en gestion mémoire mais facilite votre utilisation
   de ce module */
#define ADHS_NBMAX 50
extern adherent_t Annuaire[ADHS_NBMAX];

/* Valeur contenant le nombre d'adhérents actuellement dans l'annuaire */
extern int ann_nb_adhs;

/****************************************************************
		Fonctions exportées par le module */

/*
	Fonction : LireAnnuaire

	Paramètre : un pointeur sur une chaine terminée par
             le caractère '\0' contenant le nom du fichier à charger.

	Valeur de retour : le nombre d'adhérents lus depuis le fichier
	     ou 0 si aucun n'a pu être lu.

	Remarque : si la fonction ne peut ouvrir le fichier, l'annuaire reste
	     inchangé.

*/
int LireAnnuaire (const char *NomFichier);

/*
	Fonction : EcrireAnnuaire

	Paramètre : un pointeur sur une chaine terminée par
	    le caractère '\0' contenant le nom du fichier pour la sauvegarde.

	Valeur de retour : le nombre d'adhérents écrits dans le fichier
	    ou 0 si l'écriture l'a pu être possible.

	Remarque : l'annuaire reste inchangé.

*/
int EcrireAnnuaire (const char *NomFichier);

#endif // ifndef __GESTIONADHERENTS_H__
