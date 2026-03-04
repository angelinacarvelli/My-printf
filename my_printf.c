#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int my_putchar(char character)       // Fonction qui affiche UN caractère
{
    return write(1, &character, 1);     // write(fd=1 car ecrit dans term, adresse du char, taille ) → renvoie 1 si OK
}

int my_putstr(char *string)                        // Fonction qui affiche une chaîne de caractères
{
    int size = 0;

    if (!string)      // Si string == NULL
    {
        return my_putstr("(null)"); 
    }

    while (*string)         // Boucle tant que le pointeur ne pointe pas sur '\0'
    {
        write(1, string, 1);    // Affiche le caractère pointé (*string)
        string += 1;
        size += 1;
    }
    return size;        // Retourne le nombre total de caractères écrits
}

int my_putnbr(long number, int base, char *hexadecimal) // Affiche un nombre dans la base donnée
{
    int size = 0;

    if (number < 0)      // Si le nombre est négatif
    {
        size += my_putchar('-');     // Affiche le signe moins
        number = -number;         // Rend le nombre positif pour la suite
    }

    if (number >= base)           // Si le nombre est grand pour être représenté sur plusieurs chiffres
        size += my_putnbr(number / base, base, hexadecimal); // Appel récursif : affiche les "chiffres avant"

    size += my_putchar(hexadecimal[number % base]); // Affiche le dernier chiffre (représentation dans la base "hexadecimal")

    return size;              
}

int my_printf(char *formatage, ...)
{
    va_list args;         // Liste d'arguments variadiques
    int size = 0;

    va_start(args, formatage);   // Initialise la liste d'arguments

    for (int index = 0; formatage[index]; index += 1)   // Parcours caractère par caractère la string formatage
    {
        if (formatage[index] == '%')    // Si on détecte un %
        {
            index += 1;      // On avance pour lire la lettre juste après %

            if (formatage[index] == 's')           // %s : string
                size += my_putstr(va_arg(args, char*)); // Récupère un "char*" dans la liste d'arguments

            else if (formatage[index] == 'c')      // %c : caractère
                size += my_putchar(va_arg(args, int));  // Les chars deviens en int dans variadics

            else if (formatage[index] == 'd')      // %d : entier signé
                size += my_putnbr(va_arg(args, int), 10, "0123456789"); // base 10

            else if (formatage[index] == 'o')      // %o : affichage octal
                size += my_putnbr(va_arg(args, unsigned int), 8, "01234567");

            else if (formatage[index] == 'u')      // %u : entier non signé en base 10
                size += my_putnbr(va_arg(args, unsigned int), 10, "0123456789");

            else if (formatage[index] == 'x')      // %x : hexadécimal (majuscule)
                size += my_putnbr(va_arg(args, unsigned int), 16, "0123456789ABCDEF");

            else if (formatage[index] == 'p')      // %p : pointeur (adresse mémoire)
            {
                size += my_putstr(("0x"));    // Préfixe classique d'une adresse
                size += my_putnbr((unsigned long)va_arg(args, void *), // Récupère le pointeur et cast en entier
                                   16, "0123456789abcdef");             // En base 16, format minuscule
            }
        }
        else
        {
            size += my_putchar(formatage[index]);  // Si ce n’est pas %, on affiche le caractère tel quel
        }
    }

    va_end(args);              // Termine l'utilisation des arguments var
    return size;
}

 int main()
 {
     my_printf("Test : %d %o %u %x %p 12\n",-42, 42, 42, 42);
     return 0;
 }
