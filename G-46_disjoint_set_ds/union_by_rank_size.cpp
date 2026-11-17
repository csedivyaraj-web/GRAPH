#include <iostream>
#include <vector>
using namespace std;

class disjointset
{
    vector<int> rank , parent , size;

public:
    disjointset(int n)
    {
        //1 based indexing graph
        rank.resize(n+1,0);
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

    //Here, we need to check if both u and v belong to the same component. If yes, then we will simply return. 
    //If no, then we will first union them, combine them, and then return.
    void union_by_rank(int u , int v)
    {
        int ul_par_u = findUpar(u);
        int ul_par_v = findUpar(v);    
        
        if(ul_par_u == ul_par_v)
            return;

        if (rank[ul_par_u] < rank[ul_par_v])
            parent[ul_par_u] = ul_par_v;

        else if (rank[ul_par_v] < rank[ul_par_u])
            parent[ul_par_v] = ul_par_u;

        else{
            parent[ul_par_u] = ul_par_v;
            rank[ul_par_v]++;
        }
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

int main() {
    
    disjointset ds(7);
    ds.union_by_size(1,2);
    ds.union_by_size(2,3);
    ds.union_by_size(4,5);
    ds.union_by_size(6,7);
    ds.union_by_size(5,6);
    // ds.union_by_rank(3,7);

    //if 3 & 7 belong to the same compO?
    if(ds.findUpar(3) == ds.findUpar(7))
        cout<< "SAME" << endl;
    
    else cout << "NOT SAME" << endl;
    ds.union_by_rank(3,7);

    if(ds.findUpar(3) == ds.findUpar(7))
        cout<< "SAME OK" << endl;
    
    else cout << "NOT SAME OK" << endl;

    return 0;
}
//why connect smaller to larger. ??
//I don't want to increase the height.
