#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int main(int argc, char *argv[])
{
    FILE *f;
    f = fopen(argv[1], "r");
    int st1, st2, end1, end2;
    int num1[MAX], num2[MAX];
    int pairs = 0;

    while (!feof(f))
    {
        fscanf(f, "%d-%d, %d-%d", &st1, &end1, &st2, &end2);

        if (end1 == st2 || end1 == end2)
        {
            pairs++;
        }
        else if (end2 == st1 || end2 == end1)
        {
            pairs++;
        }

        if (end1 < end2 && end1 > st2) pairs ++;
        if (end2 < end1 && end2 > st1) pairs ++;
    }

    fclose(f);

    printf("\npairs = %d", pairs);

    return 0;
}