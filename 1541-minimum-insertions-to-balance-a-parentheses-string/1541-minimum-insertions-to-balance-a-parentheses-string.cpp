class Solution {
public:
    int minInsertions(string s) {
        int leftcount = 0;
        int index = 0;
        int insertions = 0;
        int length = s.size();

        while (index < length) {
            if (s[index] == '(') {
                leftcount++;
                index++;
            } else {
                if (leftcount > 0) {
                    leftcount--;
                }
                else{
                    insertions++;
                }

                if(index < length - 1 && s[index+1] == ')'){
                    index+=2;
                }
                else{
                    insertions++;
                    index++;
                }
            }
        }

        insertions += leftcount*2;
        return insertions;
    }
};