class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       vector<int> hash(256,-1);
       int left=0,right=0,max_val=0;
       while(right<s.size()){
         if(hash[s[right]]!=-1){
            if(hash[s[right]]>=left){
                left=hash[s[right]]+1;
            }
         }
         max_val=max(max_val,right-left+1);
         hash[s[right]]=right;
         right++;
       }
       return max_val;
    }
};
