class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftSum=0,rightSum=0;
        for(int i=0;i<k;i++){
            leftSum+=cardPoints[i];
        }
        int maxSum=leftSum;
        int r=cardPoints.size()-1;
        for(int i=k-1;i>=0;i--){
            leftSum-=cardPoints[i];
            rightSum+=cardPoints[r];
            maxSum=max(maxSum,leftSum+rightSum);
            r--;
        }
        return maxSum;
    }
};
