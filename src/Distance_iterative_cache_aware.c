

#include "Distance_iterative_cache_aware.h"
#include "characters_to_base.h"
#define INT_MAX 100000

// Fonction principale pour calculer la distance d'édition
int edit_distance_cache_aware(char *X, char *Y, int M, int N, int KI, int KJ) {

    _init_base_match();
    int *tab_M = malloc((M + 1) * sizeof(int));
    int *tab_N = malloc((N + 1) * sizeof(int));


    tab_M[M] = 0;
    for (int i = M - 1; i >= 0; i--) {
        tab_M[i] = (isBase(X[i]) ? INSERTION_COST : 0) + tab_M[i + 1];
    }

    tab_N[N] = 0;
    for (int j = N - 1; j >= 0; j--) {
        tab_N[j] = (isBase(Y[j]) ? INSERTION_COST : 0) + tab_N[j + 1];
    }

//Remplissage par blocking avec des pas KI et KJ

int phi_i_plus1_j_plus1 = tab_M[M];
int avant;
// on fait des blocs avec des pas KI et KJ (bloc de taille KI*KJ)
    for (int J = N - 1; J >= 0; J -= KJ) {
        int j_min = (J - KJ + 1 >= 0) ? J - KJ + 1 : 0;
        for (int I = M - 1; I >= 0; I -= KI) {
            int i_min = (I - KI + 1 >= 0) ? I - KI + 1 : 0;
            for (int j = J; j >= j_min; j--) {

                phi_i_plus1_j_plus1 = (I==M-1) ? tab_M[M] : (j==J)? tab_N[J+1]: avant;;
                tab_M[M] = (I==M-1) ? tab_N[j] : tab_M[M];

                for (int i = I; i >= i_min; i--) {
                    int option2 = INT_MAX;
                    int option3 = INT_MAX;

                    if (!isBase(X[i])) {
                        option2 = (i == I && i != M - 1) ? tab_N[j] : tab_M[i + 1];
                    }
                    if (!isBase(Y[j])) {
                        option3 = tab_M[i];
                    }

                    int phi_ij;
                    if (isBase(X[i]) && isBase(Y[j])) {
                        int min1 = min(
                            (isUnknownBase(X[i] || isUnknownBase(Y[j])) ? SUBSTITUTION_UNKNOWN_COST : (isSameBase(X[i], Y[j]) ? 0 : SUBSTITUTION_COST)) + phi_i_plus1_j_plus1,
                            2 + ((i == I && i != M - 1) ? tab_N[j] : tab_M[i + 1])
                        );
                        int min2 = min(min1, 2 + tab_M[i]);
                        phi_ij = min(option2, min(option3, min2));
                    } else {
                        phi_ij = min(option2, option3);
                    }
                    int temp = tab_M[i];
                    tab_M[i] = phi_ij;
                    phi_i_plus1_j_plus1 = temp;  // on met à jour phi_i_plus1_j_plus1
                    if(i == i_min){
                        if(J == j) {
                            tab_N[J+1] = temp;
                        }
                        avant = tab_N[j];
                        tab_N[j] = tab_M[i];

                    }
                }

            }
        }
    }

    int result = tab_M[0];
    free(tab_M);
    free(tab_N);

    return result;
}