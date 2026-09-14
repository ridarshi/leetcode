class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {

        // If rec1 is completely to the left of rec2
        if (rec1[2] <= rec2[0]) {
            return false;
        }

        // If rec1 is completely to the right of rec2
        if (rec1[0] >= rec2[2]) {
            return false;
        }

        // If rec1 is completely below rec2
        if (rec1[3] <= rec2[1]) {
            return false;
        }

        // If rec1 is completely above rec2
        if (rec1[1] >= rec2[3]) {
            return false;
        }

        // If none of the above happened,
        // the rectangles must have positive-area overlap.
        return true;
    }
};
