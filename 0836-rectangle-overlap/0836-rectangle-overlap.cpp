class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // If one rectangle is completely to the left of the other
        if (rec1[2] <= rec2[0] || rec2[2] <= rec1[0])
            return false;
        
        // If one rectangle is completely above the other
        if (rec1[3] <= rec2[1] || rec2[3] <= rec1[1])
            return false;
        
        // Otherwise, rectangles overlap with positive area
        return true;
    }
};
    