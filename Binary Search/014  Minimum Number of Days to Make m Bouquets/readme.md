# 🌸 1482. Minimum Number of Days to Make m Bouquets

## 🧠 Intuition (MOST IMPORTANT)

At first glance, this problem looks like simulation — checking day by day.  
But that would be too slow ❌

So think like this:

👉 We are NOT asked to simulate days  
👉 We are asked to find the MINIMUM day  

This screams:

🔥 **Binary Search on Answer**

---

### 💡 Key Observation

- If we can make `m` bouquets on day `X`  
  → then we can also make them on any day `> X`

✅ This is a **monotonic property** → perfect for binary search

---

## 🪄 Problem Understanding (Simple Words)

- Each flower blooms on a certain day
- We need **k adjacent flowers** to make 1 bouquet
- Need total **m bouquets**

👉 Return the **minimum day** when this becomes possible

---

## 🔍 Example (Step-by-Step Thinking)

bloomDay = [1,10,3,10,2]  
m = 3  
k = 1  

We need **3 bouquets**, each of **1 flower**

Try different days:

Day = 1  
Flowers bloomed: [1, _, _, _, _]  
Bouquets = 1 ❌  

Day = 2  
[1, _, _, _, 2]  
Bouquets = 2 ❌  

Day = 3  
[1, _, 3, _, 2]  
Bouquets = 3 ✅  

👉 Answer = **3**

---

## 🚀 Approach

### Step 1: Edge Case

If:
m * k > n  

👉 Not enough flowers → return -1

---

### Step 2: Binary Search

Search space:
low  = min(bloomDay)  
high = max(bloomDay)

---

### Step 3: Check Function (Core Logic)

For a given day:

- Traverse array
- Count continuous bloomed flowers
- Every k flowers → 1 bouquet

⚠️ If a flower is not bloomed → reset count

---

### Step 4: Binary Search Decision

- If possible to make m bouquets  
  → try smaller day (high = mid - 1)  
- Else  
  → increase day (low = mid + 1)

---

## 🧾 Code (C++)

```cpp
class Solution {
public:
    bool canMake(vector<int>& bloomDay, int m, int k, int day) {
        int count = 0, bouquets = 0;

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                count++;
                if (count == k) {
                    bouquets++;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }

        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size()) return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canMake(bloomDay, m, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
