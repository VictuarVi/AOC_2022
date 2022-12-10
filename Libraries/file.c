#include "file.h"
#include <stdio.h>
#include <stdlib.h>

FILE *file_control(int argv, char *argc[])
{
    if (argv != 2)
    {
        printf("Only 2 arguments allowed.");
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