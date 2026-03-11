# Baseball Game

**LeetCode Problem:** 682
**Difficulty:** Easy
**Pattern:** Stack / Simulation

---

# Problem Statement

You are keeping score for a baseball game with strange rules.

The game consists of several rounds where the **score of each round is recorded in a list of operations**.

Each operation can be one of the following:

| Operation   | Meaning                                                           |
| ----------- | ----------------------------------------------------------------- |
| Integer `x` | Record a new score of `x`                                         |
| `"+"`       | Record a new score that is the **sum of the previous two scores** |
| `"D"`       | Record a new score that is **double the previous score**          |
| `"C"`       | **Invalidate the previous score**                                 |

Return the **sum of all valid scores**.

---

# Example

### Example 1

Input

```
operations = ["5","2","C","D","+"]
```

Output

```
30
```

### Explanation

| Operation | Stack     | Explanation            |
| --------- | --------- | ---------------------- |
| 5         | [5]       | push 5                 |
| 2         | [5,2]     | push 2                 |
| C         | [5]       | remove last score      |
| D         | [5,10]    | double previous score  |
| +         | [5,10,15] | sum of last two scores |

Total Score

```
5 + 10 + 15 = 30
```

---

# Intuition

We need to keep track of **previous scores** because some operations depend on them.

A **stack** is ideal for this because:

* `"C"` removes the last score → `pop()`
* `"D"` doubles the last score → `top() * 2`
* `"+"` needs the **last two scores**

So we simulate the game using a **stack of integers**.

---

# Approach

1. Create a stack to store valid scores.
2. Traverse through the operations list.
3. Perform actions based on the operation:

   * If integer → push into stack
   * `"C"` → remove last score
   * `"D"` → push `2 * last score`
   * `"+"` → push sum of last two scores
4. At the end, sum all elements in the stack.

---

# Algorithm

1. Initialize an empty stack `st`.
2. Iterate through each operation.
3. Perform required stack operation.
4. Sum all values in stack.
5. Return the total score.

---

# Time Complexity

```
O(n)
```

Each operation is processed once.

---

# Space Complexity

```
O(n)
```

Stack stores valid scores.

---

# C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        
        stack<int> st;

        for(string op : operations){

            if(op == "C"){
                st.pop();
            }

            else if(op == "D"){
                st.push(2 * st.top());
            }

            else if(op == "+"){
                int top1 = st.top();
                st.pop();
                int top2 = st.top();
                st.push(top1);
                st.push(top1 + top2);
            }

            else{
                st.push(stoi(op));
            }
        }

        int sum = 0;

        while(!st.empty()){
            sum += st.top();
            st.pop();
        }

        return sum;
    }
};
```

---

# Key Concepts

* Stack Data Structure
* Simulation Problems
* Handling Multiple Operations
* String to Integer Conversion (`stoi`)

---

# Edge Cases

* `"C"` always has a valid previous score.
* `"D"` and `"+"` always have enough previous scores.
* Operations list is guaranteed to be valid.

---

# Related Problems

* Valid Parentheses
* Next Greater Element
* Daily Temperatures

All of these problems involve **stack-based logic**.

---

# Tags

```
Stack
Array
Simulation
```

---

# Author

Vedant Mahore
DSA Practice – Interview Preparation
