// Implementation of Union-Find

#include "libUF.hpp"

void UF::UFunion(int src, int dst)
  {
    int dR = UFroot(dst), dS = UFroot(src);
    if(dR != dS)
      {
        if(ufArr[dR].size > ufArr[dS].size)
          {
            ufArr[dS].root = ufArr[dR].root;
            ufArr[dR].size += ufArr[dS].size;
          }
        else
          {
            ufArr[dR].root = ufArr[dS].root;
            ufArr[dS].size += ufArr[dR].size;
          }
        numComponents -= 1;
      }
  }

bool UF::UFfind(int src, int dst)
  {
    return(UFroot(src) == UFroot(dst));
  }

int UF::UFroot(int idx)
  {
    int temp;
    while(ufArr[idx].root != idx)
      {
        temp = ufArr[ufArr[idx].root].root;
        idx = ufArr[temp].root;
      }
    return idx;
  }
