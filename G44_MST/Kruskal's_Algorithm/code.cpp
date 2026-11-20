#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class disjointset
{
    vector<int> size , parent;

public:
    disjointset(int n)
    {
        //1 based indexing graph
        parent.resize(n+1);
        size.resize(n+1 , 1);

        for(int i = 0 ; i <= n ; i++)
           parent[i] = i;
    }

    int findUpar(int n)
    {
        if(n == parent[n])
            return n;

        //path compression
        return parent[n] = findUpar(parent[n]);
    }


    void union_by_size(int v , int u)
    {
        int ul_par_u = findUpar(u);
        int ul_par_v = findUpar(v);   

        if (ul_par_u == ul_par_v)
        {
            return;
        }

        if(size[ul_par_u] < size[ul_par_v])
        {
            parent[ul_par_u] = ul_par_v;
            size[ul_par_v]+= size[ul_par_u];
        }
        
        else
        {
            parent[ul_par_v] = ul_par_u;
            size[ul_par_u]+= size[ul_par_v];
        }
    }
};



class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        
        for(auto& it: edges)
        {
            int node = it[0];
            int adjnode = it[1];
            int wt = it[2];

            it = {wt , node , adjnode};
        }
        
        sort(edges.begin() , edges.end());
        
        int mstwt = 0;
        disjointset ds(V);
        
        for(auto& it: edges)
        {
            int wt = it[0];
            int u = it[1];
            int v = it[2];

            //if U and V both belong to different components. 
            if (ds.findUpar(u) != ds.findUpar(v))
            {
                mstwt += wt;
                ds.union_by_size(u,v);
            }
        }

        return mstwt;
    }
};