class Solution {
public:
    bool isPalindrome(string s) {

        string filtered;

        for (char c : s) {

            // isalnum(c) checks whether c is an alphabet or a number!
            // Spaces and special characters like ! , . @ are ignored.
            if (isalnum(c)) {
                filtered += tolower(c);
            }
        }

        int left = 0;
        int right = filtered.size() - 1;

        while (left < right) {

            if (filtered[left] != filtered[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};