class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {

        // Store key -> value
        unordered_map<string, string> mp;

        // Put all knowledge pairs into the map
        for (auto it : knowledge) {
            mp[it[0]] = it[1];
        }

        string ans = "";

        // Traverse the string
        for (int i = 0; i < s.length(); i++) {

            // Normal character
            if (s[i] != '(') {
                ans += s[i];
            }

            // Opening bracket
            else {
                string key = "";
                i++;  // move past '('

                // Collect characters until ')'
                while (s[i] != ')') {
                    key += s[i];
                    i++;
                }

                // Check whether key exists
                if (mp.find(key) != mp.end()) {
                    ans += mp[key];
                }
                else {
                    ans += '?';
                }
            }
        }

        return ans;
    }
};