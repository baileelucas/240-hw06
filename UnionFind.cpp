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
  cout << "ADDLINK... "<< endl;
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
  
  cout << "smaller: " << smaller << endl;
  cout << "larger: " << larger << endl;
  
  Arc smallerArc;
  //smallerArc.setX(smaller);
  //smallerArc.setY(larger);
  Arcs[smaller] = smallerArc;
  //smallerArc = Arcs[smaller];
  
  //Arc whichArc = Arcs[smaller];

  
  
  if(smallerArc.getX() == DUMMYX)
  {
    Arcs[smaller].setX(smaller);
    Arcs[smaller].setY(smaller);
    cout << "smallerArc: " << smallerArc.toString() << endl;
    cout << "Arcs[smaller]: " << Arcs[smaller].toString() << endl;
  }
  
  Arc largerArc;
  Arcs[larger] = largerArc;
  //Arc someArc = Arcs[larger];
  
  if(largerArc.getX() == DUMMYX)
  {
    Arcs[larger].setX(larger);
    Arcs[larger].setY(larger);
    cout << "largerArc: " << largerArc.toString() << endl;
    cout << "Arcs[larger]: " << Arcs[larger].toString() << endl;
  }
  
  //find roots
  rootOfSmaller = this->find(smaller);
  rootOfLarger = this->find(larger);
    cout << "rootOfSmaller: " << rootOfSmaller.toString() << endl;
      cout << "rootOflarger: " << rootOfLarger.toString() << endl;
  
  //cycle found so print cycle
  if(rootOfSmaller.equals(rootOfLarger))
  {
    Arc tempArc;
    tempArc.setX(larger);
    tempArc.setY(smaller);
        cout << "tempArc: " << tempArc.toString() << endl;
    Utils::logStream << tempArc.toString() << endl;
    Utils::logStream << this->printCycle(smaller, larger) << endl;
    Utils::logStream.flush();
  }
  //creates path between two Arcs
  else
  {
    Arc tempArc;
    tempArc.setX(larger);
    tempArc.setY(smaller);
    cout << "tempArc: " << tempArc.toString() << endl;
    Utils::logStream << tempArc.toString() << endl;
    Utils::logStream.flush();
    Arcs[larger].setY(smaller);
  }
  
  Utils::logStream << TAG << endl;
  Utils::logStream << this->toString();
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
  if(root.getX() != root.getY())
  {
    while(root.getX() != root.getY())
    {
      root = Arcs[root.getY()];
      ArcPath.push_back(root);
    }
  }
  
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
  vector<Arc>::iterator itSmaller = pathSmaller.end();
  vector<Arc>::iterator itLarger = pathLarger.end();
  --itSmaller;
  --itLarger;
  
  while( (*itSmaller).equals( (*itLarger) ))
  {
    --itSmaller;
    --itLarger;
  }
  
  Arc topOfSmaller = *itSmaller;
  Arc topOfLarger = *itLarger;
  Arc tempArc;
  
  tempArc.setX(larger);
  tempArc.setY(smaller);
  
  Utils::logStream << TAG << "PATH ONE " << tempArc.toString() << this->toStringPath(pathSmaller, *itSmaller) << endl;
  Utils::logStream.flush();
  Utils::logStream << TAG << "PATH TWO " << this->toStringPath(pathLarger, *itLarger) << endl << endl;
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
  for(vector<Arc>::iterator it = path.end(); it != path.begin(); --it)
  {
    s += (*it).toString();
    if( (*it).equals(last)) break;
  }
  return s;
}
