//  Solution to second assignment of first Course of
//  Stanford Algorithms specialization
#include<iostream>
#include<fstream>
#include<cmath>
#include<string>
#include<vector>

using namespace std;

long long countInv(vector<int>&, long long, long long);
long long mergeCount(vector<int>&, long long, long long);
// int result = 0;
int main()
  {
    //cout << "HELLO WORLD!!";
    vector<int> A;
    string ipStr = "";
    ifstream invFile("IntegerArray.txt");
    if(invFile.is_open())
      {
        while(getline(invFile, ipStr))
          {
            A.push_back(stoi(ipStr));
          }
        invFile.close();
      }
    else
      {
        cout << "INVALID OPERATION!!" << endl;
      }
    long long ans = countInv(A, 0, A.size()-1);
    cout << "Ans : " << ans << endl;
    return 0;
  }

long long countInv(vector<int>& V, long long l, long long r)
  {
    if(r <= l)
      return 0;
    long long mid = l+(r-l)/2, c_l = 0, c_r = 0, c_m = 0;
    c_l = countInv(V, l, mid);
    c_r = countInv(V, mid+1, r);
    c_m = mergeCount(V, l, r);
    return (c_l+c_r+c_m);
  }

long long mergeCount(vector<int>& V, long long l, long long r)
  {
    long long m = l+(r-l)/2;
    long long j = m+1;
    long long count = 0;
    while(j <= r)
      {
        long long i = l;
        while(i <= m)
          {
            if(V.at(i) > V.at(j))
              {
                // cout << V.at(i) << " > " << V.at(j) << endl;
                ++count;
              }
            ++i;
          }
        ++j;
      }
    return count;
  }
