# 📚 Validate Stack Sequences (LeetCode)

## 🧾 Problem Statement

Given two integer arrays `pushed` and `popped`, both with distinct values:

* `pushed` represents the order in which elements are pushed onto a stack.
* `popped` represents the order in which elements are popped from the stack.

---

### 🎯 Goal:

Return `true` if the given `popped` sequence is valid, otherwise return `false`.

---

## 🧪 Examples

### Example 1:

```id="ex1"
Input:
pushed = [1,2,3,4,5]
popped = [4,5,3,2,1]

Output:
true
```

### 🧠 Explanation:

Stack simulation:

* Push 1 → [1]
* Push 2 → [1,2]
* Push 3 → [1,2,3]
* Push 4 → [1,2,3,4] → Pop 4
* Push 5 → [1,2,3,5] → Pop 5
* Pop 3 → Pop 2 → Pop 1

👉 Valid sequence ✅

---

### Example 2:

```id="ex2"
Input:
pushed = [1,2,3,4,5]
popped = [4,3,5,1,2]

Output:
false
```

### 🧠 Explanation:

At some point:

* You need to pop `1` before `2`, but `2` is above `1` in stack

👉 Impossible ❌

---

## 💡 Intuition

### 🔥 Core Idea:

We simulate the stack process.

👉 Always:

* Push elements from `pushed`
* Whenever top matches `popped[j]`, pop it

---

### 🧠 Key Observation:

> If at any moment we cannot match the required pop sequence, the answer is **false**

---

## ⚡ Step-by-Step Approach

### 1. Initialize:

* Stack `st`
* Pointer `j = 0` (for `popped`)

---

### 2. Iterate over `pushed`:

```cpp id="step2"
for each element in pushed:
    push into stack
```

---

### 3. While top matches popped:

```cpp id="step3"
while stack not empty AND st.top() == popped[j]:
    pop
    j++
```

---

### 4. Final Check:

* If stack is empty → valid
* Else → invalid

---

## 🧠 Dry Run

```id="dry"
pushed = [1,2,3]
popped = [2,1,3]
```

Steps:

* Push 1 → [1]
* Push 2 → [1,2] → Pop 2
* Pop 1
* Push 3 → Pop 3

👉 Stack empty → valid ✅

---

## ❌ Common Mistakes

* Trying to compare arrays directly ❌
* Not simulating stack operations ❌
* Missing `while` loop (important!) ❌
* Forgetting to increment pointer `j` ❌

---

## ✅ C++ Code

```cpp id="code"
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j = 0;

        for(int i = 0; i < pushed.size(); i++){
            st.push(pushed[i]);

            while(!st.empty() && st.top() == popped[j]){
                st.pop();
                j++;
            }
        }

        return st.empty();
    }
};
```

---

## 🚀 Complexity Analysis

| Operation        | Complexity |
| ---------------- | ---------- |
| Traversal        | O(n)       |
| Stack Operations | O(n)       |
| Space            | O(n)       |

---

## 🧠 Key Takeaways

* This is a **simulation problem**
* Stack is used to mimic real push/pop behavior
* The `while` loop is critical 🔥
* Order matters more than values

---

## 🎯 Pattern Recognition

This problem teaches:

* Stack simulation
* Order validation
* Push-pop dependency

---

## 🏁 Final Thought

> “If you can simulate the process correctly, the answer reveals itself.”

---

🔥 Master this → you’ll unlock many stack problems like:

* Next Greater Element
* Daily Temperatures
* Car Fleet

---
