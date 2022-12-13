#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char	buf[100];	// stocke les caractères lus par read
	int	fd;		// descripteur de fichier à lire
	int	nb_read;	// stocke le retour de read
	int	count;		// compte du nombre de lectures avec read

//	Ouvre le fichier cat.txt en mode lecture seule
	fd = open("cat.txt", O_RDONLY);
	if (fd == -1)
		return (1);
//	Initialise les variables de compte
	nb_read = -1;
	count = 0;
//	Boucle tant que read ne retourne pas 0 (ce qui veut dire
//	qu'il n'y a plus rien à lire dans le fichier)
	while (nb_read != 0)
	{
		// Lecture de 100 caractères avec read depuis le
		// descripteur de fichier ouvert
		nb_read = read(fd, buf, 100);
		// En cas d'erreur, read renvoie -1, on arrête tout
		if (nb_read == -1)
		{
			printf("Erreur de lecture !\n");
			return (1);
		}
		// Read n'ajoute pas le \0 à la fin de la chaîne
		// de caractères lus. On peut se servir du nombre
		// de caractères lus comme index du dernier caractère
		buf[nb_read] = '\0';
		// Imprime ce que contient le buffer après la lecture
		printf("\e[36m%d : [\e[0m%s\e[36m]\e[0m\n", count, buf);
		count++;
	}
//	Ferme le descripteur de fichier ouvert plus tôt
	close(fd);
	return (0);
}