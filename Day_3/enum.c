#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

enum alp {a, b, c, d, e, f, g, h, i, j, k, l, m , n, o, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, I, J, K, L, M , N, O, P, Q, R, S, T, U, V, W, X, Y, Z};

enum alp val(enum alp P){
    return P+1;
}


int main(){
    char p[1];
    char k[] = "z";

    p[0] = k[0];
    enum alp lett = z;
    //enum up Lett = z;
    
    printf ("%d", val(p[0]));
}