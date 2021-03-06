/*
 *  GestionAdherents.c
 *  MIAGE2
 *
 *  Created by Vania Marangozova-Martin on 23/11/06.
 *  Copyright 2006 UJF
 *
 */
 
#include <stdio.h>
#include "GestionAdherents.h"

/****************************************************************
    Déclaration des variables conformément au fichier .h */

/* Déclaration de l'annuaire contenant au maximum NombreMaximumDeAdherents */
Adherent Annuaire[NombreMaximumDAdherents];

/* Variable contenant le nombre d'adhérents courant dans l'annuaire
   Cette valeur doit rester cohérente avec la capacité de l'annuaire */
int NombreAdherentsDansAnnuaire = 0;	/* par défault, aucun adherent */


/****************************************************************
    Ecriture des fonctions nécessaires au fonctionnement du module */

/*
	Fonction : LireAnnuaire

	Paramètre : un pointeur sur une chaine terminée par
		le caractère '\0' contenant le nom du fichier à charger.

	Valeur de retour : le nombre d'adhérents lus depuis le fichier,
		0 si aucun n'a pu être lu, un code d'erreur en cas de problème :
		-1 si les paramètres sont incorrects
		-2 si l'on a pas pu ouvrir le fichier

	Remarque : si la fonction ne peut ouvrir le fichier, l'annaire reste
		inchangé.

*/
int
LireAnnuaire (const char *NomFichier)
{
	FILE *Fichier;		/* le pointeur sur le descripteur de fichier */
	int NombreAdherentsLus;	/* Nombres d'adhérents lus dans le fichiers */

	/* Tests des paramètres: pointeur NULL ou chaîne vide */
	if (NomFichier == NULL || NomFichier[0] == '\0')
		return ParametresIncorrects;

	/* Tentative d'ouverture du fichier en lecture binaire et vérification */
	Fichier = fopen (NomFichier, "rb");
	if (Fichier == NULL)
	  {
		  /* Impossible d'ouvrir le fichier */
		  return OuvertureFichierImpossible;
	  }

	/* On lit au maximum NombreMaximumDeAdherents adhérents depuis le fichier */
	NombreAdherentsLus =
		fread (Annuaire, sizeof (Adherent), NombreMaximumDAdherents,
		       Fichier);

	/* Fermeture du fichier */
	fclose (Fichier);

	/* Mise a jours des variables du module et retour du résultat */
	NombreAdherentsDansAnnuaire = NombreAdherentsLus;

	return NombreAdherentsLus;
}

/*
	Fonction : EcrireAnnuaire

	Paramètre : un pointeur sur une chaine terminée par
		le caractère '\0' contenant le nom du fichier pour la sauvagarde.

	Valeur de retour : le nombre d'adhérents écrits dans le fichier
		ou 0 si l'écriture l'a pu être possible.

	Remarque : le repertoire reste inchangé.

*/
int
EcrireAnnuaire (const char *NomFichier)
{
	FILE *Fichier;		/* le pointeur sur le descripteur de fichier */
	int NombreAdherentsEcrits = 0;	/* Nombres d'adhérents écrits dans le fichiers */

	/* Tests des paramètres: pointeur NULL ou chaîne vide */
	if (NomFichier == NULL || NomFichier[0] == '\0')
		return ParametresIncorrects;

	/* Tentative d'ouverture du fichier en écriture binaire et vérification */
	Fichier = fopen (NomFichier, "wb");
	if (Fichier == NULL)
	  {
		  /* Impossible d'ouvrir le fichier */
		  return OuvertureFichierImpossible;
	  }

	/* Ecriture des adhérents s'il y en a dans le repertoire */
	if (NombreAdherentsDansAnnuaire != 0)
	  {
		  NombreAdherentsEcrits =
			  fwrite (Annuaire, sizeof (Adherent),
				  NombreAdherentsDansAnnuaire, Fichier);
	  }

	/* Fermeture du fichier */
	fclose (Fichier);

	/* On retourne le nombre de livres écrits dans le fichier */
	return NombreAdherentsEcrits;
}

