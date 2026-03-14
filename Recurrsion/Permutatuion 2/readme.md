# Permutations II (Unique Permutations)

## Problem

Given a collection of numbers that might contain duplicates, return **all possible unique permutations**.

Example:

Input

```
nums = [1,1,2]
```

Output

```
[
 [1,1,2],
 [1,2,1],
 [2,1,1]
]
```

---

# Approach 1 — Brute Force + Set

### Idea

1. Generate all permutations using recursion.
2. Store them in a vector.
3. Insert them into a `set` to remove duplicates.
4. Convert the set back to a vector.

### Code

```cpp
class Solution {
public:

    void solve(int n,int i,vector<int>& nums,vector<int>& used,
               vector<int>& res,vector<vector<int>>& finial){

        if(i==n){
            finial.push_back(res);
            return;
        }

        for(int ind=0;ind<n;ind++){

            if(used[ind]==1) continue;

            used[ind]=1;
            res.push_back(nums[ind]);

            solve(n,i+1,nums,used,res,finial);

            res.pop_back();
            used[ind]=0;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        int n=nums.size();

        vector<vector<int>> finial;
        vector<int> res;
        vector<int> used(n,0);

        solve(n,0,nums,used,res,finial);

        set<vector<int>> st(finial.begin(),finial.end());

        finial.assign(st.begin(),st.end());

        return finial;
    }
};
```

### Time Complexity

Permutation generation:

```
O(n! * n)
```

Set insertion:

```
O(n! * n log(n!))
```

Overall:

```
O(n! * n log(n!))
```

### Space Complexity

```
O(n! * n)
```

---

# Approach 2 — Optimized (Skip Duplicates)

### Idea

1. Sort the array.
2. Use a `used[]` array to track elements used in the current permutation.
3. Skip duplicates during recursion.

Important condition:

```
if(i > 0 && nums[i] == nums[i-1] && !used[i-1])
    continue;
```

This ensures duplicate elements do not start the same recursion branch.

### Code

```cpp
class Solution {
public:

    void solve(vector<int>& nums, vector<int>& used,
               vector<int>& res, vector<vector<int>>& ans){

        if(res.size()==nums.size()){
            ans.push_back(res);
            return;
        }

        for(int i=0;i<nums.size();i++){

            if(used[i]) continue;

            if(i>0 && nums[i]==nums[i-1] && !used[i-1])
                continue;

            used[i]=1;
            res.push_back(nums[i]);

            solve(nums,used,res,ans);

            res.pop_back();
            used[i]=0;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums){

        sort(nums.begin(),nums.end());

        vector<vector<int>> ans;
        vector<int> res;
        vector<int> used(nums.size(),0);

        solve(nums,used,res,ans);

        return ans;
    }
};
```

### Time Complexity

```
O(n! * n)
```

### Space Complexity

```
O(n! * n)
```

---

# Why Simple Swap Approach is Not Directly Applicable

The basic permutation algorithm uses swapping:

```
swap(nums[ind], nums[i])
```

Example:

```
[1,1,2]
```

Recursion tree:

```
Level 0
 ├── swap(0,0) → [1,1,2]
 ├── swap(0,1) → [1,1,2]  (duplicate branch)
 └── swap(0,2) → [2,1,1]
```

Notice:

```
swap(0,0) and swap(0,1)
produce the same array
```

This means **duplicate permutations are generated**.

Example results:

```
1 1 2
1 2 1
1 1 2   ← duplicate
1 2 1   ← duplicate
2 1 1
2 1 1   ← duplicate
```

So swap alone **cannot prevent duplicates**.

To fix it we must:

* use a `set`
* or track visited elements at each level

Because of this complexity, the **used-array + skip condition approach is preferred**.

---

# Conclusion

Best approach for this problem:

```
Sort array + used[] + skip duplicates
```

Advantages:

* Avoids generating duplicate permutations
* No extra `set` required
* Time complexity improves

Final complexity:

```
Time:  O(n! * n)
Space: O(n! * n)
```
