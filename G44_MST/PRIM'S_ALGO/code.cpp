#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int primMST(vector<vector<vector<int>>> &adj) {

		int n = adj.size();
		vector<int> vis(n);

		// note :: it is a MIN_heap PQ
		priority_queue<pair<int, int>,
		               vector<pair<int, int>>,
		               greater<pair<int, int>> > pq;

		pq.push({0, 0});
		int sum = 0;

		while (!pq.empty())
		{
			pair<int, int> i = pq.top();
			pq.pop();

			int wt = i.first;
			int node = i.second;

			if (vis[node])
				continue;

			vis[node] = 1;
			sum += wt;

			for (auto &it: adj[node])
			{
				int adjnode = it[0];
				int wt = it[1];

				if (!vis[adjnode])
				{
					pq.push({wt, adjnode});
				}
			}
		}

		return sum;
	}
};
