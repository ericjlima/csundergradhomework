/*******************************************************************/
/* Programmer: Eric J Lima                                         */
/*                                                                 */
/* Approximate completion time: 2 hours 52 minutes                 */
/*                                                                 */
/* main to test the  bit vector representation of sets             */
/*******************************************************************/

#include <stdio.h>
#include "bitvector.h"

void load_set( FILE *fin , set *p_S ) ;
void print_set( set *p_S ) ;

int main ( int argc , char *argv[] ) {

  int element ;
  set A ; set B ; set C ; set D ; set E ;
  FILE *fin1 ;
  FILE *fin2 ;

  fin1 = fopen( argv[1], "r" ) ;
  fin2 = fopen( argv[2], "r" ) ;

  init_set( &A, 1000 ) ;  init_set( &B, 1000 ) ; 
  init_set( &C, 1000 ) ;  init_set( &D, 1000 ) ;
  init_set( &E, 1000 ) ;

  load_set( fin1, &A ) ; load_set( fin2, &B ) ;
  printf("\nSet A: ") ; print_set( &A ) ;   
  printf("\nSet B: ") ; print_set( &B ) ;

  printf("\nWhat element would you like to delete from set A? " ) ;
  scanf("%d", &element ) ;
  set_delete( &A, element ) ;
  printf("\nSet A: ");  print_set( &A ) ;

  printf( "\n\nWhat element would you like to add to set B? " ) ;
  scanf( "%d", &element ) ;
  set_insert( &B, element ) ;
  printf( "\nSet B: " ) ;  print_set( &B ) ;

  set_union( &A, &B, &C ) ;
  printf( "\n\nUnion of A and B: ") ; print_set( &C ) ;

  set_intersection( &A, &B, &D ) ;
  printf( "\n\nIntersection of A and B: ") ;  print_set( &D ) ;

  set_difference( &A, &B, &E ) ;
  printf( "\n\nDifference of A and B (A - B) ; ") ;  print_set( &E ) ;

  printf( "\n\n" ) ;

  fclose( fin1 ) ;
  fclose( fin2 ) ;

  return 0 ;

}

void load_set( FILE *fin, set *p_S) {
  
  int element ;
  
  while ( fscanf( fin, "%d", &element ) != EOF ) set_insert( p_S, element ) ; 
  
}

void print_set( set *p_S ) {
  
  int i ;
  
  for ( i = 0 ; i < p_S -> setsize ; i++ ) if (  set_member( p_S , i ) ) printf(" %d ", i ) ; 
  
}
