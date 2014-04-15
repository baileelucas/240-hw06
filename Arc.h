/****************************************************************
 * Header file for Homework 6, the union-find algorithm.
 *
 * Author/copyright:  Duncan Buell
 * Used with permission by: Alison Bailee Lucas.
 * Date: 12 April 2014
 *
 **/
#ifndef X_H
#define X_H

#include "../../Utilities/Utils.h"
#include "../../Utilities/Scanner.h"

#define DUMMYX -1
#define DUMMYY -2

class Arc
{
public:
  Arc();
  virtual ~Arc();
  
  int getX();
  int getY();
  void setX(int value);
  void setY(int value);
  
  bool equals(Arc that);
  bool z();
  
  string toString();
  
private:
  int x;
  int y;
  
};

#endif // X_H
