class Solution {
public:
    int strStr(string haystack, string needle) {
        int haylength = haystack.length();
        int needlelength = needle.length();
        
        if(haylength < needlelength){
            return -1;
        }

        for(int i = 0;i<= haylength - needlelength;i++){
            int j = 0;

            while(j < needlelength && haystack[i + j] == needle[j]){
                j++;
            }

            if(j == needlelength){
                return i;
            }
        }
        return -1;
    }
};