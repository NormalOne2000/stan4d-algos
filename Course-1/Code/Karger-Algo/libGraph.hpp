#ifndef _LIBGRAPH_HPP_INCLUDED_
#define _LIBGRAPH_HPP_INCLUDED_

#include<vector>
#include<utility>
#include<random>

using namespace std;
typedef std::pair<int, int> Edge;

typedef std::uniform_int_distribution<> UID;
typedef std::mt19937 PRNG;

class Graph{
private:
  int n_v;
  int n_e;
  vector<int> V;//List of Vertices
  vector<Edge> E;//List of Edges

public:
  Graph(int n_v)
    {
      this->n_v = n_v;
      this->n_e = 0;
    }

  int getVertexCount(){return n_v;}
  int getEdgeCount(){return n_e;}
  void addEdge(int, int);
  Edge getRandomEdge(int);
  int kargerMinCut();

  ~Graph()
    {
      this->n_v = this->n_e = 0;
      V.clear();
      E.clear();
    }
};

#endif
