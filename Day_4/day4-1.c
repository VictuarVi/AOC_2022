#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *f;
    f = fopen(argv[1], "r");
    int st1, st2, end1, end2;
    int pairs = 0;

    while (!feof(f))
    {
        fscanf(f, "%d-%d, %d-%d", &st1, &end1, &st2, &end2);
        
        //part1
        if (st1 >= st2 && end1 <= end2){
            pairs++;
        }
        else if (st1 <= st2 && end1 >= end2){
            pairs++;
        }
    }

    fclose(f);

    printf("\npairs = %d", pairs);

    return 0;
}