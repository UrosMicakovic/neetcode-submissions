class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left=0;
        int right=heights.size()-1;
        int maxHeight;
        int width;
        int res=0;
        while (left<right){
            if(heights[left]<heights[right]) maxHeight=heights[left];
            else maxHeight=heights[right];
            width=right-left; 
            if(res<maxHeight*width) res=maxHeight*width;
            if(heights[left]<heights[right]) left++;
            else right--;
        }
        return res;
    }
};
