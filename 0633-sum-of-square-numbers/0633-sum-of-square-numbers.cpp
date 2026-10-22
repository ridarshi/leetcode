
class Solution {
public:
    bool judgeSquareSum(int c) {

        // start begins at 0
        // end begins at sqrt(c), the largest possible number
        long long start = 0;
        long long end = sqrt(c);

        while (start <= end) {

            long long sum = start * start + end * end;

            // If the sum is too small, increase start
            if (sum < c) {
                start++;
            }

            // If the sum is too large, decrease end
            else if (sum > c) {
                end--;
            }

            // If the sum equals c, we found two valid numbers
            else {
                return true;
            }
        }

        // No pair of numbers was found whose squares add up to c
        return false;
    }
};
