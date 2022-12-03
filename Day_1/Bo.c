#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

int main(){
    FILE *f;
    f = fopen("prova.txt", "r");

    int n = 1;
    int val=0, st =0, s =0;
    char cal[6];

    
    do {   
        printf ("Ciclo %d | ", n++);
        
        //val = (atoi(fgets(cal, 5, f)));
        val = (getline (cal, sizeof(char), f));
        
        printf ("%d ", st);

        st = st + val;

        printf ("+ %d \n", val);
    } while (EOF != getc(f));

    printf ("\nSomma = %d", st);
}