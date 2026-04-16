# 🔍 Kth Missing Positive Number

## 📌 Problem Statement

Given a **sorted strictly increasing array** `arr` and an integer `k`, return the **kth missing positive number**.

---

# 🧪 Examples (START HERE FIRST)

### Example 1

```text
arr = [2,3,4,7,11], k = 5
```

Missing numbers:

```text
[1,5,6,8,9,10,...]
```

👉 5th missing = **9**

---

### Example 2

```text
arr = [1,2,3,4], k = 2
```

Missing numbers:

```text
[5,6,7,...]
```

👉 2nd missing = **6**

---

# 🧠 Core Idea (REMEMBER THIS)

👉 We are NOT searching a number
👉 We are searching **how many numbers are missing till an index**

---

# ⚡ Golden Formula (MUST REMEMBER)

```text
missing till index i = arr[i] - (i + 1)
```

### 🧠 Why?

| Concept        | Meaning             |
| -------------- | ------------------- |
| Expected value | `i + 1`             |
| Actual value   | `arr[i]`            |
| Missing        | `actual - expected` |

---

# 🔍 Visual Understanding

```text
arr = [2,3,4,7,11]

Index:   0  1  2  3  4
Value:   2  3  4  7 11
Expected:1  2  3  4  5
Missing: 1  1  1  3  6
```

👉 Missing count is increasing → perfect for **Binary Search**

---

# 🧠 What are we searching?

👉 First index where:

```text
missing >= k
```

---

# ⚙️ Binary Search Logic

### Step 1:

```cpp
missing = arr[mid] - (mid + 1);
```

### Step 2:

| Condition   | Move  |
| ----------- | ----- |
| missing < k | Right |
| missing ≥ k | Left  |

---

# 🎯 Final Answer (IMPORTANT)

```text
answer = start + k
```

## 🧠 Why this works?

* `start` → how many numbers already exist before answer
* `k` → how many missing we need

👉 Combine → actual missing number

---

# 🧪 Dry Run

### Input:

```text
arr = [2,3,4,7,11], k = 5
```

Binary search gives:

```text
start = 4
```

Final:

```text
answer = 4 + 5 = 9 ✅
```

---

# 💻 Code (C++)

```cpp
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int start = 0, end = arr.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            int missing = arr[mid] - (mid + 1);

            if (missing < k) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return start + k;
    }
};
```

---

# 🚀 Memory Hooks (REVISION BOOST)

### 🔥 1 Line Trigger:

```text
missing = actual - expected
```

---

### 🔥 Pattern Recognition:

* Sorted array
* Missing elements
* Increasing gap

👉 **Binary Search on Answer**

---

### 🔥 Final Shortcut:

```text
Find first index where missing ≥ k → return start + k
```

---

# ⚠️ Common Mistakes

❌ Writing:

```cpp
arr[mid] - mid + 1
```

✅ Correct:

```cpp
arr[mid] - (mid + 1)
```

---

# 🧠 When to Use This Pattern?

Use this approach when:

* Array is sorted
* You are dealing with **missing numbers**
* Missing count follows a pattern

---

# 🎯 Final Takeaway

👉 Don’t search the number
👉 Search **m
