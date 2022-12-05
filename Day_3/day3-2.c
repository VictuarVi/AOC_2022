#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int ascii(char p)
{
    int v;

    if (p >= 'a' && p <= 'z')
    {
        v = p - 96;
        return v;
    }
    else
    {
        v = p - 38;
        return v;
    }
}

int main(int argc, char *argv[])
{
    FILE *f;
    f = fopen(argv[1], "r");
    char p;
    int s = 0; // somma delle priorità

    int n = 0; // numero di cicli

    while (!feof(f))
    {
        char b[70], p1[70], p2[70], p3[70];

        fscanf(f, "%s\n", &p1);
        int l1 = strlen(p1);
        fscanf(f, "%s\n", &p2);
        int l2 = strlen(p2);
        fscanf(f, "%s\n", &p3);
        int l3 = strlen(p3);

        bool flag = true;
        for (int j = 0; j < l1 && flag; j++)
        {
            for (int k = 0; k < l2 && flag; k++)
            {
                if (p1[j] == p2[k])
                {
                    for (int i = 0; i < l3 && flag; i++)
                    {
                        if (p1[j] == p3[i])
                        {
                            p = p2[k];
                            flag = false;
                        }
                    }
                }
            }
        }

        s = s + ascii(p);
    }

    fclose(f);

    printf("\ns = %d\n", s);

    return 0;
}