class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freeTime;
        freeTime.push_back(startTime[0]);
        for(int i=1;i<startTime.size();i++){
            int t=startTime[i]-endTime[i-1];
            freeTime.push_back(t);
        }
        freeTime.push_back(eventTime-endTime[endTime.size()-1]);
        int n=freeTime.size();
        vector<int> right(n,0);
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],freeTime[i+1]);
        }
        int maxi=0,left=0;
        for(int i=1;i<n;i++){
            int currTime=endTime[i-1]-startTime[i-1];
            if(currTime<=max(right[i],left)){
                maxi=max(maxi,freeTime[i-1]+currTime+freeTime[i]);
            }
            else maxi=max(maxi,freeTime[i-1]+freeTime[i]);
            left=max(left,freeTime[i-1]);
        }
        return maxi;
    }
};
