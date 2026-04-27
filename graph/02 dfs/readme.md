# 🌳 Depth First Search (DFS) - Graph Traversal

## 📌 Problem

Implement **Depth First Search (DFS)** traversal of a graph starting from node `0`.

* The graph is represented using an **adjacency list**
* Return the DFS traversal order

---

## 🧠 Approach

We use **Recursion (Backtracking)** to explore the graph as deep as possible before backtracking.

### Steps:

1. Maintain a **visited array** to avoid revisiting nodes
2. Start DFS from node `0`
3. Mark the current node as visited
4. Add it to the result
5. Recursively visit all unvisited neighbors

---

## ⚙️ Algorithm

1. Start from node `0`
2. Mark it visited
3. Traverse all adjacent nodes
4. Recursively call DFS on unvisited neighbors
5. Continue until all reachable nodes are visited

---

## 💻 Code (C++)

```cpp id="dfs-code"
class Solution {
  public:
    void solve(int node, vector<int>& ans, vector<int>& visited, vector<vector<int>>& adj) {
        visited[node] = 1;
        ans.push_back(node);
        
        for (int i = 0; i < adj[node].size(); i++) {
            if (!visited[adj[node][i]]) {
                solve(adj[node][i], ans, visited, adj);
            }
        }
    }

    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> ans;
        vector<int> visited(n, 0);
        
        solve(0, ans, visited, adj);
        
        return ans;
    }
};
```

---

## ⏱️ Complexity

| Type  | Complexity   |
| ----- | ------------ |
| Time  | **O(V + E)** |
| Space | **O(V)**     |

### 🔍 Explanation

* **Time Complexity:**

  * Each node is visited once → `O(V)`
  * Each edge is explored once → `O(E)`
  * 👉 Total = **O(V + E)**

* **Space Complexity:**

  * `visited` array → `O(V)`
  * recursion stack (worst case) → `O(V)`
  * 👉 Total = **O(V)**

---

## 📊 Example

### Input Graph:

```
0 -> 1, 2
1 -> 3
2 -> 4
```

### DFS Traversal:

```
0 1 3 2 4
```

---

## 🔑 Key Points

* DFS explores **as deep as possible first**
* Uses **recursion (stack internally)**
* Always mark nodes **visited before recursion**
* Traversal depends on adjacency order

---

## 🧩 Applications

* Cycle detection in graphs
* Topological sorting
* Connected components
* Path finding
* Maze solving

---

## ⚠️ Note

This implementation:

* Starts from node `0`
* Works for **connected graphs**

👉 For disconnected graphs, you need to run DFS for all unvisited nodes.

---

## 🙌 Author

**Vedant Mahore**

* 🎓 IT Student | G H Raisoni College of Engineering, Pune
* 💻 DSA Enthusiast | Problem Solver

---
