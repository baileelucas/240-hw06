/****************************************************************
 * Header file for Homework 6, the union-find algorithm.
 *
 * Author/copyright:  Duncan Buell
 * Used with permission by: Alison Bailee Lucas.
 * Date: 12 April 2014
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
  void dumpTrees();
  Arc find(int thatX);
  Arc find(int thatX, vector<Arc>& ArcPath);
  
  string toString();
  
private:
  vector<std::pair<int, int> > links;
  map<int, Arc> Arcs;
  
  string printCycle(int xx, int yy);
  string toStringPath(vector<Arc> path, Arc last);
};

#endif // UNIONFIND_H
