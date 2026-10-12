
class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        // n = 4: binary representation is 100,
        // which is not a palindrome.

        // n > 4: in base (n - 2), the representation
        // of n is always 12, which is not a palindrome.
        // The same logic works for every n > 4:
        // n = 1 * (n-2) + 2
        
        // always check the largest base first, if n = 15;
        // largest base is (n-2) = 13
        // 15 = 1*(15-2) + 2;

        // Therefore, no valid n can be strictly palindromic.
        return false;
    }
};
