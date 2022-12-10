#include <stdio.h>
#include <stdlib.h>

int main(int argv, char *argc[])
{
    if (argv != 2)
    {
        printf("Errore nel numero di parametri.");
        exit(-1);
    }

    FILE *fp;
    fp = fopen(argc[1], "r");
    if (fp == NULL)
    {
        printf("Errore nell'apertura del file");
        exit(1);
    }

    char com[5];
    int num = 0, x = 1, cycle = 0;
    int sig = 1;

    while (!feof(fp))
    {
        fscanf(fp, "%s %d", &com, &num);
        x += num;

        if (com == 'noop') cycle += 1;
        if (com == 'addx') cycle += 2;

        if (cycle == 20 || cycle == 60 || cycle == 100 || cycle == 120 || cycle == 180 || cycle == 220)
        {
            sig = cycle * x;
        }
    }

    fclose(fp);

    printf("signal strength = %d\n", sig);

    return 0;
}