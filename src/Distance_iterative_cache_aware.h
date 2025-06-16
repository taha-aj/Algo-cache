#ifndef DISTANCE_ITERATIVE_CACHE_AWARE_H
#define DISTANCE_ITERATIVE_CACHE_AWARE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // pour strchr et strlen
#include <stdbool.h>



// Macro pour calculer le minimum de deux valeurs
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))



#define SUBSTITUTION_COST	1

/** \def SUBSTITUTION_UNKNOWN_COST
 *  \brief Cost of substitution of an unknown base (N) by another one (canonical or unknown)
 */
#define SUBSTITUTION_UNKNOWN_COST	1  /* Cost for sustitition of an Unknown bas N by another on -known or unkown- */ 

/** \def INSERTION_COST
 *  \brief Cost of insertion of a canonical base 
 */
#define INSERTION_COST		2

// Déclaration de la fonction principale pour le calcul de distance
int edit_distance_cache_aware(char *X, char *Y, int M, int N,int K_i,int K_j);

#endif // DISTANCE_ITERATIVE_H
