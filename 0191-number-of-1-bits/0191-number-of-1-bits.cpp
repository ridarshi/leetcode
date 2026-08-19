class Solution {
public:
    int hammingWeight(int n) {
        // initiate the count
        int count = 0;

        // run a loop until the number becomes zero
        while(n != 0){
            // check the last bit
            if((n & 1) == 1){
                // if its 1 then increase the count
                count++;
            }
            // shift n right by 1; 
            n >>= 1;
        }
        return count;
    }
};