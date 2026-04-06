# 🔍 Smallest Divisor Given a Threshold (LeetCode)

---

## 🧩 Problem Statement

Given an integer array `nums` and an integer `threshold`, find the **smallest divisor** such that:

[
\sum \lceil \frac{nums[i]}{divisor} \rceil \leq threshold
]

Each result of division is rounded up to the nearest integer.

---

## 📊 Example

```
Input:
nums = [1,2,5,9]
threshold = 6

Output:
5
```

### 🔎 Explanation

For divisor = 5:

```
ceil(1/5) = 1
ceil(2/5) = 1
ceil(5/5) = 1
ceil(9/5) = 2

Sum = 5 ≤ 6 ✅
```

Try smaller divisor (like 4):

```
ceil(1/4)=1
ceil(2/4)=1
ceil(5/4)=2
ceil(9/4)=3

Sum = 7 > 6 ❌
```

👉 So smallest valid divisor = **5**

---

## 📌 Constraints

* `1 ≤ nums.length ≤ 5 * 10^4`
* `1 ≤ nums[i] ≤ 10^6`
* `nums.length ≤ threshold ≤ 10^6`

---

## 💡 Intuition

* We need to **minimize the divisor**
* For every divisor, we compute a sum

### 🔥 Key Observation

* As **divisor increases → sum decreases**
* This is **monotonic behavior**

👉 This hints towards **Binary Search on Answer**

---

## 🐢 Brute Force Approach

### Idea:

* Try every divisor from `1` to `max(nums)`
* Compute sum for each

### Time Complexity:

```
O(n * max(nums))
```

👉 Very slow (TLE for large inputs)

---

## ⚡ Better Approach (Binary Search on Answer)

### Search Space:

```
1 → max(nums)
```

### Why max(nums)?

If:

```
divisor ≥ max(nums)
```

Then:

```
ceil(num / divisor) = 1 for all elements
⇒ sum = n (constant)
```

👉 So beyond this point, answer doesn’t change

---

## 🚀 Optimal Approach

### Steps:

1. Apply Binary Search on `[1, max(nums)]`
2. For each `mid`:

   * Compute sum:

     ```
     ceil(num / mid)
     ```
3. If sum ≤ threshold:

   * Store answer
   * Try smaller divisor
4. Else:

   * Increase divisor

---

## ⚡ Optimization Trick

Instead of:

```cpp
ceil((double)num / mid)
```

Use:

```cpp
(num + mid - 1) / mid
```

👉 Avoids floating point operations

---

## 💻 Code (Optimal)

```cpp
class Solution {
public:
    bool possible(vector<int>& nums, int mid, int threshold) {
        long long sum = 0;
        
        for (auto num : nums) {
            sum += (num + mid - 1) / mid;
            
            if (sum > threshold) return false;
        }
        
        return true;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int start = 1;
        int end = *max_element(nums.begin(), nums.end());
        int ans = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (possible(nums, mid, threshold)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }
};
```

---

## ⏱ Complexity Analysis

### Time Complexity:

```
O(n * log(max(nums)))
```

### Space Complexity:

```
O(1)
```

---

## 🧠 Key Takeaways

* Binary Search works when condition is **monotonic**
* Always **tighten search space**
* Avoid floating point in interviews
* Use **early exit** for optimization

---

## 🏁 Final Thought

👉 This is a classic **Binary Search on Answer** problem
👉 Focus on recognizing monotonic patterns — that's the real skill 🚀
