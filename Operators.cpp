/***********************************************************
 * Operators.cpp is an overloader for the Arc.cpp toString()
 *
 * Created by Bailee on 4/15/14.
 * Copyright (c) 2014 Bailee. All rights reserved.
 *
 * Used and modifed, with permission, by: 
 * Andrew Campbell, Rohit Gupta, Jacob Leidel, and Timothy Bradley.
 *
 * Date: 16 April 2014
 */

#include "Arc.h"
ostream& operator <<(ostream& outputStream,  const Arc& arc)
{
  outputStream << arc.toString();
  return outputStream;
}
