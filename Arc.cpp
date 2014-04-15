/****************************************************************
 * Class for doing something not yet known yet.
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * Used with permission by: Alison Bailee Lucas.
 * Date: 12 April 2014
 *
 **/
#include "Arc.h"

static const string TAG = "ZORK: ";
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
 * 'getX' function.
 *
**/
int Arc::getX()
{
  return this->x;
}
/****************************************************************
 * 'getY' function.
 *
**/
int Arc::getY()
{
  return this->y;
}
/****************************************************************
 * 'setX' function.
 *
**/
void Arc::setX(int value)
{
  this->x = value;
}
/****************************************************************
 * 'setY' function.
 *
 **/
void Arc::setY(int value)
{
  this->y = value;
}
/****************************************************************
 * 'equals' function.
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
 * 'z' function. Checks to see if Arc points to self?
 *
 * Returns:
 *   this->x = this->y
 **/

bool Arc::z()
{
  return (this->x = this->y);
}
/****************************************************************
 * 'toString' function.
 *
 * Parameters:
 *   that -- an instance of Arc
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
