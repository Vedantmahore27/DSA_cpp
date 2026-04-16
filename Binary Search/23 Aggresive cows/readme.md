# 🐄 Aggressive Cows

## 📌 Problem Statement

You are given positions of `n` stalls and `k` cows.

👉 Place the cows in stalls such that the **minimum distance between any two cows is maximized**.

Return that maximum minimum distance.

---

# 🧪 Examples (START HERE FIRST)

### Example 1

```text
stalls = [1,2,4,8,9], k = 3
```

Possible placement:

```text
[1, 4, 8]
```

Distances:

```text
3, 4 → minimum = 3
```

👉 Answer = **3**

---

### Example 2

```text
stalls = [10,1,2,7,5], k = 3
```

After sorting:

```text
[1,2,5,7,10]
```

Best placement:

```text
[1,5,10]
```

👉 Answer = **4**

---

# 🧠 Core Idea (REMEMBER THIS)

👉 We are NOT placing cows directly
👉 We are checking:

```text
Can we place k cows with at least X distance?
```

---

# 🔥 Pattern

```text
maximize minimum distance
→ Binary Search on Answer
```

---

# 🧠 Approach 1: Brute Force

## 💡 Idea

Try all distances from:

```text
1 → max(stall) - min(stall)
```

For each distance:

* Check if we can place cows

---

## ⏱️ Complexity

* `O(n * range)` ❌ Too slow

---

# 🧠 Approach 2: Better (Binary Search)

## 💡 Idea

Instead of checking all distances, use **Binary Search** on distance.

---

## ⚙️ Search Space

```text
start = 1
end = stalls[n-1] - stalls[0]
```

---

## 🧠 Feasibility Check

Greedy placement:

* Place first cow at first stall
* Place next cow only if:

```text
current_position - last_position >= mid
```

---

# ⚙️ Binary Search Logic

| Condition            | Move               |
| -------------------- | ------------------ |
| possible(mid) = true | try bigger → right |
| false                | reduce → left      |

---

# 🚀 Approach 3: Optimal

## 💻 Code (C++)

```cpp
class Solution {
public:
    bool possible(int k, int mid, vector<int> &stalls){
        int position = stalls[0];
        int cow = 1;

        for(int i = 0; i < stalls.size(); i++){
            if(stalls[i] - position >= mid){
                cow++;
                position = stalls[i];
            }
        }

        return cow >= k;
    }

    int aggressiveCows(vector<int> &stalls, int k) {

        sort(stalls.begin(), stalls.end());

        int start = 1;
        int end = stalls[stalls.size() - 1] - stalls[0];
        int ans = -1;

        while(start <= end){
            int mid = start + (end - start) / 2;

            if(possible(k, mid, stalls)){
                ans = mid;
                start = mid + 1; // maximize distance
            } else {
                end = mid - 1;
            }
        }

        return ans;
    }
};
```

---

# ⏱️ Complexity

* **Time:** `O(n log range)`
* **Space:** `O(1)`

---

# ⚠️ Important Points

* Always **sort stalls first**
* Greedy placement works because:

  * placing earlier gives more space for next cows
* We maximize → move right when valid

---

# 🧠 Dry Run (Quick)

```text
stalls = [1,2,4,8,9], k = 3
```

Try mid = 3:

* Place at 1
* Next at 4
* Next at 8 ✅

👉 possible → try bigger

---

# 🚀 Memory Hooks (REVISION BOOST)

### 🔥 1 Line Trigger:

```text
Can we place cows with at least X distance?
```

---

### 🔥 Pattern Recognition:

* Maximize minimum
* Placement problem
* Sorted positions

👉 **Binary Search on Answer**

---

### 🔥 Final Shortcut:

```text
If possible(mid) → go right
Else → go left
```

---

# 🎯 Final Takeaway

👉 Don’t try to place optimally directly
👉 Convert problem into **feasibility check + binary search**

---
