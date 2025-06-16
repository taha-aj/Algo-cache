#include "Distance_iterative.h"
#include "characters_to_base.h"

#define min(a, b) ((a) < (b) ? (a) : (b))
#define INT_MAX 100000

int edit_distance(char *X, char *Y, int M, int N) {
    _init_base_match();
    int *tab_M = malloc((M + 1) * sizeof(int));
    int *tab_N = malloc((N + 1) * sizeof(int));

    tab_M[M] = 0;
    for (int i = M-1; i >= 0; i--) {
        tab_M[i] = (isBase(X[i]) ? INSERTION_COST : 0) + tab_M[i + 1];
    }

    tab_N[N] = 0;
    for (int j = N-1; j >= 0; j--) {
        tab_N[j] = (isBase(Y[j]) ? INSERTION_COST : 0) + tab_N[j + 1];
    }


    for (int j = N-1; j >= 0; j--) {

        int phi_i_plus1_j_plus1 = tab_M[M];  // Initialisation correcte de phi_i_plus1_j_plus1
        tab_M[M] = tab_N[j];

        for (int i = M - 1; i >= 0; i--) {
            int option2 = INT_MAX;
            int option3 = INT_MAX;

            if (!isBase(X[i])) {
                option2 = tab_M[i + 1];
            }
            if (!isBase(Y[j])) {
                option3 = tab_M[i];
            }

            int phi_ij;
            if (isBase(X[i]) && isBase(Y[j])) {
                int min1 = min((isUnknownBase(X[i]) || isUnknownBase(Y[j])) ? SUBSTITUTION_UNKNOWN_COST :(isSameBase(X[i], Y[j]) ? 0 : SUBSTITUTION_COST) + phi_i_plus1_j_plus1, 2 + tab_M[i + 1]);
                int min2 = min(min1, 2 + tab_M[i]);
                phi_ij = min(option2, min(option3, min2));
            } else {
                phi_ij = min(option2, option3);
            }

            int temp = tab_M[i];
            tab_M[i] = phi_ij;
            phi_i_plus1_j_plus1 = temp; 
        }


     }

    int result = tab_M[0];
    free(tab_M);
    free(tab_N);
    return result;
}



// int main() {
//     char X[] = "ActcagrAAttatataatttacacacaacTaaatacat";
//     char Y[] = "cgttatatttgatgatgatgatgtaagctacgT";

//     int M = strlen(X);
//     int N = strlen(Y);

//     int result = edit_distance(X, Y, M, N);
//     printf("La distance d'édition entre \"%s\" et \"%s\" est: %d\n", X, Y, result);

//     return 0;
// }