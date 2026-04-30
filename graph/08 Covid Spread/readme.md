# 🏥 Helpaterp (Rotten Oranges) - GFG

## 🔴 Problem

Given a grid `hospital[][]` of size `r x c`:

* `0` → Empty cell
* `1` → Fresh patient
* `2` → Infected patient

Every minute, an infected patient spreads infection to its **adjacent (up, down, left, right)** fresh patients.

👉 Return the **minimum time required** to infect all patients.
👉 If impossible, return `-1`.

---

## 🧪 Example

```
Input:
hospital = [
  [2,1,0],
  [1,1,0],
  [0,1,1]
]

Output:
4
```

---

## 🧠 Problem Understanding

* Infection spreads **level by level**
* Each level in BFS = **1 unit time**
* Multiple infected sources → **multi-source BFS**
* We must:

  * Spread infection
  * Track time
  * Ensure no fresh patient remains

---

## 💡 Intuition

This is not a DFS problem.

👉 Why BFS?

Because infection spreads **simultaneously in all directions**, like waves.

So:

* Push all infected cells into queue initially
* Process neighbors level by level
* Each level = **1 minute**

---

## 🐢 Brute Force Approach

### Idea:

* For every minute, scan the entire grid
* Convert fresh cells if adjacent to infected

### Steps:

1. Traverse grid repeatedly
2. Check neighbors manually
3. Update grid each iteration

### ❌ Problems:

* Too many redundant traversals

### ⏱️ Complexity:

* Time: **O((r × c)²)**
* Space: **O(1)**

---

## ⚡ Better Approach

### Idea:

* Start BFS from **each infected cell separately**

### ❌ Problem:

* Repeated BFS → inefficient

### ⏱️ Complexity:

* Time: **O((r × c) × (r × c))**
* Space: **O(r × c)**

---

## 🚀 Optimal Approach (Multi-Source BFS)

### 🔥 Key Idea:

Push **all infected cells at once** into queue.

### Steps:

1. Traverse grid:

   * Add all `2`s to queue
   * Count fresh patients

2. Run BFS:

   * For each level:

     * Process all nodes in queue
     * Infect neighbors
     * Push newly infected

3. Increment time after each level

4. If fresh > 0 → return `-1`

---

## ✅ Code

```cpp
class Solution {
  public:
    int row[4] = {-1,1,0,0};
    int col[4] = {0,0,1,-1};
    
    int r,c;
    
    bool valid(int i,int j){
        return i>=0 && j>=0 && i<r && j<c;
    }
    
    int helpaterp(vector<vector<int>> hospital) {
       r = hospital.size();
       c = hospital[0].size();
       
       queue<pair<int,int>> q;
       int fresh = 0;
       
       for(int i=0;i<r;i++){
           for(int j=0;j<c;j++){
              if(hospital[i][j]==2) q.push({i,j});
              else if(hospital[i][j]==1) fresh++;
           }
       }
       
       if(fresh == 0) return 0;
       
       int timer = 0;
       
       while(!q.empty()){
           int size = q.size();
           
           while(size--){
               auto [i,j] = q.front();
               q.pop();
               
               for(int k=0;k<4;k++){
                   int ni = i + row[k];
                   int nj = j + col[k];
                   
                   if(valid(ni,nj) && hospital[ni][nj]==1){
                       hospital[ni][nj] = 2;
                       q.push({ni,nj});
                       fresh--;
                   }
               }
           }
           
           timer++;
       }
       
       if(fresh > 0) return -1;
       
       return timer - 1;
    }
};
```

---

## ⏱️ Complexity Analysis

| Type  | Complexity   |
| ----- | ------------ |
| Time  | **O(r × c)** |
| Space | **O(r × c)** |

👉 Each cell is visited at most once.

---

## 🎯 Key Takeaways

* Multi-source BFS is the **core concept**
* Each BFS level = **time unit**
* Avoid revisiting → mark immediately
* Use direction arrays for clean traversal

---

## 🔥 Interview Insight

If asked:

> Why BFS and not DFS?

👉 Answer:

> “Because infection spreads simultaneously, and BFS naturally models minimum time level-by-level.”

---

## 🚀 Tags

`BFS` `Matrix` `Graph` `Multi-source BFS` `Queue`
