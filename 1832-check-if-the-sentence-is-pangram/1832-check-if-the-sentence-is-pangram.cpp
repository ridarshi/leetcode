class Solution {
public:
    bool checkIfPangram(string sentence) {

        if (sentence.length() < 26)
            return false;

        bool vis[26] = {false};

        // Traverse every character in the sentence
        for (char c : sentence) {
            vis[c - 'a'] = true;
        }

        // Check whether every letter from a to z was found
        for (bool b : vis) {
            // If any letter was not found, the sentence is not a pangram.
            if (!b) {
                return false;
            }
        }

        // All 26 letters are present
        return true;
    }
};
