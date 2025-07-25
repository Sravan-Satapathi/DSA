class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> hash;
        for(int i=0;i<t.size();i++){
            hash[t[i]]++;
        }
        int left=0,right=0;
        int start=-1,minLen=INT_MAX;
        int count=0;
        while(right<s.size()){
            hash[s[right]]--;
            if(hash[s[right]]>=0) count++;
            while(count==t.size()){
                int currLen=right-left+1;
                if(currLen<minLen){
                    minLen=currLen;
                    start=left;
                }
                hash[s[left]]++;
                if(hash[s[left]]>0) count--;
                left++;
            }
            right++;
        }
        if(start==-1) return "";
        return s.substr(start,minLen);
    }
};
