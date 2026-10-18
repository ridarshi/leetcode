class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n - 1;

        int maxwater = 0;

        while (left < right) {
            int water = 0;

            if (height[left] > height[right]) {
                water = height[right] * (right - left);
                maxwater = max(maxwater, water);
                right--;
            } else {
                water = height[left] * (right - left);
                maxwater = max(maxwater, water);
                left++;
            }
        }

        return maxwater;
    }
};