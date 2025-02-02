/*************************************************/
/*  Eric Lima                                    */
/*                                               */
/*  Project 3                                    */
/*                                               */
/*  April 27, 2010                               */
/*************************************************/

#include <iostream>
#include <string>
#include "tree.h"
#include "treeADT.h"
#include "treeIFC.h"

using namespace std ;

Tree::Tree( int x, int y ) { // Two parameters are taken to choose either ADT or IFC

  if ( y <= 0 ) y = 10 ;

  if ( x == 0 )
    treeObject_ = new treeADT( y ) ;

  if ( x != 0 )
    treeObject_ = new treeIFC( y ) ;

}

Tree::Tree( int x ) { // Does same as previous constructor except one parameter for this constructor.

  if( x == 0 )
    treeObject_ = new treeADT( 10 ) ;

  if ( x != 0 )
    treeObject_ = new treeIFC( 10 ) ;
}


Tree::Tree() {  // This is the default constructor and it takes cases for no input.

  treeObject_ = NULL ;
}

Tree::~Tree() {

  delete treeObject_ ;
}

int Tree::numberofnodes() {

  return nodes_ ;
}

int leaves() {

  return 0 ;
}

void Tree::dfs() {

  return treeObject_->dfs() ;

}

Node& Tree::getRoot () {

  if ( treeObject_ == NULL ) {

    cout << "Empty Tree." << endl ;

    return treeObject_->getRoot() ;
  }

  else

    return treeObject_->getRoot() ;
}







