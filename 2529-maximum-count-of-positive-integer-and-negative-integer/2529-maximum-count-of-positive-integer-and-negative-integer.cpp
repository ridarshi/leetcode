// TC : 0(log n);
class Solution {
private:
    int binarySearch(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        // Default answer:
        // If target is not found, return n
        int result = nums.size();

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                result = mid;
                right = mid - 1;
            }
        }
        return result;
    }

public:
    int maximumCount(vector<int>& nums) {

        int neg = binarySearch(nums, 0);
        int pos = nums.size() - binarySearch(nums, 1);

        return max(neg, pos);
    }
};

// // TC : 0(N);
// class Solution {
// public:
//     int maximumCount(vector<int>& nums) {
//         int n = nums.size();
//         int pos = 0;
//         int neg = 0;

//         for(int i = 0;i<n;i++){
//             if(nums[i] > 0){
//                 pos++;
//             }
//             else if(nums[i]<0){
//                 neg++;
//             }
//         }
//         return max(pos, neg);
//     }
// };