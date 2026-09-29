class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();

        int count[501] = {0};
        for(auto x : arr){
            count[x]++;
        }

        for(int i = 500;i>0;i--){
            if(i == count[i]){
                return i;
            }
        }
        return -1;
    }
};