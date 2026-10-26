#include <iostream>
#include <vector>
using namespace std;


class Solution {
	public:
	
	void traverse(int node, vector<int>& vis, vector<int>& dfs, vector<vector<int>> & adj)
	{
		vis[node] = 1;
		dfs.push_back(node);
		
		for (auto& it : adj[node])
			{
			if (!vis[it])
				traverse(it, vis, dfs, adj);
		}
	}
	
	vector<int> dfs(vector<vector<int>> & adj) {
		
		int n = adj.size();
		vector<int> vis(n);
		vector<int> dfs;
		
		traverse(0, vis, dfs, adj);
		
		return dfs;
	}
};
