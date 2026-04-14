# 🔁 142. Linked List Cycle II

## 📌 Problem Statement

Given the `head` of a linked list, return the **node where the cycle begins**.
If there is no cycle, return `NULL`.

---

## 🧠 Intuition

We use **Floyd’s Cycle Detection Algorithm (Tortoise & Hare)**.

👉 Two phases:

1. **Cycle Detection**

   * Use slow and fast pointers.
   * If they meet → cycle exists.
2. **Find Cycle Start**

   * Move one pointer to `head`.
   * Move both pointers one step at a time.
   * They will meet at the **start of the cycle**.

---

## ⚙️ Approach

1. Initialize two pointers `slow` and `fast` at `head`.
2. Move:

   * `slow` → 1 step
   * `fast` → 2 steps
3. If they meet:

   * Initialize `temp = head`
   * Move both `temp` and `slow` one step at a time
   * The meeting point is the **cycle start**
4. If no meeting occurs → return `NULL`

---

## 💻 Code (C++)

```cpp id="8dzr6k"
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        // Step 1: Detect cycle
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                // Step 2: Find cycle start
                ListNode *temp = head;
                while(temp != slow){
                    temp = temp->next;
                    slow = slow->next;
                }
                return temp;
            }
        }

        return NULL;
    }
};
```

---

## ⏱️ Complexity Analysis

* **Time Complexity:** O(n)
* **Space Complexity:** O(1)

---

## 🔍 Example

### Input:

```id="1tt7s2"
head = [3,2,0,-4], pos = 1
```

### Visualization:

```id="1kl9qz"
3 → 2 → 0 → -4
    ↑         ↓
    ← ← ← ← ←
```

### Output:

```id="dtqtxg"
Node with value 2
```

---

## 🚫 Edge Cases

* No cycle → return `NULL`
* Single node with no cycle
* Cycle starting at head

---

## 💡 Key Takeaway

> After detecting a cycle, resetting one pointer to head and moving both one step at a time guarantees meeting at the cycle’s starting node.

---

## 🏷️ Tags

* Linked List
* Two Pointers
* Floyd’s Algorithm
* Cycle Detection

---

## 🔗 Problem Link

* https://leetcode.com/problems/linked-list-cycle-ii/

---
