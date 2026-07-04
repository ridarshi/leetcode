class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long revNum = 0;
        int dup = x;

        while(x>0){
            int lastdigit = x % 10;
            revNum = revNum * 10 + lastdigit;
            x /= 10;
        }
        if(dup == revNum) return true;
        return false;
    }
};