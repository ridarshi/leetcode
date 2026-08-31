class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;

        // do sum of the first k number of values
        for(int i = 0; i<k;i++){
            sum += nums[i];
        }

        // take the sum of fisrt k number values in a variable
        int maxSum = sum;

        // now go frontwards and remove the back elements one by one while taking the maximum of each k values and the previous one
        for(int i = k;i<n;i++){
            sum = sum - nums[i-k] + nums[i];
            maxSum = max(maxSum, sum);
        }

        // now return the double value of the maximum average
        return (double)maxSum/k;
    }
};