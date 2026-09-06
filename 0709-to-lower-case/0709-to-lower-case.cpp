class Solution {
public:
    string toLowerCase(string s) {

        // & makes c a reference to the actual
        // character in the string
        for(char &c : s) {

            // Check if character is uppercase
            if(c >= 'A' && c <= 'Z') {

                // Convert uppercase to lowercase
                c = c + 32;
            }
        }

        return s;
    }
};