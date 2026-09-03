class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = INT_MAX;

        for (auto x : nums1) {
            if (x < mn) {
                mn = x;
            }
        }

        for (int x : nums1) {
            // If x has different parity from the minimum
            if (x % 2 != mn % 2) {

                // nums1	Minimum	Answer
                // [1,4,7]	1 (odd)	✅ true
                // [3,6,10]	3 (odd)	✅ true
                // [2,4,8]	2 (even) ✅ true
                // [2,5,8]	2 (even) ❌ false
                // If minimum is even, we cannot change an odd number into even.
                // so it will always be false;
                if (mn % 2 == 0) {
                    return false;
                }
            }
        }

        return true;
    }
};