# 🔍 Cycle Detection in Undirected Graph (BFS)

## 📌 Problem Statement

Given an undirected graph with **V vertices** and a list of edges, determine whether the graph contains a **cycle**.

---

## 🧠 Approach: Breadth First Search (BFS)

We use **BFS traversal** with a **queue**, and store **(node, parent)** pairs.

---

## 💡 Key Idea

While traversing:

* If we encounter a **visited node that is NOT the parent**, then a **cycle exists**.

---

## ⚙️ Algorithm Steps

1. Convert edge list → adjacency list
2. Maintain a `visited` array
3. Traverse all nodes (to handle disconnected graph)
4. For each unvisited node:

   * Push `{node, parent}` into queue
   * Run BFS
5. If a visited node is found (not parent) → cycle

---

## 🧾 Code Implementation

```cpp
class Solution {
public:
    bool bfs(int start, vector<int>& visited, vector<vector<int>>& adj) {
        queue<pair<int, int>> q; // {node, parent}
        visited[start] = 1;
        q.push({start, -1});

        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            int node = front.first;
            int parent = front.second;

            for (auto it : adj[node]) {
                if (!visited[it]) {
                    visited[it] = 1;
                    q.push({it, node});
                }
                else if (it != parent) {
                    return true;
                }
            }
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {

        // Build adjacency list
        vector<vector<int>> adj(V);
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> visited(V, 0);

        // Handle disconnected graph
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (bfs(i, visited, adj)) return true;
            }
        }

        return false;
    }
};
```

---

## 🔁 Dry Run Example

### Input:

```
V = 4
Edges:
0-1
1-2
2-0
1-3
```

### BFS Flow:

* Start at 0 → push (0, -1)
* Visit 1 → push (1, 0)
* Visit 2 → push (2, 1)
* From 2 → see 0 (already visited & not parent)
  ✅ Cycle detected

---

## ⏱️ Complexity Analysis

### Time Complexity:

```
O(V + E)
```

### Space Complexity:

```
O(V + E)
```

* Adjacency list → O(V + E)
* Visited array → O(V)
* Queue → O(V)

---

## ⚠️ Common Mistakes

* ❌ Not storing parent in queue
* ❌ Missing condition `it != parent`
* ❌ Not handling disconnected graph
* ❌ Forgetting to mark visited before pushing

---

## 🔥 BFS vs DFS (Quick Insight)

| Feature     | BFS          | DFS             |
| ----------- | ------------ | --------------- |
| Structure   | Queue        | Recursion/Stack |
| Approach    | Level-wise   | Depth-wise      |
| Cycle Logic | Parent check | Parent check    |

---

## 🚀 Key Takeaways

* BFS uses **queue + parent tracking**
* Same logic as DFS, just iterative
* Always handle disconnected graphs

---

## 💬 Interview One-Liner

> “In BFS, we store (node, parent) in queue and if we reach a visited node that is not the parent, a cycle exists.”

---

## 👨‍💻 Author

Vedant Mahore
IT | G H Raisoni College of Engineering, Pune

---
