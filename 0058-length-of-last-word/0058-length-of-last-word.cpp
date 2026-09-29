class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;

        // Traverse from the end of the string
        for(int i = s.size() - 1; i >= 0; i--) {

            // Count characters of the last word
            if(s[i] != ' ') {
                count++;
            }

            // We found a space after counting the last word
            else if(count != 0 && s[i] == ' ') {
                return count;
            }
        }

        return count;
    }
};