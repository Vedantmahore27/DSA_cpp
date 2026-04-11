# House Robber Problem (C++)

## 📌 Problem Statement

You are given an integer array `nums` where each element represents the
amount of money in a house.

You cannot rob two adjacent houses.

Return the **maximum amount of money** you can rob without alerting the
police.

------------------------------------------------------------------------

## 🔢 Example

Input:\
`nums = [2, 7, 9, 3, 1]`

Output:\
`12`

Explanation:\
Rob house 1 (2) + house 3 (9) + house 5 (1) = 12

------------------------------------------------------------------------

# 🚀 C++ Approaches

------------------------------------------------------------------------

## 1️⃣ Brute Force (Recursion)

### 💡 Idea

At each house, you have 2 choices: - Rob it → skip next house - Skip it
→ move to next house

### 🔁 Code

``` cpp
#include <bits/stdc++.h>
using namespace std;

int solve(int i, vector<int>& nums) {
    if (i >= nums.size()) return 0;

    int rob = nums[i] + solve(i + 2, nums);
    int skip = solve(i + 1, nums);

    return max(rob, skip);
}

int rob(vector<int>& nums) {
    return solve(0, nums);
}
```

### ⏱ Complexity

-   Time: **O(2\^n)**
-   Space: **O(n)**

------------------------------------------------------------------------

## 2️⃣ Memoization (Top-Down DP)

### 💡 Idea

Store results to avoid recomputation.

### 🔁 Code

``` cpp
#include <bits/stdc++.h>
using namespace std;

int solve(int i, vector<int>& nums, vector<int>& dp) {
    if (i >= nums.size()) return 0;

    if (dp[i] != -1) return dp[i];

    int rob = nums[i] + solve(i + 2, nums, dp);
    int skip = solve(i + 1, nums, dp);

    return dp[i] = max(rob, skip);
}

int rob(vector<int>& nums) {
    vector<int> dp(nums.size(), -1);
    return solve(0, nums, dp);
}
```

### ⏱ Complexity

-   Time: **O(n)**
-   Space: **O(n)**

------------------------------------------------------------------------

## 3️⃣ Tabulation (Bottom-Up DP)

### 💡 Idea

Build solution iteratively.

### 🔁 Code

``` cpp
#include <bits/stdc++.h>
using namespace std;

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];

    vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
    }

    return dp[n - 1];
}
```

### ⏱ Complexity

-   Time: **O(n)**
-   Space: **O(n)**

------------------------------------------------------------------------

## 4️⃣ Space Optimized

### 💡 Idea

Only last two values are needed.

### 🔁 Code

``` cpp
#include <bits/stdc++.h>
using namespace std;

int rob(vector<int>& nums) {
    int prev2 = 0;
    int prev1 = 0;

    for (int num : nums) {
        int curr = max(prev1, prev2 + num);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}
```

### ⏱ Complexity

-   Time: **O(n)**
-   Space: **O(1)**

------------------------------------------------------------------------

# 📊 Summary

  Approach      Time Complexity   Space Complexity
  ------------- ----------------- ------------------
  Recursion     O(2\^n)           O(n)
  Memoization   O(n)              O(n)
  Tabulation    O(n)              O(n)
  Optimized     O(n)              O(1)

------------------------------------------------------------------------

# 🧠 Key Insight

👉 At every house: - Either take it → add `nums[i] + dp[i-2]` - Or skip
it → take `dp[i-1]`

👉 So transition becomes: `dp[i] = max(dp[i-1], nums[i] + dp[i-2])`

------------------------------------------------------------------------

# 🎯 Interview Tip

Say this clearly:

"This is a classic pick/not-pick DP problem similar to Fibonacci, but
with a constraint of skipping adjacent elements."
