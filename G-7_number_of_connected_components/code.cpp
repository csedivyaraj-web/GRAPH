#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
	
	void dfs(int node, vector<int>& vis, vector<vector<int>> & edges)
	{
		vis[node] = 1;
		
		for (auto& it : edges)
			{
			if (it[0] == node && !vis[it[1]])
				{
				dfs(it[1], vis, edges);
			}
			
			else if (it[1] == node && !vis[it[0]])
				{
				dfs(it[0], vis, edges);
			}
		}
		
		return;
	}
	
	int countConnected(int V, vector<vector<int>> & edges) {
		
		vector<int> vis(V);
		
		int count = 0;
		
		for (int i = 0; i < V; i++)
		{
			if (!vis[i])
			{
				count++;
				dfs(i, vis, edges);
			}
		}
		
		return count;
	}
};
