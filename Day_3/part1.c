#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    FILE *f;
    f = fopen(argv[1], "r");
    char b[70], p1[35], p2[35], p; // trasformato p in char, non più array[1] di char
    int l;                         // lunghezza della stringa
    int s = 0;                     // somma delle priorità

    while (!feof(f))
    {
        fgets(b, 70, f);

        // Come ho scoperto l'odio di Vittorio per C:
        //      char ch = getc(f);
        //      printf("%c\n", ch);

        l = strlen(b);
        if (l % 2 == 1)
            l--;

        for (int i = 0; i < l / 2; i++)
        {
            p1[i] = b[i];
            p2[i] = b[i + l / 2];
        }

        bool flag = true;
        for (int j = 0; j < l / 2 && flag; j++)
        {
            for (int k = 0; k < l / 2 && flag; k++)
            {
                if (p1[j] == p2[k])
                {
                    p = p2[k];
                    flag = false;
                }
            }
        }

        int v;

        if (p >= 'a' && p <= 'z')
        {
            v = p - 96;
        }
        else
        {
            v = p - 38;
        }
        s = s + v;
    }

    fclose(f);

    printf("\ns = %d\n", s);

    return 0;
}