#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f;
    f = fopen("input.txt", "r");
    char num[10];      // numero
    int s = 0, sM = 0; // somme parziali, somma massima

    while (!feof(f))
    {
        int val = (atoi(fgets(num, 10, f)));
        s = s + val;

        if (num[0] == '\n')
        {
            if (s > sM)
                sM = s;
            s = 0;
        }
    }

    fclose(f);

    printf("Massimo = %d", sM);

    return 0;
}