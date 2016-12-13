/***************************************************************************************************************/
/* Using a sequential set implementation to store a set of words (dynamic arrays).                             */ 
/***************************************************************************************************************/

#include <stdio.h>
#include "set.h"
#include "globals.h"
#include "ctype.h"
#include <stdlib.h>
#include <string.h>

#define n 100

extern status write_word( generic_ptr word ) {

  printf("%s", (char *) word ) ;
  printf("\n") ;
  return OK ;

}

char *getword ( FILE *fin ) {

  int c ;
  int i ;
  char *s ;
  char temp[100] ;
  int state = 1 ;

  for ( i = 0 ; i < 100 ; i++ ) temp[i] = '\0' ;

  i = 0 ;

  while ( ( c = getc( fin ) ) != EOF  ) {

    c = toupper( c ) ; 
    if ( ( state == 1 ) && ( ( c < 65 ) || ( c > 91  ) ) ) { state = 1 ;  continue ; }
    if ( ( state == 1 ) && ( ( 65 <= c) && (c <= 90  ) ) ) { state = 2 ; temp[i] = c ; i++ ; continue ; }
    if ( ( state == 2 ) && ( ( 65 <= c) && (c <= 90  ) ) ) { state = 2 ; temp[i] = c ; i++ ; continue ; }
    if ( ( state == 2 ) && ( ( c < 65 ) || ( c > 91  ) ) ) break ;

  }

  s = (char *) malloc( strlen(temp) * sizeof(char) + 1) ;
  strcpy( s , temp ) ;

  return s ;
}

int compare( generic_ptr word1, generic_ptr word2 ) {

  return strcmp( (char *) word1, (char *) word2 )  ;

}

int main( int argc, char *argv[] ) {

  set setofwords ;
  FILE *fin ;
  char *word ;
  fin =  fopen(argv[1] , "r" ) ;

  init_set( &setofwords , n ) ; 

  while ( strlen( word = getword( fin ) ) != 0 ) set_insert( &setofwords, (generic_ptr) word, compare ) ;
  set_write( &setofwords, write_word ) ;

  
  printf("\n\nPlease enter a word using all capital letters: :  ") ; 

  while ( strlen( word = getword( stdin ) ) != 0 ) {
 
    if ( set_member( &setofwords, (generic_ptr) word, compare ) == TRUE ) printf("The word %s is in the file.\n", word ) ;
    else printf("The word %s is not in the file. \n", word ) ;  
    free( word ) ;

    printf("Another word? (hit CONTROL-D to exit): ") ;
  }

  set_write( &setofwords, write_word ) ;
  
  rewind( stdin ) ;
  printf("\n\nWhat word would you like to have deleted? ") ;
  
  word = getword( stdin ) ;
  set_delete( &setofwords, (generic_ptr) word, compare ) ;
  printf("The set is words is: \n");  set_write( &setofwords, write_word) ;

  printf("\n\n") ;

  fclose( fin ) ;

  return 0 ;

}
