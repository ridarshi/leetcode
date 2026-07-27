class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int ind1 = 0;
        int ind2 = 1;

        for(int i = 2;i<n;i++){
            
            if(nums[i] > nums[ind1] || nums[i] > nums[ind2]){
                if(nums[ind1] > nums[ind2]){
                    ind2 = i;
                }
                else{
                    ind1 = i;
                }
            }
        }

        return (nums[ind1] - 1)*(nums[ind2] - 1);
    }
};