/*************************************************/
/*  Eric Lima                                    */
/*                                               */
/*  Project 3                                    */
/*                                               */
/*  April 27, 2010                               */
/*************************************************/

#include <iostream>
#include "tree.h"

using namespace std ;

int main( int argc, char *argv[] ) {
  
  cout << "A tree with the following parameters is being made. ( 1, 7 )" << endl ;


  Tree Treea( 1, 7 ) ; // A tree with a size 7 list is created here.


  cout << "The dfs of the tree is " ;


  Treea.dfs() ;


  cout << "A tree with the following parameters is being made. ( 0 ) " << endl ;


  Tree Treeb( 0 ) ; // A tree with a size 10 array is created here.


  cout << "A size 10 array implemented tree has been made.  " << endl ;

  return 0 ;

}
