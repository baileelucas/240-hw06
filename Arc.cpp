/****************************************************************
 * Class to handle an instance of an arc. Will contain the 
 * accesseros, mutators, data, and methods needed to use
 * and manipulate a single arc.
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * 
 * Used and modifed, with permission, by: 
 * Alison Bailee Lucas, Andrew Campbell, Rohit Gupta,
 * Jacob Leidel, and Timothy Bradley
 *
 * Date: 16 April 2014
 *
 **/
#include "Arc.h"

static const string TAG = "Arc: ";
/****************************************************************
 * Constructor.
 *
**/
Arc::Arc()
{
  this->x = DUMMYX;
  this->y = DUMMYY;
}
/****************************************************************
 * Destructor.
 *
**/
Arc::~Arc()
{
}
/****************************************************************
 * Accessors and Mutators.
 *
**/
/****************************************************************
 * Returns the X value of an arc. Arcs are referred to in the
 * form (X , Y)
 *
**/
int Arc::getX()
{
  return this->x;
}
/****************************************************************
 * Returns the Y  value of an arc. Arcs are referred to in the
 * form (X , Y)
 *
**/
int Arc::getY()
{
  return this->y;
}
/****************************************************************
 * Method to set the X value of an arc. 
 *
 */
void Arc::setX(int value)
{
  this->x = value;
}
/****************************************************************
 * Method to set the Y value of an arc. 
 *
 **/
void Arc::setY(int value)
{
  this->y = value;
}
/****************************************************************
 * Method to determine if two Arcs share the same Y cooridinate.
 * This would mean they are connected to the same root. 
 *
 * Parameters:
 *   that -- an instance of Arc
 *
 * Returns:
 *   bool
 **/
bool Arc::equals (Arc that)
{
  if(this->y == that.getY())
  {
    return true;
  }
  
  return false;
}

/****************************************************************
 * Normal 'toString' to represent the Data.
 *
 * Parameters:
 *   None
 *
 * Returns:
 *   s
 **/
string Arc::toString()
{
  string s = "";
  s += "(" + Utils::Format(this->getX(), 3) + " -> ";
  s += Utils::Format(this->getY(), 3) + ")";
  return s;
}
