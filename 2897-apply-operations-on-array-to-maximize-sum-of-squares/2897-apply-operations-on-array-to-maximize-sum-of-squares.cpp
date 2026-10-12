
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {

        const int MOD = 1e9 + 7;

        // cnt[bit] stores how many numbers have a 1 at this bit position.
        // For example, cnt[2] counts how many numbers have the value 4's bit set.
        vector<int> cnt(31, 0);

        // STEP 1: Count the set bits in all numbers.
        for (int num : nums) {

            // Check every bit position from 0 to 30.
            for (int bit = 0; bit < 31; bit++) {

                // (1 << bit) creates a number with only this bit set.
                // Example: 1 << 2 = 4, which is binary 100.
                // 0001 (1) ---> 0100 (4)
                //
                // & checks whether this bit is set in num.
                // If the result is non-zero, this bit is 1.
                if (num & (1 << bit)) {
                    cnt[bit]++;
                }
            }
        }

        long long ans = 0;

        // STEP 2: Construct k numbers, one at a time.
        for (int i = 0; i < k; i++) {

            // Start each new number at 0.
            long long x = 0;

            // Try to include every available bit in this number.
            for (int bit = 0; bit < 31; bit++) {

                // If at least one number still has this bit available,
                // we can use this bit in our current number.
                if (cnt[bit] > 0) {

                    // Turn ON this bit in x.
                    // Example: if bit = 2, then (1LL << 2) = 4.
                    // x |= 4 sets the bit worth 4 without removing
                    // any bits that are already set in x.
                    x |= (1LL << bit);

                    // We used one available bit, so reduce its count.
                    cnt[bit]--;
                }
            }

            // STEP 3: Add the square of the number we constructed.
            // Take modulo to keep the answer within the required range.
            ans = (ans + x * x) % MOD;
        }

        // Return the maximum sum of squares.
        return ans;
    }
};
