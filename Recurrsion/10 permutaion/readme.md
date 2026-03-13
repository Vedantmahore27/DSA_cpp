# Permutations (LeetCode 46)

## 🧩 Problem

Given an array `nums` of **distinct integers**, return all the possible **permutations**.

A permutation is an arrangement of elements in a **different order**.

---

## Example

Input

```text
nums = [1,2,3]
```

Output

```text
[1,2,3]
[1,3,2]
[2,1,3]
[2,3,1]
[3,1,2]
[3,2,1]
```

Total permutations:

```text
n!
```

For `n = 3`

```text
3! = 6
```

---

# 🧠 Key Idea

Permutation means:

```text
Every element must appear exactly once
Every ordering must be generated
```

At each position we choose **one unused element**.

---

# Approach 1 — Backtracking using `used[]` Array

## Idea

We maintain:

* `res` → current permutation
* `used[]` → marks which element is already used

When an element is used in the permutation, we **mark it** so it cannot be selected again.

---

## Algorithm

1. Start with empty permutation.
2. Loop through all elements.
3. If an element is not used:

   * mark it used
   * add it to permutation
   * recurse
4. Backtrack:

   * remove element
   * mark it unused

---

## Code

```cpp
class Solution {
public:

    void solve(int n, int i,
               vector<int> &nums,
               vector<int> &res,
               vector<int> &used,
               vector<vector<int>> &finial)
    {
        if(i == n){
            finial.push_back(res);
            return;
        }

        for(int ind = 0; ind < n; ind++)
        {
            if(used[ind] == 1) continue;

            used[ind] = 1;

            res.push_back(nums[ind]);

            solve(n, i+1, nums, res, used, finial);

            res.pop_back();

            used[ind] = 0;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        int n = nums.size();

        vector<int> res;
        vector<vector<int>> finial;
        vector<int> used(n,0);

        solve(n,0,nums,res,used,finial);

        return finial;
    }
};
```

---

## Recursion Tree (Example)

For:

```text
nums = [1,2,3]
```

```
[]
├──1
│  ├──2
│  │  └──3
│  └──3
│     └──2
├──2
│  ├──1
│  │  └──3
│  └──3
│     └──1
└──3
   ├──1
   │  └──2
   └──2
      └──1
```

---

## Complexity

Time Complexity

```
O(n!)
```

Space Complexity

```
O(n)
```

(extra `used` array + recursion stack)

---

# Approach 2 — Optimal Swap Method (In-place)

## Idea

Instead of tracking used elements, we **fix one position at a time**.

For position `i`, we try placing **every element from `i → n-1`**.

We do this by **swapping elements**.

---

## Algorithm

1. Fix the current index `i`.
2. Swap it with every element from `i → n-1`.
3. Recurse for the next index.
4. Swap back (backtracking).

---

## Code

```cpp
class Solution {
public:

    void solve(int i, vector<int>& nums, vector<vector<int>>& res)
    {
        if(i == nums.size())
        {
            res.push_back(nums);
            return;
        }

        for(int j = i; j < nums.size(); j++)
        {
            swap(nums[i], nums[j]);

            solve(i+1, nums, res);

            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> res;

        solve(0, nums, res);

        return res;
    }
};
```

---

## Example

Input

```
[1,2,3]
```

Fix position `0`:

```
swap(0,0) → [1,2,3]
swap(0,1) → [2,1,3]
swap(0,2) → [3,2,1]
```

Then recursively fix next positions.

---

## Complexity

Time Complexity

```
O(n!)
```

Space Complexity

```
O(1) extra
```

(only recursion stack)

---

# Comparison

| Approach    | Idea                   | Extra Space | Code Complexity |
| ----------- | ---------------------- | ----------- | --------------- |
| Used Array  | Track used elements    | O(n)        | Medium          |
| Swap Method | Fix positions via swap | O(1)        | Easy            |

---

# ⭐ Interview Insight

Permutation problems generally follow two templates:

### Template 1 — Used Array

```
choose unused element
recurse
backtrack
```

### Template 2 — Swap Method

```
swap
recurse
swap back
```

Most interviewers prefer the **swap method** because it is **in-place and cleaner**.

---

# 🔑 Key Takeaways

* Permutations generate **n! combinations**
* Backtracking is required
* Two main patterns exist:

  * `used[]` tracking
  * `swap` based recursion
* Swap method is **space optimal and interview friendly**
