class Solution {
public:
    long long countSmallest(vector<int>& nums1, vector<int>& nums2,long long product){
        long long n=nums2.size();
        long long count=0;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]>=0){
                long long left=0;
                long long right=n-1;
                long long ind=-1;
                while(left<=right){
                    long long mid=right-(right-left)/2;
                    long long mul=1LL*nums1[i]*nums2[mid];
                    if(mul<=product){
                        ind=mid;
                        left=mid+1;
                    }
                    else right=mid-1;
                }
                count+=ind+1;
            }
            else{
                long long left=0;
                long long right=n-1;
                long long ind=n;
                while(left<=right){
                    long long mid=right-(right-left)/2;
                    long long mul=1LL*nums1[i]*nums2[mid];
                    if(mul<=product){
                        ind=mid;
                        right=mid-1;
                    }
                    else left=mid+1;
                }
                count+=n-ind;
            }
        }
        return count;
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long left=-1e10;
        long long right=1e10;
        long long result=0;
        while(left<=right){
            long long mid=right-(right-left)/2;
            long long count=countSmallest(nums1,nums2,mid);
            if(count<k){
                left=mid+1;
            }
            else right=mid-1;
        }
        return left;
    }
};
