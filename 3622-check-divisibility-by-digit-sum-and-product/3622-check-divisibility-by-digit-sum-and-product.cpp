class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int product = 1;

        int copy = n;

        while(copy > 0){
            int digit = copy % 10;
            copy /= 10;

            sum += digit;
            product *= digit;
        }

        int divisor = sum + product;

        if( n % divisor == 0)return true;

        return false;
    }
};