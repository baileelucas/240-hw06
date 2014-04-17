/****************************************************************
 * Header file for the Arc class.
 *
 * Author/copyright:  Duncan Buell
 *
 * Author/copyright:  Duncan Buell
 * Used and modifed, with permission, by: 
 * Alison Bailee Lucas, Andrew Campbell, Rohit Gupta,
 * Jacob Leidel, and Timothy Bradley
 *
 * Date: 16 April 2014
 *
 **/
#ifndef Arc_H
#define Arc_H

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
    
  string toString();
  
private:
  int x;
  int y;
  
};

#endif // Arc_H
