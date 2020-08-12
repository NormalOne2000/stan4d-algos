#ifndef _LIBUF_HPP_INCLUDED_
#define _LIBUF_HPP_INCLUDED_

#include<vector>
#include<new>

using namespace std;

struct ufEle{
  int root;
  unsigned int size;
};

class UF{
private:
  unsigned int numComponents;
  unsigned int size;
  vector<ufEle> ufArr;

public:
  UF(int s)
    {
      size = s;
      ufEle v;
      for(int i = 0; i < size; ++i)
        {
          v = {i, 1};
          ufArr.push_back(v);
        }
      numComponents = size;
    }
  unsigned int getNumComp(){return numComponents;};
  int UFroot(int);
  void UFunion(int, int);
  bool UFfind(int, int);
  ~UF()
    {
      ufArr.clear();
    }
};

#endif
