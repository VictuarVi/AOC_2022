#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(){
    FILE *f;
    f = fopen("input.txt", "r");
    char cal[5];
    int c;
    int sl=0, st=0, stMax;
    int n=1; //numero elfo
    char capo;
    int i;
    int max;
    int val;

    int elf[1];

    stMax = 0;
    max = 0;

    do{   
        if (feof(f)) break;
        
        val = (atoi(fgets(cal, 5, f)));

        if (val != 0){
            st = st + val;
        }

        elf[0] = st;
        
        if (val == 0)
        {
            if (st > stMax) stMax = st;
            //printf ("Elfo N %d = %d\n", ++n, stMax);
            st = 0;
        }
    } while(1);

    fclose(f);

    printf ("Elfo n 1 = %d", elf [0]);

    printf ("Calorie top = %d", stMax);
    
}