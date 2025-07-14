//TC - O(2N)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0,zeros=0;
        int left=0,right=0;
        while(right<n){
            if(nums[right]==0) zeros++;
            while(zeros>k){
                if(nums[left]==0) zeros--;
                left++;
            }
            count=max(count,right-left+1);
            right++;
        }
        return count;
    }
};

//TC - O(N)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0,zeros=0;
        int left=0,right=0;
        while(right<n){
            if(nums[right]==0) zeros++;
            if(zeros>k){
                if(nums[left]==0) zeros--;
                left++;
            }
            if(zeros<=k){
                 count=max(count,right-left+1);
            }
            right++;
        }
        return count;
    }
};
