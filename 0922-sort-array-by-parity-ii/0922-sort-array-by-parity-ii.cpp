class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int even = 0;
        int odd = 1;
        int n = nums.size();

        while(even < n && odd < n){
            if(nums[even] % 2 == 0){
                even += 2;
            }
            else if(nums[odd] % 2 != 0){
                odd += 2;
            }
            else{
                int temp = nums[even];
                nums[even] = nums[odd];
                nums[odd] = temp;
            }
        }

        return nums;
    }
};