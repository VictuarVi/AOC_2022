#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    FILE *f;
    f = fopen(argv[1], "r");
    char b[70], p1[35], p2[35], p[1];
    int l;     // lunghezza della stringa
    int s = 0; // somma delle priorità

    int n = 0; // nnumero di cicli

    while (!feof(f))
    {
        fgets(b, 70, f);
        getc(f);

        l = strlen(b);
        // printf ("l = %d", l);

        for (int i = 0; i < l / 2; i++)
        {
            p1[i] = b[i];
            p2[i] = b[i + l / 2];
        }

        // printf ("\nCiclo %d | ", ++n);
        // for (int i = 0; i < l / 2; i++)
        // {
        //     printf ("%c", p1[i]);
        // }
        // printf ("----");
        // for (int i = 0; i < l / 2; i++)
        // {
        //     printf ("%c", p2[i]);
        // }

        bool flag = true;
        for (int j = 0; j < l / 2 && flag; j++)
        {
            for (int k = 0; k < l / 2 && flag; k++)
            {
                if (p1[j] == p2[k])
                {
                    p[0] = p2[k];
                    flag = false;
                }
            }
        }

        int v;
        // printf (" | p = %c", p[0]);
        // if (p[0] >= 'a' && p[0] <= 'z'){
        //     v = p[0]-96;
        //     printf (" => %d", v);
        //     s = s + v;
        // }
        // else {
        //     v = tolower(p[0]);
        //     v = p[0]-38;
        //     printf (" => %d", v);
        //     s = s + v;
        // }

        if (p[0] >= 'a' && p[0] <= 'z')
        {
            v = p[0] - 96;
            s = s + v;
        }
        else
        {
            v = p[0] - 38;
            s = s + v;
        }
    }

    fclose(f);

    printf("\ns = %d\n", s);
    // 14582 è troppo alta
    // 7875 è troppo alta
    // 7872 = soluzione

    return 0;
}