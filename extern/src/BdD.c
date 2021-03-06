/****************************************************************

	Corps du module des données BdD.c
	Auteur: Dominique Vaufreydaz, Vincent Danjean

*****************************************************************/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/file.h>
#include <unistd.h>
#include <stdio.h>
#include "BdD.h"

/****************************************************************
    Définition des variables conformément au fichier .h 
*/

/* Déclaration du catalogue contenant au maximum NombreMaximumDeLivres */
Livre Catalogue[NombreMaximumDeLivres];

/* Variable contenant le nombre d'ouvrage courant dans le catalogue
   Cette valeur doit rester cohérente avec la capacité du catalogue */
int NombreOuvragesAuCatalogue = 0;	/* par défault, aucun livre */

/* Déclaration de l'annuaire contenant au maximum NombreMaximumDeAdherents */
Adherent Annuaire[NombreMaximumDAdherents];

/* Variable contenant le nombre d'adhérents courant dans l'annuaire
   Cette valeur doit rester cohérente avec la capacité de l'annuaire */
int NombreAdherentsDansAnnuaire = 0;	/* par défault, aucun adherent */

/****************************************************************
    Implémentation des fonctions du module
*/


#define LOCK_FILENAME "serveur.lock"

static int lock_fd = -1;

void BdD_acces_lecture_debut()
{
	lock_fd = open(LOCK_FILENAME, O_RDONLY | O_CREAT, S_IRUSR);
	if (-1 == lock_fd) {
		perror("Unable to open " LOCK_FILENAME);
		return;
	}
	flock(lock_fd, LOCK_SH);
}

void BdD_acces_lecture_fin()
{
	if (-1 == lock_fd) {
		return;
	}
	flock(lock_fd, LOCK_UN);
	close(lock_fd);
	lock_fd = -1;
}

void BdD_acces_ecriture_debut()
{
	lock_fd = open(LOCK_FILENAME, O_RDONLY | O_CREAT, S_IRUSR);
	if (-1 == lock_fd) {
		perror("Unable to open " LOCK_FILENAME);
		return;
	}
	flock(lock_fd, LOCK_EX);
}

void BdD_acces_ecriture_fin()
{
	if (-1 == lock_fd) {
		return;
	}
	flock(lock_fd, LOCK_UN);
	close(lock_fd);
	lock_fd = -1;
}

/* Lecture des données depuis le ou les fichiers vers la mémoire
   (ie vers les tableaux Catalogue et Annuaire ainsi que vers les
   variables globales NombreOuvragesAuCatalogue et
   NombreAdherentsDansAnnuaire)
*/
void BdD_chargement()
{
	/* A COMPLETER
	 */
}

/* Sauvegarde des données depuis la mémoire vers le ou les fichiers
*/
void BdD_sauvegarde()
{
	/* A COMPLETER
	 */
}
