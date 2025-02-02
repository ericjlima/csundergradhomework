/***********************************************/
/* Programmer: Eric Lima                       */
/*                                             */
/* File: maingrep2     			       */
/*                                             */
/* Date: February 25, 2011  		       */
/***********************************************/

#include <stdio.h>
#include <fcntl.h>

int main( int argc, char *argv[] ){
  
  int pout[2], pin[2], fd, nread;
  char buffer[512];

  if (  pipe( pout ) == -1 || pipe( pin ) == -1  ){
    perror(  "pipe"  );
    exit( 1 );
  }

  switch( fork(  ) ){

    case -1:
      perror(  "fork"  );
      exit( 2 );
      break;

    case 0:
      if( close( 0 ) == -1 ){
        perror(  "pipe"  );
        exit( 1 );
      }
      if( dup( pout[0] ) != 0 ){
        perror(  "dup"  );
        exit( 1 );
      }
      if( close( 1 ) == -1 ){
        perror(  "pipe"  );
        exit( 1 );
      }
      if(  dup( pin[1] ) != 1 ){
        perror(  "dup"  );
        exit( 1 );
      }
      if( close( pout[0] ) == -1 || close( pout[1] ) == -1 ||
	close( pin[0] ) == -1 || close( pin[1] ) == -1  ) {
        perror( "close" );
        exit( 1 );
      }
      execlp( "grep", "grep", "123", NULL );
      perror( "execlp" );
      exit( 1 );
  } 

  if(  close( pout[0] ) == -1 || close( pin[1] ) == -1 ){
    perror(  "close"  );
    exit(  1  );
  }

  if( (  fd = open( "cs308a2_grep_data_2", O_RDONLY, 0 ) ) == -1 ){
    perror(  "open"  );
    exit( 1 );
  }

  while( (  nread = read( fd, buffer, sizeof( buffer ) ) ) != 0 ){

    if(  nread == -1 ){
      perror(  "read"  );
      exit( 1 );
    }

    if( write( pout[1], buffer, nread ) == -1 ){
      perror(  "write"  );
      exit( 1 );
    }
  }
  
  if( close( fd ) == -1 || close(  pout[1] ) == -1 ){
    perror(  "close"  );
    exit( 1 );
  }

  while( ( nread = read( pin[0], buffer, sizeof( buffer ) ) ) != 0 ){

    if( nread == -1 ){
      perror(  "read"  );
      exit( 1 );
    }

    if( write( 1, buffer, nread ) == -1 ){
      perror(  "write"  );
      exit( 1 );
    }
  }

  close( pin[0] );

  return 0;
}
