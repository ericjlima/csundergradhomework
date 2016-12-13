/*************************************************/
/*  Eric Lima                                    */
/*                                               */
/*  Project 3                                    */
/*                                               */
/*  April 27, 2010                               */
/*************************************************/

#ifndef _NODE
#define _NODE

#include <string>

using namespace std ;

class Node {

  friend class treeADT ;
  friend class treeIFC ;

 public:

  Node( int ) ;
  Node() ;
  ~Node() ;

  Node& next() ;
  Node& getLc() ;
  Node& insertLeft( int s ) ;
  Node& insertRight( int s ) ;

  void printlabel() ;

 protected:

  Node *lc ; //The left child
  Node *rs ; //The right sibling
  int Label ;

} ;

#endif
