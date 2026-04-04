# 🚗 Repair Cars (Binary Search on Answer)

## 📌 Problem Statement

You are given an integer array `ranks` representing the ranks of mechanics.  
The time taken by a mechanic with rank `r` to repair `n` cars is:

time = r * n²

You are also given an integer `cars`, representing the total number of cars that need to be repaired.

👉 Return the **minimum time** required to repair all cars.

---

## 🧪 Example

### Example 1:

Input:
ranks = [4, 2, 3, 1]  
cars = 10  

Output:
16  

### Explanation:
- Mechanic with rank 1 repairs 4 cars → time = 1 × 4² = 16  
- Mechanic with rank 2 repairs 2 cars → time = 2 × 2² = 8  
- Mechanic with rank 3 repairs 1 car → time = 3 × 1² = 3  
- Mechanic with rank 4 repairs 1 car → time = 4 × 1² = 4  

Total cars repaired = 10 within time = 16

---

## 🧠 Intuition

This is a classic **Binary Search on Answer** problem.

### Key Observation:
Instead of directly calculating time, we reverse the formula:

n = sqrt(time / rank)

So, for a given time `mid`, each mechanic can repair:

cars = floor(sqrt(mid / rank))

👉 Sum up all mechanics:
- If total cars ≥ required → time is valid ✅  
- Else → need more time ❌  

---

## 🔍 Approach

### Step 1: Define Search Space
- Minimum time = 1  
- Maximum time = max(rank) × cars²  

---

### Step 2: Binary Search
Find the minimum time `mid` such that:

total cars repaired ≥ required cars  

---

### Step 3: Feasibility Function
For each mechanic:

cars += sqrt(mid / rank)

---

## ⚙️ Algorithm

1. Initialize:
   - start = 1  
   - end = max(rank) × cars²  

2. While start ≤ end:
   - mid = start + (end - start) / 2  
   - If possible to repair all cars in mid:
     - store answer  
     - move left (end = mid - 1)  
   - Else:
     - move right (start = mid + 1)  

---

## 💻 Code Implementation (C++)

```cpp
class Solution {
public:
    bool check(vector<int>& ranks, int cars, long long mid){
        long long cnt = 0;

        for(int i = 0; i < ranks.size(); i++){
            cnt += sqrt((double)mid / ranks[i]);

            if(cnt >= cars) return true;
        }

        return false;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long start = 1;
        long long end = 1LL * (*max_element(ranks.begin(), ranks.end())) * cars * cars;
        long long ans = 0;

        while(start <= end){
            long long mid = start + (end - start) / 2;

            if(check(ranks, cars, mid)){
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }
};
