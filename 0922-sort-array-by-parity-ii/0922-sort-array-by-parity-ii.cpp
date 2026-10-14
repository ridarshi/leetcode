class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        // use two pointer, one at even indexes and other at odd indexes
        int even = 0;
        int odd = 1;
        int n = nums.size();

        // run this loop to each indexes
        while(even < n && odd < n){
            if(nums[even] % 2 == 0){
                even += 2;
            }
            else if(nums[odd] % 2 != 0){
                odd += 2;
            }
            else{
                // swap the numbers
                int temp = nums[even];
                nums[even] = nums[odd];
                nums[odd] = temp;
            }
        }

        return nums;
    }
};