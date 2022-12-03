#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *f;
    f = fopen(argv[1], "r");
    char p[4];
    int s = 0, st = 0;

    int n = 0;

    while (!feof(f))
    {
        fgets(p, 4, f);
        getc(f);

        if (0 == strcmp(p, "A X"))
            s += 2;
        if (0 == strcmp(p, "A Y"))
            s += 8;
        if (0 == strcmp(p, "A Z"))
            s += 3;
        if (0 == strcmp(p, "B X"))
            s += 1;
        if (0 == strcmp(p, "B Y"))
            s += 4;
        if (0 == strcmp(p, "B Z"))
            s += 9;
        if (0 == strcmp(p, "C X"))
            s += 7;
        if (0 == strcmp(p, "C Y"))
            s += 2;
        if (0 == strcmp(p, "C Z"))
            s += 6;

        printf ("Ciclo %d | s = %d | p = '%s'\n", ++n, s, p);

        st = st + s;
        s = 0;
    }

    fclose(f);

    printf("st = %d\n", st);
    printf("per %d linee", n);
}