# 🔢 215. Kth Largest Element in an Array

- **Platform:** LeetCode  
- **Difficulty:** Medium  
- **Topic:** Heap / Priority Queue  

---

## 🧠 Problem Statement

Given an integer array `nums` and an integer `k`, return the **kth largest element** in the array.

> Note: It is the kth largest element in sorted order, not the kth distinct element.

---

## 💡 Approach: Min Heap of Size K

Instead of sorting the entire array (O(n log n)),  
we maintain a **min heap of size k**.

### 🔎 Logic

- Traverse the array.
- Push each element into a min heap.
- If heap size exceeds `k`, remove the smallest element.
- At the end:
  - The heap contains the `k` largest elements.
  - The top element is the **kth largest element**.

---

## 🧩 Algorithm Steps

1. Create a min heap.
2. Iterate through the array.
3. Push elements into the heap.
4. If heap size > k → pop the smallest.
5. Return heap top.

---
