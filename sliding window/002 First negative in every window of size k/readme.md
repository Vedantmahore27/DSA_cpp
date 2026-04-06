# 🔥 First Negative Integer in Every Window of Size K

## 🧩 Problem Statement
Given an array `arr[]` and an integer `k`, find the **first negative integer for every window of size k**.

👉 If a window does not contain a negative number, return `0` for that window.

---

## 💡 Intuition

Brute force:
- For every window → scan all k elements
- Time complexity → O(n * k) ❌

### 🚀 Optimized Approach — Sliding Window + Queue

- Use a **queue** to store negative elements of the current window
- Why queue?
  - It keeps elements in order
  - Helps to get **first negative** in O(1)

---

## ⚙️ Approach

1. Traverse the array using sliding window
2. If element is negative → push into queue
3. When window size becomes `k`:
   - If queue not empty → answer = front of queue
   - Else → answer = 0
4. Before sliding:
   - If outgoing element == queue front → pop it
5. Move window forward

---

## 📌 Example 1 (Step by Step)

```
Input: arr = [-8, 2, 3, -6, 10], k = 2

Window 1: [-8, 2] → first negative = -8
Window 2: [2, 3] → no negative → 0
Window 3: [3, -6] → first negative = -6
Window 4: [-6, 10] → first negative = -6

Output: [-8, 0, -6, -6]
```

---

## 📌 Example 2 (Detailed Flow)

```
Input: arr = [12, -1, -7, 8, -15, 30, 16, 28], k = 3

Window 1: [12, -1, -7] → -1
Window 2: [-1, -7, 8] → -1
Window 3: [-7, 8, -15] → -7
Window 4: [8, -15, 30] → -15
Window 5: [-15, 30, 16] → -15
Window 6: [30, 16, 28] → 0

Output: [-1, -1, -7, -15, -15, 0]
```

---

## 📌 Example 3 (No Negatives)

```
Input: arr = [1, 2, 3, 4], k = 2

All windows:
[1, 2] → 0
[2, 3] → 0
[3, 4] → 0

Output: [0, 0, 0]
```

---

## 🧠 Code (C++)

```cpp
class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
       queue<int> q;
       vector<int> result;
       int n = arr.size();
       int j = 0;

       for(int i = 0; i < n; i++){
           if(arr[i] < 0) q.push(arr[i]);

           if(i - j + 1 == k){
               if(!q.empty()){
                   result.push_back(q.front());
               } else {
                   result.push_back(0);
               }

               if(!q.empty() && arr[j] == q.front()){
                   q.pop();
               }

               j++;
           }
       }

       return result;
    }
};
```

---

## ⏱️ Complexity Analysis

- **Time Complexity:** O(n)
- **Space Complexity:** O(k) (for queue)

---

## 🎯 Key Takeaways

- Use **Sliding Window** for fixed size problems
- Use **Queue** when order matters
- Store only useful elements (negatives here)

---

## 🏁 Summary

👉 Maintain a queue of negative numbers  
👉 For each window, front of queue = answer  
👉 Remove elements when they go out of window  

💯 Efficient solution in **O(n)** 🚀
