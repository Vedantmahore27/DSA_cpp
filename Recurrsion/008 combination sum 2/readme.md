# 40. Combination Sum II

## Problem

Given a collection of candidate numbers (`candidates`) and a target number (`target`), find all **unique combinations** in `candidates` where the candidate numbers sum to `target`.

### Rules

* Each number in `candidates` **may only be used once** in the combination.
* The solution set **must not contain duplicate combinations**.

---

# Approach 1 — Pick / Not Pick (Using Set to Remove Duplicates)

### Idea

This approach is similar to **Combination Sum I recursion pattern**.

At every index we have two choices:

1. **Pick the element**

   * Add it to the current combination.
   * Reduce the target.
   * Move to the next index (`ind + 1`) because elements can only be used once.

2. **Not Pick the element**

   * Skip the current element.
   * Move to the next index.

Since duplicate combinations can appear, we insert results into a **set** to remove duplicates.

---

### Algorithm

1. Sort the array.
2. Recursively try pick and not pick.
3. If `target == 0`, store the combination.
4. After recursion, insert results into a set to remove duplicates.

---

### Code

```cpp
class Solution {
public:
    void solve(int ind, int target , int n ,vector<int> ans, vector<int>& candidates , vector<vector<int>> &result  ){
        
        if(ind==n){
            if(target==0){
                result.push_back(ans);
            }
            return;
        }

        if(candidates[ind] <= target){
            ans.push_back(candidates[ind]);
            solve(ind+1,target-candidates[ind],n ,ans,candidates,result);
            ans.pop_back();
        }
            
        solve(ind+1,target,n ,ans,candidates,result);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> result;
        vector<int> ans;

        solve(0,target,n,ans,candidates,result);

        set<vector<int>> st;
        st.insert(result.begin(),result.end());

        result.assign(st.begin(),st.end());

        return result;
    }
};
```

---

### Complexity

Time Complexity

```
O(2^n * log(k))
```

* `2^n` recursion states
* `log(k)` due to set insertion

Space Complexity

```
O(2^n)
```

---

# Approach 2 — Backtracking with For Loop (Optimal)

### Idea

Instead of generating duplicates and removing them later, we **skip duplicates during recursion itself**.

Key condition:

```
if(i > ind && candidates[i] == candidates[i-1]) continue;
```

Meaning:

* If the current element is same as previous element **at the same recursion level**, skip it.

Also:

```
solve(i+1, target - candidates[i])
```

Because each element can only be used **once**.

---

### Algorithm

1. Sort the array.
2. Start recursion from index `0`.
3. Use a loop from `ind → n`.
4. Skip duplicates using `if(i > ind && candidates[i] == candidates[i-1])`.
5. Pick the element and recurse with `i+1`.
6. Backtrack.

---

### Code

```cpp
class Solution {
public:
    void solve(int n,int ind , int target ,
               vector<int>& candidates,
               vector<int>& ans,
               vector<vector<int>>& finial){
     
        if(target == 0){
            finial.push_back(ans);
            return;
        }

        for(int i = ind; i < n; i++){

            if(i > ind && candidates[i] == candidates[i-1]) continue;

            if(candidates[i] > target) break;

            ans.push_back(candidates[i]);

            solve(n, i+1, target - candidates[i], candidates, ans, finial);

            ans.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        int n = candidates.size();
        vector<int> ans;
        vector<vector<int>> finial;

        sort(candidates.begin(), candidates.end());

        solve(n,0,target,candidates,ans,finial);

        return finial;
    }
};
```

---

# Key Difference Between Both Approaches

| Feature                 | Approach 1      | Approach 2                       |
| ----------------------- | --------------- | -------------------------------- |
| Recursion Style         | Pick / Not Pick | For Loop Backtracking            |
| Duplicate Handling      | Using `set`     | Skip duplicates during recursion |
| Performance             | Slower          | Faster                           |
| Preferred in Interviews | ❌ Usually not   | ✅ Yes                            |

---

# Important Observations

### Why sorting is required?

Sorting helps to:

* Detect duplicates easily
* Break early when `candidate > target`

---

### Why `i+1`?

Because each number can be **used only once**.

---

# Final Recommendation

The **For-Loop Backtracking approach** is the **optimal and interview-preferred solution** because:

* Avoids duplicate generation
* Uses pruning
* Faster than the set-based solution

---

⭐ **Difficulty:** Medium
⭐ **Pattern:** Backtracking / Recursion
⭐ **Related Problems:**

* Combination Sum
* Subsets II
* Permutations II
