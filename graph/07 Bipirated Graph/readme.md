# 📘 Bipartite Graph (BFS + DFS)

## 🚀 What is a Bipartite Graph?

A graph is **bipartite** if we can divide its nodes into **two groups** such that:

> No two adjacent nodes belong to the same group.

---

## 🧠 Intuition

Think of:

* Two teams
* Or two colors (0 and 1)

### Rule:

```text
Connected nodes must have opposite colors
```

---

## 🔥 Key Property

```text
Graph is bipartite ⇔ No odd-length cycle
```

* Even cycle → ✔️ bipartite
* Odd cycle → ❌ not bipartite

---

## ⚡ Approach 1: BFS (Level Order)

### 💡 Idea

* Start from a node
* Assign color `0`
* All neighbors → color `1`
* Continue level by level

---

## 🧾 Code (BFS)

```cpp
class Solution {
public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        
        vector<vector<int>> adj(V);
        
        // build undirected graph
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> color(V, -1);
        
        for(int i = 0; i < V; i++){
            if(color[i] != -1) continue;
            
            queue<int> q;
            q.push(i);
            color[i] = 0;
            
            while(!q.empty()){
                int node = q.front();
                q.pop();
                
                for(int j = 0; j < adj[node].size(); j++){
                    int nei = adj[node][j];
                    
                    if(color[nei] == -1){
                        color[nei] = !color[node];
                        q.push(nei);
                    }
                    else if(color[nei] == color[node]){
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
};
```

---

## ⚡ Approach 2: DFS

### 💡 Idea

* Use recursion
* Assign opposite color to neighbors
* If conflict → not bipartite

---

## 🧾 Code (DFS)

```cpp
class Solution {
public:

    bool dfs(int node, vector<int> &color, vector<vector<int>> &adj){
        
        for(int j = 0; j < adj[node].size(); j++){
            int nei = adj[node][j];
            
            if(color[nei] == -1){
                color[nei] = !color[node];
                
                if(!dfs(nei, color, adj)) return false;
            }
            else if(color[nei] == color[node]){
                return false;
            }
        }
        
        return true;
    }

    bool isBipartite(int V, vector<vector<int>> &edges) {
        
        vector<vector<int>> adj(V);
        
        // build undirected graph
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> color(V, -1);
        
        for(int i = 0; i < V; i++){
            if(color[i] == -1){
                color[i] = 0;
                
                if(!dfs(i, color, adj)) return false;
            }
        }
        
        return true;
    }
};
```

---

## 🧠 Color Meaning

| Value | Meaning     |
| ----- | ----------- |
| -1    | Not colored |
| 0     | Group 1     |
| 1     | Group 2     |

---

## 🔁 BFS vs DFS

| Feature              | BFS    | DFS       |
| -------------------- | ------ | --------- |
| Method               | Queue  | Recursion |
| Easy to visualize    | ✔️     | ❌         |
| Code length          | Medium | Short     |
| Interview preference | ✔️✔️   | ✔️        |

---

## ⚡ Important Points

### ✅ Disconnected Graph

* Always run loop for all nodes

---

### ❗ Undirected Graph Only

* Add both directions:

```cpp
adj[u].push_back(v);
adj[v].push_back(u);
```

---

### ❌ Odd Cycle = Not Bipartite

Example:

```text
0 — 1 — 2 — 0
```

---

## 🧠 Quick Summary

```text
Try coloring graph using 2 colors

If conflict occurs → not bipartite
Else → bipartite
```

---

## 🎯 Applications

* Graph coloring problems
* Scheduling problems
* Matching problems (like jobs ↔ people)
* Checking conflicts

---

## 💬 Final Tip

If stuck in interview:
👉 Start with BFS
👉 Then mention DFS as alternative

---

✨ That’s Bipartite Graph — simple concept, powerful logic!
