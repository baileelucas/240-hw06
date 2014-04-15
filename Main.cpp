/****************************************************************
 * Main program for doing union-find algorithm.
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * Used with permission by: Alison Bailee Lucas.
 * Date: 12 April 2014
 *
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
  
  /*
   srand(1);
   int count = 20;
   for(int i = 0; i < 100; ++i)
   {
   int a = rand() % count;
   int b = rand() % count;
   while(a == b)
   {
   b = rand() % count;
   }
   
   Utils::logStream << Utils::Format(a, 3) << " " << Utils::Format(b, 3) << endl;
   Utils::logStream.flush();
   
   }
   exit(1);
   */
  
  inStream.openFile(inFileName);
  int numberOfArcs = inStream.nextInt();
  
  outStream << "Arcs: " << numberOfArcs << endl;

  for(int arc = 0; arc < numberOfArcs; ++arc)
  {
    int a = inStream.nextInt();
    outStream << "(" << a << ", ";
    int b = inStream.nextInt();
    outStream << b << ")" << endl;
    //    cout << "ZORK " << a << " " << b << endl;
//    int rootA = unionFind.find(a);
//    int rootB = unionFind.find(b);
//    
//    if (rootA != rootB)
//    {
//      unionFind.addLink(a, b);
//    }
    
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
  
    Utils::logStream << unionFind.toString() << endl;
    Utils::logStream.flush();
  
    //unionFind.buildTrees();
    Utils::logStream << unionFind.toString() << endl;
    Utils::logStream.flush();
  
  timeCallOutput = Utils::timecall("ending");
  Utils::logStream << timeCallOutput;
  Utils::logStream << TAG << "Ending execution" << endl;
  Utils::logStream.flush();
  
  Utils::FileClose(outStream);
  Utils::FileClose(Utils::logStream);
  
  return 0;
}
