class Solution {
public:
    int countNice(vector<int>& nums,int k){
        if(k<0) return 0;
        int left=0,right=0,count=0,result=0;
        while(right<nums.size()){
            count+=nums[right]%2;
            while(count>k){
                count-=nums[left]%2;
                left++;
            }
            result+=right-left+1;
            right++;
        }
        return result;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return countNice(nums,k)-countNice(nums,k-1);
    }
};
