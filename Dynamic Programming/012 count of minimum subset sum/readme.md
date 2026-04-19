# 🔢 Count Partitions with Given Difference

---

## 📌 Problem Statement

Given an array of non-negative integers `arr` and an integer `d`,
count the number of ways to partition the array into two subsets such that:

```text
|sum(S1) - sum(S2)| = d
```

---

## 🎯 What the Problem is Asking

We need to:

```text
Split array into two subsets S1 and S2
such that difference of their sums = d
```

👉 Return **number of such partitions**

---

## 📌 Example

```text
Input: arr = [1, 1, 2, 3], d = 1  
Output: 3
```

### Explanation:

Valid partitions:

```text
S1 = [1,1,2], S2 = [3]  
S1 = [1,3],   S2 = [1,2]  
S1 = [1,3],   S2 = [1,2]   (different arrangement)
```

---

## 🧠 Problem Transformation (VERY IMPORTANT)

Let:

```text
S1 = subset 1 sum  
S2 = subset 2 sum  
Total sum = S
```

We know:

```text
S1 + S2 = S
S1 - S2 = d
```

---

## ➕ Add both equations:

```text
2 * S1 = S + d
```

👉 So:

```text
S1 = (S + d) / 2
```

---

## 🔑 Final Problem

```text
Count number of subsets with sum = (S + d) / 2
```

---

## ⚠️ Important Conditions

```text
If (S + d) is odd → return 0  
If d > S → return 0
```

---

## 🧠 Identify Pattern

```text
Subset Sum + Counting
```

👉 Same as:

```text
Perfect Sum Problem
```

---

## 💡 Intuition

At each element:

```text
1. pick → include in subset
2. not pick → exclude
```

Total ways:

```text
ways = pick + not pick
```

---

## ⚙️ DP Approach (Tabulation)

---

## 🧩 State Definition

```text
dp[i][j] = number of ways to form sum j using first i elements
```

---

## 🧱 Base Cases

```text
dp[0][0] = 1     → empty subset  
dp[0][j>0] = 0   → cannot form positive sum  
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

## 💻 Code (2D DP)

```cpp
class Solution {
public:

    int count_subset(vector<int>& arr, int target){
        int n = arr.size();
        int dp[n+1][target+1];

        // base cases
        for(int j = 0; j <= target; j++){
            dp[0][j] = 0;
        }
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

    int countPartitions(vector<int>& arr, int d) {
        int sum = 0;
        for(int x : arr) sum += x;

        if((sum + d) % 2 != 0 || d > sum) return 0;

        int target = (sum + d) / 2;

        return count_subset(arr, target);
    }
};
```

---

## 🚀 Space Optimization (1D DP)

```cpp
class Solution {
public:
    int countPartitions(vector<int>& arr, int d) {
        int sum = 0;
        for(int x : arr) sum += x;

        if((sum + d) % 2 != 0 || d > sum) return 0;

        int target = (sum + d) / 2;

        vector<int> dp(target+1, 0);
        dp[0] = 1;

        for(int num : arr){
            for(int j = target; j >= num; j--){
                dp[j] += dp[j - num];
            }
        }

        return dp[target];
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
2D → O(n × target)  
1D → O(target)
```

---

## ⚠️ Special Case: Zeros

If array contains `0`:

```text
Each zero doubles number of subsets
```

👉 DP automatically handles it

---

## 🧠 Key Takeaways

* Convert partition → subset sum
* Use:

  ```text
  (sum + d) / 2
  ```
* Counting → use `+`
* Boolean → use `||`

---

## 🔥 Final Insight

> “Partition problems often reduce to subset sum — the trick is identifying the transformation.”

---

## 📚 Conclusion

This problem is a classic example of transforming a partition problem into a subset sum problem. Mastering this pattern helps solve:

* Target Sum
* Equal Partition
* Minimum Subset Difference

---
