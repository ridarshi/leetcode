class Solution {
public:
    bool judgeSquareSum(int c) {
        long long start = 0;
        long long end = sqrt(c);

        while (start <= end) {
            long long sum = start * start + end * end;

            if (sum > c) {
                end--;
            } else if (sum < c) {
                start++;
            } else {
                return true;
            }
        }
        return false;
    }
};