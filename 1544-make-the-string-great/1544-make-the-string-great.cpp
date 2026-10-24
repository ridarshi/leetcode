class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        string result = "";

        for(char c : s){
            if(st.empty()){
                st.push(c);
            }
            else if(abs(st.top() - c) == 32){
                st.pop();
            }
            else{
                st.push(c);
            }
        }
        while(!st.empty()){
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};