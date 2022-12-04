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

        // part1
        if (st1 >= st2 && end1 <= end2)
        {
            pairs++;
        }
        else if (st1 <= st2 && end1 >= end2)
        {
            pairs++;
        }
        // part2
        int p1 = num1[0], p2 = num2[0];
        int c1 = num1[99] - num1[0] + 1, c2 = num2[99] - num2[0] + 1;
        for (int i = 0; i < c1; i++)
        {
            num1[i] = p1++;
        }
        for (int i = 0; i < c2; i++)
        {
            num2[i] = p2++;
        }

        int k = 0, sh = 0;
        bool found = true;
        bool kek = true;
        int count = 0;
        if (c1 > c2)
        {
            while (found && k < c2)
            {
                if (num2[0] == num1[k])
                {
                    sh = k;
                    found = false;
                }
                else
                    k++;
            }

            for (int i = 0; i < c2 && kek; i++)
            {
                if (num2[i] == num1[i + sh])
                {
                    kek = false;
                    pairs++;
                }
            }
        }
        if (c1 < c2)
        {
            while (found)
            {
                if (num1[0] == num2[k])
                {
                    sh = k;
                    found = false;
                }
                else
                    k++;
            }

            for (int i = 0; i < c1 && kek; i++)
            {
                if (num1[i] == num2[i + sh])
                {
                    kek = false;
                    pairs++;
                }
            }
        }
    }

    fclose(f);

    printf("\npairs = %d", pairs);

    return 0;
}