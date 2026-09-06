class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int> mp;

        int count = 0;

        for(char c : stones){
            mp[c]++;
        }

        for(char c : jewels){
            count += mp[c];
        }

        return count;
    }
};