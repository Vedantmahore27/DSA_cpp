# 🧱 Min Stack

## 📌 Problem Statement

Design a stack that supports the following operations in **constant time**:

* `push(x)` → Push element `x` onto stack
* `pop()` → Removes the top element
* `top()` → Get the top element
* `getMin()` → Retrieve the minimum element in the stack

All operations must run in **O(1)** time.

---

# 🧠 Approach 1 — Brute Force

### Idea

Maintain a normal stack.
Whenever `getMin()` is called, traverse the entire stack and find the minimum element.

### Steps

1. Use a single stack.
2. Push elements normally.
3. For `getMin()` iterate through all elements and find the minimum.

### Complexity

| Operation | Time |
| --------- | ---- |
| push      | O(1) |
| pop       | O(1) |
| top       | O(1) |
| getMin    | O(N) |

### ❌ Drawback

`getMin()` is **linear time**, which violates the requirement.

---

### 💻 Brute Force Implementation

```cpp
class MinStack {
public:
    stack<int> st;

    void push(int val) {
        st.push(val);
    }

    void pop() {
        if(!st.empty())
            st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {

        stack<int> temp = st;
        int mn = INT_MAX;

        while(!temp.empty()){
            mn = min(mn, temp.top());
            temp.pop();
        }

        return mn;
    }
};
```

---

# ⚡ Approach 2 — Better (Two Stack Method)

### Idea

Maintain two stacks:

1. **Main stack** → stores elements
2. **Min stack** → stores minimum elements

When pushing:

* If the new value is **≤ current minimum**, push it into `minStack`.

When popping:

* If popped element equals `minStack.top()`, pop from `minStack` too.

---

### Example

```text
push(5)
stack = [5]
minStack = [5]

push(3)
stack = [5,3]
minStack = [5,3]

push(7)
stack = [5,3,7]
minStack = [5,3]
```

Minimum always remains at:

```
minStack.top()
```

---

### Complexity

| Operation | Time |
| --------- | ---- |
| push      | O(1) |
| pop       | O(1) |
| top       | O(1) |
| getMin    | O(1) |

Space:

```
O(N)
```

(extra stack)

---

### 💻 Better Implementation

```cpp
class MinStack {
public:
    stack<int> st;
    stack<int> minSt;

    void push(int val) {

        st.push(val);

        if(minSt.empty() || val <= minSt.top())
            minSt.push(val);
    }

    void pop() {

        if(st.top() == minSt.top())
            minSt.pop();

        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};
```

---

# 🚀 Approach 3 — Optimal (Best Solution)

### Idea

Use **only one stack** and store encoded values.

If a new element becomes the new minimum:

```
encoded_value = 2 * val - min
```

This allows us to recover the **previous minimum** during pop.

---

### Key Observations

If

```
stack.top() < min
```

then the value is **encoded**.

---

### Push Logic

```
if stack empty
    min = val
else if val < min
    push(2*val - min)
    min = val
else
    push(val)
```

---

### Pop Logic

If encoded value appears:

```
previousMin = 2*currentMin - encodedValue
```

---

### Complexity

| Operation | Time |
| --------- | ---- |
| push      | O(1) |
| pop       | O(1) |
| top       | O(1) |
| getMin    | O(1) |

Space:

```
O(N)
```

(no extra stack)

---

### 💻 Optimal Implementation

```cpp
class MinStack {
public:
    stack<long long> st;
    long long min_ele;

    MinStack() {}

    void push(int val) {

        if(st.empty()){
            min_ele = val;
            st.push(val);
        }
        else if(val < min_ele){
            st.push(2LL * val - min_ele);
            min_ele = val;
        }
        else{
            st.push(val);
        }
    }

    void pop() {

        if(st.top() < min_ele){
            min_ele = 2LL * min_ele - st.top();
        }

        st.pop();
    }

    int top() {

        if(st.top() < min_ele)
            return min_ele;

        return st.top();
    }

    int getMin() {
        return min_ele;
    }
};
```

---

# 📊 Approach Comparison

| Approach    | Time        | Space             | Notes                 |
| ----------- | ----------- | ----------------- | --------------------- |
| Brute Force | O(N) getMin | O(N)              | Not interview optimal |
| Better      | O(1)        | O(N) extra stack  | Most common solution  |
| Optimal     | O(1)        | O(N) single stack | Most efficient        |

---

# 🏆 Key Takeaway

The **Optimal Encoding Technique** avoids using an extra stack and still maintains **O(1)** operations for all stack functions.

This problem is a classic example of **space optimization using mathematical encoding**.

---
