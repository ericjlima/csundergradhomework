
/***********************************************/
/* Programmer: Eric Joesph Lima                */
/*                                             */
/* Program 43: Malloc up Space for One Integer */
/*                                             */
/* Approximate completion time:  43 minutes    */
/***********************************************/

#include <stdio.h>
#include <stdlib.h>

int main( int argc, char *argv[] ) {

  int *p ;

  p = (int *)malloc(sizeof(int));

  *p = 6 ;

  printf( "%d\n" , *p ) ;

  return 0 ;

}
