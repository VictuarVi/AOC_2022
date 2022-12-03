// Idea:
// 1 - Lunghezza della stringa
// 2 - Dividerla per metà
// 3 - Controllare quali caratteri si ripetono (case sensitive)
// 4 - Salvare quel dato
// 5 - Convertire per priorità
// 6 - Salvare dato
// 7 - Stampare somma di tutte le priorità

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

enum alp {a, b, c, d, e, f, g, h, i, j, k, l, m , n, o, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, I, J, K, L, M , N, O, P, Q, R, S, T, U, V, W, X, Y, Z};

enum alp val(enum alp P){
    return P;
}

int main(int argc, char *argv[])
{
    FILE *f;
    f = fopen(argv[1], "r");
    char b[70], p1[35], p2[35], p[1];
    int l;
    int s = 0; // somma delle priorità

    int n = 0;

    while (!feof(f))
    {
        fgets(b, 70, f);
        getc(f);

        l = strlen(b);
        // printf ("l = %d", l);

        for (int i = 0; i < l / 2; i++)
        {
            p1[i] = b[i];
            p2[i] = b[i + l/2];
        }
        
        printf ("\nCiclo %d | ", ++n);
        for (int i = 0; i < l / 2; i++)
        {
            printf ("%c", p1[i]);
        }
        printf ("----");
        for (int i = 0; i < l / 2; i++)
        {
            printf ("%c", p2[i]);
        }

        bool flag = true;
        for (int j = 0; j < l / 2 && flag; j++)
        {
            for (int k = 0; k < l / 2 && flag; k++)
            {
                if (p1[j] == p2[k])
                {
                    p[0] = p2[k];
                    flag = false;
                }
            }
        }
        
        printf (" | p = %c", p[0]);
        enum alp lett;
        lett = p[0];
        printf (" => %d", lett);

        s = s + val(p[0]);
    }

    fclose(f);

    printf("\n\ns = %d", s);
    //14582 è troppo alta
}