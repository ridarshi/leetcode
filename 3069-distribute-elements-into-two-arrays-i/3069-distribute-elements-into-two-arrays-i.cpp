// class Solution {
// public:
//     vector<int> resultArray(vector<int>& nums) {
//         int n = nums.size();

//         vector<int> arr1, arr2;

//         arr1.push_back(nums[0]);
//         arr2.push_back(nums[1]);

//         for(int i = 2; i<n;i++){
//             if(arr1.back() > arr2.back()){
//                 arr1.push_back(nums[i]);
//             }
//             else{
//                 arr2.push_back(nums[i]);
//             }
//         }

//         arr1.insert(arr1.end(), arr2.begin(), arr2.end());

//         return arr1;
//     }
// };



class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> arr(n);

        arr[0] = nums[0];
        arr[n-1] = nums[1];

        // initiating the two pointers
        int idx = 0;
        int revIdx = n-1;

        for(int i = 2;i<n;i++){
            //  checking for the first condition
            if(arr[idx] > arr[revIdx]){
                idx++;
                arr[idx] = nums[i];
            }
            // checking for the second condition
            else{
                revIdx--;
                arr[revIdx] = nums[i];
            }
        }

        // reversing the second part of the array;
        reverse(arr.begin()+revIdx, arr.end());

        return arr;
    }
};