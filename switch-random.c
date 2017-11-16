/* switch-random.c - Kurzbeispiel zu switch und rand() 
 * (C) FHDW Motivation Group 2017 - http://github.com/fhdwbap/switch-random
 *
 * In diesem Code wird u.a. die Funktion strchr() verwendet, die mit dem Aufruf
 * strchr(s,z) prueft, ob ein Zeichen z in einer Zeichenkette s vorkommt
 * [siehe z.B. https://www.tutorialspoint.com/cprogramming/c_strings.htm].
 *
 * Anregung: wenn Sie recht fleissig sein wollen, dann koennen Sie das in dieser
 * Version ziemlich umfangreich geratene Hauptprogramm main() durch die Einfuehrung
 * weiterer Funktionen (fuer die einzelnen Auswahlpunkte) ein bisschen straffen.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define ERROR_NO_STATISTICS_AVAILABLE  1001
#define ERROR_NO_VALID_SELECTION       1002

void error(int);
void hilfe();

int main(void) 
{
  char auswahl = '$';
  int anzahl = 0, minimum = -1, maximum = -1, zahl = 0;
  time_t t;
  
  printf("Willkommen.\n");
  hilfe();
  
  srand((unsigned)time(&t)); // Initialisiert den Pseudo-Zufallszahlengenerator
  
  do
  {
    printf("> ");
    fflush(stdin);
    auswahl = getchar();
    getchar();
    
    switch(auswahl)
    {
      case 'h':
      case 'H':
      case '?': // undokumentierter Hilfe-Aufruf ;-)
        hilfe();
        break;
      
      case 's':
      case 'S':
        if (anzahl > 0)
        {
          printf("Statistik:\nkleinster Wert: %d\ngroesster Wert: %d\n"
                "Anzahl Werte: %d\n", minimum, maximum, anzahl);
        }
        else
        {
          error(ERROR_NO_STATISTICS_AVAILABLE);
          printf("Es wurden noch keine Werte generiert!\n");
        }
        break;
        
      case 'x':
      case 'X':
        printf("Auf Wiedersehen.\n");
        break;
      
      case 'z':
      case 'Z':
          t = time(NULL);
          zahl = rand(); // Erzeugen einer Zufallszahl
          printf("Generiert wurde die Zahl %d.\n",zahl);
          if (anzahl == 0)
          {
            minimum = maximum = zahl;
          }
          anzahl++;
          if (zahl < minimum)
          {
            minimum = zahl;
          }
          if (zahl > maximum)
          {
            maximum = zahl;
          }
      
        break;
        
      default:
        error(ERROR_NO_VALID_SELECTION);
        printf("'%c' ist keine gueltige Auswahl.\n",auswahl);
    }
    
  } while (strchr("Xx",auswahl)==NULL);
  // alternativ ist moeglich:     while (!strchr("Xx",auswahl))

  return EXIT_SUCCESS;
}

void error(int no)
{
   printf("Fehler Nr. %d aufgetreten: ",no);  
}

void hilfe()
{
  printf("Geben Sie bitte 'z' fuer eine neue Zufallszahl ein,\n"
        "'s' fuer eine Statistik oder 'x' fuer Exit/Beenden.\n"
        "'h' zeigt diese Hilfe noch einmal an.\n");
}

