# 📘 Topological Sort (DFS + BFS/Kahn’s Algorithm)

## 🚀 What is Topological Sort?

Topological Sort is a **linear ordering of vertices** in a **Directed Acyclic Graph (DAG)** such that:

> For every directed edge `u → v`, node `u` appears before `v`.

---

## 🧠 Intuition (Very Important)

Think of it like:

* Tasks with dependencies
* You **must complete prerequisites first**

### Example:

```
0 → 1 → 2
```

Valid order:

```
0 1 2
```

---

## ❗ Key Conditions

* Graph must be **Directed**
* Graph must be **Acyclic (no cycle)**

If cycle exists → **Topological Sort NOT possible**

---

# 🔥 Approach 1: DFS (Depth First Search)

## 💡 Idea

* Go deep first (DFS)
* Add node **after visiting all neighbors**
* Reverse the result

---

## 🧠 Intuition

```
Go deep → finish dependencies → then add node
```

---

## 🧾 Code (DFS)

```cpp
class Solution {
public:
    
    void dfs(int node, vector<int>& visited, vector<vector<int>>& adj, vector<int>& ans){
        visited[node] = 1;
        
        for(auto neighbor : adj[node]){
            if(!visited[neighbor]){
                dfs(neighbor, visited, adj, ans);
            }
        }
        
        ans.push_back(node); // push after visiting neighbors
    }

    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
        }

        vector<int> visited(V, 0);
        vector<int> ans;

        for(int i = 0; i < V; i++){
            if(!visited[i]){
                dfs(i, visited, adj, ans);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

---

## ⚠️ Cycle Detection (DFS)

Use 3 states:

```
0 = unvisited
1 = visiting
2 = visited
```

If you see `1` again → **cycle**

---

# 🔥 Approach 2: BFS (Kahn’s Algorithm)

## 💡 Idea

* Count **indegree** (incoming edges)
* Start with nodes having indegree = 0
* Remove them and reduce indegree of neighbors

---

## 🧠 Intuition

```
Nodes with no dependencies → process first
```

---

## 🧾 Code (Kahn’s Algorithm)

```cpp
class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);
        vector<int> ans;
        
        // build graph
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
        }
        
        // calculate indegree
        for(int i = 0; i < V; i++){
            for(int j = 0; j < adj[i].size(); j++){
                indegree[adj[i][j]]++;
            }
        }
        
        queue<int> q;
        
        // push 0 indegree nodes
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        // BFS
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            ans.push_back(node);
            
            for(int j = 0; j < adj[node].size(); j++){
                indegree[adj[node][j]]--;
                
                if(indegree[adj[node][j]] == 0){
                    q.push(adj[node][j]);
                }
            }
        }
        
        // cycle check
        if(ans.size() != V) return {};
        
        return ans;
    }
};
```

---

# ⚖️ DFS vs BFS (Kahn’s)

| Feature              | DFS                 | BFS (Kahn’s)     |
| -------------------- | ------------------- | ---------------- |
| Approach             | Recursion           | Queue            |
| Cycle Detection      | via recursion stack | via size check   |
| Easy to Code         | Medium              | Easy             |
| Interview Preference | Good                | ⭐ Most Preferred |

---

# 🔥 Important Notes

### ✅ Disconnected Graph

* Works in both approaches
* Each component processed separately

---

### ❌ Cycle Case

* No valid topo order
* Always check:

```cpp
if(ans.size() != V) return {};
```

---

# 🧠 Quick Summary

```
DFS:
Go deep → push after → reverse

BFS:
Indegree → queue → process → reduce
```

---

# 🎯 When to Use?

* Course Scheduling problems
* Dependency resolution
* Task ordering
* Build systems

---

# 💬 Final Tip

If confused in interview:
👉 Start with **Kahn’s Algorithm**
👉 Then mention DFS as alternative

---

✨ That’s Topological Sort — clean, powerful, and super important!
