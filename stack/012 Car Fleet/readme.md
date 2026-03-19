# 🚗 Car Fleet (LeetCode)

## 🧾 Problem Statement

There are `n` cars going to the same destination along a one-lane road.

You are given:

* `target`: the destination position
* `position[i]`: the starting position of the `i-th` car
* `speed[i]`: the speed of the `i-th` car

---

### 🚦 Rules:

* A car **cannot overtake** another car.
* If a faster car catches up with a slower car, it becomes part of the same fleet.
* The fleet moves at the speed of the slowest car.

---

### 🎯 Goal:

Return the **number of car fleets** that will arrive at the destination.

---

## 🧪 Example

### Example 1:

```
Input:
target = 12
position = [10, 8, 0, 5, 3]
speed =    [2, 4, 1, 1, 3]

Output:
3
```

---

### 🧠 Explanation:

| Car Position | Speed | Time to Reach |
| ------------ | ----- | ------------- |
| 10           | 2     | 1             |
| 8            | 4     | 1             |
| 5            | 1     | 7             |
| 3            | 3     | 3             |
| 0            | 1     | 12            |

* Cars at 10 and 8 → same time → form 1 fleet
* Car at 5 → separate fleet
* Cars at 3 and 0 merge later

👉 Total fleets = **3**

---

## 💡 Intuition

### 🔥 Key Insight:

We don't care about:

* Speed directly ❌
* Distance alone ❌

👉 We care about:

```
Time to reach target
```

```
time = (target - position) / speed
```

---

### 🧠 Core Idea:

* If a car behind takes **less or equal time**, it will catch up → merge
* If it takes **more time**, it becomes a new fleet

---

## ⚡ Step-by-Step Approach

### 1. Pair position & speed

```cpp
vector<pair<int,int>> cars;
```

---

### 2. Sort cars by position

* Ascending order
* We will process from **right → left**

---

### 3. Calculate time for each car

```cpp
time = (target - position) / speed
```

---

### 4. Traverse from closest → farthest

```cpp
for(i = n-1 → 0)
```

---

### 5. Use stack (or variable)

* If current time ≤ last fleet time → merge
* Else → new fleet

---

## 🧠 Dry Run (Important)

```
target = 10
position = [6, 8]
speed = [3, 2]
```

Times:

* Car at 8 → 1 sec
* Car at 6 → 1.33 sec

👉 Behind car is slower → cannot catch → **2 fleets**

---

## ❌ Common Mistakes

* Using speed comparison instead of time ❌
* Using LCM or complex math ❌
* Traversing in wrong direction ❌
* Popping from stack (WRONG concept) ❌

---

## ✅ Correct Code (C++)

```cpp
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        
        vector<pair<int,int>> cars;
        for(int i = 0; i < n; i++){
            cars.push_back({position[i], speed[i]});
        }

        // Sort by position
        sort(cars.begin(), cars.end());

        stack<double> st;

        // Traverse from closest to target
        for(int i = n-1; i >= 0; i--){
            double time = (double)(target - cars[i].first) / cars[i].second;

            if(!st.empty() && time <= st.top()){
                continue; // merge into fleet
            }

            st.push(time); // new fleet
        }

        return st.size();
    }
};
```

---

## 🚀 Optimized Version (No Stack)

```cpp
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        
        vector<pair<int,double>> cars;
        for(int i = 0; i < n; i++){
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        sort(cars.begin(), cars.end());

        int fleets = 0;
        double prev = 0;

        for(int i = n-1; i >= 0; i--){
            if(cars[i].second > prev){
                fleets++;
                prev = cars[i].second;
            }
        }

        return fleets;
    }
};
```

---

## 🧠 Complexity Analysis

| Operation | Complexity |
| --------- | ---------- |
| Sorting   | O(n log n) |
| Traversal | O(n)       |
| Space     | O(n)       |

---

## 🎯 Key Takeaways

* Always think in terms of **time, not speed**
* Direction matters → process **closest first**
* Stack is optional → logic is greedy
* Never remove fleets → only merge or create

---

## 🏁 Final Thought

> “Cars merge… fleets don’t disappear.”

---

🔥 This is a **classic greedy + sorting problem** — mastering this builds strong intuition for many interview questions.

---
