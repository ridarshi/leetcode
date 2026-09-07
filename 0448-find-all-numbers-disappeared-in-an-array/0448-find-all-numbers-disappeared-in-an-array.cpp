class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();

        // Mark the numbers that we have seen
        for (int i = 0; i < n; i++) {

            // Use abs because nums[i] may have already been made negative
            int index = abs(nums[i]) - 1;

            if (nums[index] > 0) {
                // Mark this number as seen
                nums[index] = -abs(nums[index]);
            }
        }

        vector<int> result;

        // Positive value means that the number corresponding to this index was
        // never seen
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                result.push_back(i + 1);
            }
        }

        return result;
    }
};