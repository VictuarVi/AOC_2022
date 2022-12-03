#include <stdio.h>
#include <stdlib.h>

#define dim 99999

int main()
{
    FILE *f;
    f = fopen("input.txt", "r");
    char num[10];      // numero
    int s = 0, sM = 0; // somme parziali, somma massima
    int sM3[dim], i = 0;

    for (i = 0; i < dim; i++)
    {
        sM3[i] = 0;
    }

    i = 0;
    while (!feof(f))
    {
        int val = (atoi(fgets(num, 10, f)));
        s = s + val;

        if (num[0] == '\n')
        {
            if (s > sM)
            {
                sM = s;
            }
            sM3[i] = s;
            i++;
            s = 0;
        }
    }

    fclose(f);

    printf("Massimo = %d", sM);

    // bubblesort
    int I = i, j, temp;
    for (i = 0; i < I; i++)
    {
        for (j = 0; j < I - 1; j++)
        {
            if (sM3[j] > sM3[j + 1])
            {
                temp = sM3[j];
                sM3[j] = sM3[j + 1];
                sM3[j + 1] = temp;
            }
        }
    }

    int r = sM3[I - 1] + sM3[I - 2] + sM3[I - 3];
    printf("\nSomma dei primi 3 = %d", r);

    return 0;
}