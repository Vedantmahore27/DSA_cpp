# 🚀 Asteroid Collision (Stack)

## 📌 Problem

You are given an integer array `asteroids`.

- Positive value → moving right ➡️  
- Negative value → moving left ⬅️  

### 💥 Collision Rules:
- Collision occurs only when a right-moving asteroid meets a left-moving asteroid
- Smaller asteroid explodes
- If both are equal → both explode
- Remaining asteroids continue moving

---

## 🧾 Examples

### Example 1
Input:
[5, 10, -5]

Output:
[5, 10]

Explanation:
10 and -5 collide → 10 survives

---

### Example 2
Input:
[8, -8]

Output:
[]

Explanation:
Equal size → both destroyed

---

### Example 3
Input:
[10, 2, -5]

Output:
[10]

Explanation:
2 vs -5 → 2 destroyed  
10 vs -5 → 10 survives  

---

## 🧠 Intuition

### 🔑 Who Collides?

Collision happens only when:

previous > 0 AND current < 0

Reason:
- Right-moving meets left-moving → collision
- Same direction → no collision

---

## 💡 Why Stack?

We need to:
- Compare current asteroid with **previous surviving ones**
- Only the **latest active asteroid matters**

👉 Stack gives:
- Last-in access (top)
- Efficient collision handling

---

## 🧠 Mental Model

Stack = "alive asteroids so far"

For each asteroid:
1. Check collision with stack top
2. Resolve until stable
3. Push if it survives

---

## ⚙️ Approach

1. Traverse array
2. For each asteroid:
   - While collision possible:
     - If stack top < current → pop
     - If equal → pop and stop
     - If stack top > current → current destroyed
3. If current survives → push to stack
4. Return stack

---

## 🧑‍💻 Code

```cpp
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;

        for (int x : asteroids) {
            bool destroyed = false;

            while (!st.empty() && st.back() > 0 && x < 0) {
                if (st.back() < abs(x)) {
                    st.pop_back();
                } 
                else if (st.back() == abs(x)) {
                    st.pop_back();
                    destroyed = true;
                    break;
                } 
                else {
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed) {
                st.push_back(x);
            }
        }

        return st;
    }
};
