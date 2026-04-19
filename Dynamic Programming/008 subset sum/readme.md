# 🧩 Subset Sum Problem (Dynamic Programming)

## 📌 Problem Statement

Given an array of integers `arr` and a target sum `sum`, determine whether there exists a subset of the given array whose sum is equal to the given target.

---

## 🧠 Approach

We solve this problem using **Dynamic Programming (Tabulation)**.

### 💡 Idea:

Define a DP table:

```
dp[i][j] = true/false
```

Where:

* `i` → number of elements considered (0 to n)
* `j` → target sum (0 to sum)

👉 Meaning:

> Can we form sum `j` using first `i` elements?

---

## ⚙️ Transition

For each element:

* **Pick the element** → reduce sum
* **Don't pick the element** → keep sum

```
if(arr[i-1] <= j)
    dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]]
else
    dp[i][j] = dp[i-1][j]
```

---

## 🧱 Base Cases

```
dp[0][j] = false  → no elements → can't form positive sum
dp[i][0] = true   → sum = 0 always possible (empty subset)
```

---

## 💻 Code (Tabulation)

```cpp
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        bool dp[n+1][sum+1];
       
        // Base cases
        for(int j = 0; j <= sum; j++){
            dp[0][j] = false;
        }
        
        for(int i = 0; i <= n; i++){
            dp[i][0] = true;
        }
        
        // Fill DP table
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= sum; j++){
                
                if(arr[i-1] <= j){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][sum];
    }
};
```

---

## ⏱️ Complexity

### Time Complexity:

```
O(n × sum)
```

### Space Complexity:

```
O(n × sum)
```

---

## 🚀 Space Optimization (1D DP)

We can optimize space using a single array:

```cpp
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        bool dp[sum+1];
        
        dp[0] = true;
        for(int j = 1; j <= sum; j++) dp[j] = false;
        
        for(int i = 0; i < n; i++){
            for(int j = sum; j >= arr[i]; j--){
                dp[j] = dp[j] || dp[j - arr[i]];
            }
        }
        
        return dp[sum];
    }
};
```

---

## ⚠️ Important Note

👉 In 1D DP, iterate **from right to left**:

```
for(j = sum → arr[i])
```

This ensures each element is used **only once** (0/1 constraint).

---

## 🎯 Key Takeaways

* This is a **classic DP problem**
* Forms the base of:

  * 0/1 Knapsack
  * Partition Equal Subset Sum
  * Target Sum
* Always remember:

  * State → `dp[i][j]`
  * Transition → pick / not pick

---

## 📚 Conclusion

The Subset Sum problem is a fundamental problem in Dynamic Programming that helps build intuition for more advanced problems. Mastering this pattern makes many DP problems easier to solve.

---
