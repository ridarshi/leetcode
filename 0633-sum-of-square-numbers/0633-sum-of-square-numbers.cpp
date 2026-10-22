class Solution {
public:
    bool judgeSquareSum(int c) {
        long start = 0;
        long end = sqrt(c);

        while(start <= end){
            long sum = start*start + end*end;

            if(sum < c){
                start++;
            }
            else if(sum > c){
                end--;
            }
            else{
                return true;
            }
        }
        return false;
    }
};