class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int contentchildren = 0;
        int cookieIndex = 0;

        while(contentchildren < g.size() && cookieIndex < s.size()){
            if(g[contentchildren] <= s[cookieIndex]){
                contentchildren++;
            }
            cookieIndex++;
        }

        return contentchildren;
    }
};