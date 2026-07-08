class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = -1; 

        // largest prefix match
        for(int i = n-2;i>=0;i--){
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }
        
        // if no index found
        if(index == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        
        // find the number > value of index
        for(int i = n-1;i>= 0;i--){
            if(nums[i] > nums[index]){
                swap(nums[i], nums[index]);
                break;
            }
        }
        reverse(nums.begin()+index+1, nums.end());
        return;
    }
};