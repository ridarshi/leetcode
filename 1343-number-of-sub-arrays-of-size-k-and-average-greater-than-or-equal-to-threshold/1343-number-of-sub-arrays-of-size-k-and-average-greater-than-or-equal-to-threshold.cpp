
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int left = 0;
        int n = arr.size();

        int sum = 0;          // Stores the sum of the current window
        int subarrcount = 0;  // Counts subarrays satisfying the condition

        for (int right = 0; right < n; right++) {

            // Step 1: Add the current element to the window
            sum += arr[right];

            // Step 2: Check if the window size has reached k
            if (right - left + 1 == k) {

                // Step 3: Calculate the average of the current window
                // If the average is >= threshold, count this subarray
                if (sum / k >= threshold) {
                    subarrcount++;
                }

                // Step 4: Remove the leftmost element from the window
                // so that we can slide the window forward
                sum -= arr[left];

                // Move the left pointer to the next position
                left++;
            }
        }

        // Return the total number of valid subarrays
        return subarrcount;
    }
};
