class Solution {
public:
    // OPTIMAL APPROACH : TC = 0(1)
    long long countCommas(long long n) {
        long long res = 0;

        long long a = n - 999;
        if (a > 0) {
            res += a;
            a = n - 999999;
            if (a > 0) {
                res += a;
                a = n - 999999999;
                if (a > 0) {
                    res += a;
                    a = n - 999999999999;
                    if (a > 0) {
                        res += a;
                        a = n - 999999999999999;
                        if (a > 0) {
                            res += a;
                        }
                    }
                }
            }
        }
        return res;
    }
};


// Another OPTIMAL APPROACH : TC = 0(log n)
// class Solution {
// public:
//     long long countCommas(long long n) {
//         long long res = 0;

//         long long a = 1000;

//         while(a <= n){
//             res += n - a + 1;
//             a *= 1000;
//         }

//         return res;
//     }
// };