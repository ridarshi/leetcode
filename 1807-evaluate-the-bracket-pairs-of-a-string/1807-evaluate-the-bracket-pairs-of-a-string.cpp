class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;

        for(auto it : knowledge){
            mp[it[0]] = it[1];
        }

        string answer = "";

        for(int i = 0;i<s.length();i++){
            if(s[i] != '('){
                answer += s[i];
            }
            else {
                string key = "";
                i++;

                while(s[i] != ')'){
                    key += s[i];
                    i++;
                }

                if(mp.find(key) != mp.end()){
                    answer += mp[key];
                }
                else{
                    answer += '?';
                }
            }
        }
        return answer;
    }
};