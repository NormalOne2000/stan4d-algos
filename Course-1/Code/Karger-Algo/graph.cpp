//Implementation of Graph data structure

#include "libGraph.hpp"
#include "libUF.hpp"

void Graph::addEdge(int src, int dst)
  {
    if(!E.empty())
      {
        if(src > dst)
          {
            int temp = dst;
            dst = src;
            src = temp;
          }
        for(auto e : E)
          {
            if((e.first == src) && (e.second == dst))
              return;
          }
      }
    E.push_back(std::make_pair(src, dst));
    ++n_e;
  }

Edge Graph::getRandomEdge(int idx)
  {
    return E[idx];
  }

int Graph::kargerMinCut()
  {
    int retVal = 0;
    PRNG engine{static_cast<PRNG::result_type>(time(nullptr))};
    UID randVal{0, n_e};
    UF ufVar(n_v);
    while(ufVar.getNumComp() > 2)
      {
        Edge tempEdge = getRandomEdge(randVal(engine));
        int src = tempEdge.first, dst = tempEdge.second;
        if(!ufVar.UFfind(src, dst))
          ufVar.UFunion(src, dst);
      }

    for(auto e : E)
      {
        if(ufVar.UFroot(e.first) != ufVar.UFroot(e.second))
          ++retVal;
      }
    return retVal;
  }
