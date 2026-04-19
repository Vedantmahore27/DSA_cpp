# 🔢 Count Number of Subsets with Given Sum (Perfect Sum Problem)

---

## 📌 Problem Statement

Given an array of non-negative integers `arr` and an integer `target`,
find the **number of subsets** whose sum is equal to `target`.

---

## 🎯 What the Problem is Asking

```text
Count how many subsets exist such that:
sum of subset = target
```

👉 Unlike subset sum (boolean), here we need **COUNT**, not just existence.

---

## 📌 Examples

### Example 1

```text
Input: arr = [2, 3, 5, 6, 8, 10], target = 10  
Output: 3

Subsets:
[2,3,5]
[2,8]
[10]
```

---

### Example 2 (with zero)

```text
Input: arr = [0, 0, 1], target = 1  
Output: 4

Subsets:
[1]
[0,1]
[0,1]
[0,0,1]
```

👉 Zeros increase combinations!

---

## 🧠 Identify the Pattern

Ask:

```text
Can I form a target using subset?
```

👉 YES → This is **Subset Sum Pattern**

But instead of:

```text
true / false
```

We need:

```text
count of ways
```

---

## 🔗 Problem Type

```text
0/1 Knapsack (Count variant)
```

---

## 💡 Intuition

At each element:

```text
1. pick it → reduce target
2. skip it → keep target
```

So:

```text
total ways = pick + not pick
```

---

## ⚙️ DP Approach (Tabulation)

---

## 🧩 State Definition

```text
dp[i][j] = number of ways to make sum j using first i elements
```

---

## 🧱 Base Cases

```text
dp[0][0] = 1     → empty subset
dp[0][j>0] = 0   → no elements → can't form sum
```

---

## 🔄 Transition

```text
if(arr[i-1] <= j)
    dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j]
else
    dp[i][j] = dp[i-1][j]
```

---

## ⚠️ Special Case: Zeros

```text
If arr[i-1] == 0:

dp[i][j] = dp[i-1][j] + dp[i-1][j]
         = 2 × dp[i-1][j]
```

👉 Zero doubles number of subsets

---

## 💻 Code (Tabulation)

```cpp
class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        int dp[1001][1001];

        // base cases
        for(int j = 0; j <= target; j++)
            dp[0][j] = 0;

        dp[0][0] = 1;

        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= target; j++){

                if(arr[i-1] <= j){
                    dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][target];
    }
};
```

---

## ⏱️ Complexity Analysis

### Time Complexity

```text
O(n × target)
```

---

### Space Complexity

```text
O(n × target)
```

---

## 🚀 Space Optimization (1D DP)

```cpp
class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        int dp[target+1];

        dp[0] = 1;

        for(int i = 0; i < n; i++){
            for(int j = target; j >= 0; j--){
                if(arr[i] <= j){
                    dp[j] += dp[j - arr[i]];
                }
            }
        }

        return dp[target];
    }
};
```

---

## 🧠 Important Concepts

### 🔹 Difference from Subset Sum

```text
Subset Sum → OR (true/false)
Perfect Sum → + (count)
```

---

### 🔹 Why start from j = 0?

```text
dp[i][0] = base state → required for all transitions
```

---

### 🔹 Why iterate backward in 1D DP?

```text
to avoid using same element multiple times
```

---

## 🎯 Key Takeaways

* This is **subset sum + counting**
* Always:

  ```text
  OR → +
  ```
* Zero elements:

  ```text
  multiply count
  ```
* DP state:

  ```text
  dp[i][j]
  ```

---

## 🔥 Final Insight

> “Every element gives two choices — count all valid combinations.”

---

## 📚 Conclusion

The Perfect Sum problem is a classic DP problem that builds directly on subset sum logic. Mastering this unlocks many advanced DP problems like:


---
