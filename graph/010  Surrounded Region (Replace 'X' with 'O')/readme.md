# 🧩 Surrounded Regions (BFS) - GFG

## 🔴 Problem

Given a 2D grid `grid[][]` of size `r x c`:

* `'X'` → Blocked cell
* `'O'` → Open cell

👉 A region of `'O'` is considered **captured** if it is completely surrounded by `'X'`.

### Task:

Convert all **captured `'O'` → `'X'`**, while keeping boundary-connected `'O'` unchanged.

---

## 🧪 Example

```id="ex2"
Input:
grid = [
  ['X','X','X','X'],
  ['X','O','O','X'],
  ['X','X','O','X'],
  ['X','O','X','X']
]

Output:
[
  ['X','X','X','X'],
  ['X','X','X','X'],
  ['X','X','X','X'],
  ['X','O','X','X']
]
```

---

## 🧠 Problem Understanding

* We need to convert only those `'O'` which are:

  * **Not connected to boundary**
* Any `'O'` connected to boundary (directly or indirectly) is **safe**

---

## 💡 Intuition

Instead of finding surrounded regions directly ❌
👉 We **reverse the thinking**:

> “Find all `'O'` that should NOT be converted”

### 🔥 Key Idea:

* Start from **boundary `'O'`**
* Mark all reachable `'O'` as **safe**

---

## 🐢 Brute Force Approach

### Idea:

* For every `'O'`, check if it is surrounded by `'X'`
* Perform DFS/BFS for each cell

### ❌ Problems:

* Repeated traversal
* High redundancy

### ⏱️ Complexity:

* Time: **O((r × c)²)**
* Space: **O(r × c)**

---

## ⚡ Better Approach

### Idea:

* Use a **visited array**
* Run DFS/BFS from boundary `'O'`

### Steps:

1. Traverse boundary
2. Mark connected `'O'` using visited[][]
3. Flip unvisited `'O'`

### ⏱️ Complexity:

* Time: **O(r × c)**
* Space: **O(r × c)**

---

## 🚀 Optimal Approach (BFS without extra space)

### 🔥 Key Idea:

Use grid itself to mark visited:

👉 `'O' → 'T'` (temporary safe mark)

---

## 🪜 Steps

1. Traverse **boundary cells**
2. For every `'O'` on boundary:

   * Push into queue
   * Mark `'T'`
3. Run BFS:

   * Mark all connected `'O' → 'T'`
4. Traverse grid:

   * `'O' → 'X'` (captured)
   * `'T' → 'O'` (restore safe)

---

## ✅ Code

```cpp id="code1"
class Solution {
  public:
  
    int r,c;
    int row[4] = {-1,0,1,0};
    int col[4] = {0,1,0,-1};
    
    bool valid(int i ,int j ){
        return i>=0 && j>=0 && i<r && j<c;
    }
    
    void fill(vector<vector<char>>& grid) {
        
        r = grid.size();
        c = grid[0].size();
        
        queue<pair<int,int>> q;
        
        // Top row
        for(int i=0;i<c;i++){
            if(grid[0][i]=='O'){
                q.push({0,i});
                grid[0][i]='T';
            }
        }
        
        // Bottom row
        for(int i=0;i<c;i++){
            if(grid[r-1][i]=='O'){
                q.push({r-1,i});
                grid[r-1][i]='T';
            }
        }
        
        // Left column
        for(int i=0;i<r;i++){
            if(grid[i][0]=='O'){
                q.push({i,0});
                grid[i][0]='T';
            }
        }
        
        // Right column
        for(int i=0;i<r;i++){
            if(grid[i][c-1]=='O'){
                q.push({i,c-1});
                grid[i][c-1]='T';
            }
        }
        
        // BFS traversal
        while(!q.empty()){
            auto [ni,nj] = q.front();
            q.pop();
            
            for(int k=0;k<4;k++){
                int x = ni + row[k];
                int y = nj + col[k];
                
                if(valid(x,y) && grid[x][y]=='O'){
                    grid[x][y]='T';
                    q.push({x,y});
                }
            }
        }
        
        // Final conversion
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='T') grid[i][j]='O';
                else grid[i][j]='X';
            }
        }
    }
};
```

---

## ⏱️ Complexity Analysis

| Type  | Complexity                         |
| ----- | ---------------------------------- |
| Time  | **O(r × c)**                       |
| Space | **O(r × c)** (queue in worst case) |

👉 Each cell is processed at most once.

---

## 🎯 Key Takeaways

* Think in reverse → **protect safe cells first**
* Boundary traversal is critical
* BFS/DFS = flood fill pattern
* No need for extra visited array

---

## ⚠️ Important Notes

* Use **4 directions only**
* Diagonal (8-direction) will give wrong result
* Always mark visited immediately

---

## 🔥 Interview Insight

If asked:

> Why start from boundary?

👉 Answer:

> “Because only boundary-connected regions are safe; the rest must be captured.”

---

## 🚀 Tags

`BFS` `Matrix` `Graph` `Flood Fill` `Boundary Traversal`
