class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n-1;

        vector<int> result(n);
        int i = n-1;

        while(left <= right){
            int leftsq = nums[left] * nums[left];
            int rightsq = nums[right] * nums[right];

            if(leftsq > rightsq){
                result[i] = leftsq;
                left++;
            }
            else{
                result[i] = rightsq;
                right--;
            }
            i--;
        }

        return result;
    }
};