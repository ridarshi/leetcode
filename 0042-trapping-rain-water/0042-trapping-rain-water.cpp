class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        // Store the maximum height seen so far
        // from the left and right sides.
        int leftmax = 0;
        int rightmax = 0;
        int water = 0;

        while (left < right) {

            // If the left height is smaller,
            // we can safely calculate water using leftmax.
            if (height[left] < height[right]) {

                leftmax = max(leftmax, height[left]);
                // Water trapped at the current left position:
                // leftmax - current height.
                water += leftmax - height[left];
                left++;
            }

            // If the right height is smaller (or equal),
            // we can safely calculate water using rightmax.
            else {

                rightmax = max(rightmax, height[right]);
                // Water trapped at the current right position:
                // rightmax - current height.
                water += rightmax - height[right];
                right--;
            }
        }

        return water;
    }
};