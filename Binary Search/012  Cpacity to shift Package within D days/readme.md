# 🚢 Capacity To Ship Packages Within D Days

🔗 **LeetCode Link:** https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

---

## 🧾 Problem Statement

You are given an array `weights` where `weights[i]` represents the weight of the `i-th` package.

You are also given an integer `days`.

You must ship all packages within `days` days.

### 📦 Rules:

* Packages must be shipped **in order** (no rearranging).
* Each day, you load packages until reaching the ship’s capacity.
* You cannot exceed the ship's capacity in a single day.

---

## 🎯 Task

Return the **minimum ship capacity** required to ship all packages within `days`.

---

## 📌 Example

### Example 1:

```id="ex1"
Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
```

### Explanation:

* Day 1 → 1+2+3+4+5 = 15
* Day 2 → 6+7 = 13
* Day 3 → 8
* Day 4 → 9
* Day 5 → 10

---

### Example 2:

```id="ex2"
Input: weights = [3,2,2,4,1,4], days = 3
Output: 6
```

---

## 🧠 Intuition

This is a classic **Binary Search on Answer** problem.

👉 We are not searching for an index
👉 We are searching for the **minimum valid capacity**

---

### 🔍 Observations

* Minimum capacity = `max(weights)`
  (because we must carry the heaviest package)

* Maximum capacity = `sum(weights)`
  (carry everything in one day)

👉 So search space is:

```id="range"
[max(weights), sum(weights)]
```

---

## 🚀 Approach

1. Apply **Binary Search** on capacity
2. For each candidate capacity `mid`, check:

   * Can we ship all packages within `days`?

---

## ⚙️ Check Function Logic

* Start with `1` day
* Keep adding weights
* If adding a package exceeds capacity:

  * Move to next day
  * Reset current load

---

## 💻 Code (C++)

```cpp id="code"
class Solution {
public:
    bool check(int capacity, int days, vector<int>& weights) {
        int cnt = 1; // start with 1 day
        int sum = 0;

        for (int w : weights) {
            if (sum + w > capacity) {
                cnt++;       // new day
                sum = w;     // start new load
            } else {
                sum += w;
            }
        }

        return cnt <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int start = *max_element(weights.begin(), weights.end());
        int end = accumulate(weights.begin(), weights.end(), 0);
        int ans = end;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (check(mid, days, weights)) {
                ans = mid;
                end = mid - 1; // try smaller capacity
            } else {
                start = mid + 1; // increase capacity
            }
        }

        return ans;
    }
};
```

---

## ⏱️ Time Complexity

* Binary Search: `O(log(sum))`
* Check function: `O(n)`

### ✅ Total:

```id="tc"
O(n * log(sum(weights)))
```

---

## 🧮 Space Complexity

```id="sc"
O(1)
```

---

## 🧠 Key Takeaways

* Binary Search on Answer pattern
* Always define **valid search space**
* Greedy check function is key
* Maintain order of elements

---

## 🔥 Similar Problems

* 🍌 Koko Eating Bananas
* 📚 Allocate Minimum Number of Pages
* 📦 Split Array Largest Sum

---

## ⭐ Final Thought

Whenever:

* You need to **minimize/maximize something**
* And you can **validate a candidate**

👉 Think **Binary Search on Answer** 🚀

---
