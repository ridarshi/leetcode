class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        // If there is at least one odd number,
        // we can use that odd number to make
        // every even number odd.
        //
        // Example:
        // 8 - 5 = 3  (odd)
        //
        // The odd number itself can simply be kept.
        //
        // If there is no odd number, then all numbers
        // are already even.
        //
        // Therefore, an answer is always possible.

        return true;
    }
};