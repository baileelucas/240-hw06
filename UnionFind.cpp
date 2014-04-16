/****************************************************************
 * Class for finding unions in a graph.
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * Used with permission by: Alison Bailee Lucas.
 * Date: 12 April 2014
 *
 **/
#include "UnionFind.h"

static const string TAG = "UnionFind: ";

/****************************************************************
 * Constructor.
 **/
UnionFind::UnionFind()
{
}

/****************************************************************
 * Destructor.
 **/
UnionFind::~UnionFind()
{
}

/****************************************************************
 * General Functions.
 **/

/****************************************************************
 * 'addLink' function.
 * 
 * Parameters:
 *   a -- an integer
 *   b -- an integer
 *
 * Returns:
 *   none
 **/
void UnionFind::addLink(int a, int b)
{
  int larger;
  int smaller;
  
  Arc rootOfLarger;
  Arc rootOfSmaller;
  
  if(a <= b)
  {
    smaller = a;
    larger = b;
  }
  else
  {
    smaller = b;
    larger = a;
  }
  
  cout << "Add link (" << smaller  << "->" << larger << ")" << endl;
  
  if(Arcs[smaller].getX() == DUMMYX)
  {
    Arcs[smaller].setX(smaller);
    Arcs[smaller].setY(smaller);
  }
  
  if(Arcs[larger].getX() == DUMMYX)
  {
    Arcs[larger].setX(larger);
    Arcs[larger].setY(larger);
  }
  
  rootOfSmaller = this->find(smaller);
  rootOfLarger = this->find(larger);
  
  //cycle found so print cycle
  if(rootOfSmaller.equals(rootOfLarger))
  {
    cout << "Cycle found: " << endl;
    Arc tempArc;
    tempArc.setX(larger);
    tempArc.setY(smaller);
    Utils::logStream << tempArc.toString() << endl;
    cout  << this->printCycle(smaller, larger) << endl;
    Utils::logStream.flush();
  }
  //creates path between two Arcs
  else
  {
    Arc tempArc;
    tempArc.setX(larger);
    tempArc.setY(smaller);
    cout << tempArc.toString() << endl;
    Utils::logStream.flush();
    Arcs[larger] = tempArc;
    Arcs[larger].setY(smaller);
  }
  
  Utils::logStream << TAG << endl;
  cout << this->toString();
  Utils::logStream.flush();
}

/****************************************************************
 * 'find' function find the root of the tree in which the Arc 'lives'
 *
 * Parameters:
 *   zz -- an integer
 *
 * Returns:
 *   root
 **/
Arc UnionFind::find(int zz)
{
  Arc root;
  vector<Arc> ArcPath;
  root = this->find(zz, ArcPath);
  return root;
}
/****************************************************************
 * 'find' function.
 *
 * Parameters:
 *   zz -- an integer
 *   ArcPath -- a vector
 *
 * Returns:
 *   root
 **/
Arc UnionFind::find(int zz, vector<Arc>& ArcPath)
{
  Arc root;
  
  root = Arcs[zz];
  ArcPath.push_back(root);
 
  return root;
}
/****************************************************************
 * 'buildTrees' function
 *
 *
 * Returns:
 *   
 **/
//Arc UnionFind::buildTrees()
//{
// return "zork";
//}

/****************************************************************
 * 'printCycle' function.
 *
 * Parameters:
 *   which -- an integer
 *   whatever -- an integer
 *
 * Returns:
 *   s
 **/
string UnionFind::printCycle(int smaller, int larger)
{
  string s = "";
  Arc thisValue, rootOfSmaller;
  vector<Arc> pathSmaller, pathLarger;
  rootOfSmaller = this->find(smaller, pathSmaller);
  thisValue = this->find(larger, pathLarger);
  vector<Arc>::iterator itSmaller = pathSmaller.begin();
  vector<Arc>::iterator itLarger = pathLarger.begin();

  Arc tempArc;
  
  tempArc.setX(larger);
  tempArc.setY(smaller);
  
  cout << TAG << "PATH ONE " << tempArc.toString() << this->toStringPath(pathSmaller, *itSmaller) << endl;
  Utils::logStream.flush();
  cout << TAG << "PATH TWO " << this->toStringPath(pathLarger, *itLarger) << endl << endl;
  Utils::logStream.flush();
  return s;
}
/****************************************************************
 * 'toString' function.
 *
 * Returns:
 *   s
 **/
string UnionFind::toString()
{
  string s = "";
  map<int, Arc>::iterator it;
  
  for(it = this->Arcs.begin(); it != this->Arcs.end(); ++it)
  {
    vector<Arc> path;
    int usu = it->first;
    Arc Arc = this->find(usu, path);
    s += this->toStringPath(path, Arc) + "\n";
  }
  return s;
}
/****************************************************************
 * 'toStringZORK' function.
 *
 * Parameters:
 *   path -- a vector
 *   last -- an instance of Arc
 *
 * Returns:
 *   s
 **/
string UnionFind::toStringPath(vector<Arc> path, Arc last)
{
  string s = "";
  for(vector<Arc>::iterator it = path.begin(); it != path.end(); ++it)
  {
    s += (*it).toString();
    if( (*it).equals(last)) break;
  }
  return s;
}
