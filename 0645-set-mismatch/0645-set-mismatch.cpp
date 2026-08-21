// BRUTE FORCE:
// class Solution {
// public:
//     vector<int> findErrorNums(vector<int>& nums) {
//         int n = nums.size();

//         int duplicate, missing;

//         vector<int> freq(n + 1, 0);

//         for (auto x : nums) {
//             freq[x]++;
//         }

//         for (int i = 1; i <= n; i++) {
//             if (freq[i] == 2) {
//                 duplicate = i;
//             } else if (freq[i] == 0) {
//                 missing = i;
//             }
//         }
//         return {duplicate, missing};
//     }
// };


// OPTIMAL SOLUTION:
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int duplicate, missing;
        int index;

        // Traverse through every number in nums
        for (auto x : nums) {

            // Since numbers are from 1 to n,
            // number x corresponds to index (x - 1)
            //
            // abs(x) is used because we may have already
            // changed some numbers to negative.
            index = abs(x) - 1;

            // If nums[index] is already negative,
            // it means we have seen this number before.
            // Therefore, x is the duplicate number.
            if (nums[index] < 0) {
                duplicate = index + 1;
            } 
            else {
                // Mark this number as "visited" by making
                // the value at its corresponding index negative.
                nums[index] = -nums[index];
            }
        }

        // Now find the missing number.
        //
        // Every number that appeared should have caused
        // its corresponding position to become negative.
        //
        // Therefore, the position that is still positive
        // represents the missing number.
        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] > 0) {

                // Index i represents the number (i + 1)
                missing = i + 1;
            }
        }

        return {duplicate, missing};
    }
};