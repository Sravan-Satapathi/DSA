//Approach 1
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> prefix_max(n),suffix_max(n);
        prefix_max[0]=height[0],suffix_max[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            prefix_max[i]=max(prefix_max[i-1],height[i]);
        }
        for(int i=n-2;i>=0;i--){
            suffix_max[i]=max(suffix_max[i+1],height[i]);
        }
        int sum=0;
        for(int i=0;i<n;i++){
            int left_max=prefix_max[i];
            int right_max=suffix_max[i];
            sum+=min(left_max,right_max)-height[i];
        }
        return sum;
    }
};
