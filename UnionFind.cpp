/****************************************************************
 * UnionFind.cpp takes in a set of arcs from an input file and
 * proceeds to build a "tree" of these arcs. For each new Arc 
 * a Union is performed to add it to the tree. If a cycle
 * found the program will recognize this, alert the user of the 
 * cycle, and discard the arc without adding it to the tree.
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * 
 * Used and modifed, with permission, by: 
 * Alison Bailee Lucas, Andrew Campbell, Rohit Gupta,
 * Jacob Leidel, and Timothy Bradley
 *
 * Date: 18 April 2014
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
//void UnionFind::addLink(int a, int b, ofstream& outStream){
//}
/****************************************************************
 * In addLink two numbers are passed in to represent the two nodes 
 * of an arc. First, we use an if/else to determine which value is
 * larger to make the process easier. Next we check to see if the 
 * value has been set to DUMMY value, meaning it has not been added
 * yet, and if so set it to it's own root. The following step uses
 * the find  function to find the root of each node. Finally, the two
 * roots are compared. If they are equal we have found a cycle and, 
 * the program will output that information. If they are not equal,
 * there is no cycle and the arc is added to the tree.   
 * 
 * Parameters:
 *   a -- an integer
 *   b -- an integer
 *
 * Returns:
 *   none
 **/
void UnionFind::addLink(int a, int b, ofstream& outStream)
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

  Utils::logStream << "\nCurrent link (   " << larger  
        << " ->   " << smaller << ")" << endl;
  Utils::logStream.flush();
  
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
  
  if(rootOfSmaller.equals(rootOfLarger))
  {
    Utils::logStream << "Cycle found: " << endl;
    Utils::logStream.flush();
    Arc tempArc;
    tempArc.setX(larger);
    tempArc.setY(smaller);
    outStream << TAG << "Found cycle for arc " << tempArc.toString ()<< endl;
    outStream  << this->printCycle(smaller, larger) << "\n\n";
    Utils::logStream.flush();
  }

  else
  { 
    Arc tempArc;
    tempArc.setX(larger);
    tempArc.setY(smaller);
    Utils::logStream << "No Cycles Add arc (  " 
         << larger << " ->   " << smaller << ")" << endl; 
    Utils::logStream.flush();
    Arcs[larger] = tempArc;
    Arcs[larger].setY(smaller);
  }
  
  Utils::logStream << this->toString() << "\n";
  Utils::logStream.flush();
}

/****************************************************************
 * find(int) takes in a integer and forwards that integer and an 
 * empty Vector of Arcs to the next find function. This us mainly 
 * used so that we dont have to worry about creating and passing 
 * along an empty vector at other points in the program. In the end
 * it will return the arc containing the root of the Node passed in.
 *
 * Parameters:
 *   node -- an integer
 *
 * Returns:
 *   root
 **/
Arc UnionFind::find(int node)
{
  Arc root;
  vector<Arc> ArcPath;
  root = this->find(node, ArcPath);
  return root;
}
/****************************************************************
 * This version of the find method is passed an integer and 
 * Vector<Arc> pointer. This method travels from the original node
 * that is passed, up the path, until it reaches the root node. The 
 * root points to itself so the arc containing the root will have the
 * same X and Y values.
 *
 * Parameters:
 *   node -- an integer
 *   ArcPath -- a vector
 *
 * Returns:
 *   root
 **/
Arc UnionFind::find(int node, vector<Arc>& ArcPath)
{
  Arc root;
  
  root = Arcs[node];
  ArcPath.push_back(root);
 
  if (root.getX() != root.getY())
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
 * This is basically a toString() that will print out the two 
 * seperates paths that would be created by a cycle.
 *
 * Parameters:
 *   smaller -- an integer
 *   larger -- an integer
 *
 * Returns:
 *   s
 **/
string UnionFind::printCycle(int smaller, int larger)
{
  string s = "";
  Arc rootOfLarger, rootOfSmaller, tempArc; 
  vector<Arc> pathSmaller, pathLarger;

  rootOfSmaller = this->find(smaller, pathSmaller);
  rootOfLarger  = this->find(larger, pathLarger);
  
  tempArc.setX(larger);
  tempArc.setY(smaller);
  
  
  s += TAG + "PATH ONE " + tempArc.toString()
           + this->toStringPath(pathSmaller, rootOfSmaller) + "\n";
  s += TAG + "PATH TWO " + this->toStringPath(pathLarger, rootOfLarger);
  
  Utils::logStream << TAG << "PATH ONE " << tempArc.toString() 
                   << this->toStringPath(pathSmaller, rootOfSmaller) << endl;
  Utils::logStream.flush();
  Utils::logStream << TAG << "PATH TWO " 
                   << this->toStringPath(pathLarger, rootOfLarger)  << endl;
  Utils::logStream.flush();
  
  return s;
}
/****************************************************************
 * Normal toString() for the class that iterates through the map
 * and returns a string containing each node and the path from 
 * that node to the root. 
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
 * toStringPath retrns the path from an arc to its root.
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
  vector<Arc>::iterator it;
  for(it = path.begin(); it != path.end(); ++it)
  {
    s += (*it).toString();
    if( (*it).equals(last)) break;
  }
  return s;
}
