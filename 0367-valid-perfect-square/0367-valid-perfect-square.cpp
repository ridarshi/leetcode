class Solution {
public:
    bool isPerfectSquare(int num) {

        for(int i = 1; ;i++){
            long long square = 1LL * i * i;

            if(square == num){
                return true;
            }
            if(square > num){
                break;
            }
        }
        return false;
    }
};