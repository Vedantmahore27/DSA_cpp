# 🍌 Koko Eating Bananas (Binary Search on Answer)

## 🧾 Problem Statement

Koko loves to eat bananas. There are `n` piles of bananas, where the `i-th` pile has `piles[i]` bananas.

Koko can decide her eating speed `k` (bananas per hour). Each hour, she chooses a pile and eats up to `k` bananas from that pile.

* If the pile has less than `k` bananas, she eats all of them.
* Koko wants to finish eating all the bananas within `h` hours.

### 🔍 Task

Return the **minimum integer `k`** such that she can eat all bananas within `h` hours.

---

## 📌 Example

### Example 1:

```
Input: piles = [3,6,7,11], h = 8
Output: 4
```

### Explanation:

* Speed = 4 bananas/hour
* Hours required:

  * 3 → 1 hour
  * 6 → 2 hours
  * 7 → 2 hours
  * 11 → 3 hours
* Total = 8 hours ✅

---

### Example 2:

```
Input: piles = [30,11,23,4,20], h = 5
Output: 30
```

---

## 🧠 Intuition

This problem is a classic example of **Binary Search on Answer**.

### 💡 Key Idea:

* We are not searching for an element.
* We are searching for the **minimum valid eating speed `k`**.

---

### 🔎 Observations:

* Minimum possible speed = `1`
* Maximum possible speed = `max(piles)`

👉 So the answer lies in range:

```
[1, max(piles)]
```

---

### 🚀 Strategy:

1. Apply **Binary Search** on `k`
2. For each `k`, check:

   * Can Koko finish all bananas within `h` hours?
3. If yes → try smaller `k`
4. If no → increase `k`

---

## ⚙️ Helper Logic

To calculate hours needed for a pile:

```
ceil(pile / k)
```

Instead of using floating point:

```
(pile + k - 1) / k
```

👉 This avoids precision issues and is faster.

---

## 💻 Code (C++)

```cpp
class Solution {
public:
    bool check(int k, int h, vector<int>& piles) {
        long long hr = 0;

        for (int i = 0; i < piles.size(); i++) {
            hr += (piles[i] + k - 1) / k;
        }

        return hr <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());
        int ans = end;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (check(mid, h, piles)) {
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

## ⏱️ Time Complexity

### 🔹 Binary Search

* Range: `1 → max(piles)`
* Steps: `O(log M)` where `M = max(piles)`

### 🔹 Check Function

* Iterates through all piles → `O(n)`

---

### ✅ Total Time Complexity:

```
O(n * log M)
```

---

## 🧮 Space Complexity

* No extra space used (only variables)

### ✅ Space Complexity:

```
O(1)
```

---

## 🧠 Key Takeaways

* This is a **Binary Search on Answer** problem
* Avoid floating point when possible
* Use integer trick for ceiling:

  ```
  (a + b - 1) / b
  ```
* Always think:

  > “Can I binary search the answer space?”

---

## 🚀 Similar Problems

* Capacity To Ship Packages Within D Days
* Allocate Minimum Number of Pages
* Split Array Largest Sum

---

## ⭐ Final Thought

Whenever:

* Answer lies in a **range**
* And you can **validate a candidate**

👉 Think **Binary Search on Answer** 🔥

---
