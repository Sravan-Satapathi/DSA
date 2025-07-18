class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int el=nums.size();
        int n=el/3;
        vector<long long> left(el,LONG_MAX),right(el,LONG_MIN);
        priority_queue<int> maxHeap;
        priority_queue<int,vector<int>,greater<int>> minHeap;
        long long sum=0;
        for(int i=0;i<el-n;i++){
            sum+=nums[i];
            maxHeap.push(nums[i]);
            if(!maxHeap.empty() && maxHeap.size()>n){
                sum-=maxHeap.top();
                maxHeap.pop();
            }
            left[i]=sum;
        }
        sum=0;
        for(int i=el-1;i>=n;i--){
            sum+=nums[i];
            minHeap.push(nums[i]);
            if(!minHeap.empty() && minHeap.size()>n){
                sum-=minHeap.top();
                minHeap.pop();
            }
            right[i]=sum;
        }
        long long diff=LONG_MAX;
        for(int i=n-1;i<el-n;i++){
            diff=min(diff,left[i]-right[i+1]);
        }
        return diff;
    }
};
