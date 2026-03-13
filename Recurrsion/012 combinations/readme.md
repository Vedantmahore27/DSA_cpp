# Combinations

## Problem

Given two integers **n** and **k**, return all possible combinations of **k numbers chosen from the range [1, n]**.

You may return the answer in **any order**.

### Example

**Input**

```
n = 4, k = 2
```

**Output**

```
[1,2]
[1,3]
[1,4]
[2,3]
[2,4]
[3,4]
```

---

# Approach 1 – Basic Backtracking (My Solution)

Idea:

1. Create a vector `nums` containing numbers from **1 to n**.
2. Use recursion to build combinations.
3. At each step:
   - Pick the current element
   - Move to the next index
   - Backtrack

### Code

```cpp
class Solution {
public:
    void solve(int n ,int i ,int k,vector<int> ans,vector<int> &nums ,vector<vector<int>> &finial){
        if(ans.size()==k){
            finial.push_back(ans);
            return;
        }

        for(int ind=i; ind<n; ind++){
            ans.push_back(nums[ind]);
            solve(n , ind+1 , k, ans, nums , finial);
            ans.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>> finial;
        vector<int> nums;

        for(int i=0;i<n;i++){
            nums.push_back(i+1);
        }

        vector<int> ans;

        solve(n,0,k,ans,nums,finial);

        return finial;
    }
};
```

### Time Complexity

```
O(C(n,k) * k)
```

Because we generate all possible combinations.

### Space Complexity

```
O(k)
```

Recursion depth is at most **k**.

---

# Approach 2 – Optimal Backtracking with Pruning

The optimal solution avoids exploring **unnecessary recursion branches**.

Key observation:

If we already picked some numbers and there are **not enough remaining numbers to complete k elements**, that branch should not be explored.

### Important Condition

```
i ≤ n - (k - ans.size()) + 1
```

This ensures that **enough numbers remain to complete the combination**.

### Code

```cpp
class Solution {
public:

    void solve(int start, int n, int k, vector<int> &ans, vector<vector<int>> &res){

        if(ans.size() == k){
            res.push_back(ans);
            return;
        }

        for(int i = start; i <= n - (k - ans.size()) + 1; i++){
            ans.push_back(i);
            solve(i + 1, n, k, ans, res);
            ans.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>> res;
        vector<int> ans;

        solve(1, n, k, ans, res);

        return res;
    }
};
```

---

# Why the Loop is Not Until `n` in Optimal Solution

In the basic solution the loop runs until `n`, which means recursion also explores **invalid branches**.

Example:

```
n = 5
k = 3
current ans = [4]
```

We still need **2 more numbers**, but only **one number (5)** remains.

So combinations like:

```
[4,5]
```

cannot reach size **3**, but recursion still explores them.

This is unnecessary work.

---

# Pruning Idea

Remaining numbers needed:

```
k - ans.size()
```

Remaining numbers available from index `i`:

```
n - i + 1
```

Valid recursion requires:

```
remaining ≥ needed
```

Rearranging gives:

```
i ≤ n - (k - ans.size()) + 1
```

This condition **stops recursion early** when it is impossible to form a valid combination.

---

# Why Larger Loop Is Still Acceptable

If the loop runs until `n`, the algorithm will **still produce correct results**.

However:

- It explores **extra recursion branches**
- Time complexity becomes larger in practice
- Many invalid paths are checked

The pruning condition simply **reduces unnecessary recursion calls**, making the algorithm more efficient.

---

# Key Concepts

- Recursion
- Backtracking
- Pruning
- Combinatorics

---

# Similar Problems

- Subsets
- Combination Sum
- Generate Parentheses
- Letter Case Permutation
