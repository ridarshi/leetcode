class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        map<int, int> mp;

        for(auto x : nums){
            mp[x]++;
        }

        vector<int> ans;

        for(auto it : mp){
            if(it.second > 1){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};