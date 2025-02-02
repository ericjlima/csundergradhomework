/***********************************************/
/* Programmer: Eric Lima                       */
/*                                             */
/* File: maingrep1  			       */
/*                                             */
/* Date: February 25, 2011  		       */
/***********************************************/

#include <stdio.h>
#include <fcntl.h>

int main( int argc, char *argv[] ){
  
  int fd, fd2, lcount = 0, pout[2], pin[2], nread;
  FILE* datafile;
  char buffer[512];

  if (  pipe( pout ) == -1 || pipe( pin ) == -1  ){
    perror(  "pipe"  );
    exit( 1 );
  }

  switch(  fork(  )  ){

    case -1:
      perror(  "fork"  );
      exit( 2 );
      break ;

    case 0:
      if( close( 0 ) == -1 ){
        perror(  "pipe"  ) ;
        exit( 1 ) ;
      }
      if( dup( pout[0] ) != 0 ){
        perror(  "dup"  ) ;
        exit( 1 ) ;
      }
      if( close( 1 ) == -1 ){
        perror(  "pipe"  ) ;
        exit( 1 ) ;
      }
      if(  dup( pin[1] ) != 1 ){
        perror(  "dup"  ) ;
        exit( 1 ) ;
      }
      if( close( pout[0] ) == -1 || close( pout[1] ) == -1 ||
	close( pin[0] ) == -1 || close( pin[1] ) == -1  ) {
        perror(  "close"  );
        exit( 1 );
      }
      execlp( "grep", "grep", "123", NULL );
      perror(  "execlp"  );
      exit( 1 );
  } 

  if(  close( pout[0] ) == -1 || close( pin[1] ) == -1 ){
    perror(  "close"  );
    exit(  1  );
  }

  if( (  fd = open( "cs308a2_grep_data_1", O_RDONLY, 0 ) ) == -1 ){
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

  datafile = fopen( ".datafile", "w+" );
  fd2 = open( ".datafile", O_RDWR, 0 );

  while( ( nread = read( pin[0], buffer, sizeof( buffer ) ) ) != 0 ){

    if( nread == -1 ){
      perror(  "read"  );
      exit( 1 );
    }

    if( write( fd2, buffer, nread ) == -1 ){

      perror(  "write"  );

      exit( 1 );

    }

  }

  while(  fgets(  buffer, 200, datafile  ) != NULL  ){
    lcount++;
  }

  printf( "\n\n\nThe lines %d were matched correctly.\n\n\n", lcount );

  close(  pin[0]  );
  close(  datafile  );

  return 0;

}
