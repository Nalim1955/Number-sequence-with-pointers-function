#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Vytvorte program, ktory do pola nacita postupnost cisel a nasledne vypocita priemer
z prvkov pola. Umoznite velkost pola zadat pouzivatelovi, pole alokujte dynamicky a
na najdenie priemeru pouzite a) funkciu, ktora pracuje s polom, b) funkciu, ktora
vyuziva ukazatele.*/

double f_pole_a(double pole[], int velkost); //funkcia zadanie a
double f_ukazovatel_b(double *pole, int velkost); //funkcia zadanie b

int main(void)
{
    double *p_array;
    int i, rozsah_pola, rozhodnutie;

    do
    {
        printf("Zadaj rozsah pola: ");
        scanf("%d", &rozsah_pola);
    }
    while(1 > rozsah_pola); // Rozsah vacsi ako 0

    printf("\nPostupnost cisel mozete zadat manualne alebo automaticky: ");

    do
    {
        printf("\nPre manualne zadanie stlac 1. | Pre automaticke zadanie stlac 2. :");
        scanf("%d", &rozhodnutie);
    }
    while(!(1 == rozhodnutie) && !(2 == rozhodnutie));

    p_array=(double*)calloc(rozsah_pola,sizeof(double)); //alokovane pole dinamicky

    if(!p_array)
    {
        printf("Pole sa nepodarilo vytvorit !!!");
        return 1;
    }
    else
    {
        if (rozhodnutie == 1)
        {
            for(i=0; i<rozsah_pola; i++)
            {
                printf("Zadaj prvok c. %d: ", i+1);
                scanf("%lf", &p_array[i]);
            }

        }
        else if (rozhodnutie == 2)
        {
            srand (time(NULL));
            for(i=0; i<rozsah_pola; i++)
            {
                p_array[i] = ((double)rand() * (500 - 0.3)) / (double)RAND_MAX + 0.07;
            }
            /* Zobrazenie cisiel pri automatickom generovani
            printf("\n");

            for(i=0; i<rozsah_pola; i++)
            {
              printf("%lf \t",p_array[i]);
            }
            */
        }

        printf("\n\nPriemer z prvkov - pomocou funkcie, ktora pracuje s polom: %lf\n", f_pole_a(p_array, rozsah_pola)); //funkcia zadanie a
        printf("Priemer z prvkov - pomocou funkcie, ktora vyuziva ukazatele: %lf\n", f_ukazovatel_b(p_array, rozsah_pola)); //funkcia zadanie b
    }

    free((void *)p_array);
    p_array=NULL;

    return 0;
}

double f_pole_a(double pole[], int velkost) //funkcia zadanie a
{
    double avg, pomoc;
    int  i;

    for(i=0; i<velkost; i++)
    {
        pomoc += pole[i];
    }

    avg = pomoc / velkost;

    return avg;
}

double f_ukazovatel_b(double *pole, int velkost) //funkcia zadanie b
{
    double avg, pomoc;
    int  i;

    for(i=0; i<velkost; i++)
    {
        pomoc += *(pole+i);
    }

    avg = pomoc / velkost;

    return avg;
}
