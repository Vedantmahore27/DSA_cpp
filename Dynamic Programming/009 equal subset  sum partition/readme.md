# ⚖️ Equal Sum Partition (Partition Equal Subset Sum)

---

## 📌 Problem Statement

Given an array of positive integers `arr`, determine whether it can be partitioned into **two subsets such that the sum of elements in both subsets is equal**.

---

## 🎯 What the Problem is Asking

We need to check:

```text
Can we divide the array into 2 parts with equal sum?
```

👉 That means:

```text
Total Sum = S

We need:
Subset1 sum = S/2  
Subset2 sum = S/2
```

---

## ⚠️ Important Observation

If:

```text
S is odd → ❌ NOT possible
```

Because equal partition requires:

```text
S = 2 × (subset sum)
```

---

## 📌 Examples

### Example 1

```text
Input: arr = [1, 5, 11, 5]
Total sum = 22

Target = 22 / 2 = 11

Output: true
Explanation:
Subset1 → [11]
Subset2 → [1, 5, 5]
```

---

### Example 2

```text
Input: arr = [1, 2, 3, 5]
Total sum = 11 (odd)

Output: false
```

---

## 🧠 Identify the Pattern (VERY IMPORTANT)

Ask yourself:

```text
Can I find a subset with given sum?
```

👉 YES → This is **Subset Sum Problem**

---

## 🔗 Problem Reduction

```text
Equal Partition Problem
        ↓
Subset Sum Problem
        ↓
Find subset with sum = total_sum / 2
```

---

## 💡 Intuition

Instead of splitting into two subsets:

👉 Just check:

```text
Is there a subset with sum = S/2 ?
```

If yes:

* Remaining elements automatically form the other subset

---

## 🧩 Workflow (Step-by-Step Thinking)

1. Calculate total sum `S`
2. If `S % 2 != 0` → return false
3. Set target = `S / 2`
4. Solve subset sum problem for target

---

## ⚙️ DP Approach (Tabulation)

### 🔹 State Definition

```text
dp[i][j] = can we form sum j using first i elements?
```

---

### 🔹 Base Cases

```text
dp[0][j] = false   → no elements → can't form sum
dp[i][0] = true    → sum 0 always possible
```

---

### 🔹 Transition

```text
If arr[i-1] <= j:

dp[i][j] = dp[i-1][j] 
        OR dp[i-1][j - arr[i-1]]

Else:

dp[i][j] = dp[i-1][j]
```

---

## 💻 Code (Tabulation)

```cpp
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        bool dp[n+1][sum+1];
        
        for(int j = 0; j <= sum; j++)
            dp[0][j] = false;
        
        for(int i = 0; i <= n; i++)
            dp[i][0] = true;
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= sum; j++){
                
                if(arr[i-1] <= j)
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][sum];
    }
    
    bool canPartition(vector<int>& arr) {
        int total = 0;
        for(int x : arr) total += x;
        
        if(total % 2 != 0) return false;
        
        return isSubsetSum(arr, total / 2);
    }
};
```

---

## ⏱️ Complexity Analysis

### Time Complexity

```text
O(n × target) = O(n × sum)
```

---

### Space Complexity

```text
O(n × sum)
```

---

## 🚀 Space Optimization (1D DP)

```cpp
bool canPartition(vector<int>& arr) {
    int sum = 0;
    for(int x : arr) sum += x;
    
    if(sum % 2 != 0) return false;
    
    int target = sum / 2;
    bool dp[target+1];
    
    dp[0] = true;
    for(int j = 1; j <= target; j++) dp[j] = false;
    
    for(int i = 0; i < arr.size(); i++){
        for(int j = target; j >= arr[i]; j--){
            dp[j] = dp[j] || dp[j - arr[i]];
        }
    }
    
    return dp[target];
}
```

---

## 🧠 Key Takeaways

* Convert problem → **Subset Sum**
* Always check:

  ```text
  total % 2 == 0
  ```
* State:

  ```text
  dp[i][j]
  ```
* Transition:

  ```text
  pick / not pick
  ```
* 1D DP optimization is highly important for interviews

---

## 🔥 Final Insight

This problem is a **direct application of 0/1 Knapsack pattern**.

If you master this, you unlock:

* Partition problems
* Target sum
* Minimum subset difference

---

## 📚 Conclusion

Equal Sum Partition is not a new problem — it's just a **clever transformation of Subset Sum**.

👉 Once you recognize the pattern, the solution becomes straightforward.

---
