#include <stdio.h>
#include <stdlib.h>

int main(int argv, char argc[])
{
    if (argv != 2)
    {
        printf("Errore nel numero di parametri.");
        exit(-1);
    }

    FILE *fp;
    fp = fopen("argc[]", "r");
    if (fp == NULL)
    {
        printf("Errore nell'apertura del file");
        exit(1);
    }

    char com[4];
    int num = 0, sum = 0, cycle = 0;
    int sig = 0;

    while (!feof(fp))
    {
        fscanf(fp, "%s %d\n", &com, &num);
        sum += num;

        if (com == 'noop') cycle += 1;
        if (com == 'addx') cycle += 2;

        if (cycle == 20 || cycle == 60 || cycle == 100 || cycle == 120 || cycle == 180 || cycle == 220)
        {
            sig = cycle * sum;
            sum = 0;
        }
    }

    fclose(fp);

    printf("signal strenght = %d\n", sig);

    return 0;
}