# 🔢 GFG - Sort a K-Sorted Array  
# 🔢 GFG - K-Sorted Array ko Sort karna

- **Platform:** GeeksforGeeks  
- **Topic:** Heap / Priority Queue  
- **Difficulty:** Medium  

---

## 🧠 Problem Statement (English)

Given an array where each element is at most `k` positions away from its correct sorted position, sort the array efficiently.

---

## 🧠 Problem Samjhaai (Hindi)

Humein ek aisa array diya gaya hai jisme har element apni correct sorted position se maximum `k` distance door ho sakta hai.  
Humein is array ko efficiently sort karna hai.

Is type ke array ko **k-sorted array** kehte hain.

---

## 💡 Approach (English)

We use a **Min Heap of size k+1**.

### Why?

At any index `i`, the correct element must be present within the next `k+1` elements.

### Steps:

1. Push first `k+1` elements into a min heap.
2. Extract the smallest element and place it in correct position.
3. Push the next element from array.
4. Repeat until array becomes sorted.

---

## 💡 Approach (Hindi)

Hum ek **Min Heap (size k+1)** ka use karte hain.

### Kyun?

Kyuki agar array k-sorted hai, to kisi bhi position par jo correct element hoga, woh next `k+1` elements ke andar hi milega.

### Steps:

1. Pehle `k+1` elements ko min heap me daalo.
2. Sabse chhota element nikaal kar correct position par rakho.
3. Next element heap me daalo.
4. Yeh process repeat karo jab tak array sort na ho jaye.

---
