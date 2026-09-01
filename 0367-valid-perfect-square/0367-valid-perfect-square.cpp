// class Solution {
// public:
//     bool isPerfectSquare(int num) {

//         for(int i = 1; ;i++){
//             long long square = 1LL * i * i;

//             if(square == num){
//                 return true;
//             }
//             if(square > num){
//                 break;
//             }
//         }
//         return false;
//     }
// };


// OPTIMAL BINARY SEARCH SOLUTION
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 2)return true;

        int low = 2;
        int high = num/2;

        while(low <= high){
            int mid = low + (high - low)/2;

            long long square = 1LL*mid*mid;

            if(square == num){
                return true;
            }
            else if(square < num){
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return false;
    }
};