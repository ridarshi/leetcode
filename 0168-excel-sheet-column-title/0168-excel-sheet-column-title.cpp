class Solution {
public:
    string convertToTitle(int columnNumber) {
        
        // This string will store the Excel column name
        string result = "";

        // Keep processing until columnNumber becomes 0
        while (columnNumber > 0) {

            // Excel columns are 1-based (A = 1, ..., Z = 26)
            // But % 26 works with 0-based values (0 to 25)
            // So we decrease columnNumber by 1
            columnNumber--;

            // Get the remainder
            // 0 -> A, 1 -> B, ..., 25 -> Z
            int rem = columnNumber % 26;

            // Convert the remainder into a character
            // 'A' + 0 = A
            // 'A' + 1 = B
            // ...
            // 'A' + 25 = Z
            result += 'A' + rem;

            // Move to the next position
            columnNumber /= 26;
        }

        // We calculated the characters from right to left,
        // so reverse the string to get the correct order
        reverse(result.begin(), result.end());

        // Return the Excel column title
        return result;
    }
};