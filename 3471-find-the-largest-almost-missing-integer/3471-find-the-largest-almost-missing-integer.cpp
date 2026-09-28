class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        if(n == k){
            return *max_element(nums.begin(), nums.end());
        }

        int count[51] = {0};
        for(int x : nums){
            count[x]++;
        }

        if(k == 1){
            for(int i = 50;i>=0;i--){
                if(count[i] == 1){
                    return i;
                }
            }
        }

        int res = -1;
        if(count[nums[0]] == 1){
            res = max(res, nums[0]);
        }

        if(count[nums[n-1]] == 1){
            res = max(res, nums[n-1]);
        }

        return res;
    }
};