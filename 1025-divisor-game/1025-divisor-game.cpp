class Solution {
public:
    bool divisorGame(int n) {

        // Hint 1: If n is even, Alice can choose x = 1.
        // Subtracting 1 from an even number gives an odd number.

        // Hint 2: If n is odd, every divisor x (where 0 < x < n)
        // must also be odd.
        // Subtracting an odd number from an odd number gives an even number.

        // Hint 3: The player who receives an even number can choose x = 1
        // and give the other player an odd number.
        // This strategy allows the player with an even number to win.

        // Hint 4: Therefore, Alice wins if n is even
        // and loses if n is odd.

        return n % 2 == 0;
    }
};