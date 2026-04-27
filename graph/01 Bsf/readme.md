# 🚀 Breadth First Search (BFS) - Graph Traversal

## 📌 Problem

Implement **Breadth First Search (BFS)** traversal of a graph starting from node `0`.

* The graph is represented using an **adjacency list**
* Return the BFS traversal order

---

## 🧠 Approach

We use a **Queue (FIFO)** to explore nodes level by level.

### Steps:

1. Initialize a **visited array** to track visited nodes
2. Push the starting node (`0`) into the queue
3. Mark it as visited
4. While the queue is not empty:

   * Pop the front node
   * Add it to the result
   * Traverse all its neighbors
   * Push unvisited neighbors into the queue

---

## ⚙️ Algorithm

1. Start from node `0`
2. Use a queue for traversal
3. Mark nodes as visited when pushing into queue
4. Continue until queue is empty

---

## 💻 Code (C++)

```cpp
class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        int n = adj.size();
        queue<int> q;
        vector<int> visited(n, 0);
        vector<int> ans;
       
        q.push(0);
        visited[0] = 1;
       
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            ans.push_back(node);
           
            for (int neighbour : adj[node]) {
                if (!visited[neighbour]) {
                    q.push(neighbour);
                    visited[neighbour] = 1;
                }
            }
        }
       
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

* `V` = number of vertices
* `E` = number of edges

---

## 📊 Example

### Input Graph:

```
0 -> 1, 2
1 -> 3
2 -> 4
```

### Output:

```
0 1 2 3 4
```

---

## 🔑 Key Points

* BFS explores nodes **level by level**
* Uses **Queue (FIFO)**
* Always mark nodes **visited at insertion time**
* Useful for:

  * Shortest path (unweighted graph)
  * Level order traversal
  * Connectivity problems

---

## 🧩 Applications

* Shortest path in unweighted graphs
* Network broadcasting
* Web crawling
* Social network analysis

---

## 🙌 Author

**Vedant Mahore**

* 🎓 IT Student | G H Raisoni College of Engineering, Pune
* 💻 Passionate about DSA & Development

---
