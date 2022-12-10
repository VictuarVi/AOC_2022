#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(int argc, char argv[]){
    FILE *f;
    f = fopen(argv[1], "r");

    fclose(f);
}