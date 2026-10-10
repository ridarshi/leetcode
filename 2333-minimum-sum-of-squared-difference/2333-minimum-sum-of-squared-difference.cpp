
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
                               int k2) {

        int n = nums1.size();
        // Combine both operation budgets.
        long long k = (long long)k1 + k2;

        // Store the absolute difference at every index.
        vector<int> diff(n);
        int maxDiff = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxDiff = max(maxDiff, diff[i]);
        }

        // If we can eliminate all differences, the answer is 0.
        long long total = 0;
        for (int d : diff) {
            total += d;
        }

        // If all differences can become zero, the minimum sum is zero.
        if (total <= k) {
            return 0;
        }

        // Binary search for the smallest maximum difference
        // that can be reached using at most k operations.
        int left = 0;
        int right = maxDiff;

        while (left < right) {
            int mid = left + (right - left) / 2;
            long long operations = 0;

            // Count operations needed to make every difference
            // at most mid.
            for (int d : diff) {
                if (d > mid) {
                    operations += d - mid;
                }
            }

            if (operations <= k) {
                right = mid; // mid is achievable
            } else {
                left = mid + 1; // need a larger limit
            }
        }

        // left is the smallest achievable maximum difference.
        int limit = left;
        long long answer = 0;

        // Reduce every difference greater than limit down to limit.
        // Count how many operations this reduction uses.
        long long used = 0;

        for (int d : diff) {
            if (d > limit) {
                used += d - limit;
                d = limit;
            }
            answer += 1LL * d * d;
        }

        // Any remaining operations should reduce differences
        // currently equal to limit by one.
        long long remaining = k - used;

        // Use remaining operations to reduce differences
        // equal to limit by one.
        //
        // IMPORTANT FORMULA TO REMEMBER:
        //
        // Reducing a difference x to x - 1 saves:
        // x^2 - (x - 1)^2
        //
        // Expand the square:
        // = x^2 - (x^2 - 2*x + 1)
        // = x^2 - x^2 + 2*x - 1
        // = 2*x - 1
        //
        // Therefore, each reduction from limit to limit - 1
        // decreases the answer by (2 * limit - 1).
        //
        // Because total <= k was checked earlier, limit is positive.
        // Binary search ensures there are enough differences equal
        // to limit to use all remaining operations this way.
        answer -= remaining * (2LL * limit - 1);

        return answer;
    }
};
