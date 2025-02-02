/*****************************************************************************/
/* Programmer: Eric Joesph Lima                                              */
/*                                                                           */
/* Program 58: Products of Unequal Primes                                    */
/*                                                                           */
/* Approximate completion time:  52 minutes                                  */
/*****************************************************************************/

#include <stdio.h>

int IsPrime( int x ) ;

int main( int argc, char *argv[] ) {
  
  int x, y, prod ;
  
  for( x = 0 ; x < 20 ; x++ ) {
    
    for( y = 20 ; y < 250 ; y++ ) {
      
      if( ( IsPrime( y ) == 1 ) && ( IsPrime( x ) == 1 ) && ( x != y ) ) {
	
	prod = x * y ;
	
	if( prod < 500 && prod > 300 ) printf( "%d = %d * %d\n", prod, x, y ) ;
	
      }
      
    }
    
  }
  
  return 0 ;
  
}

int IsPrime( int x ) {
  
  int i, count = 0 ;
  
  for( i = 1 ; i <= x ; i++ ) if( ( x % i ) == 0 ) count++ ;
  
  return ( count == 2 ) ;
  
}
