/***********************************************/
/* Programmer: Eric Joesph Lima                */
/*                                             */
/* Program 26: Bubble Sort                     */
/*                                             */
/* Approximate completion time: 43 minutes     */
/***********************************************/

#include <stdio.h>

void bubblesort( int A[], int size ) ;

int main( int argc, char *argv[] ) {

  int A[10], i ;
  FILE *fin    ;
  
  fin = fopen( argv[1], "r") ;
  
  for( i = 0 ; i < 10 ; i++ ) fscanf( fin, "%d", &A[i] ) ;
  
  bubblesort( A, 10) ;
  
  for( i = 0 ; i < 10 ; i++ ) printf("%d", A[i]) ;
  
  fclose( fin ) ;
  
  return 0 ;
  
}


void bubblesort( int A[], int size ) {
  
  int i, j, temp ;
  
  
  for( i = 0 ; i < size ; i++) { 
    for( j = 0 ; j < size - 1 - i ; j ++ ) 
      if( A[j] > A[j+1] ) {
	
	temp = A[j]     ;
	A[j] = A[j+1]   ; 
	A[j+1] = temp   ;
	
      }  
    
  }
  
}
