# 🎯 Target Sum (LeetCode 494)

---

## 📌 Problem Statement

Given an array of integers `nums` and an integer `target`,
assign either `'+'` or `'-'` sign to each number such that:

```text id="t4b0i1"
sum of all signed numbers = target
```

👉 Return the **number of ways** to achieve this.

---

## 🎯 What the Problem is Asking

```text id="tq1y6g"
For each element:
+nums[i] or -nums[i]

Count total expressions whose result = target
```

---

## 📌 Example

### Example 1

```text id="0a7vpx"
Input: nums = [1,1,1,1,1], target = 3  
Output: 5
```

### Explanation:

```text id="q0n6t6"
+1 +1 +1 +1 -1 = 3  
+1 +1 +1 -1 +1 = 3  
+1 +1 -1 +1 +1 = 3  
+1 -1 +1 +1 +1 = 3  
-1 +1 +1 +1 +1 = 3  
```

---

## 🧠 Problem Transformation (KEY IDEA)

Let:

```text id="u8fx8j"
Positive subset sum = S1  
Negative subset sum = S2
```

Then:

```text id="d5m0qz"
S1 - S2 = target  
S1 + S2 = total sum
```

---

## ➕ Add both equations:

```text id="m8tq4c"
2 * S1 = total + target
```

👉 So:

```text id="g0i2k1"
S1 = (total + target) / 2
```

---

## 🔑 Final Problem

```text id="9n6zjz"
Count number of subsets with sum = (total + target) / 2
```

---

## ⚠️ Important Conditions

```text id="l1d9ya"
If (total + target) is odd → return 0  
If abs(target) > total → return 0
```

---

## 🧠 Identify Pattern

```text id="3h8a9o"
Subset Sum + Counting
```

👉 Same as:

```text id="w6e7tf"
Perfect Sum / Count Partitions
```

---

## 💡 Intuition

At each number:

```text id="r7t6pl"
1. Add it (+) → goes to S1
2. Subtract it (-) → goes to S2
```

👉 Equivalent to selecting subset with sum = S1

---

## ⚙️ DP Approach (Tabulation)

---

## 🧩 State Definition

```text id="f2h4mb"
dp[i][j] = number of ways to form sum j using first i elements
```

---

## 🧱 Base Cases

```text id="9h3g2n"
dp[0][0] = 1  
dp[0][j>0] = 0
```

---

## 🔄 Transition

```text id="q8r4y1"
if(nums[i-1] <= j)
    dp[i][j] = dp[i-1][j - nums[i-1]] + dp[i-1][j]
else
    dp[i][j] = dp[i-1][j]
```

---

## 💻 Code (2D DP)

```cpp id="y7k1vn"
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for(int x : nums) total += x;

        if((total + target) % 2 != 0 || abs(target) > total) return 0;

        int s1 = (total + target) / 2;
        int n = nums.size();

        vector<vector<int>> dp(n+1, vector<int>(s1+1, 0));

        dp[0][0] = 1;

        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= s1; j++){
                
                if(nums[i-1] <= j){
                    dp[i][j] = dp[i-1][j - nums[i-1]] + dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][s1];
    }
};
```

---

## 🚀 Space Optimization (1D DP)

```cpp id="p4n7kq"
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for(int x : nums) total += x;

        if((total + target) % 2 != 0 || abs(target) > total) return 0;

        int s1 = (total + target) / 2;

        vector<int> dp(s1+1, 0);
        dp[0] = 1;

        for(int num : nums){
            for(int j = s1; j >= num; j--){
                dp[j] += dp[j - num];
            }
        }

        return dp[s1];
    }
};
```

---

## ⚠️ Special Case: Zeros

If `nums` contains `0`:

```text id="8o0g3f"
Each zero doubles the number of ways
```

👉 DP automatically handles it:

```text id="3j8u6p"
dp[j] += dp[j]
```

---

## ⏱️ Complexity Analysis

### Time Complexity

```text id="p2l4m6"
O(n × s1)
```

---

### Space Complexity

```text id="l5g3z8"
2D → O(n × s1)  
1D → O(s1)
```

---

## 🧠 Key Takeaways

* Convert sign assignment → subset sum
* Use:

  ```text
  (total + target) / 2
  ```
* Counting → use `+`
* Boolean → use `||`

---

## 🔥 Final Insight

> “Target Sum is not about signs — it's about splitting numbers into two groups.”

---

## 📚 Conclusion

Target Sum is a classic DP problem that reduces to subset sum with counting. Mastering this helps solve:


---
