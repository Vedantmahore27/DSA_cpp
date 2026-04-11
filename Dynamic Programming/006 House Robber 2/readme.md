# House Robber II Problem (C++)

## 📌 Problem Statement

You are given an integer array `nums` where each element represents
money in a house.

All houses are arranged in a **circle**, meaning: - First house is
adjacent to last house

You cannot rob two adjacent houses.

Return the **maximum amount of money** you can rob.

------------------------------------------------------------------------

## 🔢 Example

Input:\
`nums = [2, 3, 2]`

Output:\
`3`

Explanation:\
You cannot rob both first and last house.

------------------------------------------------------------------------

# 🚀 Key Idea

👉 Since houses are in a circle: - Either you rob from **0 to n-2** - Or
you rob from **1 to n-1**

👉 Solve both as **House Robber I** and take max.

------------------------------------------------------------------------

# 🚀 C++ Approaches

------------------------------------------------------------------------

## 1️⃣ Helper Function (Linear House Robber)

``` cpp
int solve(vector<int>& nums, int start, int end) {
    int prev2 = 0, prev1 = 0;

    for (int i = start; i <= end; i++) {
        int curr = max(prev1, prev2 + nums[i]);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}
```

------------------------------------------------------------------------

## 2️⃣ Optimal Solution

``` cpp
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums, int start, int end) {
    int prev2 = 0, prev1 = 0;

    for (int i = start; i <= end; i++) {
        int curr = max(prev1, prev2 + nums[i]);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int rob(vector<int>& nums) {
    int n = nums.size();

    if (n == 1) return nums[0];

    int case1 = solve(nums, 0, n - 2); // exclude last
    int case2 = solve(nums, 1, n - 1); // exclude first

    return max(case1, case2);
}
```

------------------------------------------------------------------------

## ⏱ Complexity

-   Time: **O(n)**
-   Space: **O(1)**

------------------------------------------------------------------------

# 📊 Summary

  Case            Explanation
  --------------- -------------------
  Exclude last    Rob from 0 → n-2
  Exclude first   Rob from 1 → n-1
  Final Answer    max(case1, case2)

------------------------------------------------------------------------

# 🧠 Key Insight

👉 Circular dependency breaks DP\
👉 Convert into **two linear problems**

------------------------------------------------------------------------

# 🎯 Interview Tip

Say this:

"Since first and last are adjacent, we cannot take both. So we split
into two cases and solve using House Robber I."
