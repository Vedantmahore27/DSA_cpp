# 🟩 Maximal Rectangle (Binary Matrix)

## 📌 Problem Statement

Given a **binary matrix** filled with `0`s and `1`s, find the **largest rectangle containing only 1's** and return its area.

This problem is an extension of **Largest Rectangle in Histogram**.

---

## 🧠 Key Idea

Instead of solving the rectangle directly in the matrix, we convert each row into a **histogram**.

For every row:

* If the current cell is `1` → increase the height.
* If the current cell is `0` → reset height to `0`.

After updating the heights for a row, we apply the **Largest Rectangle in Histogram algorithm** to compute the maximum rectangle area for that histogram.

We repeat this for every row and track the maximum area.

---

## 📊 Example

### Input Matrix

```
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
```

### Histogram Transformation

Row 1 → `[1,0,1,0,0]`
Row 2 → `[2,0,2,1,1]`
Row 3 → `[3,1,3,2,2]`
Row 4 → `[4,0,0,3,0]`

We compute the **largest rectangle in histogram** for each row.

### Output

```
Max Area = 6
```

---

## ⚙️ Algorithm

1. Initialize a `heights` array of size `cols`.
2. Traverse each row of the matrix.
3. Update histogram heights:

   * If cell = `1` → `height[j] += 1`
   * If cell = `0` → `height[j] = 0`
4. Apply **Largest Rectangle in Histogram** on `heights`.
5. Track the maximum area.

---

## ⏱️ Complexity Analysis

| Complexity       | Value              |
| ---------------- | ------------------ |
| Time Complexity  | **O(rows × cols)** |
| Space Complexity | **O(cols)**        |

Each row builds a histogram and processes it using a stack.

---

## 💻 C++ Implementation

```cpp
class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {

        stack<int> st;
        int n = heights.size();
        int ans = 0;

        for(int i = 0; i < n; i++){

            while(!st.empty() && heights[i] < heights[st.top()]){

                int indx = st.top();
                st.pop();

                if(!st.empty())
                    ans = max(ans, heights[indx] * (i - st.top() - 1));
                else
                    ans = max(ans, heights[indx] * i);
            }

            st.push(i);
        }

        while(!st.empty()){

            int indx = st.top();
            st.pop();

            if(!st.empty())
                ans = max(ans, heights[indx] * (n - st.top() - 1));
            else
                ans = max(ans, heights[indx] * n);
        }

        return ans;
    }


    int maximalRectangle(vector<vector<char>>& matrix) {

        if(matrix.empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> heights(cols,0);
        int maxArea = 0;

        for(int i = 0; i < rows; i++){

            for(int j = 0; j < cols; j++){

                if(matrix[i][j] == '1')
                    heights[j] += 1;
                else
                    heights[j] = 0;
            }

            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }
};
```

---

## 🔥 Important Concept

This problem demonstrates a powerful technique:

**Convert 2D problems into 1D histogram problems.**

Many advanced matrix problems use this trick.

---

## 🧩 Related Problems

* Largest Rectangle in Histogram
* Maximum Area Rectangle in Binary Matrix
* Maximal Square
* Trapping Rain Water
* Next Smaller Element

---

## 🏆 Key Takeaway

If you can solve **Largest Rectangle in Histogram**, then **Maximal Rectangle** becomes straightforward by building histograms row by row.

Mastering stack-based histogram problems is extremely useful for coding interviews.
