# ⚖️ Minimum Subset Sum Difference

---

## 📌 Problem Statement

Given an array of integers `nums`, partition it into **two subsets** such that the **absolute difference of their sums is minimized**.

---

## 🎯 What the Problem is Asking

```text
Split array into two subsets S1 and S2 such that:
|sum(S1) - sum(S2)| is minimum
```

---

## 📌 Example

### Example 1

```text
Input: nums = [1, 6, 11, 5]
Output: 1

Explanation:
Subset1 = [1, 5, 6] → sum = 12  
Subset2 = [11]     → sum = 11  
Difference = 1
```

---

## 🧠 Problem Transformation

Let:

```text
Total Sum = S
Subset1 = s1
Subset2 = s2
```

We know:

```text
s1 + s2 = S
```

So:

```text
Difference = |s1 - s2|
           = |S - 2*s1|
```

---

## 🔑 Key Idea

👉 Instead of dividing directly, we:

```text
Find subset sum s1 such that:
s1 is as close as possible to S/2
```

---

## 🧠 Identify the Pattern

Ask:

```text
Can we form a subset with sum = j ?
```

👉 YES → **Subset Sum Problem**

---

## 🔗 Problem Type

```text
0/1 Knapsack Pattern (Boolean DP)
```

---

## 💡 Intuition

At each element:

```text
1. Pick → include in subset
2. Not pick → exclude
```

We track all possible subset sums.

---

## ⚙️ DP Approach (Tabulation)

---

## 🧩 State Definition

```text
dp[i][j] = true if we can form sum j using first i elements
```

---

## 🧱 Base Cases

```text
dp[0][0] = true        → empty subset
dp[0][j>0] = false     → no elements → no sum
```

---

## 🔄 Transition

```text
if(nums[i-1] <= j)
    dp[i][j] = dp[i-1][j] OR dp[i-1][j - nums[i-1]]
else
    dp[i][j] = dp[i-1][j]
```

---

## 💻 Code (2D DP)

```cpp
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<bool>> dp(n+1, vector<bool>(total+1, false));

        dp[0][0] = true;

        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= total; j++){
                
                if(nums[i-1] <= j){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i-1]];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        int mini = INT_MAX;

        for(int j = 0; j <= total/2; j++){
            if(dp[n][j]){
                mini = min(mini, total - 2*j);
            }
        }

        return mini;
    }
};
```

---

## 🚀 Space Optimization (1D DP)

```cpp
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        vector<bool> dp(total+1, false);
        dp[0] = true;

        for(int num : nums){
            for(int j = total; j >= num; j--){
                dp[j] = dp[j] || dp[j - num];
            }
        }

        int mini = INT_MAX;

        for(int j = 0; j <= total/2; j++){
            if(dp[j]){
                mini = min(mini, total - 2*j);
            }
        }

        return mini;
    }
};
```

---

## ⏱️ Complexity Analysis

### Time Complexity

```text
O(n × total)
```

---

### Space Complexity

```text
2D → O(n × total)  
1D → O(total)
```

---

## ⚠️ When This Approach Fails

If:

```text
total sum is very large (10^6 or more)
```

👉 DP becomes infeasible

---

## 🚀 Alternative Approaches

| Case               | Approach           |
| ------------------ | ------------------ |
| small sum          | DP (above)         |
| large sum, small n | Meet-in-the-Middle |
| moderate           | 1D DP              |

---

## 🧠 Key Takeaways

* Convert problem → subset sum
* Focus on:

  ```text
  minimize |S - 2*s1|
  ```
* Only check till:

  ```text
  total/2
  ```
* Use:

  ```text
  OR for boolean DP
  ```

---

## 🔥 Final Insight

> “This problem is not about splitting — it's about finding a subset closest to half of the total sum.”

---

## 📚 Conclusion

Minimum Subset Sum Difference is a classic DP problem derived from subset sum. Mastering this builds strong intuition for:

* Partition problems
* Knapsack variations
* Optimization problems

---
