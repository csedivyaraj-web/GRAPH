//Dijkstra's algorithm for finding the shortest path from source to any Vertex
#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;

class Edge
{
public:
    int v;
    int wt;

    Edge(int v , int wt)
    {
        this->v = v;
        this->wt = wt;
    }
}; 


void dijkstra(int src , vector<vector<Edge>>& graph , int v)
{
    vector<int> dis(v,INFINITY);
    dis[src] = 0;

    priority_queue <pair<int,int> , 
                    vector<pair<int,int>> , 
                    greater<pair<int,int>>> pq;

    pq.push({0,src});

    while (!pq.empty())
    {
        auto x = pq.top();
        pq.pop();
        int u = x.second;
        int wt = x.first;
        
        for(auto& e : graph[u])
        {
            if(dis[e.v] > dis[u]+e.wt)
            {
                dis[e.v] = dis[u]+e.wt;
                pq.push({dis[e.v] , e.v});
            }
        }
    }
    
    for (int i = 0 ; i<v ; i++)
    {
        cout << dis[i] << " "; 
    }
    cout << endl;

    return;
}

int main()
{
    int Vertices = 6;
    vector<vector<Edge>> graph(Vertices);

    graph[0].push_back(Edge(1,2));
    graph[0].push_back(Edge(2,4));

    graph[1].push_back(Edge(2,1));
    graph[1].push_back(Edge(3,7));

    graph[2].push_back(Edge(4,3));

    graph[3].push_back(Edge(5,1));

    graph[4].push_back(Edge(3,2));
    graph[4].push_back(Edge(5,5));

    dijkstra(0 , graph , Vertices);
    return 0;
}
