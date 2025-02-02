/***********************************************/
/* Programmer: Eric Joesph Lima                */
/*                                             */
/* Program 25: Digit Sum                       */
/*                                             */
/* Approximate completion time: 25 minutes     */
/***********************************************/

#include <stdio.h>

int digitsum( int x ){
  
  int digit, sum = 0 ;
  
  while( x > 0 ) {
    
    digit = x % 10 ;
    
    x = x / 10 ;
    
    sum = sum + digit ;
    
  }
  
  return sum ;
  
}

int main( int argc, char *argv[] ) {
  
  
  FILE *fin ;
  int x     ;
  fin = fopen( argv[1] , "r" ) ;
  
  
  while( fscanf( fin , "%d" , &x ) != EOF ) {
    
    printf( "%d\n" , digitsum( x ) ) ;
    
  }
  
  fclose( fin ) ;

  return 0 ;
  
}
