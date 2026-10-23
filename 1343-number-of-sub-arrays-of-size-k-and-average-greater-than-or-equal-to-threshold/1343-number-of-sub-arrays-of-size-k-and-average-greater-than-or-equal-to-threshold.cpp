class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int left = 0;
        int n = arr.size();
        int sum = 0;

        int subarrcount = 0;

        for(int right = 0;right < n;right++){
            sum += arr[right];

            if(right - left + 1 == k){
                if(sum / k >= threshold){
                    subarrcount++;
                } 
                sum -= arr[left];
                left++;
            }
        }
        return subarrcount;
    }
};