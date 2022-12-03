// x = 1, Y = 2, Z = 3
// vinta = +6
// pari = lettera + lettera
// tot = somma di tutti i precedenti

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *f;
    f = fopen("input.txt", "r");
    char p[4];
    int s = 0, st = 0;

    int n = 0;
    while (!feof(f))
    {   
        fgets(p, 4, f);
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
        
        st = st + s;
        s = 0;
    }

    printf ("\nst = %d", st);

    fclose(f);
}