# 📍 LC 973 – K Closest Points to Origin

---

## 🧩 Problem Statement

Given an array of 2D points where each point is represented as [x, y], 
return the k closest points to the origin (0,0).

The distance between a point (x, y) and the origin is:

    √(x² + y²)

The answer may be returned in any order.

---

## 🔎 Core Observation

✔ We only need to compare distances.  
✔ Square root computation is NOT required.

Reason:

If  
    a < b  
Then  
    √a < √b  

So instead of calculating √(x² + y²), 
we compare:

    x² + y²

This avoids floating-point operations and improves efficiency.

---

# 💡 Approach 1 – Max Heap (Optimal Strategy)

## 🧠 Intuition

We need the k smallest distances.

Instead of sorting all points:

• Maintain a max heap of size k  
• Store each point along with its squared distance  
• If heap size exceeds k → remove the farthest point  
• At the end, heap contains exactly k closest points  

---

## 🔁 Algorithm Steps

1. Initialize a max heap  
2. For each point:
   - Compute squared distance
   - Insert into heap
   - If heap size > k → remove the largest distance  
3. Extract remaining elements from heap  

---

## ⏱ Complexity Analysis

Time Complexity:
    O(n log k)

Space Complexity:
    O(k)

---

# 💡 Approach 2 – Sorting

Idea:
• Compute squared distance for every point  
• Sort the entire array based on distance  
• Return first k elements  

Time Complexity:
    O(n log n)

Space Complexity:
    O(1) or O(n)

---

# 💡 Approach 3 – Quick Select (Advanced)

Idea:
• Use partition logic similar to QuickSort  
• Position pivot based on distance  
• Recursively process only the required side  

Average Time Complexity:
    O(n)

Worst Time Complexity:
    O(n²)

Space Complexity:
    O(1)

---

# 🧪 Example

Input:
    points = [[3,3],[5,-1],[-2,4]]
    k = 2

Squared Distances:
    [3,3]  → 18
    [5,-1] → 26
    [-2,4] → 20

Output:
    [[3,3], [-2,4]]

---

# 🎯 Learning Outcomes

✔ Avoid unnecessary square root operations  
✔ Understand heap size control logic  
✔ Optimize from O(n log n) to O(n log k)  
✔ Compare heap vs sorting vs selection approaches  

---

Category:
Heap
Priority Queue
Selection Algorithm
Sorting
