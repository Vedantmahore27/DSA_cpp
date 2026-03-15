# Buy Two Chocolates 🍫

## Problem Statement

You are given an integer array `prices` where `prices[i]` represents the price of the `i-th` chocolate, and an integer `money` representing the amount of money you have.

Your goal is to **buy exactly two chocolates**.

- If the **total price of the two cheapest chocolates is less than or equal to `money`**, return the **remaining money**.
- Otherwise, return the **original `money`**, meaning you cannot afford two chocolates.

---

## Approach 💡

The main idea is to **buy the two cheapest chocolates** so that we spend the least amount of money.

### Steps

1. Check if the array contains at least two chocolates.
2. Sort the `prices` array.
3. Take the **two smallest prices** (`prices[0]` and `prices[1]`).
4. If their sum is **less than or equal to the available money**, return the remaining money.
5. Otherwise, return the original money.

---

## C++ Implementation

```cpp
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int n = prices.size();
        if(n <= 1) return money;

        sort(prices.begin(), prices.end());

        if(prices[0] + prices[1] <= money)
            return money - (prices[0] + prices[1]);

        return money;
    }
};
