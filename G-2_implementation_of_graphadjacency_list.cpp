#include <iostream>
#include <vector> 
using namespace std;
//tc ::O(m);
//space :: O(2*E) undirected O(E)

int main() {
    int m , n;
    cin >> n >> m;

    vector<pair<int , int>> adj_list[n+1];

    for (int i = 0; i < m; i++)
    {
        int u , v , weight;
        cin >> u >> v >> weight;
        adj_list[u].push_back({v,weight});
        //If there is a directed graph, then we will not be using the second line of inserting `u` in the node `v`. 
        adj_list[v].push_back({u,weight});
    }

    return 0;
}
