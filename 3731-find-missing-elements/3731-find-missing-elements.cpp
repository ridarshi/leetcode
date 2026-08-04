// class Solution {
// public:
//     vector<int> findMissingElements(vector<int>& nums) {
//         vector<int> ans;
//         map<int, int> mp;

//         if (nums.empty())
//             return ans;

//         int n = nums.size();
//         int maxi = INT_MIN;
//         int mini = INT_MAX;

//         for (int i = 0; i < n; i++) {
//             mini = min(nums[i], mini);
//             maxi = max(nums[i], maxi);
//         }

//         for (int i = 0; i < n; i++) {
//             mp[nums[i]]++;
//         }

//         for (int i = mini; i <= maxi; i++) {
//             if (mp[i] == 0) {
//                 ans.push_back(i);
//             }
//         }
//         return ans;
//     }
// };


class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;

        if (nums.empty())
            return ans;

        int n = nums.size();
        int maxi = INT_MIN;
        int mini = INT_MAX;

        for (int i = 0; i < n; i++) {
            mini = min(nums[i], mini);
            maxi = max(nums[i], maxi);
        }

        unordered_set<int> s;
        for(int x : nums){
            s.insert(x);
        }

        for(int i = mini;i<=maxi;i++){
            if(!s.count(i)){
                ans.push_back(i);
            }
        }

        return ans;
    }
};