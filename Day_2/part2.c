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
            s += 3;
        if (0 == strcmp(p, "A Y"))
            s += 4;
        if (0 == strcmp(p, "A Z"))
            s += 8;
        if (0 == strcmp(p, "B X"))
            s += 1;
        if (0 == strcmp(p, "B Y"))
            s += 5;
        if (0 == strcmp(p, "B Z"))
            s += 9;
        if (0 == strcmp(p, "C X"))
            s += 2;
        if (0 == strcmp(p, "C Y"))
            s += 6;
        if (0 == strcmp(p, "C Z"))
            s += 7;

        st = st + s;
        s = 0;
    }

    fclose(f);

    printf("\nst = %d\n", st);
}