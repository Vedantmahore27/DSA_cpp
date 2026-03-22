class Solution {
public:
    int countOnes(int x) {
        int cnt = 0;
        while (x > 0) {
            cnt += (x & 1);
            x >>= 1;
        }
        return cnt;
    }

    vector<int> countBits(int n) {
        vector<int> ans;
        for (int i = 0; i <= n; i++) {
            ans.push_back(countOnes(i));
        }
        return ans;
    }
};

// ⏱ Complexity:
// Time: O(n log n)
// Space: O(1)


class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            ans[i] = ans[i / 2] + (i & 1);
        }

        return ans;
    }
};

// ⏱ Complexity:
// Time: O(n)
// Space: O(n)


class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            ans[i] = ans[i & (i - 1)] + 1;
        }

        return ans;
    }
};

// Complexity:
// Time: O(n)
// Space: O(n)
