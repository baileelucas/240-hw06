/****************************************************************
 * Header file for Homework 6, the union-find algorithm.
 *
 * Author/copyright:  Duncan Buell
 * 
 * Used and modifed, with permission, by: 
 * Alison Bailee Lucas, Andrew Campbell, Rohit Gupta,
 * Jacob Leidel, and Timothy Bradley
 *
 * Date: 16 April 2014
 *
 **/
#ifndef UNIONFIND_H
#define UNIONFIND_H

#include <map>
#include <vector>

#include "../../Utilities/Utils.h"
#include "../../Utilities/Scanner.h"

#include "Arc.h"

class UnionFind
{
public:
  UnionFind();
  virtual ~UnionFind();
  
  void addLink(int a, int b);
  Arc find(int thatX);
  Arc find(int thatX, vector<Arc>& ArcPath);
  string toString();
  
private:
  map<int, Arc> Arcs;
  
  string printCycle(int xx, int yy);
  string toStringPath(vector<Arc> path, Arc last);
};

#endif // UNIONFIND_H
