// Optimal solution : TC -> 0(root of n)
class Solution {
public:
    bool checkPerfectNumber(int num) {

        int sum = 0;
        // Check divisors only up to sqrt(num)
        for (int i = 1; i * i <= num; i++) {

            // If i divides num completely, it is a divisor
            if (num % i == 0) {

                // Add the smaller divisor
                sum += i;

                // Add its corresponding larger divisor
                // Avoid adding the same divisor twice for perfect squares
                if (i * i != num) {
                    sum += num / i;
                }
            }
        }

        // sum includes num itself, so subtract num
        // A perfect number equals the sum of its proper divisors
        return sum - num == num;
    }
};


// BRUTE FORCE: TC -> 0(n)
// class Solution {
// public:
//     bool checkPerfectNumber(int num) {

//         int sum = 0;
        
//         for(int i = 1;i<num;i++){
//             if(num % i == 0){
//                 sum += i;
//             }
//             if(sum > num){
//                 return false;
//             }
//         }

//         return sum == num;
//     }
// };