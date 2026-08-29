class Solution {
public:
    bool isUgly(int n) {

        // Ugly numbers must be positive
        if(n <= 0)
            return false;

        // Remove all factors of 2
        while(n % 2 == 0){
            n /= 2;
        }

        // Remove all factors of 3
        while(n % 3 == 0){
            n /= 3;
        }

        // Remove all factors of 5
        while(n % 5 == 0){
            n /= 5;
        }

        // If nothing remains except 1,
        // the number had only 2, 3 and 5 as prime factors
        return n == 1;
    }
};