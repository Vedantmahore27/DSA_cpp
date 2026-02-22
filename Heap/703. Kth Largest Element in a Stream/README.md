# 🔢 703. Kth Largest Element in a Stream

- **Platform:** LeetCode  
- **Difficulty:** Easy  
- **Topic:** Heap / Priority Queue  

---

## 🧠 Problem Statement

Design a class to find the kth largest element in a stream of numbers.

The class should support:

- Constructor: `KthLargest(int k, vector<int>& nums)`
- Method: `add(int val)` → returns kth largest element

---

## 💡 Approach: Min Heap of Size K

We maintain a min heap of size `k`.

### 🔎 Logic

- Store `k` as a class variable.
- Push elements into min heap.
- If heap size exceeds `k`, remove the smallest element.
- The top of the heap is always the kth largest element.

---

## ⏱️ Complexity

- **Time Complexity:** O(log k) per insertion  
- **Space Complexity:** O(k)

---

## 🚀 Key Learning

- Understanding Top-K pattern
- Maintaining heap dynamically
- Using class member variables properly
