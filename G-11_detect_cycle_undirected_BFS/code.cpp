#include <vector>
#include <queue>
using namespace std;

class Solution {
	
	bool detect_cycle(int src, vector<int>& vis, vector<vector<int>> & adj)
	{
		vis[src] = 1;
		queue<pair<int, int>> q;
		
		q.push({src, -1});
		
		while (!q.empty())
			{
			pair<int, int> p = q.front();
			int node = p.first;
			int parent = p.second;
			q.pop();
			
			for (auto & it: adj[node])
				{
				if (!vis[it])
					{
					vis[it] = 1;
					q.push({it, node});
				}
				
				else if (it != parent) {
					return true;
				}
			}
		}
		return false;
	}
	
	public:
	bool isCycle(vector<vector<int>> & adj) {
		
		int n = adj.size();
		vector<int> vis(n, 0);
		for (int i = 0 ; i<n ; i++)
			{
			if (!vis[i])
				{
				if (detect_cycle(i, vis, adj))
					{
					return true;
				}
			}
		}
		
		return false;
	}
};
