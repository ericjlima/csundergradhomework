/***********************************************/
/* Programmer: Eric Joesph Lima                */
/*                                             */
/* Program 6: The fscanf Function              */
/*                                             */
/* Approximate completion time: 30 minutes     */
/***********************************************/

#include <stdio.h>

int main( int argc, char *argv[] ) {

  FILE *fin ;

  int num ;

  fin = fopen( "testdata6" , "r") ;

  fscanf( fin , "%d" , &num ) ;

  printf( "\n\n%d \n \n \n", num ) ;

  fclose( fin ) ;


  return 0 ;

}
