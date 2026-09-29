class Solution {
public:
    int romanToInt(string s) {

        // Store the value of each Roman numeral
        unordered_map<char, int> roman = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int result = 0;

        // Traverse the string
        for (int i = 0; i < s.size(); i++) {

            // If current value is smaller than the next value,
            // subtract the current value.
            // Example: IV -> 1 < 5, so subtract I.
            if (i + 1 < s.size() && roman[s[i]] < roman[s[i + 1]]) {
                result -= roman[s[i]];
            }

            // Otherwise, add the current value.
            else {
                result += roman[s[i]];
            }
        }

        return result;
    }
};

// current < next
//        ↓
//    SUBTRACT

// current >= next
//        ↓
//       ADD

// for MCMXCIV:
// M → 1000 → add
// C → 100  → subtract (because next is M = 1000)
// M → 1000 → add
// X → 10   → subtract (because next is C = 100)
// C → 100  → add
// I → 1    → subtract (because next is V = 5)
// V → 5    → add