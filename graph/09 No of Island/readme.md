# 🌊 Number of Islands (BFS) - LeetCode / GFG

## 🔴 Problem

Given a 2D grid `grid[][]` of size `r x c`:

* `'1'` → Land
* `'0'` → Water

An **island** is formed by connecting adjacent lands **horizontally or vertically (4 directions)**.

👉 Return the **number of islands**.

---

## 🧪 Example

```id="ex1"
Input:
grid = [
  ['1','1','0','0'],
  ['1','0','0','1'],
  ['0','0','1','1'],
  ['0','0','0','0']
]

Output:
3
```

---

## 🧠 Problem Understanding

* We need to count **connected components of '1'**
* Each group of connected `'1'` forms **one island**
* Once visited, a cell should **not be counted again**

---

## 💡 Intuition

This is a **graph problem in disguise**.

* Each cell = node
* Adjacent `'1'` = connected nodes

👉 So, problem reduces to:

> “Count number of connected components”

---

## 🐢 Brute Force Approach

### Idea:

* For each cell, try exploring all directions recursively
* But without marking visited properly → leads to repeated work

### ❌ Issues:

* Re-exploration of same cells
* High redundancy

### ⏱️ Complexity:

* Time: **O((r × c)²)**
* Space: **O(r × c)** (recursion stack)

---

## ⚡ Better Approach

### Idea:

* Use a **visited array**
* For every unvisited `'1'`, perform BFS/DFS

### Steps:

1. Traverse grid
2. If `'1'` and not visited → BFS
3. Mark all reachable land

### ⏱️ Complexity:

* Time: **O(r × c)**
* Space: **O(r × c)** (visited + queue)

---

## 🚀 Optimal Approach (BFS without extra space)

### 🔥 Key Idea:

Instead of using a visited array, **modify the grid itself**

👉 Convert `'1' → '0'` when visited

---

### Steps:

1. Traverse grid
2. When `'1'` found:

   * Increment island count
   * Start BFS
3. During BFS:

   * Mark visited by setting `'0'`
   * Explore 4 directions
4. Continue until grid is fully traversed

---

## ✅ Code

```cpp
class Solution {
public:
    int r,c;
    
    int row[4] = {-1,0,1,0};
    int col[4] = {0,1,0,-1};
    
    bool valid(int i ,int j ){
        return i>=0 && j>=0 && i<r && j<c;
    }

    int numIslands(vector<vector<char>>& grid) {
        
        if(grid.empty()) return 0;
        
        r = grid.size();
        c = grid[0].size();
        
        int island = 0;
        queue<pair<int,int>> q;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                
                if(grid[i][j]=='1'){
                    island++;
                    
                    q.push({i,j});
                    grid[i][j]='0';   // mark visited

                    while(!q.empty()){
                        auto [ni,nj] = q.front();
                        q.pop();

                        for(int k=0;k<4;k++){
                            int x = ni + row[k];
                            int y = nj + col[k];

                            if(valid(x,y) && grid[x][y]=='1'){
                                grid[x][y]='0';
                                q.push({x,y});
                            }
                        }
                    }
                }
            }
        }
        return island;
    }
};
```

---

## ⏱️ Complexity Analysis

| Type  | Complexity                         |
| ----- | ---------------------------------- |
| Time  | **O(r × c)**                       |
| Space | **O(r × c)** (queue in worst case) |

👉 Each cell is processed only once.

---

## 🎯 Key Takeaways

* Grid problems → often graph problems
* BFS/DFS used to find **connected components**
* Mark visited immediately to avoid revisits
* Using grid as visited saves space

---

## 🔥 Interview Insight

If asked:

> Why BFS/DFS?

👉 Answer:

> “Because the problem is equivalent to finding connected components in a graph.”

---

## ⚠️ Important Notes

* This solution uses **4 directions only**
* If diagonals are allowed → use 8 directions
* Always check for **empty grid edge case**

---

## 🚀 Tags

`BFS` `DFS` `Graph` `Matrix` `Flood Fill` `Connected Components`
