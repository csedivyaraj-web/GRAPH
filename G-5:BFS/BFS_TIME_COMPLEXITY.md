# BFS Time Complexity: Why O(V + E)?

This note explains why Breadth-First Search on a graph (adjacency list) runs in **O(V + E)** time, and why we **add** V and E instead of multiplying them.

- **V** = number of vertices (nodes)
- **E** = number of edges

## The Code

```cpp
vector<int> bfs(vector<vector<int>> &adj) {
    int n = adj.size();
    if (n == 0) return {};

    vector<int> vis(n, 0);
    vis[0] = 1;                      // zero-based indexing
    queue<int> q;
    q.push(0);

    vector<int> bfs;
    while (!q.empty()) {             // outer loop
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for (auto i : adj[node]) {   // inner loop
            if (!vis[i]) {
                vis[i] = 1;          // mark when pushing, not when popping
                q.push(i);
            }
        }
    }
    return bfs;
}
```

## The Big Idea

We add V and E because they are **two separate totals counted across the whole run**, not one job nested inside another.

### Job 1: Visiting the nodes (outer `while` loop)

- Every node goes into the queue only once and comes out only once (because we mark it visited when pushing).
- So the `while` loop runs **V times in total**.
- This loop decides the **V** part.

### Job 2: Checking the edges (inner `for` loop)

- When a node is taken out, we look at all its neighbors.
- A node with 3 neighbors makes the `for` loop run 3 times. A node with 1 neighbor makes it run 1 time.
- Different nodes have different numbers of neighbors, so the inner loop does **not** run the same number of times for every node.
- Adding up the neighbors of all nodes gives the total number of edges: **E** for a directed graph, **2E** for an undirected graph (each edge is listed from both sides).
- This loop decides the **E** part.

## Why Not Multiplication?

Multiplication (V × something) is correct only when **every node does the same amount of work**. For example, if every node had to check all V other nodes, the cost would be V × V.

Here, the inner loop is **not** "V times for every node". Each node only checks **its own neighbors**, which is usually far fewer than V.

Writing "outer loop V times × inner loop up to V times = O(V²)" is a valid upper bound, but it is loose. It pretends every node is as busy as the busiest possible node.

## Directed vs Undirected Graphs

The only difference is how many times each edge appears in the adjacency lists.

### Directed graph

An edge `u → v` is stored once, in `adj[u]` only.

- Sum of all list lengths = **E**
- Total time = V + E = **O(V + E)**

### Undirected graph

An edge `u - v` is stored twice, in `adj[u]` and in `adj[v]`.

- Sum of all list lengths = sum of degrees = **2E**
- Total time = V + 2E = **O(V + E)**

The 2 is a constant and Big-O drops constants, so the result is still **O(V + E)** in both cases.

## Analogy

A teacher visits V classrooms, once each (V visits). In each classroom she checks the students' notebooks. The total work is:

> (number of classroom visits) + (total notebooks checked across all classrooms)

not (number of classrooms × number of notebooks).

## Adjacency List vs Adjacency Matrix

| Representation | Cost to scan neighbors of one node | Total BFS time |
|----------------|------------------------------------|----------------|
| Adjacency list | `deg(u)` | **O(V + E)** |
| Adjacency matrix | V (full row) | **O(V²)** |

## Space Complexity

- `vis` array: O(V)
- Queue: up to O(V)
- Result vector: O(V)

Total auxiliary space: **O(V)**.

## Notes

- This version only visits the component containing node 0. For disconnected graphs, run BFS from every unvisited node (still O(V + E) overall).
- The same reasoning (aggregate analysis) applies to DFS and many other graph algorithms: ask "how many times is each vertex processed, and how many times is each edge examined?" and add those counts.

## One-Line Summary

The outer loop counts the nodes (V), the inner loop across the whole run counts the edges (E), and since these are separate totals that add up, BFS takes **O(V + E)** time.