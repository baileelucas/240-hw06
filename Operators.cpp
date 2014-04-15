//
//  Operators.cpp
//  Homework 6
//
//  Created by Bailee on 4/15/14.
//  Copyright (c) 2014 Bailee. All rights reserved.
//

#include "Arc.h"
ostream& operator <<(ostream& outputStream, const Arc& arc)
{
  outputStream << arc.toString();
  return outputStream;
}
