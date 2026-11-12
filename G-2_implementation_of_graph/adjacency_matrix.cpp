#include <iostream>
using namespace std;

//tc O(m) :: to store the graph in adj_matrix
//space n^2

int main() {
    
    int n,m;
    cin >> n >> m;

    int adj[n+1][n+1];
    for (int i = 0; i < m; i++)
    {
        int u , v , weight;
        cin >> u >> v >> weight;
        adj[u][v] = weight;
        //If there is a directed graph, then we will not be using the second line of inserting `u` in the node `v`. 
        adj[v][u] = weight;
    }
    
    return 0;
}
