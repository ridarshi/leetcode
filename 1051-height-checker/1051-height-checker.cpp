class Solution {

    void countingsort(vector<int> & nums){

        unordered_map<int, int> counts;

        int minval = *min_element(nums.begin(), nums.end());
        int maxval = *max_element(nums.begin(), nums.end());

        int index = 0;

        for(auto val : nums){
            counts[val]++;
        }

        for(int val = minval; val<=maxval; val++){
            while(counts[val] >0){
                nums[index] = val;
                index++;
                counts[val]--;
            }
        }
    }
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sortedheights = heights;

        countingsort(sortedheights);

        int count = 0;

        for(int i = 0; i<heights.size();i++){
            if(heights[i] != sortedheights[i]){
                count++;
            }
        }

        return count;
    }
};


// // Better solution Using Sort function
// // TC: 0(n log n)
// class Solution {
// public:
//     int heightChecker(vector<int>& heights) {

//         vector<int> expected = heights;

//         sort(expected.begin(), expected.end());

//         int count = 0;

//         for (int i = 0; i < heights.size(); i++) {
//             if (heights[i] != expected[i]) {
//                 count++;
//             }
//         }

//         return count;
//     }
// };