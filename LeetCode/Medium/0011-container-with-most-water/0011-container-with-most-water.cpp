class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int lp = 0 , rp = height.size()-1;
        while(lp < rp){
            int ht = min(height[lp],height[rp]);
            int wt = rp - lp;
            int currArea = ht * wt;
            maxArea = max(currArea , maxArea);

            height[lp] < height[rp] ? lp++ : rp--;
        }
        return maxArea;
        
    } 
};