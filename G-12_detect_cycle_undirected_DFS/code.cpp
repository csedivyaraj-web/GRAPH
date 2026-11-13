#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    bool detect_dfs(int src, int par, vector<vector<int>> &adj, vector<int> &vis)
    {
        vis[src] = 1;

        for (auto &it : adj[src])
        {
            if (!vis[it])
            {
                if (detect_dfs(it, src, adj, vis))
                    return true;
            }
            else if (par != it)
            {
                return true;
            }
        }
        return false;
    }

public:
    bool isCycle(vector<vector<int>> &adj)
    {
        int n = adj.size();
        vector<int> vis(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                if (detect_dfs(i, -1, adj, vis))
                    return true;
            }
        }
        return false;
    }
};
