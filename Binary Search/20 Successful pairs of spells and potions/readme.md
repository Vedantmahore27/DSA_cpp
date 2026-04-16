# 🧪 Successful Pairs of Spells and Potions (Without STL)

## 📌 Problem Statement

You are given two arrays:

* `spells[]` → power of spells
* `potions[]` → strength of potions

And an integer `success`.

A pair `(spell, potion)` is **successful** if:

```text id="eq1"
spell * potion >= success
```

Return an array where each index `i` contains the number of potions that form a successful pair with `spells[i]`.

---

## 🧠 Intuition

For each spell, we need to find:

> The **first potion index** such that
> `spell * potion >= success`

Since `potions` is sorted, we can apply **Binary Search** to efficiently find this index.

---

## ⚙️ Approach (Manual Binary Search)

1. Sort the `potions` array
2. For each spell:

   * Perform binary search on `potions`
   * Find the **leftmost index (`possi`)** where:

     ```
     spell * potions[mid] >= success
     ```
   * If found:

     ```
     count = m - possi
     ```
   * Else:

     ```
     count = 0
     ```

---

## 💻 Code (C++)

```cpp id="code1"
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();

        sort(potions.begin(), potions.end()); // sorting required

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            int start = 0, end = m - 1;
            int possi = m; // default (no valid index)

            while (start <= end) {
                int mid = start + (end - start) / 2;

                if (1LL * spells[i] * potions[mid] >= success) {
                    possi = mid;
                    end = mid - 1; // search left for first occurrence
                } else {
                    start = mid + 1;
                }
            }

            ans.push_back(m - possi);
        }

        return ans;
    }
};
```

---

## 📐 Key Observation

Instead of directly checking:

```text id="obs1"
spell * potion >= success
```

We are effectively finding the **first valid potion index** using binary search.

---

## ⚠️ Important Points

* Initialize `possi = m` → means no valid potion found
* Use `1LL *` to prevent integer overflow
* Always search for **leftmost valid index**

---

## ⏱️ Complexity Analysis

* **Time Complexity:**

  * Sorting → `O(m log m)`
  * Binary search for each spell → `O(n log m)`
    👉 Overall: `O(n log m + m log m)`

* **Space Complexity:** `O(1)` (excluding output)

---

## 🧪 Example

### Input

```text id="ex1"
spells = [5,1,3]
potions = [1,2,3,4,5]
success = 7
```

### Output

```text id="ex2"
[4,0,3]
```

---

## 🚀 Key Takeaways

* Binary Search can find the **first valid index efficiently**
* Sorting is essential for applying binary search
* Avoid STL like `lower_bound` by implementing manually
* Handle overflow carefully using `1LL`

---
