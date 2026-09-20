class Solution {
public:

    int reverseDegree(string s) {

        // Stores the final reverse degree
        int sum = 0;

        // Traverse every character of the string
        for (int i = 0; i < s.length(); i++) {

            // Calculate the reverse alphabet value
            // a -> 26, b -> 25, ..., z -> 1
            int reverseValue = 26 - (s[i] - 'a');

            // i + 1 gives the position of the character
            // Multiply position with its reverse alphabet value
            // and add it to the total sum
            sum += (i + 1) * reverseValue;
        }

        // Return the total reverse degree
        return sum;
    }
};