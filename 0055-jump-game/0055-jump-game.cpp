
class Solution {
public:
    bool canJump(vector<int>& nums) {
        // The farthest index we can reach so far
        int maxReach = 0;

        for (int i = 0; i < nums.size(); i++) {
            // If the current index is beyond our reach,
            // we cannot reach this position
            if (i > maxReach) {
                return false;
            }

            // Update the farthest index we can reach
            maxReach = max(maxReach, i + nums[i]);
        }

        // If the loop finishes, the last index is reachable
        return true;
    }
};
