/*
#include<iostream>
#include<new>
#include<fstream>
#include<vector>
#include<sstream>
#include<random>
#include<ctime>
#include<algorithm>
#include<string>
*/

#include<bits/stdc++.h>
#include "libUF.hpp"
#include "libGraph.hpp"

using namespace std;

int main()
  {
    int prevCut = 0, presentCut = 0, allMinCut = 1000000;
    string ipStr = "";
    Graph gObj(200);
    ifstream ipFile
    ("/home/sahyrlelyaams/Desktop/Projects/Algorithms/Course-1/Code/Karger-Algo/kmc.txt");
    if(ipFile.is_open())
      {
        while( getline (ipFile, ipStr) )
          {
            int Idx, temp = 0;
            stringstream objStr(ipStr);
            objStr >> Idx;
            while(!objStr.eof())
              {
                objStr >> temp;
                if(Idx < temp)
                  gObj.addEdge(Idx-1, temp-1);
              }
          }
        ipFile.close();
      }
    else
      {
        cout << "NaN" << endl;
        return 0;
      }
    for(int k = 0; k < 100000; ++k)
      {
        prevCut = 0, presentCut = 1000000;
        for(int i = 0; i < 10; ++i)
          {
            Graph temp(gObj);
            prevCut = temp.kargerMinCut();
            if(prevCut < presentCut)
              presentCut = prevCut;
          }
        if(presentCut < allMinCut)
          allMinCut = presentCut;
      }
    cout << "ANS : " << allMinCut << endl;
    return 0;
  }
