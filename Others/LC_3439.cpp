class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freeTime;
        freeTime.push_back(startTime[0]);
        for(int i=1;i<startTime.size();i++){
            int free=startTime[i]-endTime[i-1];
            freeTime.push_back(free);
        }
        freeTime.push_back(eventTime-endTime[endTime.size()-1]);
        int left=0,right=0;
        int n=freeTime.size();
        int maxi=0,sum=0;
        while(right<n){
            if(right-left+1>k+1){
                sum-=freeTime[left];
                left++;
            }
            sum+=freeTime[right];
            maxi=max(maxi,sum);
            right++;
        }
        return maxi;
    }
};
