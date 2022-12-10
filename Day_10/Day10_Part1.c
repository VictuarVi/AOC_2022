#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *file_control(int argv, char *argc[])
{
    if (argv != 2)
    {
        printf("Only 2 parameters arguments allowed.");
        exit(-1);
    }

    FILE *fp;
    fp = fopen(argc[1], "r");
    if (fp == NULL)
    {
        printf("The file can't be read.");
        exit(-1);
    }

    return fp;
}

int main(int argv, char *argc[])
{
    FILE *fp = file_control(argv, argc);

    int x = 1, cycle = 1, k = 20;
    int sig = 0;

    while (!feof(fp))
    {
        char com[5];
        int num = 0;
        fscanf(fp, "%s %d", &com, &num);
        x += num;

        cycle++;
        if (!strcmp(com, "addx"))
            cycle++;

        if (cycle >= k)
        {
            sig = sig + k * x;
            k += 40;
        }
    }

    fclose(fp);

    printf("\nsignal strength = %d\n", sig);

    return 0;
}