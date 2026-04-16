# 📚 Allocate Minimum Number of Pages

## 📌 Problem Statement

You are given an array `arr[]` where each element represents number of pages in a book.

You have `k` students.

👉 Allocate books such that:

* Each student gets **at least one book**
* Books assigned are **contiguous**
* Minimize the **maximum pages assigned to a student**

---

# 🧪 Examples (START HERE FIRST)

### Example 1

```text id="ex1"
arr = [12, 34, 67, 90], k = 2
```

Possible splits:

```text id="ex2"
[12,34,67] | [90] → max = 113
[12,34]    | [67,90] → max = 157
[12]       | [34,67,90] → max = 191
```

👉 Answer = **113**

---

### Example 2

```text id="ex3"
arr = [10,20,30,40], k = 2
```

```text id="ex4"
[10,20,30] | [40] → max = 60 ✅
```

---

# 🧠 Core Idea (REMEMBER THIS)

👉 We are NOT dividing books directly

👉 We are checking:

```text id="core1"
Can we assign books so that no student gets more than X pages?
```

---

# 🔥 Pattern

```text id="pattern"
Minimize maximum → Binary Search on Answer
```

---

# 🧠 Approach 1: Brute Force

Try all values from:

```text id="range1"
max(arr) → sum(arr)
```

Check for each.

⏱️ **Time:** `O(n * range)` ❌

---

# 🧠 Approach 2: Binary Search (Optimal)

---

## ⚙️ Search Space

```text id="range2"
start = max(arr)
end = sum(arr)
```

---

## 🧠 Feasibility Check (`possible()`)

👉 Simulate allocation:

* Start with 1 student
* Keep adding books
* If adding a book exceeds limit → assign new student

---

## 🔍 Logic

```cpp id="logic"
if(pages + arr[i] <= mid){
    pages += arr[i];
} else {
    students++;
    pages = arr[i];
}
```

---

## 🎯 Key Condition

```cpp id="cond"
return students <= k;
```

---

## 🧠 Why `students <= k`?

* `students` = required students for given `mid`
* `k` = available students

👉 If:

```text id="cond2"
required ≤ available → possible
```

---

# ⚙️ Binary Search Flow

| Condition            | Move               |
| -------------------- | ------------------ |
| possible(mid) = true | go left (minimize) |
| false                | go right           |

---

# 💻 Code (C++)

```cpp id="code"
class Solution {
  public:
   bool possible(int k, int mid, vector<int> &arr){
        int students = 1;
        int pages = 0;

        for(int i = 0; i < arr.size(); i++){
            if(pages + arr[i] <= mid){
                pages += arr[i];
            } else {
                students++;
                pages = arr[i];
            }
        }

        return students <= k;
    }
    
    int findPages(vector<int> &arr, int k) {
        if(k > arr.size()) return -1;

        int start = *max_element(arr.begin(), arr.end());
        int end = accumulate(arr.begin(), arr.end(), 0LL);
        int ans = -1;

        while(start <= end){
            int mid = start + (end - start) / 2;

            if(possible(k, mid, arr)){
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

# 🧪 Quick Dry Run

```text id="dry1"
arr = [10,20,30,40], k = 2
mid = 60
```

Allocation:

```text id="dry2"
[10,20,30] | [40]
students = 2 ≤ k → valid
```

---

# 🚀 Memory Hooks (REVISION BOOST)

### 🔥 1 Line Trigger

```text id="mem1"
Can we distribute with max X pages?
```

---

### 🔥 Pattern Recognition

* Contiguous allocation
* Minimize maximum
* Partition problem

👉 **Binary Search on Answer**

---

### 🔥 Final Shortcut

```text id="mem2"
If required ≤ available → possible
```

---

# ⚠️ Common Mistakes

❌ Using `>= mid` instead of checking before adding
❌ Forgetting `k > n` case
❌ Using `0` in accumulate → overflow

---

# 🎯 Final Takeaway

👉 Don’t assign books directly
👉 Convert into **feasibility check + binary search**

---
