class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;

        // Store all numbers present in nums
        for (auto x : nums) {
            st.insert(x);
        }

        // Check multiples of k: k, 2k, 3k, ...
        for (int i = 1; i <= 101; i++) {
            if (st.find(k * i) == st.end()) {
                return k * i;
            }
        }

        return -1;
    }
};