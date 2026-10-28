class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int sum = 0;
        int sublen = INT_MAX;

        for(int right = 0;right < n;right++){
            sum += nums[right];

            // travel the left pointer until the sum is >= target;
            while(sum >= target){
                sublen = min(sublen, right-left+1);
                sum -= nums[left];
                left++;
            }
        }
        return sublen == INT_MAX ? 0 : sublen;
    }
};