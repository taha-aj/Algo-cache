
#include "Distance_edition_cache_oblivious.h"
#include "characters_to_base.h"

#define min(a, b) ((a) < (b) ? (a) : (b))
#define INT_MAX 100000

void recursive(char* X,char* Y,int i_start, int i_end, int j_start, int j_end,  int* tab_M,int* tab_N, int M, int N,int seuil){

      if(i_end - i_start > seuil){
         
         int i_mid=(i_start+i_end)/2;

         recursive(X,Y,i_mid+1, i_end, j_start, j_end, tab_M,tab_N, M, N,seuil);
         recursive(X,Y,i_start, i_mid, j_start, j_end, tab_M,tab_N, M, N,seuil);

      }else if(j_end - j_start > seuil){

         int j_mid=(j_start+j_end)/2;

         recursive(X,Y,i_start, i_end, j_mid+1, j_end,  tab_M,tab_N, M, N,seuil);
         recursive(X,Y,i_start, i_end, j_start, j_mid, tab_M,tab_N, M, N,seuil);

      }else{

         
        int phi_i_plus1_j_plus1 =  tab_M[i_end+1];
        int phi_i_j_plus1 =  tab_M[i_end];

         for(int i = i_end; i >= i_start; i--){
            
            for(int j = j_end; j >= j_start; j--){
                  

               int phi_ij;

               if( !isBase(X[i])){
                  phi_ij = tab_N[j];
               }else if( !isBase(Y[j])){
                  phi_ij = phi_i_j_plus1;
               }else{
                  
                  phi_ij = min(2 + phi_i_j_plus1,min(2 + tab_N[j],(isUnknownBase(X[i]||Y[j]))?SUBSTITUTION_UNKNOWN_COST:(isSameBase(X[i], Y[j]) ? 0 : SUBSTITUTION_COST )+ phi_i_plus1_j_plus1));
               }

               if(j !=j_start){
                  phi_i_j_plus1 = phi_ij;
                  phi_i_plus1_j_plus1 = tab_N[j];

                  
               }else{
               
                  phi_i_plus1_j_plus1 = tab_M[i];
                  tab_M[i] = phi_ij;

                  if(i == i_end ){
                     tab_M[i+1] = tab_N[j];
                  }

                  if(i != 0){
                     phi_i_j_plus1 = tab_M[i-1];
                  } 
               } 
               tab_N[j] = phi_ij;

            }

        }

   }
}


//fonction principale   
int edit_distance_cache_oblivious(char* X,char* Y, int M ,int N,int seuil){

   _init_base_match();


   int* tab_N = malloc(sizeof(int)*(N+1));
   tab_N[N] = 0; 
   for (int j=N-1;j>=0;j--) {
        tab_N[j] = (isBase(Y[j]) ? INSERTION_COST : 0) + tab_N[j + 1];
   }

   int* tab_M = malloc(sizeof(int) * (M+1));
   tab_M[M]=0;
   for (int i = M - 1; i >= 0; i--) {
        tab_M[i] = (isBase(X[i]) ? INSERTION_COST : 0) + tab_M[i + 1];
   }

   recursive(X,Y,0, M-1, 0, N-1, tab_M,tab_N, M, N,seuil);

   int resultat = tab_M[0];
   free(tab_M);
   free(tab_N);
   
   return resultat;

}