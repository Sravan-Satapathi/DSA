//Time Complexity - O(nlogn)
//Space Complexity - O(n)
class Solution {
public:
    bool isValid(vector<int>& nums,int window,int n,vector<long long>& prefix,long long k){
        int left=0,right=window-1;
        while(right<n){
            int mid=(left+right)/2;
            long long target=nums[mid];
            long long lh;
            if(mid==0) lh=0;
            else{
                lh=prefix[mid-1];
                if(left!=0) lh-=prefix[left-1];
            }
            long long rh=prefix[right]-prefix[mid];
            long long op=target*(mid-left)-lh;
            op+=(rh-target*(right-mid));
            if(op<=k) return true;
            left++,right++;
        }
        return false;
    }
    void prefixSum(int n,vector<int>& nums,vector<long long>& prefix){
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=nums[i]+prefix[i-1];
        }
    }
    //main call
    int maxFrequencyScore(vector<int>& nums, long long k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<long long> prefix(n,0);
        prefixSum(n,nums,prefix);
        int low=1,high=n;
        int ans=1;
        while(low<=high){
            int mid=high-(high-low)/2;
            if(isValid(nums,mid,n,prefix,k)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};
