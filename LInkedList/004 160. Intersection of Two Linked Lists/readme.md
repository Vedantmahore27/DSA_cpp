# 🔗 160. Intersection of Two Linked Lists

## 📌 Problem Statement

Given the heads of two singly linked lists `headA` and `headB`, return the **node at which the two lists intersect**.

👉 If the two linked lists have no intersection, return `NULL`.

---

## 🧠 Intuition

We use the **two-pointer technique with pointer switching**.

👉 Idea:

* Traverse both lists using two pointers.
* When a pointer reaches the end, redirect it to the head of the other list.
* This ensures both pointers traverse equal total distance.

---

## ⚙️ Approach

1. Initialize two pointers:

   * `a = headA`
   * `b = headB`
2. Traverse both lists:

   * If `a == NULL`, move it to `headB`, else `a = a->next`
   * If `b == NULL`, move it to `headA`, else `b = b->next`
3. Continue until `a == b`
4. Return either pointer (`a` or `b`)

---

## 💻 Code (C++)

```cpp id="1p0z0r"
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA;
        ListNode *b = headB;

        while(a != b){
            a = (a == NULL) ? headB : a->next;
            b = (b == NULL) ? headA : b->next;
        }

        return a;
    }
};
```

---

## ⏱️ Complexity Analysis

* **Time Complexity:** O(n + m)
* **Space Complexity:** O(1)

---

## 🔍 Example

### Input:

```id="xt3czh"
A: 1 → 2 → 3 \
                 → 7 → 8
B:       4 → 5 /
```

### Output:

```id="1p36hz"
7 → 8
```

---

## 🚫 Edge Cases

* No intersection → return `NULL`
* One or both lists are empty
* Intersection at head

---

## 💡 Key Takeaway

> By switching heads, both pointers traverse equal distances, ensuring they meet at the intersection node (if it exists).

---

## 🏷️ Tags

* Linked List
* Two Pointers
* Fast & Slow Pointer

---

## 🔗 Problem Link

* https://leetcode.com/problems/intersection-of-two-linked-lists/

---
