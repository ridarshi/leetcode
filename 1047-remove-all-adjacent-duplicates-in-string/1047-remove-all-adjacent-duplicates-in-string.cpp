class Solution {
public:
    string removeDuplicates(string s) {
        string st;

        for(char x : s){
            if(!st.empty() && st.back() == x){
                st.pop_back();
            }
            else{
                st.push_back(x);
            }
        }
        return st;
    }
};