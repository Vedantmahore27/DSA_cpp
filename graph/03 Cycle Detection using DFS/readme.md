# 🔍 Cycle Detection in Undirected Graph (DFS)

## 📌 Problem Statement

Given an undirected graph with **V vertices** and a list of edges, determine whether the graph contains a **cycle** or not.

---

## 🧠 Approach: Depth First Search (DFS)

We use **DFS traversal** along with a **parent tracking mechanism**.

### 💡 Key Idea

While traversing:

* If we visit a node that is already visited **and is NOT the parent**, then a **cycle exists**.

---

## ⚙️ Algorithm Steps

1. **Convert Edge List → Adjacency List**
2. Maintain a `visited` array
3. Traverse all nodes (to handle disconnected graph)
4. For each unvisited node:

   * Run DFS
   * Track parent node
5. If DFS detects a back-edge → cycle found

---

## 🧾 Code Implementation

```cpp
class Solution {
public:
    bool solve(int node, int parent, vector<int>& visited, vector<vector<int>>& adj) {
        visited[node] = 1;

        for (auto it : adj[node]) {
            // Skip parent node
            if (it == parent) continue;

            // If already visited → cycle detected
            if (visited[it]) return true;

            // Recursive DFS
            if (solve(it, node, visited, adj)) return true;
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {

        // Step 1: Build adjacency list
        vector<vector<int>> adj(V);

        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]); // undirected graph
        }

        // Step 2: Visited array
        vector<int> visited(V, 0);

        // Step 3: Handle disconnected components
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (solve(i, -1, visited, adj)) return true;
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

### Graph:

```
0 --- 1
|     |
2     3
```

### Explanation:

* DFS starts at node 0
* Visits 1 → 2 → back to 0 (already visited & not parent)
* ✅ Cycle detected

---

## ⏱️ Complexity Analysis

### Time Complexity:

```
O(V + E)
```

* Each vertex visited once
* Each edge explored once

---

### Space Complexity:

```
O(V + E)
```

* Adjacency list → O(V + E)
* Visited array → O(V)
* Recursion stack → O(V)

---

## ⚠️ Common Mistakes

* ❌ Not adding both directions in adjacency list
* ❌ Not handling disconnected graph
* ❌ Not checking parent node
* ❌ Uninitialized variables (like `bool ans`)

---

## 🚀 Key Takeaways

* DFS is efficient for cycle detection in undirected graphs
* Always track **parent node**
* Always handle **multiple components**

---

## 🔥 Interview One-Liner

> “A cycle exists if during DFS we encounter a visited node that is not the parent.”

---

## 📚 Related Topics

* BFS Cycle Detection
* Directed Graph Cycle Detection (using recursion stack)
* Union-Find (Disjoint Set)

---

## 👨‍💻 Author

Vedant Mahore
IT | G H Raisoni College of Engineering, Pune

---
