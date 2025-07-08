class Solution {
public:
    int search(int low,int high,int end,vector<vector<int>>& events){
        while(low<=high){
            int mid=high-(high-low)/2;;
            if(events[mid][0]>end){
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
    int func(int ind,int k,int n,vector<vector<int>>& events,vector<vector<int>>& dp){
        if(k==0 || ind==events.size()) return 0;
        if(dp[ind][k]!=-1) return dp[ind][k];
        int next=search(ind+1,n-1,events[ind][1],events);
        int pick=events[ind][2]+func(next,k-1,n,events,dp);
        int notpick=func(ind+1,k,n,events,dp);
        return dp[ind][k]=max(pick,notpick);
    }
    // main call
    int maxValue(vector<vector<int>>& events, int k) {
        int n=events.size();
        sort(events.begin(),events.end());
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        return func(0,k,n,events,dp);
    }
};
