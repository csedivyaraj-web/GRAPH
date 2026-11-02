#include <iostream>
#include <vector>
using namespace std;

class Solution {
	private:
	void dfs(int row, int col, vector<int>& delrow, vector<int>& delcol, 
                vector<vector<int>> & ans, int initcol, int newcol)
	{
		if (initcol == newcol)
			{
			return;
		}
		ans[row][col] = newcol;
		int m = ans.size();
		int n = ans[0].size();
		
		for (int i = 0; i<4; i++)
			{
			int new_r = row + delrow[i];
			int new_c = col + delcol[i];
			
			if (new_r >= 0 && new_r<m && new_c >= 0 && new_c<n && ans[new_r][new_c] == initcol)
				{
				dfs(new_r, new_c, delrow, delcol, ans, initcol, newcol);
			}
		}
	}
	
	public:
	vector<vector<int>> floodFill(vector<vector<int>> & image, int sr, int sc,
	int newColor) {
		int init_col = image[sr][sc];
		vector<vector<int>> & ans = image;
		
		vector<int> delrow = {1, 0, -1, 0};
		vector<int> delcol = {0, 1, 0, -1};
		dfs(sr, sc, delrow, delcol, ans, init_col, newColor);
		return ans;
	}
};

