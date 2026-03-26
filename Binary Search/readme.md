# 🎯 Guess Number Higher or Lower

## 📘 Problem Description
We are playing the **Guess Game**.  
You need to guess a number between `1` and `n`.

Each time you guess a number `x`, the API `guess(x)` returns:
- `-1` → Your guess is **higher** than the picked number  
- `1` → Your guess is **lower** than the picked number  
- `0` → Your guess is **correct**

Return the number that was picked.

---

## 🔧 API Provided
```cpp
int guess(int num);
