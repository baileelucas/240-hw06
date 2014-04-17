/****************************************************************
 * Main program for doing union-find algorithm.
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * 
 * Used and modifed, with permission, by: 
 * Alison Bailee Lucas, Andrew Campbell, Rohit Gupta,
 * Jacob Leidel, and Timothy Bradley
 *
 *  Date: 16 April 2014
 **/

#include "Main.h"

static const string TAG = "Main: ";

int main(int argc, char *argv[])
{
  string timeCallOutput = "";
  string inFileName = "";
  string outFileName = "";
  string logFileName = "";
  ofstream outStream;
  Scanner inStream;
  
  UnionFind unionFind;
  
  Utils::CheckArgs(3, argc, argv, "infilename outfilename logfilename");
  inFileName = (string) argv[1];
  outFileName = (string) argv[2];
  logFileName = (string) argv[3];
  
  Utils::FileOpen(outStream, outFileName);
  Utils::LogFileOpen(logFileName);
  
  timeCallOutput = Utils::timecall("beginning");
  Utils::logStream << timeCallOutput;
  Utils::logStream << TAG << "Beginning execution" << endl;
  Utils::logStream.flush();
  
  Utils::logStream << TAG << "infile '" << inFileName << "'" << endl;
  Utils::logStream << TAG << "outfile '" << outFileName << "'" << endl;
  Utils::logStream << TAG << "logfile '" << logFileName << "'" << endl;
  
  inStream.openFile(inFileName);
  int numberOfArcs = inStream.nextInt();
  
  outStream << "Arcs: " << numberOfArcs << endl;

  for(int arc = 0; arc < numberOfArcs; ++arc)
  {
    int a = inStream.nextInt();
    outStream << "(" << a << ", ";
    int b = inStream.nextInt();
    outStream << b << ")" << endl;
    
    if(a < b)
    {
      unionFind.addLink(a, b);
        outStream << a << " < " << b << endl;
        outStream << "add link: " << a << " to " << b << endl;
    }
    else
    {
      unionFind.addLink(b, a);
      outStream << a << " > " << b << endl;
      outStream << "add link: " << b << " to " << a << endl;
    }
  }
  
  Utils::logStream << "Final Tree:\n" << unionFind.toString() << endl;
  Utils::logStream.flush();
  
  timeCallOutput = Utils::timecall("ending");
  Utils::logStream << timeCallOutput;
  Utils::logStream << TAG << "Ending execution" << endl;
  Utils::logStream.flush();
  
  Utils::FileClose(outStream);
  Utils::FileClose(Utils::logStream);
  
  return 0;
}
