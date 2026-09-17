class Solution {
public:

    // Returns the index of the next character that survives
    int getNext(string &s, int i, int &skip) {

        while (i >= 0) {

            // '#' means the previous character must be deleted
            if (s[i] == '#') {
                skip++;
                i--;
            }

            // This character is deleted by a previous '#'
            else if (skip > 0) {
                skip--;
                i--;
            }

            // This character survives
            else {
                return i;
            }
        }

        // No character left
        return -1;
    }

    bool backspaceCompare(string s, string t) {

        int i = s.length() - 1;
        int j = t.length() - 1;

        int skipS = 0;
        int skipT = 0;

        while (true) {

            // Find next valid character in both strings
            i = getNext(s, i, skipS);
            j = getNext(t, j, skipT);

            // Both strings have no characters left
            if (i == -1 && j == -1) {
                return true;
            }

            // Only one string has a character left
            if (i == -1 || j == -1) {
                return false;
            }

            // Surviving characters are different
            if (s[i] != t[j]) {
                return false;
            }

            // Characters matched, move both pointers left
            i--;
            j--;
        }
    }
};