//Time Complexity - O((logn)^2)
//Space Complexity - O(logn) 
class Solution {
public:
    int func(long curr,long next,int n){
        int count=0;
        while(curr<=n){
            count+=next-curr;
            curr*=10;
            next*=10;
            next=min(next,long(n+1));
        }
        return count;
    }
    int findKthNumber(int n, int k) {
        int curr=1;
        k--;
        while(k>0){
            int count=func(curr,curr+1,n);
            if(count<=k){
                curr++;
                k-=count;
            }
            else{
                curr*=10;
                k--;
            }
        }
        return curr;
    }
};
