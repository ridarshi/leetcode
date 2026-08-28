class Solution {
public:
    int addDigits(int num) {

        // Special case: digital root of 0 is 0
        if (num == 0)
            return 0;

        // Digital root formula
        return 1 + (num - 1) % 9;
    }
};

// class Solution {
// public:
//     int addDigits(int num) {

//         int sum = 0;

//         // First, calculate the sum of all digits of num
//         while (num > 0) {

//             // Get the last digit
//             int digit = num % 10;

//             // Add the digit to sum
//             sum += digit;

//             // Remove the last digit
//             num /= 10;
//         }

//         // If sum has more than one digit,
//         // keep adding its digits until only one digit remains
//         while (sum >= 10) {

//             int newSum = 0;

//             // Extract and add all digits of sum
//             while (sum > 0) {

//                 // Get the last digit of sum
//                 int dig = sum % 10;

//                 // Add it to newSum
//                 newSum += dig;

//                 // Remove the last digit from sum
//                 sum /= 10;
//             }

//             // Store the newly calculated digit sum
//             sum = newSum;
//         }

//         // Return the final single-digit result
//         return sum;
//     }
// };