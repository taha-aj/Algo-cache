
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // pour strchr et strlen
#include <stdbool.h>

#define SUBSTITUTION_COST	1

/** \def SUBSTITUTION_UNKNOWN_COST
 *  \brief Cost of substitution of an unknown base (N) by another one (canonical or unknown)
 */
#define SUBSTITUTION_UNKNOWN_COST	1  /* Cost for sustitition of an Unknown bas N by another on -known or unkown- */ 

/** \def INSERTION_COST
 *  \brief Cost of insertion of a canonical base 
 */
#define INSERTION_COST		2
#define min(a, b) ((a) < (b) ? (a) : (b))
#define INT_MAX 100000


int edit_distance_cache_oblivious(char *X, char *Y, int M, int N,int seuil);
