/*********************************************************/
/* Programmer: Jim Canning                               */
/*                                                       */
/* Program: This is a test driver for the queue module.  */
/*                                                       */
/* You need to fill in some of the code here.            */
/*                                                       */
/*********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "globals.h"
#include "list.h"

status printnum( generic_ptr n ) {

  int *p = (int*)n;

  printf( "%d\n", *p ) ;

  return OK ;

}

status addnumber( queue *q, int n ) {

  int *p ;

  p = ( int * ) malloc ( sizeof( int ) ) ;

  *p = n ;

  qadd( q, (generic_ptr) p ) ;

  return OK ;

}

status removenumber( queue *q, int *n ) {

  int *temp ;

  temp = ( int * ) malloc ( sizeof( int )  ) ;

  qremove( q, (generic_ptr) temp ) ;

  *n = *temp ;

  return OK ;

}

int main( int argc, char *argv[] ) {

  int n, option ;
  queue q ;

  init_queue( &q ) ;

  while( 1 ) {

    printf("Add to queue (1) : \n") ;
    printf("Remove from queue (2) : \n") ;
    printf("Done: (3) \n") ;

    scanf("%d", &option ) ;

    if ( option == 1 ) {

      printf("\nWhat number do you want to add to the queue? ") ;
      scanf(" %d", &n ) ;
      addnumber( &q, n ) ;

    }

    if ( option == 2 ) {

      removenumber( &q, &n ) ;
      printf( "\nThe number %d was removed from the queue.\n ", n ) ;

    }

    if ( option == 3 ) break ;

    printf("\n\nThe queue has the following values: " ) ;
    qprint( &q, printnum ) ;
    printf("\n");

  }

  return 0 ;

}
