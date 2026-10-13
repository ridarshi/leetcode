// TC : 0(n + M)
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {

        // Maximum possible absolute value in nums
        const int MAX_VAL = 40000;

        // freq[x] stores how many times abs(x) occurs
        vector<int> freq(MAX_VAL + 1, 0);

        // Step 1: Count the frequency of each absolute value
        for (int x : nums) {
            freq[abs(x)]++;
        }

        int n = nums.size();

        // We need to subtract the smallest n/2 values
        int remaining = n / 2;

        // Stores the final maximum score
        long long ans = 0;

        // Step 2: Subtract the smallest n/2 squared values
        // Visit values in increasing order, starting from 0
        for (int x = 0; x <= MAX_VAL && remaining > 0; x++) {

            // Number of occurrences of x we need to subtract
            int take = min(freq[x], remaining);

            // Subtract take occurrences of x^2
            // 1LL ensures multiplication is done using long long
            ans -= 1LL * take * x * x;

            // Update how many values still need to be subtracted
            remaining -= take;

            // Remove the occurrences already used
            freq[x] -= take;
        }

        // Step 3: Add the squares of all remaining values
        for (int x = 0; x <= MAX_VAL; x++) {

            // Add freq[x] occurrences of x^2
            ans += 1LL * freq[x] * x * x;
        }

        // Step 4: Return the maximum possible score
        return ans;
    }
};




// BETTER SOLUTION TC: (n log n)
// class Solution {
// public:
//     long long maxAlternatingSum(vector<int>& nums) {

//         int n = nums.size();

//         // Step 1: Square every element.
//         // We only care about squared values.
//         for (int i = 0; i < n; i++) {
//             nums[i] = nums[i] * nums[i];
//         }

//         // Step 2: Sort the squared values in ascending order.
//         sort(nums.begin(), nums.end());

//         // Step 3: The first n/2 values are the smallest.
//         // These values will be subtracted.
//         int m = n / 2;

//         // Use long long because the total sum can be large.
//         long long ans = 0;

//         // Step 4: Subtract the smaller squared values.
//         for (int i = 0; i < m; i++) {
//             ans -= nums[i];
//         }

//         // Step 5: Add the remaining larger squared values.
//         for (int i = m; i < n; i++) {
//             ans += nums[i];
//         }

//         // Step 6: Return the maximum possible score.
//         return ans;
//     }
// };
