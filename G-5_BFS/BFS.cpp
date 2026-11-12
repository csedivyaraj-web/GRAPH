#include <iostream>
#include <vector>
using namespace std;

//space complexity :: O(3N) :: N:queue ,N:vis , N:bfs array
 

class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        
        int n = adj.size();
        vector<int> vis(n);
        
        //zero based indexing
        vis[0] = 1;
        queue<int> q;
        q.push(0);
        
        vector<int> bfs;
        while(!q.empty())
        {
            int node = q.front(); 
            q.pop();
            bfs.push_back(node);
            
            for(auto i:adj[node])
            {
                if(!vis[i])
                {
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }
        
        return bfs;
    }
};


